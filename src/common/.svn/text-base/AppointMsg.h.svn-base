#ifndef __APPOINT_MSG_H__
#define __APPOINT_MSG_H__

#include "MsgDefine.h"
#include "PlayerMsg.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

struct AppointOpCMsg : public PlayerMsg
{
    enum { id = 0xB50 };
    
    int AppointSlot;
    int CardSlot;

    AppointOpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , AppointSlot(0)
        , CardSlot(0)
    {}
};

struct AppointSMsg : public PlayerMsg
{
    enum { id = 0xB51 };
    
    int ret;
    int slot[6];
    
    AppointSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {
        bzero(slot, sizeof(slot));
    }
};
#pragma pack(pop)

CORE_NAMESPACE_END
#endif

