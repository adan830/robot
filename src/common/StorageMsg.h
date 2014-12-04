#ifndef __NXCORE_STORAGE_MSG__
#define __NXCORE_STORAGE_MSG__

#include <BaseMsg.h>
#include <DBEntity.h>

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * \brief 创建角色数据
 */
struct CreatePlayerDataMsg: public MsgBase
{
	enum{ id = 0x40 };

	playerid_t playerGuid;							//角色唯一ID
	uint32 playerId;								//角色临时ID
	char playerName[PLAYER_NAME_SIZE];				//角色名
	playerid_t accountUid;							//账号Uid
	uint32 cardKey;									//默认卡牌ID
	uint32 createTime;								//创建时间

	CreatePlayerDataMsg()
		: MsgBase(id, sizeof(*this))
		, playerGuid(0)
		, playerId(0)
		, accountUid(0)
		, cardKey(0)
		, createTime(0)
	{
		playerName[0] = '\0';
	}
};

/**
 * \brief 读取角色数据
 */
struct ReadPlayerDataMsg: public MsgBase
{
	enum{ id = 0x41 };

	playerid_t CharId;   							//角色唯一ID
	uint32 playerId;								//角色临时Id

	ReadPlayerDataMsg() 
	: MsgBase(id, sizeof(*this))
	, CharId(0)
	, playerId(0)
	{
	}
};


/**
 * \brief 读取角色数据返回
 */
struct ResponsePlayerDataMsg: public MsgBase 
{
	enum{ id = 0x42 };

	uint64 CharId;								//角色临时Id
	uint16 length;									//数据字节数
	char data[];

    ResponsePlayerDataMsg() : MsgBase(id, sizeof(*this)), CharId(0), length(0)
	{
	}

	uint16 getSize()
	{
		return sizeof(*this) + length;
	}

};



/**
 * \brief 保存角色数据
 */
struct SavePlayerDataMsg: public MsgBase
{
	enum{ id = 0x43 };

	playerid_t playerGuid;							//角色唯一ID
	PlayerBaseProperties baseProps;

	SavePlayerDataMsg() : MsgBase(id, sizeof(*this)), playerGuid(0)
	{
	}
};

/**
 * \brief 保存角色卡牌数据
 */
struct SavePlayerCardMsg: public MsgBase
{
	enum{ id = 0x46 };

	playerid_t playerGuid;							//角色唯一ID
	CardProps cardProps;							//卡牌属性

	SavePlayerCardMsg() 
		: MsgBase(id, sizeof(*this))
		, playerGuid(0)
	{
	}
};

/**
 * \brief 删除某张角色卡牌
 */
struct DelPlayerCardMsg: public MsgBase
{
	enum{ id = 0x47 };

	playerid_t playerGuid;							//角色唯一ID
    CardProps cardProps;							//卡牌属性

	DelPlayerCardMsg() 
		: MsgBase(id, sizeof(*this))
		, playerGuid(0)
	{
	}
};

/**
 * \brief 保存背包数据
 */
struct SavePlayerPackageMsg : public MsgBase
{
    enum { id = 0x48 };

    playerid_t playerGuid;
    uint16     bagType;
    uint16     count;
    
    struct PackageItems
    {
        uint16 slot;
        Item item;
    } list[];

    SavePlayerPackageMsg()
        : MsgBase(id, sizeof(*this))
        , playerGuid(0)
        , bagType(0)
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + sizeof(list[0]) * count;
    }
};

/**
 * 保存、读取副本进度
 */
struct SceneScoresMsg : public MsgBase
{
    enum { id = 0x49 };

    playerid_t playerGuid;
    uint16 count;

    struct SceneScores
    {
        uint16 sceneid;
        uint8  score;
    } list[];

    SceneScoresMsg()
        : MsgBase(id, sizeof(*this))
        , playerGuid(0)
        , count(0)
    {}
    
    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

/**
 * 保存帐号登录、退出信息
 */
struct InfoLoginZoneMsg : public MsgBase
{
    enum { id = 0x4A };

    playerid_t Uid;
    uint16 Zoneid;
    uint16 Rolenum;
    uint32 LastLoginTime;
    uint32 LastLogoutTime;

    InfoLoginZoneMsg()
        : MsgBase(id, sizeof(*this))
        , Uid(0)
        , Zoneid(0)
        , Rolenum(0)
        , LastLoginTime(0)
        , LastLogoutTime(0)
    {}
};

/**
 * 保存场景属性
 */
struct SaveScenePropsMsg : public MsgBase
{
    enum { id = 0x4B };

    playerid_t CharId;
    SceneProps sceneProps;

    SaveScenePropsMsg()
        : MsgBase(id, sizeof(*this))
        , CharId(0)
    {}
};

/**
 * 
 */
struct SaveLotteryPropMsg :public MsgBase
{
    enum { id = 0x4C };

    playerid_t CharId;
    LotteryProps lp;

    SaveLotteryPropMsg()
        : MsgBase(id, sizeof(*this))
        , CharId(0)
    {}
};

struct SaveDungeonProgressMsg : public MsgBase
{
    enum { id = 0x4D };

    playerid_t CharId;
    DungeonProgress dp;

    SaveDungeonProgressMsg()
        : MsgBase(id, sizeof(*this))
    {}
};

struct SaveSlotEquipMsg : public MsgBase
{
    enum { id = 0x4E };

    playerid_t CharId;
    SlotEquip se;

    SaveSlotEquipMsg()
        : MsgBase(id, sizeof(*this))
        , CharId(0)
    {}
};

struct SaveShopItemMsg : public MsgBase
{
    enum { id = 0x4F };
    playerid_t CharId;

    uint32 shoptype;
    uint32 count;
    ShopItem items[0];

    SaveShopItemMsg()
        : MsgBase(id, sizeof(*this))
        , CharId(0)
        , shoptype(0)
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + sizeof(items[0]) * count;
    }
};

struct SaveSceneRewardMsg : public MsgBase
{
    enum { id = 0x50 };
    playerid_t CharId;
    uint16 BigLv;
    uint16 Reward;

    SaveSceneRewardMsg()
        : MsgBase(id, sizeof(*this))
        , CharId(0)
        , BigLv(0)
        , Reward(0)
    {}
};

/**
* \brief 读取角色中心数据
*/

struct ReadPlayerData2Msg: public MsgBase
{
	enum{ id = 0x51 };

	playerid_t playerGuid;							//角色唯一ID
	uint32 playerId;                                //角色临时Id

	ReadPlayerData2Msg() : MsgBase(id, sizeof(*this)), playerGuid(0), playerId(0)
	{
	}
};

/**
   * \brief 读取角色数据2返回
    */
struct ReadPlayerResponseData2Msg: public MsgBase 
{
	enum{ id = 0x52 };

	uint32 playerId;                                //角色临时Id
	uint16 length;									//数据字节数
	char data[];

	ReadPlayerResponseData2Msg() : MsgBase(id, sizeof(*this)), playerId(0), length(0)
	{
	}

	uint32 getSize()
	{
		return sizeof(*this) + length;
	}
};

/**
* \brief保存竞技数据
 */
struct SaveArenaDataMsg: public MsgBase 
{
	enum{ id = 0x53 };
	
	playerid_t CharId;							//唯一ID
    ArenaProps arenaProps;

	SaveArenaDataMsg() 
		: MsgBase(id, sizeof(*this))
        , CharId(0)
	{}
};

struct SaveQuestStatusMsg : public MsgBase
{
    enum { id = 0x54 };

    playerid_t CharId;
    uint16 count;
    struct {
        uint16 QuestId;
        uint16 State;
        uint32 Value;
        uint32 Time;
    } list[0];

    SaveQuestStatusMsg()
        : MsgBase(id, sizeof(*this))
        , CharId(0)
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

/**
* \brief保存中心服玩家基础数据2
 */
struct SaveCentralPlayerBaseDataMsg: public MsgBase 
{
	enum{ id = 0x55 };

	playerid_t playerGuid;
	PlayerCenteralBaseProps centralBaseProps;

	SaveCentralPlayerBaseDataMsg()
		: MsgBase(id, sizeof(*this))
		, playerGuid(0)
	{

	}
};

/**
 * \brief Daily Update
 */
struct DailyUpdateMsg: public MsgBase 
{
	enum{ id = 0x56 };

	uint8 hour;

	DailyUpdateMsg()
		: MsgBase(id, sizeof(*this))
		, hour(0)
	{

	}
};

/**
 * \brief 同步副本状态
 */
struct SaveSceneState : public MsgBase
{
    enum { id = 0x57 };

    playerid_t CharId;
    uint16 dungeonId;
    DungeonState ds;

    SaveSceneState()
        : MsgBase(id, sizeof(*this))
        , CharId(0)
        , dungeonId(0)
    {}
};

/**
* \brief保存好友数据
 */
struct SaveFriendDataMsg: public MsgBase 
{
	enum{ id = 0x58 };
	
	playerid_t playerGuid;							//唯一ID
	uint16 length;									//数据字节数
	char data[0];

	SaveFriendDataMsg() 
		: MsgBase(id, sizeof(*this))
		, playerGuid(0)
		, length(0)				   
	{
	}

	uint32 getSize()
	{
		return sizeof(*this) + sizeof(data[0]) * length;
	}
};

/**
 * 保存VIP数据
 */
struct SaveVipPropsMsg : MsgBase
{
    enum { id = 0x59 };

    playerid_t CharId;
    VipProps vp;
    
    SaveVipPropsMsg()
        : MsgBase(id, sizeof(*this))
        , CharId(0)
    {}
};

/**
 * 保存签到数据
 */
struct SaveDaySignPropsMsg : MsgBase
{
    enum { id = 0x5A };

    playerid_t CharId;
    DaySignProps dsp;

    SaveDaySignPropsMsg()
        : MsgBase(id, sizeof(*this))
        , CharId(0)
    {}
};

struct SaveBabelPropsMsg : MsgBase
{
    enum { id = 0x5B };

    playerid_t CharId;
    BabelProps bp;

    SaveBabelPropsMsg()
        : MsgBase(id, sizeof(*this))
        , CharId(0)
    {}
};

struct SendHisRankMsg : MsgBase
{
    enum { id = 0x5C };

    uint32 count;
    
    struct Rank {
        uint32 Rank;
        uint32 RankType;
        uint64 CharId;
    } data[0];

    SendHisRankMsg()
        : MsgBase(id, sizeof(*this))
        , count(0)
    {}

    uint32 getSize()
    {
        return sizeof(data[0]) * count + sizeof(*this);
    }
};

struct SingialMsg : MsgBase
{
    enum { id = 0x5D };

    uint32 value;

    SingialMsg()
        : MsgBase(id, sizeof(*this))
        , value(0)
    {}
};

struct NormalShopMsg : MsgBase
{
    enum { id = 0x5D };

    playerid_t CharId;

    uint32 ItemParam;
    uint32 ItemCount;

    NormalShopMsg()
        : MsgBase(id, sizeof(*this))
        , CharId(0)
        , ItemParam(0)
        , ItemCount(0)
    {}
};

/**
 * \brief 保存狩猎数据
 */
struct SaveHuntingDataMsg: public MsgBase
{
    enum { id = 0x60 };

    playerid_t playerGuid;
	uint8 stayPos;				//当前停留位置
	uint8 remainTimes;			//剩余投掷次数
	uint8 buyTimes;				//已经购买次数
	uint32 restoreTime;			//恢复投掷次数时间

	struct HuntingMission
	{
		uint8 missionType;		//任务类型
		uint8 require;			//任务需求次数
		uint8 value;			//达成次数
		bool rewarded;			//是否已经领奖

		HuntingMission()
			: missionType(0)
			, require(0)
			, value(0)
			, rewarded(false)
		{

		}
	}missions[3];

    SaveHuntingDataMsg()
        : MsgBase(id, sizeof(*this))
        , playerGuid(0)
		, stayPos(0)
		, remainTimes(0)
		, buyTimes(0)
		, restoreTime(0)
    {
		
	}
};

/**
 * \brief 保存点神兵数据
 */
struct SaveDrawCardDataMsg: public PlayerMsg
{
    enum { id = 0x61};

    playerid_t playerGuid;
	uint8 remainDrawTimes;			//剩余刷新次数
	struct
	{
		uint16 prob;				//概率
		uint16 itemType;			//类型
		uint16 itemId;				//道具ID 
		uint16 itemCount;			//道具数量
		uint8 itemPos;
		bool gained;				//是否已经获取
	}data[6];
    
    SaveDrawCardDataMsg()
        : PlayerMsg(id, sizeof(*this))
        , playerGuid(0)
		, remainDrawTimes(0)
    {
		bzero(data, sizeof(data));
	}
};
#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_LOGINMSG__

