/**
 * \filename   Base.h		v1.0
 * \brief      定义基础类型和Base类
 *             
 * \author     zhufang(zhufang666@gmail.com)
 * \created    2012-09-25 02:58
 */
#ifndef __NXCORE_BASE__
#define __NXCORE_BASE__

#include <stddef.h>
#include <sys/types.h>

#ifdef __NXCORE_NAMESPACE__
#define CORE_NAMESPACE_START namespace NXCore{
#define CORE_NAMESPACE_END };
#define USING_NXCORE using namespace NXCore;
#else
#define CORE_NAMESPACE_START
#define CORE_NAMESPACE_END 
#define USING_NXCORE
#endif

CORE_NAMESPACE_START

typedef __int8_t    int8;
typedef __int16_t   int16;
typedef __int32_t   int32;
typedef __int64_t   int64;

typedef __uint8_t   uint8;
typedef __uint16_t  uint16;
typedef __uint32_t  uint32;
typedef __uint64_t  uint64;

typedef int8		SBYTE;
typedef int16		SWORD;
typedef int32		SDWORD;
typedef int64		SQWORD;

typedef uint8		BYTE;
typedef uint16		WORD;
typedef uint32		DWORD;
typedef uint64		QWORD;

#if __WORDSIZE == 64
typedef	uint64		PTR;
#else 
typedef	uint32		PTR;
#endif

const int MSG_MAX_SIZE = 64 * 1000;

CORE_NAMESPACE_END

#endif//__NXCORE_BASE__

