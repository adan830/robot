#ifndef __NXCORE_CASHMSG__
#define __NXCORE_CASHMSG__

#include "MsgDefine.h"
#include "PlayerMsg.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

struct CashOpCMsg : public PlayerMsg
{
    enum { id = 0xB60 };

    int op;
    int param;
    
    CashOpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , param(0)
    {}
};

struct CashorsListSMsg : public PlayerMsg
{
    enum { id = 0xB61 };

    int count;

    CashorMsgData list[0];

    CashorsListSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}

    int getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

struct CashPropsSMsg : public PlayerMsg
{
    enum { id = 0xB62 };

    CashProps props;

    CashPropsSMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

struct CashRewardSMsg : public PlayerMsg
{
    enum { id = 0xB63 };

    uint32     reschgtype;
    uint32     count;
    ItemReward list[0];
    
    CashRewardSMsg()
        : PlayerMsg(id, sizeof(*this))
    {}

    uint32 getSize()
    {
        return sizeof(*this) + sizeof(list[0]) * count;
    }
};

struct CashorsMineListSMsg : public PlayerMsg
{
    enum { id = 0xB64 };

    int count;
    
    Cashor list[0];

    CashorsMineListSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}

    int getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};
#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_ARENAMSG__

