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
    
    uint32 curr;       // 当前所在层数
    uint32 best;       // 历史最高层数
    uint32 lifeused;   // 已经用掉的挑战次数
    uint32 lifecount;  // 可以挑战的总次数
    uint32 resetused;  // 已经重置的次数
    uint32 resetcount; // 可以重置的总次数
    uint32 autofight;  // 是否处在扫荡状态
    uint32 starttime;  // 扫荡开始的时间戳
    uint32 endtime;    // 扫荡结束的时间戳
    uint32 currtime;   // 服务器当前时间戳
    uint32 startlevel; // 扫荡开始的层数
    
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
    uint32 param;
    
    BabelOpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , param(0)
    {}
};

/**
 * 挑战操结果
 */
struct BabelOpSMsg : public PlayerMsg
{
    enum { id = 0xAC2 };

    uint32 op;
    uint32 ret;
    uint32 param;
    
    BabelOpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , ret(0)
        , param(0)
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

struct BabelAutoFightRewardSMsg : public PlayerMsg
{
    enum { id = 0xAC6 };

    uint32 reschgtype;
    uint32 count;
    ItemReward list[0];
    
    BabelAutoFightRewardSMsg()
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

