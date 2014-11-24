#ifndef _NXCORE_SUNDRY_MSG_H_
#define _NXCORE_SUNDRY_MSG_H_

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

// 背包中的道具
struct SundryListSMsg : public PlayerMsg
{
    enum { id = 0xA80 };

    uint16 count;
    struct Props {
        uint16 slot;
        uint16 sundryID;
        uint16 count;
    } list[0];
    
    SundryListSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

// 使用道具
struct SundryUseCMsg : public PlayerMsg
{
    enum { id = 0xA81 };
    
    uint16 slot;
    uint16 count;
    SundryUseCMsg()
        : PlayerMsg(id, sizeof(*this))
        , slot(0)
        , count(0)
    {}
};

// 使用道具结果
struct SundryUseSMsg : public PlayerMsg
{
    enum { id = 0xA82 };

    uint8 ret;
    SundryUseSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};
#pragma pack(pop)

CORE_NAMESPACE_END

#endif//SundryMsg 
