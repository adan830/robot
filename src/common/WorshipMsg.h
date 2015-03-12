#ifndef __WORSHIP_MSG__
#define __WORSHIP_MSG__

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

struct WorshipOpCMsg : public PlayerMsg
{
    enum { id = 0xAE0 };

    int op;           // 0 请求信息  1 膜拜  2 领奖 3 请求三个人
    int param;        // 1 第一个  2 第二个 3 第三个 
    
    WorshipOpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
    {}
};

struct WorshipSMsg : public PlayerMsg
{
    enum { id = 0xAE1 };

    WorshipProps mProps;
    
    WorshipSMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

struct WorshipTopSMsg : public PlayerMsg
{
    enum { id = 0xAE2 };

    char name1[TINYSTR];
    char name2[TINYSTR];
    char name3[TINYSTR];

    int scores[3];
    
    WorshipTopSMsg()
        : PlayerMsg(id, sizeof(*this))
    {
        bzero(name1 ,sizeof(name1));
        bzero(name2 ,sizeof(name1));
        bzero(name3 ,sizeof(name1));
    }
};

/**
 * 通天塔排名信息
 */
struct WorshipScoreRankSMsg : public PlayerMsg
{
    enum { id = 0xAE3 };

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
    
    WorshipScoreRankSMsg()
        : PlayerMsg(id, sizeof(*this))
        , currrank(0)
        , count(0)
    {}

    uint32 getSize()
    {
        return sizeof(*this) + sizeof(list[0]) * count;
    }
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_BATTLEMSG__

