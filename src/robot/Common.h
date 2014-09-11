#ifndef COMMON_H
#define COMMON_H

typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;
typedef unsigned long long uint64;

#include <muduo/net/TcpClient.h>

#include <muduo/base/Logging.h>
#include <muduo/base/Thread.h>
#include <muduo/base/Singleton.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/EventLoopThreadPool.h>
#include <muduo/net/InetAddress.h>

#include <boost/bind.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include <utility>

#include <muduo/net/Buffer.h>
#include <muduo/net/Endian.h>
#include <muduo/net/TcpConnection.h>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

#include <stdio.h>
#include <unistd.h>

#endif
