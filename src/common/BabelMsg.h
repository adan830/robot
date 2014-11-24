#ifndef __BABEL_MSG_H__
#define __BABEL_MSG_H__

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * 通天塔信息
 */
struct BabelSMsg : public PlayerMsg
{
    enum { id = 0xAC0 };

    uint32 curr;
    uint32 best;
    uint32 lifeused;
    uint32 lifecount;
    uint32 resetused;
    uint32 resetcount;
    uint32 autofight;
    uint32 starttime;
    uint32 endtime;
    uint32 currtime;
    uint32 startlevel;
    
    BabelSMsg()
        : PlayerMsg(id, sizeof(*this))
        , curr(0)
        , best(0)
        , lifeused(0)
        , lifecount(0)
        , resetused(0)
        , resetcount(0)
        , autofight(0)
        , starttime(0)
        , currtime(0)
        , startlevel(0)
    {}
};

/**
 * 挑战通天塔
 */
struct BabelOpCMsg : public PlayerMsg
{
    enum { id = 0xAC1 };

    uint32 op;
//    uint32 param;
    
    BabelOpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
//        , param(0)
    {}
};

/**
 * 挑战操结果
 */
struct BabelOpSMsg : public PlayerMsg
{
    enum { id = 0xAC2 };

    uint32 op;
    uint8  ret;

    BabelOpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , ret(0)
    {}
};

/**
 * 请求排名信息
 */
struct BabelRankCMsg : public PlayerMsg
{
    enum { id = 0xAC3 };

    uint32 page;

    BabelRankCMsg()
        : PlayerMsg(id, sizeof(*this))
        , page(0)
    {}
};

/**
 * 通天塔排名信息
 */
struct BabelRankSMsg : public PlayerMsg
{
    enum { id = 0xAC4 };

    uint32 currrank;
    uint32 count;
    
    struct Rank {
        playerid_t CharId;
        uint32 leadcard;
        uint32 rank;
        uint32 level;
        uint32 best;
        char   name[32];
    } list[0];
    
    BabelRankSMsg()
        : PlayerMsg(id, sizeof(*this))
        , currrank(0)
        , count(0)
    {}

    uint32 getSize()
    {
        return sizeof(*this) + sizeof(list[0]) * count;
    }
};

/**
 * 玩家获得物品
 */
struct BabelTradeInSMsg : public PlayerMsg
{
    enum { id = 0xAC5 };

    uint8 count;

    struct Item {
        uint8  type;
        uint16 itemId;
        uint32 count;
        uint8  level;
    } list[0];
    
    BabelTradeInSMsg()
        : PlayerMsg(id, sizeof(*this))
    {}

    uint32 getSize()
    {
        return sizeof(*this) + sizeof(list[0]) * count;
    }
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif

