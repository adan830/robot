/**
 * \filename   BattleMsg.h		v1.0
 * \brief      
 *             
 * \author     
 * \created    12/12/2013 02:52:44 PM
 */

#ifndef __NXCORE_BATTLEMSG__
#define __NXCORE_BATTLEMSG__

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

/** 
* 副本战斗请求
*/
struct DungeonFightCMsg: public PlayerMsg
{                                          
    enum{ id = 0xA00 };
    
    uint32 dungeon;  //副本ID
    uint8 hard;      // 1 简单，2 普通，3 困难
    uint8 mode;      // 1 战一次 2 战 10 次
    DungeonFightCMsg()
        : PlayerMsg(id ,sizeof(*this))
        , dungeon(0)
        , hard(0)
        , mode(0)
    {}
};


/** 
* 副本战斗回应
*/
struct DungeonFightSMsg: public PlayerMsg
{                                          
	enum{ id = 0xA01 };
	
	uint32 dungeon;				//副本ID
    uint32 ret;
    
	DungeonFightSMsg()
		: PlayerMsg(id ,sizeof(*this))
		, dungeon(0)
        , ret(0)
	{
	}

};

/** 
* 战斗数据
*/
struct PlayerBattleSMsg: public PlayerMsg
{                                          
	enum{ id = 0xA02 };
	uint16 dataLen;
	char data[0];
	PlayerBattleSMsg()
		: PlayerMsg(id ,sizeof(*this))
	{
	}
	
	uint32 getSize()
	{
		return sizeof(*this) + dataLen;
	}
};

/** 
* 奖励消息
*/
struct PlayerAwardCMsg: public PlayerMsg
{                                       
	enum{ id = 0xA03 };
	
	uint8 rewardType;               //战斗奖励类型
	PlayerAwardCMsg()
		: PlayerMsg(id ,sizeof(*this))
		, rewardType(0)
		{
		}
};

/** 
* 奖励消息
*/
struct PlayerAwardSMsg: public PlayerMsg
{                                          
	enum{ id = 0xA04 };
	
	
	uint8 rewardType;				//战斗奖励类型
	uint8 score;                    //战斗或者副本评分, 1 ~ 3 分胜利， 0分失败 (也可以用来表示其他参数）
	
	uint8 count;					//获得道具条数
	struct ItemData
	{
		uint8  lootType;			//掉落组
		uint16 baseId;              //获得道具的itembaseid
		uint32 num;					//数量
		uint8 level;				//等级
	}itemData[0];

	PlayerAwardSMsg()
		: PlayerMsg(id ,sizeof(*this))
	{
	}

	uint32 getSize()
	{
		return sizeof(*this) + sizeof(itemData[0]) * count;
	}
};

struct PlayerPKCMsg : public PlayerMsg
{
    enum { id = 0xA05 };

    uint32 enermy;
    
    PlayerPKCMsg()
        : PlayerMsg(id, sizeof(*this))
        , enermy(0)
    {}
};
#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_BATTLEMSG__

