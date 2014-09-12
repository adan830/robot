#ifndef COMMON_H
#define COMMON_H

#include <sys/types.h>
#include <map>
#include <set>
#include <list>
#include <vector>

#ifdef __NXCORE_NAMESPACE__
#define CORE_NAMESPACE_START namespace NXCore{
#define CORE_NAMESPACE_END };
#define USING_NXCORE using namespace NXCore;
#else
#define CORE_NAMESPACE_START
#define CORE_NAMESPACE_END 
#define USING_NXCORE
#endif

#define MAP_CONTAINER(KEY, ENTRY) std::map<KEY, ENTRY>
#define MMAP_CONTAINER(KEY, ENTRY) std::multimap<KEY, ENTRY>
#define VECTOR_CONTAINER(ENTRY) std::vector<ENTRY>
#define MSET_CONTAINER(ENTRY) std::multiset<ENTRY>
#define LIST_CONTENTER(ENTRY) std::list<ENTRY>
#define SET_CONTAINER(ENTRY) std::set<ENTRY, std::less<ENTRY> >

typedef __int8_t    int8;
typedef __int16_t   int16;
typedef __int32_t   int32;
typedef __int64_t   int64;

typedef __uint8_t   uint8;
typedef __uint16_t  uint16;
typedef __uint32_t  uint32;
typedef __uint64_t  uint64;

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
