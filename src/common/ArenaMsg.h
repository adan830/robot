/**
 * \filename   ArenaMsg.h		v1.0
 * \brief      
 *             
 * \author     
 * \created    05/09/2014 04:35:15 PM
 */
#ifndef __NXCORE_ARENAMSG__
#define __NXCORE_ARENAMSG__

#include "MsgDefine.h"
#include "PlayerMsg.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * \brief 竞技操作
 */
struct ArenaOpCSMsg: public PlayerMsg
{
	enum{ id = 0x960};

	uint32 op;     //操作
    uint64 param;  //变量
	uint32 ret;    //结果

	ArenaOpCSMsg()
		: PlayerMsg(id, sizeof(*this))
		, op(0)
        , param(0)
		, ret(0)
	{}
};

/**
 * \brief 竞技数据
 */
struct ArenaDataSMsg: public PlayerMsg
{
	enum{ id = 0x961};

	uint32 score;
	uint32 lifeused;
	uint32 lifecount;
	uint32 rank;
	uint32 prevrank;
    uint32 reward;
    uint32 lasttime;
	ArenaDataSMsg()
		: PlayerMsg(id, sizeof(*this))
		, score(0)
		, lifeused(0)
		, lifecount(0)
        , rank(0)
        , prevrank(0)
        , reward(0)
        , lasttime(0)
	{}
};

/**
 * \brief 竞技对手数据
 */
struct ArenaRivalSMsg: public PlayerMsg
{
	enum{ id = 0x962};

	uint8 count;				//对手个数
	struct DataInfo
	{
		playerid_t CharId;		//对手ID
		char playerName[PLAYER_NAME_SIZE];	//对手名称
		uint8 level;			//等级
		uint32 cardId;			//队长卡牌ID
		uint8 cardLevel;		//队长卡牌Level
		uint32 power;			//战力
		uint32 score;			//积分
		uint32 rank;			//排名
	}data[0];

	ArenaRivalSMsg()
		: PlayerMsg(id, sizeof(*this))
		, count(0)
	{
	}
	uint32 getSize()
	{
		return sizeof(*this) + sizeof(data[0])*count;
	}
};

/**
 * \brief 排行榜数据
 */
struct ArenaRankSMsg: public PlayerMsg
{
	enum{ id = 0x963};
    uint32 ranktype;                   //排行榜类型
	uint32 count;                      //个数
	struct Rank
	{
		playerid_t CharId;             //对手ID
		char   name[PLAYER_NAME_SIZE]; //对手名称
		uint32 level;                  //等级
		uint32 cardId;                 //队长卡牌ID
		uint32 cardLevel;              //队长卡牌Level 
		uint32 power;                  //战力
		uint32 score;                  //积分
		uint32 rank;                   //排名
	}list[0];

	ArenaRankSMsg()
		: PlayerMsg(id, sizeof(*this))
        , ranktype(0)
		, count(0)
	{}

    uint32 getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

struct ArenaPkCMsg : public PlayerMsg
{
    enum { id = 0x964 };

    ArenaPkCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

/**
 * 竞技场奖励
 */
struct ArenaRewardSMsg : public PlayerMsg
{
    enum { id = 0x965 };

    uint32     reschgtype;
    uint32     count;
    ItemReward list[0];
    
    ArenaRewardSMsg()
        : PlayerMsg(id, sizeof(*this))
    {}

    uint32 getSize()
    {
        return sizeof(*this) + sizeof(list[0]) * count;
    }
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_ARENAMSG__
