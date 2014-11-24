#ifndef __NXCORE_ROLEMSG__
#define __NXCORE_ROLEMSG__

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * \brief RequestRoleListCMsg 请求角色列表
 */
struct RequestRoleListCMsg : public PlayerMsg 
{
	enum{ id = 0x800 };
	RequestRoleListCMsg() : PlayerMsg(id, sizeof(*this)){}
};

/**
 * \brief ResponseRoleListSMsg 服务端返回角色列表
 */
struct ResponseRoleListSMsg : public PlayerMsg
{
	enum{ id = 0x801 };

	uint8 count;						//角色数量,为0表示没有角色，客户端进入创建角色界面
	struct RoleInfo
	{
		uint32 playerId;                //临时ID
        playerid_t CharId;              //角色ID
		char name[PLAYER_NAME_SIZE];	//角色名称
        uint32 card;                    //队长卡牌
	} data[0];

	ResponseRoleListSMsg()
		: PlayerMsg(id, sizeof(*this))
		, count(0)
	{}

	uint32 getSize()
	{
		return sizeof(*this) + count * sizeof(data[0]);
	}
};

/**
 * \brief CreateRoleCMsg 客户端请求创建角色 无需填写playerId
 */
struct CreateRoleCMsg : public PlayerMsg
{
	enum{ id = 0x802 };
	char playerName[PLAYER_NAME_SIZE];		//角色名称
	uint16 cardKey;							//卡牌ID
	CreateRoleCMsg()
		: PlayerMsg(id, sizeof(*this))
		, cardKey(0)
	{}
};

/**
 * \brief ChooseRoleCMsg 客户端选择角色 需填写选择的target = playerId
 */
struct ChooseRoleCMsg : public PlayerMsg
{
	enum{ id = 0x803 };
    playerid_t CharId;
	ChooseRoleCMsg()
		: PlayerMsg(id, sizeof(*this))
        , CharId(0)
	{}
};


/** 
* 心跳                                    
*/
struct HeartBeatCMsg : public PlayerMsg
{                                          
	enum{ id = 0x804 };
	HeartBeatCMsg()
		: PlayerMsg(id ,sizeof(*this))
	{
	}
};

/** 
  * 进入场景
  */
struct EnterSceneSMsg: public PlayerMsg
{                                          
	enum{ id = 0x805 };

    uint32 time;

	EnterSceneSMsg()
		: PlayerMsg(id ,sizeof(*this))
        , time(0)
	{}
};

/**
 * \brief PlayerProp64ChangeSMsg 角色64位的属性改变level(0)
 */
struct PlayerPropChangeSMsg: public PlayerMsg
{
	enum{ id = 0x806 };

    uint8 count;

    struct Props {
        uint8 propId;				//属性索引，见enum PropIndex
        uint8 reason;				//属性改变原因
        uint8 oper;                 //1 增加 2 减少
        uint32 propValue;			//属性值
	} lists[0];
    
	PlayerPropChangeSMsg()
		: PlayerMsg(id, sizeof(*this))
	{}

    uint32 getSize()
    {
        return sizeof(*this) + count * sizeof(lists[0]);
    }
};

/**
 * \brief PlayerPropsCMsg 玩家属性
*/
struct PlayerBasePropsCMsg : public PlayerMsg
{
	enum{ id = 0x807 };

	PlayerBasePropsCMsg()
	: PlayerMsg(id, sizeof(*this))
	{}
};

/**
 * \brief PlayerBasePropsSMsg 玩家属性
*/

struct PlayerBasePropsSMsg : public PlayerMsg
{
	enum{ id = 0x808 };

    playerid_t playerGuid;
	char charName[PLAYER_NAME_SIZE]; //角色名
	uint32 money;					 //铜钱
	uint32 gold;                     //元宝
    uint32 arenapoint;               // 勋章
    uint32 renown;                   // 声望
    uint32 soulstone;                // 灵石
    uint32 soulrefined;              // 精魄
    uint32 horsesoul;                // 马魂
    uint32 scroll;                   // 残卷
    uint32 recharged;                //充值总元宝
	uint8 level;					 //等级
    uint8 viplevel;                  //VIP等级
	uint32 exp;						 //经验
	uint8 sp;						 //体力
    uint8 pvpsp;                     //耐力
    uint16 leadLimit;                //领导力限制
    uint16 bagCardSize;              //卡牌背包大小
    uint16 bagEquipSize;             //装备背包大小

    uint32 BuySpCount;
    uint32 BuyPvpSpCount;
    uint32 NormalDunResetCount;
    uint32 EliteDunResetCount;
    uint32 ExpDunBuyCount;
    uint32 MoneyDunBuyCount;
    
    uint32 virgin;
    uint16 guide;                                  // 新手引导

    PlayerBasePropsSMsg()
        : PlayerMsg(id, sizeof(*this))
        , playerGuid(0)
        , money(0)
        , gold(0)
        , arenapoint(0)
        , renown(0)
        , soulstone(0)
        , soulrefined(0)
        , horsesoul(0)
        , scroll(0)
        , recharged(0)
        , level(1)
        , viplevel(0)
        , exp(0)
        , sp(0)
        , pvpsp(0)
        , leadLimit(0)
        , bagCardSize(0)
        , bagEquipSize(0)
        , virgin(0)
        , guide(0)
	{
        bzero(charName, sizeof(charName));
	}
};

/** 
 * 每日抽奖操作
 */
struct DailyGachaCSMsg : public PlayerMsg
{                                          
	enum{ id = 0x820 };
	
	enum EnumOp
	{
		EO_RequestData	= 0,			//请求数据
		EO_Gacha		= 1,			//抽奖
	};

	enum EnumResult
	{
		ER_Succcess		= 0,		
		ER_Failed		= 1,
		ER_GachaOverLimit = 2,			//抽奖超过次数限制
	};
	uint8 op;							//操作码
	uint8 result;						//结果
	uint16 param;						//参数 EO_Gacha:返回当天已经抽奖次数
	DailyGachaCSMsg()
		: PlayerMsg(id ,sizeof(*this))
		, op(0)
		, result(0)
		, param(0)
	{
	}
};

/** 
 * 玩家队伍消息
 */
struct PlayerTeamSMsg: public PlayerMsg
{                                          
	enum{ id = 0x821 };
    enum {
        TEAM_FIGHT = 1,
        TEAM_ALL   = 2,
        TEAM_NEW   = 3,
    };
    uint8 teamtype;             // 1 出战武将  2 全部武将 3 新增武将
    uint32 count;
	struct CardInfo
	{
		uint16 slot;			//卡牌在背包中的位置 1号位置是队长槽位
		uint16 cardKey;			//卡牌ID
		uint8 level;			//卡牌等级
		uint32 exp;				//卡牌经验
        uint32 costexp;         //累计经验
		uint8 pos;				//出阵默认位置0 为替补位置
        uint8 rank;             //卡牌品阶
	}data[0];
	PlayerTeamSMsg()
		: PlayerMsg(id ,sizeof(*this))
		, count(0)
	{
	}

	uint32 getSize()
	{
		return sizeof(*this) +  sizeof(data[0]) * count;
	}
};

/** 
* 玩家队伍消息阵法位置改变
*/
struct TeamPosChangeCMsg: public PlayerMsg
{                                          
	enum{ id = 0x822 };
	uint16 pos[MAX_FIGHT_POS_COUNT];//里面的值用卡牌槽位slot值
	
	TeamPosChangeCMsg()
		: PlayerMsg(id ,sizeof(*this))
	{}
};

/** 
* 玩家队伍消息阵法位置改变回应
*/
struct TeamPosChangeSMsg: public PlayerMsg
{                                          
	enum{ id = 0x823 };
	
	TeamPosChangeSMsg()
		: PlayerMsg(id ,sizeof(*this))
	{
	}

};

/**
 * 同步玩家体力
 */
struct PlayerSpSyncSMsg : public PlayerMsg
{
    enum { id = 0x824 };

    uint8 sp;
    uint8 pvpsp;
    uint32 sptime;
    uint32 pvpsptime;
    
    PlayerSpSyncSMsg()
        : PlayerMsg(id, sizeof(*this))
        , sp(0)
        , pvpsp(0)
        , sptime(0)
        , pvpsptime(0)
    {}
};


/**
 * 设置引导进度
 */
struct GuideCMsg : public PlayerMsg
{
    enum { id = 0x825 };

    uint16 progress;
    
    GuideCMsg()
        : PlayerMsg(id, sizeof(*this))
        , progress(0)
    {}
};

/** 
* Gm消息
*/
struct PlayerGMCMsg: public PlayerMsg
{                                       
	enum{ id = 0x828 };
	
	char gm[255];
	PlayerGMCMsg()
		: PlayerMsg(id ,sizeof(*this))
		{
            bzero(gm, sizeof(gm));
		}
};

/**
 * 售卖物品
 */
struct SellItemCMsg : public PlayerMsg
{
    enum { id = 0x829 };

    uint8 itemtype;
    uint32 count;
    uint16 slots[];
    
    SellItemCMsg()
        : PlayerMsg(id, sizeof(*this))
        , itemtype(0)
        , count(0)
    {}

    uint32 getSize()
    {
        return sizeof(*this) + count * sizeof(slots[0]);
    }
};

/**
 * 售卖结果
 */
struct SellItemSMsg : public PlayerMsg
{
    enum { id = 0x82A };

    uint8 ret;

    SellItemSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

/**
 * 合成物品（卡牌，装备）
 */
struct ProduceItemCMsg : public PlayerMsg
{
    enum { id = 0x82B };

    uint8 itemtype; // 物品类型
    uint16 slot;    // 槽位
    ProduceItemCMsg()
        : PlayerMsg(id, sizeof(*this))
        , itemtype(0)
        , slot(0)
    {}
};

/**
 * 剧情进度设定
 */
struct PlotCMsg : public PlayerMsg
{
    enum { id = 0x82C };

    uint32 plot;
    PlotCMsg()
        : PlayerMsg(id, sizeof(*this))
        , plot(0)
    {}
};

/**
 * 剧情进度设定结果
 */
struct PlotSMsg : public PlayerMsg
{
    enum { id = 0x82D };

    uint8 ret;
    PlotSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

/**
 * 各类场景属性
 */
struct ScenePropSMsg : public PlayerMsg
{
    enum { id = 0x82E };

    SceneProps sceneProps;
    
    ScenePropSMsg()
        : PlayerMsg(id, sizeof(*this))
    {
    }
};

/**
 * 玩家获得物品
 */
struct TradeInSMsg : public PlayerMsg
{
    enum { id = 0x82F };

    uint32     reschgtype;
    uint32     count;
    ItemReward list[0];
    
    TradeInSMsg()
        : PlayerMsg(id, sizeof(*this))
    {}

    uint32 getSize()
    {
        return sizeof(*this) + sizeof(list[0]) * count;
    }
};

/**
* \brief 登录公告
*/
struct GameNoticeCMsg: public PlayerMsg
{
	enum{ id = 0x830 };

    GameNoticeCMsg() 
		: PlayerMsg(id, sizeof(*this))
	{}
};

/**
* \brief 登录公告
*/
struct GameNoticeSMsg: public PlayerMsg
{
	enum{ id = 0x831 };

    uint16 len;
    
    struct {
        uint16 titlelen;
        char title[0];

        uint16 textlen;
        char text[0];
    } notice[0];
    
    GameNoticeSMsg() 
		: PlayerMsg(id, sizeof(*this))
        , len(0)
	{}

    uint32 getSize()
    {
        return sizeof(*this) + len;
    }
};

/**
 * 选择初始卡牌
 */
struct ChoosePlayerRoleCardCMsg : public PlayerMsg
{
    enum { id = 0x832 };

    uint32 card;

    ChoosePlayerRoleCardCMsg()
        : PlayerMsg(id, sizeof(*this))
        , card(0)
    {}
};


struct ChoosePlayerRoleCardSMsg : public PlayerMsg
{
    enum { id = 0x833 };

    uint32 ret;

    ChoosePlayerRoleCardSMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_ARENAMSG__
