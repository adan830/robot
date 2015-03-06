#ifndef _NXCORE_QUEST_MSG_H_
#define _NXCORE_QUEST_MSG_H_

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * 任务列表
 */
struct QuestListSMsg : public PlayerMsg
{
    enum { id = 0xA98 };

    int    cd;
    uint16 count;
    struct Quest {
        uint16 id;
        uint32 value;
        uint32 maxvalue;
        uint16 state;
    } list[0];
    
    QuestListSMsg()
        : PlayerMsg(id, sizeof(*this))
        , cd(0)
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

/**
 * 领取任务奖励
 */
struct GetQuestRewardCMsg : public PlayerMsg
{
    enum { id = 0xA99 };

    uint16 questid;

    GetQuestRewardCMsg()
        : PlayerMsg(id, sizeof(*this))
        , questid(0)
    {}
};

/**
 * 领取任务奖励结果
 */
struct GetQuestRewardSMsg : public PlayerMsg
{
    enum { id = 0xA9A };

    uint16 questid;
    uint8 ret;
    
  GetQuestRewardSMsg()
        : PlayerMsg(id, sizeof(*this))
        , questid(0)
        , ret(0)
    {}
};

/**
 * 成就点数
 */
struct QuestPointSMsg : public PlayerMsg
{
    enum { id = 0xA9B };

    uint32 score;
    uint32 need;
    uint32 finish;
    
    QuestPointSMsg()
        : PlayerMsg(id, sizeof(*this))
        , score(0)
        , need(0)
        , finish(0)
    {}
};

/**
 * 领取成就奖励
 */
struct QuestPointRewardCSMsg : public PlayerMsg
{
    enum { id = 0xA9C };

    uint32 ret;
    QuestPointRewardCSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//SundryMsg 
