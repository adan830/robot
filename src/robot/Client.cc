#include "Robot.h"
#include "Client.h"

Client::Client(EventLoop* loop,
               const InetAddress& AccountServer,
               const InetAddress& GatewayServer,
               int blockSize,
               int sessionCount,
               int timeout,
               int threadCount)
    : loop_(loop),
      threadPool_(loop),
      sessionCount_(sessionCount),
      timeout_(timeout) {
    loop->runAfter(timeout, boost::bind(&Client::handleTimeout, this));
    if (threadCount > 1) {
        threadPool_.setThreadNum(threadCount);
    }
    threadPool_.start();

    for (int i = 0; i < blockSize; ++i) {
        message_.push_back(static_cast<char>(i % 128));
    }

    for (int i = 0; i < sessionCount; ++i) {
        char buf[32];
        snprintf(buf, sizeof buf, "C%05d", i);
        Robot* session = new Robot(threadPool_.getNextLoop(), AccountServer, GatewayServer, buf, this);
        session->AccountConnect();
        sessions_.push_back(session);
    }
}

const string& Client::message() const {
    return message_;
}

void Client::onConnect() {
    if (numConnected_.incrementAndGet() == sessionCount_) {
        LOG_WARN << "all connected";
    }
}

void Client::onDisconnect(const TcpConnectionPtr& conn) {
    if (numConnected_.decrementAndGet() == 0) {
//        int64_t totalBytesRead = 0;
//        int64_t totalMessagesRead = 0;
        conn->getLoop()->queueInLoop(boost::bind(&Client::quit, this));
    }
}

void Client::quit() {
    loop_->queueInLoop(boost::bind(&EventLoop::quit, loop_));
}

void Client::handleTimeout() {
    LOG_WARN << "stop";
//    std::for_each(sessions_.begin(), sessions_.end(),
//                  boost::mem_fn(&Robot::AccountStop));
}


