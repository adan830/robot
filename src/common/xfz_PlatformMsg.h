//////////////////   1. 共通定义 ///////////////////////
/**
 * \brief MsgBase 网络消息结构父类
 */
struct MsgBase
{
	enum { id = 0x0 };							//消息类型编号
	uint16 size;								//消息体字节数
	uint16 type;								//消息类型，被自动初始化为消息类型编号
	MsgBase(uint16 type_ = id, uint16 size_ = 0)
		: size(size_), type(type_)
	{
	}
};

/**
 * \brief PlayerMsg 玩家相关网络消息结构父类
 */
struct PlayerMsg : public MsgBase
{
	enum { id = 0x0 };
	uint32 target;								//玩家角色ID	
	PlayerMsg(uint16 type_ = id, uint16 size_ = 0)
		: MsgBase(type_, size_), target(0)
	{
	}
};

/**
 * Email附件信息
 */
struct MailAtachProperties
{
	uint32 money;									//金钱
	uint32 gold;									//金币
	uint32 item[MAX_MAIL_ITEMS_COUNT];				//道具
	uint32 itemCount[MAX_MAIL_ITEMS_COUNT];			//道具数量
	MailAtachProperties()
	{
		money = 0;
		gold = 0;
		for(uint8 i = 0; i < MAX_MAIL_ITEMS_COUNT; i++)
		{
			item[i] = 0;
			itemCount[i] = 0;
		}
	}
};


//////////////////   2. OperationServer 接口定义 ///////////////////////

/**
 * \brief 发布一个任务
 */
struct AddExeTaskCSMsg: public PlayerMsg
{
	enum{ id = 0x100 };
	
	uint8 op;										//操作类型 1启动 2停止 3更新 4更新Config.xml
	uint8 result;									//返回结果
	char platformName[PLATFORM_NAME_SIZE];			//平台简称以'\0'最大长度20
	char serverId[PLATFORM_NAME_SIZE];				//开服序号以'\0'最大长度20, 如's1', 's2'
	uint32 zoneId;									//大区ID
	uint32 exeTime;									//执行时间timestamp格式
	uint8 updateSql;								//更新sql 1表示更新update.sql 0不执行
	char version[PLATFORM_VERSION_SIZE];			//版本以'\0'最大长度10
	
	enum AddExeTaskResult
	{
		AET_Success = 0,						//成功
		AET_ServerIdNotExist = 1,					//服务器不存在
		
	};
	AddExeTaskCSMsg()
		: PlayerMsg(id, sizeof(*this))
		, op(0)
		, result(0)
		, zoneId(0)
		, exeTime(0)
		, updateSql(0)
	{
		platformName[0] = '\0';	
		serverId[0] = '\0';
		version[0] = '\0';
	}
};

/**
 * \brief 更新配置
 */
struct UpdateConfigCMsg: public PlayerMsg
{
	enum{ id = 0x101 };
	
	char platformName[PLATFORM_NAME_SIZE];			//平台简称以'\0'最大长度20
	char serverId[PLATFORM_NAME_SIZE];				//开服序号以'\0'最大长度20, 如's1', 's2'
	uint16 len;
	char data[0];
	UpdateConfigCMsg()
		: PlayerMsg(id, sizeof(*this))
		, len(0)
	{
	}

	uint16 getSize()
	{
		return sizeof(*this) + len;
	}
};

/**
 * \brief 更新配置回应
 */
struct UpdateConfigSMsg: public PlayerMsg
{
	enum{ id = 0x102 };
	
	uint8 ret;				//0,OK 非0 错误
	UpdateConfigSMsg()
		: PlayerMsg(id, sizeof(*this))
		, ret(0)
	{
	}

};

/**
 * \brief 获取配置
 */
struct GetConfigCMsg: public PlayerMsg
{
	enum{ id = 0x103 };
	
	char platformName[PLATFORM_NAME_SIZE];			//平台简称以'\0'最大长度20
	char serverId[PLATFORM_NAME_SIZE];				//开服序号以'\0'最大长度20, 如's1', 's2'
	GetConfigCMsg()
		: PlayerMsg(id, sizeof(*this))
	{
	}
};

struct GetConfigSMsg: public PlayerMsg
{
	enum{ id = 0x104 };
	
	char platformName[PLATFORM_NAME_SIZE];			//平台简称以'\0'最大长度20
	char serverId[PLATFORM_NAME_SIZE];				//开服序号以'\0'最大长度20, 如's1', 's2'
	uint16 len;
	char data[0];
	GetConfigSMsg()
		: PlayerMsg(id, sizeof(*this))
		, len(0)
	{
	}

	uint16 getSize()
	{
		return sizeof(*this) + len;
	}
};


//////////////////////// 3. 中心服接口定义  ////////////////////////////



/**
 * \brief 查询账号拥有的角色
 */
struct QueryRoleCMsg: public PlayerMsg
{
	enum{ id = 0x600 };

	char accountName[ACCOUNT_NAME_SIZE];		//账号
	
	QueryRoleCMsg()
		: PlayerMsg(id, sizeof(*this))
	{
		bzero(accountName, sizeof(accountName));
	}
};

/**
 * \brief 返回账号拥有的角色
 */
struct ResponseRoleSMsg: public PlayerMsg
{
	enum{ id = 0x601 };

	char accountName[ACCOUNT_NAME_SIZE];		//账号
	uint8 count;								//角色数目
	struct
	{
		uint64 playerGUID;						//角色GUID
		char playerName[PLAYER_NAME_SIZE];		//角色名
		uint8 sex;								//性别 1男 2女
		uint16 career;							//职业
		uint8 level;							//等级
		uint32 combatPower;						//战力
		uint32 createTime;						//创建时间戳
		uint32 state;							//bit1：是否封号 bit2:正常(请忽略) bit3:禁言 bit4~bit32:保留
	}data[];
	
	ResponseRoleSMsg()
		: PlayerMsg(id, sizeof(*this))
		, count(0)
	{
		bzero(accountName, sizeof(accountName));
	}

	uint16 getSize()
	{
		return sizeof(*this) + sizeof(data[0]) * count;
	}
};

/**
 * \brief 查询角色是否已经激活
 */
struct QueryRoleStateCMsg: public PlayerMsg
{
	enum{ id = 0x602 };

	char playerName[PLAYER_NAME_SIZE];			//角色名
	
	QueryRoleStateCMsg()
		: PlayerMsg(id, sizeof(*this))
	{
		bzero(playerName, sizeof(playerName));
	}
};

/**
 * \brief 返回角色是否已经激活
 */
struct ResponseRoleStateSMsg: public PlayerMsg
{
	enum{ id = 0x603 };

	char playerName[PLAYER_NAME_SIZE];			//角色名
	uint32 state;								//状态 0未激活 1已激活，但不能充值 2已激活，正常
	
	ResponseRoleStateSMsg()
		: PlayerMsg(id, sizeof(*this))
		, state(0)
	{
		bzero(playerName, sizeof(playerName));
	}
};

/**
 * \brief 给角色充值
 */
struct RechargeGoldCMsg: public PlayerMsg
{
	enum{ id = 0x604 };

	char playerName[PLAYER_NAME_SIZE];			//角色名
	//bool isBind;								//是否绑定
	uint32 gold;								//元宝数
	
	RechargeGoldCMsg()
		: PlayerMsg(id, sizeof(*this))
		//, isBind(true)
		, gold(0)
	{
		bzero(playerName, sizeof(playerName));
	}
};

/**
 * \brief 给角色充值响应
 */
struct RechargeGoldSMsg: public PlayerMsg
{
	enum{ id = 0x605 };

	char playerName[PLAYER_NAME_SIZE];			//角色名
	//bool isBind;								//是否绑定
	uint32 gold;								//元宝数
	uint8 retCode;								//0成功 1失败，角色不存在
	
	RechargeGoldSMsg()
		: PlayerMsg(id, sizeof(*this))
		//, isBind(true)
		, gold(0)
		, retCode(0)
	{
		bzero(playerName, sizeof(playerName));
	}
};

/**
 * \brief 给角色充值
 */
struct RechargeGoldMsg: public PlayerMsg
{
	enum{ id = 0x606 };

	union
	{
		uint32 playerTempId;					//角色临时ID
		playerid_t playerGuid;					//角色唯一ID
	};
	//bool isBind;								//是否绑定
	uint32 gold;								//元宝数
	uint8 retCode;								//0成功 1失败，角色不存在
	
	RechargeGoldMsg()
		: PlayerMsg(id, sizeof(*this))
		, playerGuid(0)
		//, isBind(true)
		, gold(0)
		, retCode(0)
	{
	}
};

/**
 * \brief 查询角色登录账户
 */
struct QueryAccountCMsg: public PlayerMsg
{
	enum{ id = 0x607 };

	char playerName[PLAYER_NAME_SIZE];		//角色名
	
	QueryAccountCMsg()
		: PlayerMsg(id, sizeof(*this))
	{
		bzero(playerName, sizeof(playerName));
	}
};

/**
 * \brief 返回角色登录账户
 */
struct ResponseAccountSMsg: public PlayerMsg
{
	enum{ id = 0x608 };

	uint64 playerGuid;
	char accountName[ACCOUNT_NAME_SIZE];		//账号
	
	ResponseAccountSMsg()
		: PlayerMsg(id, sizeof(*this))
		, playerGuid(0)
	{
		bzero(accountName, sizeof(accountName));
	}
};

/**
 * \brief 平台设置跨服战开启时间和状态
 */
struct PlatformSetInterZoneWarStateCSMsg: public PlayerMsg
{
	enum{ id = 0x609 };

	uint32 session;		//届数      0表示不对此项设置
	uint16 year;		//开始时间	0表示不对时间设置
	uint16 month;		//开始时间	0表示不对时间设置
	uint16 day;			//开始时间	0表示不对时间设置
	uint8 ret;			//返回值 0:正常2:时间参数非法				
	
	PlatformSetInterZoneWarStateCSMsg()
		: PlayerMsg(id, sizeof(*this))
		, session(0)
		, year(0)
		, month(0)
		, day(0)
		, ret(0)
	{

	}
};

/*
*	全服公告公告
*/
struct WorldNoticeCMsg : public PlayerMsg
{
	enum{ id = 0x622};
	
	char notice[1024];		//公告内容
	uint8 color;				//公告颜色0表示红色1表示绿色
	WorldNoticeCMsg()
		:PlayerMsg(id,sizeof(*this))
		,color(0)
	{
	}
};

/**
 * 系统发送邮件
 */
struct SendSystemMailCMsg: public PlayerMsg
{
	enum{ id = 0x623 };
	char subjectData[MAX_MAIL_SUBJECT_LEN];			//主题，0结尾的字符串 
	MailAtachProperties mailAttachProps;			//邮件附件属性	
	char bodyData[MAX_MAIL_BODY_LEN];				//body 0结尾的字符串 
	bool sendAllPlayer;								//是否发送给全服
	uint16 count;

	struct
	{
		playerid_t playerGuid;
	}data[];

	SendSystemMailCMsg()
		: PlayerMsg(id, sizeof(*this))
		, sendAllPlayer(false)
		, count(0)
	{
		
	}

	uint16 getSize()
	{
		return sizeof(*this)  + count*sizeof(data[0]);
	}
};

/** 
 * 中间件主动发送该消息请求服务器状态
 */
struct RequestServerStatusCMsg : public PlayerMsg
{
    enum { id = 0x624 };
    RequestServerStatusCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

/** 
 * 查询服务器状态,返回结果
 */
struct ServerStatusSMsg : public PlayerMsg
{
    enum { id = 0x625 };

    uint8 count;        // 连接中服务器的数量  
    struct sv {
        uint8 id;       // serverid
        uint8 type;     // 1 gateway 2 scene
        uint8 status;   // 0 正常连接  1 断线
    } servers[];
    
    ServerStatusSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}

	uint16 getSize()
	{
		return sizeof(*this) + sizeof(servers[0]) * count;
	}
};

/**
 * 修改玩家GM权限                                                                    
 */
struct ChangePlayerGMLevelCMsg : public PlayerMsg
{
	enum{ id = 0x626};
	char playerName[PLAYER_NAME_SIZE];			//玩家名字
	uint8 gmLevel;								//0 表示玩家 1表示普通GM 2表示超级GM
	ChangePlayerGMLevelCMsg()
		: PlayerMsg(id, sizeof(*this))
		, gmLevel(0)
	{}
};

/**
 * central 服务器回馈消息有关GM权限
 */
struct ChangeGMLevelACKSMsg: public PlayerMsg
{
	enum{ id = 0x627 };
	uint8 result;				//0 表示修改成功 1 不在线 2找不到相应玩家
	ChangeGMLevelACKSMsg()
		: PlayerMsg(id ,sizeof(*this))
		, result(0)
	{
	}
};

/**
 * 活动操作
 */
struct ActiveOpCMsg: public PlayerMsg
{
	enum{ id = 0x628 };
	enum EnumOp
	{
		EOPCreate = 1,			//发布
		EOPCancel = 2,			//取消
	};
	uint16 activeId;	//活动ID
	uint8 op;			//操作
	uint16 length;		//数据长度
	char data[];		//数据

	ActiveOpCMsg()
		: PlayerMsg(id ,sizeof(*this))
		, activeId(0)
		, op(0)
		, length(0)
	{
	}

	uint16 getSize()
	{
		return sizeof(*this) + length * sizeof(data[0]);
	}
};


/**
 * 活动操作返回
 */
struct ActiveOpSMsg: public PlayerMsg
{
	enum{ id = 0x629 };
	enum EnumResult
	{
		ER_Success = 0,			//成功
		ER_Failed = 1,			//错误
		ER_Duplicate = 2,		//重复活动Id
	};
	uint16 activeId;			//活动ID
	uint8 result;				//结果

	ActiveOpSMsg()
		: PlayerMsg(id ,sizeof(*this))
		, activeId(0)
		, result(0)
	{
		
	}
};

/*
*	修改玩家状态
*/
struct ChangePlayerStateCMsg:public PlayerMsg
{
	enum{ id = 0x630 };

	char Name[PLAYER_NAME_SIZE];	//玩家名字
	uint32 state;					//玩家状态 1表示有账号被封不能进游戏 2表示正常 3禁言 4取消禁言

	ChangePlayerStateCMsg()
		: PlayerMsg(id ,sizeof(*this))
		, state(2)
	{
		bzero(Name,PLAYER_NAME_SIZE);
	}
};

/*
*	修改玩家状态回馈
*/
struct ChangePlayerStateSMsg:public PlayerMsg
{
	enum{ id = 0x631 };

	uint8 result;					//修改结果 0表示成功 1表示玩家不存在

	ChangePlayerStateSMsg()
		: PlayerMsg(id ,sizeof(*this))
		, result(0)
	{
	}
};

/*
*	平台T玩家下线
*/
struct KickPlayerCMsg:public PlayerMsg
{
	enum{ id = 0x632 };

	char Name[PLAYER_NAME_SIZE];	//玩家名字

	KickPlayerCMsg()
		: PlayerMsg(id ,sizeof(*this))
	{
		bzero(Name,PLAYER_NAME_SIZE);
	}
};

/*
*	平台T玩家下线结果
*/
struct KickPlayerSMsg:public PlayerMsg
{
	enum{ id = 0x633 };

	uint8 result;			//结果 0表示踢人成功 1表示玩家不存在 2表示玩家不在线

	KickPlayerSMsg()
		: PlayerMsg(id ,sizeof(*this))
		, result(0)
	{
	}
};

/*
*	查看帮派信息
*/
struct ViewGuildInfoCMsg:public PlayerMsg
{
	enum{ id = 0x634 };

	char guildName[GUILD_NAME_SIZE];			//查看的帮派名字

	ViewGuildInfoCMsg()
		: PlayerMsg(id ,sizeof(*this))
	{
		bzero(guildName,GUILD_NAME_SIZE);
	}
};

/*
*	返回帮派信息
*/
struct ViewGuildInfoSMsg:public PlayerMsg
{
	enum{ id = 0x635 };

	uint32 guildId;									//帮会ID
	char guildName[GUILD_NAME_SIZE];				//帮会名称
	char guildLeaderName[GUILD_LEADER_NAME_SIZE];	//帮会帮主名称
	char guildNotice[GUILD_NOTICE_SIZE];			//帮会公告
	uint8 level;									//帮会等级
	uint32 rank;									//帮会排
	uint32 exp;										//帮会经验
	uint32 createTime;								//创建时间				
	uint32 money;									//帮会金钱
	uint16 count;									//成员数
	struct memberInfo
	{
		char memberName[PLAYER_NAME_SIZE];	//成员名字
		uint8 vipLevel;						//成员VIP等级
		uint8 level;						//成员等级
		uint8 guildRank;					//成员职位
		uint32 lastOnlineTime;				//离线时间
		uint32 todayContribution;			//成员当天贡献
		uint32 totalContribution;			//成员总共贡献
		uint32 arenaRank;					//成员仙岛排行
		uint16 jobId;						//职业ID
		uint8 sex;							//性别

	}data[];

	ViewGuildInfoSMsg()
		: PlayerMsg(id, sizeof(*this))
		, guildId(0)
		, level(0)
		, rank(0)
		, exp(0)
		, createTime(0)
		, money(0)
		, count(0)
	{
		bzero(guildName,GUILD_NAME_SIZE);
		bzero(guildLeaderName,GUILD_LEADER_NAME_SIZE);
		bzero(guildNotice,GUILD_NOTICE_SIZE);
	}

	uint16 getSize()
	{
		return sizeof(*this) + sizeof(data[0]) * count;
	}
};

/*
*	查看帮派信息
*/
struct ViewGuildResultSMsg:public PlayerMsg
{
	enum{ id = 0x636 };

	uint8 result;			//结果 1表示找不到帮派

	ViewGuildResultSMsg()
		: PlayerMsg(id ,sizeof(*this))
		, result(1)
	{
	}
};

/**
 * 设置限时商城信息
 */
struct SetTimeLimitShopCMsg : public PlayerMsg
{
    enum { id = 0x637 };

    uint16 shopid;       //商城ID
    uint32 starttime;    //起始时间
    uint32 endtime;      //结束时间
    uint8  imgid;        //背景图片ID
    uint8  color;        //颜色
    char   text[64];     //标题内容
    uint16 count;        //物品数量

    struct
    {
        uint16 itemid;   //物品ID
        uint16 count;    //库存数量
        uint16 pilecount;//堆叠数量
        uint16 price;     //原价
        uint16 discount; //折扣价
        char   text[32]; //商品简要描述
    } list[];

    SetTimeLimitShopCMsg()
        : PlayerMsg(id, sizeof(*this))
        , shopid(0)
        , starttime(0)
        , endtime(0)
        , imgid(0)
        , color(0)
        , count(0)
    {
        bzero(text, sizeof(text));
    }
    
    uint16 getSize()
    {
        return sizeof(*this) + sizeof(list[0]) * count;
    }
};

/**
 * 商城设置结果
 */
struct SetTimeLimitShopSMsg : public PlayerMsg
{
    enum { id = 0x638 };

    enum
    {
        TL_SUCCESS = 0, // 成功
        TL_FAILED  = 1, // 失败
        TL_REPEAT  = 2, // 重复
        TL_EXIST   = 3, // 已经存在，但不重复
    };

    uint16 shopid; // 商城ID
    uint8  ret;    // 操作结果
    SetTimeLimitShopSMsg()
        : PlayerMsg(id, sizeof(*this))
        , shopid(0)
        , ret(0)
    {}
};

/**
 * 设置商城状态
 */
struct SetTimeLimitShopStatusCSMsg : public PlayerMsg
{
    enum { id = 0x639 };

    enum
    {
        TL_START    = 0, // 商城在启动状态
        TL_END      = 1, // 商城已经是关闭状态
        TL_NOTEXIST = 2, // 商城被手动清空
    };

    uint16 shopid; // 商城ID
    uint8 status;  // 商城状态
    uint8 ret;     // 操作结果

    SetTimeLimitShopStatusCSMsg()
        : PlayerMsg(id, sizeof(*this))
        , shopid(0)
        , status(0)
        , ret(0)
    {}
};

/**
 * 设置玩家VIP信息
 */
struct PlayerPlatformInfoCMsg : public PlayerMsg
{
	 enum { id = 0x63A };

	 char accountName[ACCOUNT_NAME_SIZE];	//账号
	 uint8 platformVipType;					//平台会员类型 0表示普通会员 1表示月度会员 2表示季度会员 3表示年度会员
	 uint8 platformVipLevel;				//平台VIP等级
	 uint32 vipEndTime;						//Vip结束时间(s)

	 PlayerPlatformInfoCMsg()
		 : PlayerMsg(id, sizeof(*this))
		 , platformVipLevel(0)
		 , vipEndTime(0)
	 {
		bzero(accountName,sizeof(accountName));
	 }
};

/**
 * 设置玩家VIP信息结果
 */
struct PlayerPlatformInfoSMsg : public PlayerMsg
{
	enum { id = 0x63B };

	uint8 result;			//结果0表示成功 1表示失败
	PlayerPlatformInfoSMsg()
		: PlayerMsg(id, sizeof(*this))
		, result(0)
	{
	}
};


/**
 * 平台发布的基金消息
 */
struct CreateFundCMsg : public PlayerMsg
{
	enum { id = 0x63C };
	uint16 fundId;			//基金ID
	uint32 beginTime;		//基金开始时间
	uint32 endTime;			//基金结束时间
	char fundName[13];		//基金名称
	uint32 needGold;		//需要元宝
	uint32 picId1;			//背景图片1
	uint32 picId2;			//背景图片2
	uint32 totalGold;		//总元宝利润
	uint32 totalMoney;		//总铜钱利润
	uint8 count;			//返还总天数
	struct
	{
		uint8 day;			//第几天
		uint32 gold;		//奖励元宝数
		uint32 money;		//奖励铜钱数
	}data[0];

	CreateFundCMsg()
		: PlayerMsg(id, sizeof(*this))
		, fundId(0)
		, beginTime(0)
		, endTime(0)
		, needGold(0)
		, picId1(0)
		, picId2(0)
		, totalGold(0)
		, totalMoney(0)
		, count(0)
	{
		bzero(fundName,sizeof(fundName));
	}

	uint16 getSize()
	{
		return sizeof(*this) + sizeof(data[0]) * count;
	}
};

/**
 * 基金发布结果
 */
struct CreateFundSMsg : public PlayerMsg
{
	enum { id = 0x63D };

	uint8 result;			//结果0表示成功 1表示失败
	CreateFundSMsg()
		: PlayerMsg(id, sizeof(*this))
		, result(0)
	{
	}
};

/**
 * 基金删除
 */
struct DeleteFundCMsg : public PlayerMsg
{
	enum { id = 0x63E };

	uint16 fundId;			//删除的基金ID
	DeleteFundCMsg()
		: PlayerMsg(id, sizeof(*this))
		, fundId(0)
	{
	}
};

/**
 * 基金删除结果
 */
struct DeleteFundSMsg : public PlayerMsg
{
	enum { id = 0x63F };

	uint8 result;			//结果 1表示不成功
	DeleteFundSMsg()
		: PlayerMsg(id, sizeof(*this))
		, result(0)
	{
	}
};

/**
 * 开服信息查询：开服时间，服务器启动时间，服务器执行版本，大区号
 */
struct ServerZoneAndTimeCMsg : public PlayerMsg
{
    enum { id = 0x640 };

    ServerZoneAndTimeCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

struct ServerZoneAndTimeSMsg : public PlayerMsg
{
    enum { id = 0x641 };

    uint16 zoneId;
	uint32 openServerTime;				//开服时间
    uint32 initServerTime;				//服务器启动时间
    char   version[32];                   // 服务器执行版本

    ServerZoneAndTimeSMsg()
        : PlayerMsg(id, sizeof(*this))
        , zoneId(0)
        , openServerTime(0)
        , initServerTime(0)
    {
        bzero(version, sizeof(version));
    }
};

struct GetResourceCMsg : public PlayerMsg
{
	enum { id = 0x642 };
	char accountName[ACCOUNT_NAME_SIZE];		//账号

	GetResourceCMsg()
		: PlayerMsg(id, sizeof(*this))
	{
		bzero(accountName, sizeof(accountName));
	}

};

/**
 * 获取玩家资源（元宝，铜钱，阅历）
 */
struct GetResourceSMsg : public PlayerMsg
{
	enum { id = 0x643 };
	char accountName[ACCOUNT_NAME_SIZE];
	char playerName[PLAYER_NAME_SIZE];
	uint32 gold;
	uint32 bindGold;
	uint32 book;
	uint64 money;

	GetResourceSMsg()
		: PlayerMsg(id, sizeof(*this))
		, gold(0)
		, bindGold(0)
		, book(0)
		, money(0)
	{
		bzero(accountName, sizeof(accountName));
		bzero(playerName, sizeof(playerName));
	}
};

/**
 * 为玩家添加福利（元宝，VIP经验）
 */
struct AddResourceCMsg : public PlayerMsg
{
	enum { id = 0x644 };
	enum
	{
		R_BINDGOLD = 1,		//绑定元宝
		R_VIPEXP   = 2,		//vip经验
	};
	char playerName[PLAYER_NAME_SIZE];	//账号
	uint8 type;
	uint32 num;

	AddResourceCMsg()
		: PlayerMsg(id, sizeof(*this))
		, type(0)
	    , num(0)
	{
		bzero(playerName, sizeof(playerName));
	}

};


/**
 * \brief 给角色充值响应
 */
struct AddResourceSMsg: public PlayerMsg
{
	enum{ id = 0x645 };

	char playerName[PLAYER_NAME_SIZE];			//角色名
	uint8 type;									//资源类型
	uint32 num;									//数量
	uint8 retCode;								//0成功 1失败，角色不存在
	
	AddResourceSMsg()
		: PlayerMsg(id, sizeof(*this))
		, type(0)
		, num(0)
		, retCode(0)
	{
		bzero(playerName, sizeof(playerName));
	}
};

/**
 * \brief 给角色充值
 */
struct AddResourceMsg: public PlayerMsg
{
	enum{ id = 0x646 };

	union
	{
		uint32 playerTempId;					//角色临时ID
		playerid_t playerGuid;					//角色唯一ID
	};
	uint8 type;									//资源类型
	uint32 num;									//数量
	
	AddResourceMsg()
		: PlayerMsg(id, sizeof(*this))
		, playerGuid(0)
		, type(0)
		, num(0)
	{
	}
};

//跨服战报名人数统计
struct StatIZSignCountCSMsg : public PlayerMsg
{
	enum { id = 0x647 };

	uint32 session;		//跨服战届数
	uint16 count;		//返回该服跨服战报名人数

	StatIZSignCountCSMsg()
		: PlayerMsg(id, sizeof(*this))
		, session(0)
		, count(0)
	{

	}
};

