#ifndef __VIP_H__
#define __VIP_H__
#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

struct VipBuySpCMsg : public PlayerMsg
{
    enum { id = 0xAA0 };

    VipBuySpCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

struct VipBuySpSMsg : public PlayerMsg
{
    enum { id = 0xAA1 };

    uint32 ret;

    VipBuySpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

struct VipBuyPvpSpCMsg : public PlayerMsg
{
    enum { id = 0xAA2 };

    VipBuyPvpSpCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

struct VipBuyPvpSpSMsg : public PlayerMsg
{
    enum { id = 0xAA3 };

    uint32 ret;

    VipBuyPvpSpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

struct VipResetDungeonCMsg : public PlayerMsg
{
    enum { id = 0xAA4 };

    uint16 dungeonid;

    VipResetDungeonCMsg()
        : PlayerMsg(id, sizeof(*this))
        , dungeonid(0)
    {}
};

struct VipResetDungeonSMsg : public PlayerMsg
{
    enum { id = 0xAA5 };

    uint32 ret;
    uint16 dungeonid;
    
    VipResetDungeonSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
        , dungeonid(0)
    {}
};

struct VipAddBagSlotCMsg : public PlayerMsg
{
    enum { id = 0xAA6 };
    
    uint8 bagtype;
    
    VipAddBagSlotCMsg()
        : PlayerMsg(id, sizeof(*this))
        , bagtype(0)
    {}
};

struct VipAddBagSlotSMsg : public PlayerMsg
{
    enum { id = 0xAA7 };
    
    uint32 ret;

    VipAddBagSlotSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

struct VipBuyEnterCountCMsg : public PlayerMsg
{
    enum { id = 0xAA8 };

    uint16 dungeonid;

    VipBuyEnterCountCMsg()
        : PlayerMsg(id, sizeof(*this))
        , dungeonid(0)
    {}
};

struct VipBuyEnterCountSMsg : public PlayerMsg
{
    enum { id = 0xAA9 };

    uint32 ret;
    uint16 dungeonid;
        
    VipBuyEnterCountSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
        , dungeonid(0)
    {}
};

#pragma pack(pop)

CORE_NAMESPACE_END
#endif
