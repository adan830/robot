#ifndef _NXCORE_DUNGEON_MSG_H_
#define _NXCORE_DUNGEON_MSG_H_

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

struct DungeonProgressSMsg : public PlayerMsg
{
    enum { id = 0xA60 };
    
    uint8  dungeontype;
    uint16 bigLv;
    uint16 smallLv;
    uint16 eliteBigLv;
    uint16 eliteSmallLv;
    
    DungeonProgressSMsg()
        : PlayerMsg(id, sizeof(*this))
        , dungeontype(0)
        , bigLv(0)
        , smallLv(0)
        , eliteBigLv(0)
        , eliteSmallLv(0)
    {}
};

struct DungeonScoreCMsg : public PlayerMsg
{
    enum { id = 0xA61 };
    
    DungeonScoreCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

struct DungeonScoreSMsg : public PlayerMsg
{
    enum { id = 0xA62 };

    uint16 count;

    struct Scores {
        uint16 bigLvId;
        uint16 bigScore;
        uint16 reward;
        struct {
            uint16 smallLvId;
            uint16 star;
            uint16 entercount;
            uint16 count;
            uint16 tick;
        } scores[10];
    } list[0];
    
    DungeonScoreSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

/**
 * 领取大关卡奖励
 */
struct DungeonRewardCMsg : public PlayerMsg
{
    enum { id = 0xA63 };

    uint16 bigLv;
    uint16 rewardtype;

    DungeonRewardCMsg()
        : PlayerMsg(id, sizeof(*this))
        , bigLv(0)
        , rewardtype(0)
    {}
};

/**
 * 领取奖励结果
 */
struct DungeonRewardSMsg : public PlayerMsg
{
    enum { id = 0xA64 };

    uint32 ret;
    uint16 bigLv;
    uint16 rewardtype;
    uint8 reward;
    
    DungeonRewardSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
        , bigLv(0)
        , rewardtype(0)
        , reward(0)
    {}
};

struct DungeonScoreUpdateSMsg : public PlayerMsg
{
    enum { id = 0xA65 };

    uint16 bigLv;
    uint16 bigScore;
    uint16 smallLv;
    uint16 score;
    uint16 entercount;
    uint16 count;
    uint16 tick;
    
    DungeonScoreUpdateSMsg()
        : PlayerMsg(id, sizeof(*this))
        , bigLv(0)
        , bigScore(0)
        , smallLv(0)
        , score(0)
        , entercount(0)
        , count(0)
        , tick(0)
    {}
};

struct DungeonAutoFightRewardSMsg : public PlayerMsg
{
    enum { id = 0xA66 };

    struct Item {
        uint8  type;
        uint16 itemId;
        uint16 count;
        uint8  level;        
    };

    uint32 exp;
    uint32 money;
    uint8 count;
    struct reward {
        uint8 count;
        Item list[0];
    } rewards[0];
    
    DungeonAutoFightRewardSMsg()
        : PlayerMsg(id, sizeof(*this))
        , exp(0)
        , money(0)
        , count(0)
    {}

    uint16 getSize()
    {
        uint16 size = sizeof(*this);
        for (int i = 0; i < count; ++i)
        {
            // sizeof(Item) = 6
            size += rewards[i].count * 6 + 1;
        }

        return size;
    }
};
#pragma pack(pop)

CORE_NAMESPACE_END

#endif//DungeonMsge _DUNGEON_MSG_H_
