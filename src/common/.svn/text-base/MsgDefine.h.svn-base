#ifndef __NXCORE_MSGDEFINE__
#define __NXCORE_MSGDEFINE__

#include "Define.h"

CORE_NAMESPACE_START

class Task;

#ifdef WIN32
#define bzero(a, b) memset((a), 0, (b))
#endif

#define MSG_HANDLER_SIZE 0x1000

typedef void (*msg_handler_t)(void*, Task*);
#ifdef _MSC_VER
#pragma section(".CRT$XCU",read)
#define __init_fun(fun) \
	static void __cdecl fun(void); \
	__declspec(allocate(".CRT$XCU")) void (__cdecl*fun##_)(void) = fun; \
	static void __cdecl fun(void)
#elif defined(__GNUC__)
#define __init_fun(fun) \
	__attribute__((constructor)) static void fun(void)
#endif
#define MSG_HANDLER(task_type, msg_type) \
	static void _##task_type##_##msg_type##_handler(msg_type*, Task*); \
	__init_fun(_##task_type##_##msg_type##_init) { \
		Server::initMsgHandler(task_type * MSG_HANDLER_SIZE + msg_type::id, \
		(msg_handler_t)_##task_type##_##msg_type##_handler);} \
	static void _##task_type##_##msg_type##_handler(msg_type* msg, Task* task)

#define NEW_MAX_MSG(msg_type) \
	msg_type* newmsg = new (new char[MSG_MAX_SIZE]) msg_type(); \
	MM_CHECKIN(newmsg, MSG_MAX_SIZE)

#define NEW_MSG(msg_type, msg_size) \
	msg_type* newmsg = new (new char[msg_size]) msg_type(); \
	MM_CHECKIN(newmsg, msg_size)

#define NEW_ONE_MSG(msg_type) \
	msg_type* newmsg = new (new char[sizeof(msg_type)]) msg_type(); \
	MM_CHECKIN(newmsg, sizeof(msg_type))

#define COPY_MSG(msg_type, oldmsg) \
	msg_type* newmsg = new (new char[oldmsg->size]) msg_type(); \
	memcpy(newmsg, oldmsg, oldmsg->size); \
	MM_CHECKIN(newmsg, oldmsg->size)
	

#define CHECK_MSG_SIZE(msg_type) \
	if(msg->size != sizeof(msg_type)) \
	{ DEBUG_LOG("CheckMsgSize failed: type=0x%04X, size=%u\n", msg->type, msg->size); return;}

#define CHECK_MSG_USESIZE() \
	if(msg->size != msg->getSize()) \
	{ DEBUG_LOG("CheckMsgUseSize failed: type=0x%04X, size=%u\n", msg->type, msg->size); return;}

#include <BaseMsg.h>

CORE_NAMESPACE_END
#endif//__NXCORE_MSGDEFINE__

