#include "Robot.h"
#include "Client.h"

Cmd cmd;
Client::Client(EventLoop* loop,
               const InetAddress& AccountServer,
               const InetAddress& GatewayServer,
               int sessionCount,
               int timeout,
               int threadCount)
    : loop_(loop),
      threadPool_(loop),
      sessionCount_(sessionCount),
      timeout_(timeout)
{
    loop->runAfter(timeout, boost::bind(&Client::handleTimeout, this));
    if (threadCount > 1) {
        threadPool_.setThreadNum(threadCount);
    }
    threadPool_.start();

    for (int i = 0; i < sessionCount; ++i) {
        char buf[32];
        snprintf(buf, sizeof buf, "C%05d", i);
        Robot* pRobot = new Robot(threadPool_.getNextLoop(),
                                  AccountServer,
                                  GatewayServer,
                                  buf,
                                  this);
        pRobot->SetExecCmdCallBack(std::bind(&Cmd::Op, &cmd, std::placeholders::_1, std::placeholders::_2));
        // 如果本地存在 Session，就不需要连接
        // Account
        if (tableSessions.size() > 0) {
            pRobot->GetSession();
        }
        pRobot->AccountConnect();

        sessions_.push_back(pRobot);
    }
}

const string& Client::message() const {
    return message_;
}

void Client::onDisconnect(const TcpConnectionPtr& conn) {
    if (numConnected_.decrementAndGet() == 0) {
        conn->getLoop()->queueInLoop(boost::bind(&Client::quit, this));
    }
}

void Client::quit() {
    loop_->queueInLoop(boost::bind(&EventLoop::quit, loop_));
}

void Client::handleTimeout() {
    LOG_WARN << "stop";
}

void Client::IntCount()
{
    LOG_INFO << "IntCount";
}
