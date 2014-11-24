#ifndef __CLIENT_H__
#define __CLIENT_H__
#include <muduo/net/TcpClient.h>

#include <muduo/base/Logging.h>
#include <muduo/base/Thread.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/EventLoopThreadPool.h>
#include <muduo/net/InetAddress.h>

#include <boost/bind.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "Commander.h"
#include "Robot.h"
using namespace muduo;
using namespace muduo::net;

class Robot;
class Client : boost::noncopyable
{
public:
    Client(EventLoop* loop,
           const InetAddress& AccountServer,
           const InetAddress& GatewayServer,
           int sessionCount,
           int timeout,
           int threadCount);

    const string& message() const;
    void onConnect();
    void onDisconnect(const TcpConnectionPtr& conn);
    void IntCount();
private:

    void quit();
    void handleTimeout();
    
    EventLoop* loop_;
    EventLoopThreadPool threadPool_;
    int sessionCount_;
    int timeout_;
    boost::ptr_vector<Robot> sessions_;
    string message_;
    AtomicInt32 numConnected_;
};
#endif

