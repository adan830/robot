#ifndef __NXCORE_ACCOUNTMSG__
#define __NXCORE_ACCOUNTMSG__

#include <BaseMsg.h>
#include <DBEntity.h>


CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * \brief ApplyAccountCMsg 申请账号
 */
struct AccountCMsg: public MsgBase
{
	enum{ id = 0x10 };

    uint32 param;
    AccountInfo account;
    
	AccountCMsg()
        : MsgBase(id, sizeof(*this))
        , param(0)
	{}
};

/**
 * \brief ApplyAccountCMsg 申请账号
 */
struct ApplyAccountCMsg: public MsgBase
{
	enum{ id = 0x10 };

    AccountInfo account;
    
	ApplyAccountCMsg() : MsgBase(id, sizeof(*this))
	{}
};

/**
 * \brief ApplyAccountSMsg 申请账号返回
 */
struct ApplyAccountSMsg: public MsgBase
{
	enum{ id = 0x11 };
	uint64 accuid;
	char accountName[ACCOUNT_NAME_SIZE];
	ApplyAccountSMsg()
        : MsgBase(id, sizeof(*this))
        , accuid(0)
	{
		accountName[0] = '\0';
	}
};

/**
 * \brief AccountLoginMsg 账号登陆消息
 */
struct AccountLoginCMsg: public MsgBase
{
	enum{ id = 0x13 };

    accuid_t  accuid;
	char accountName[ACCOUNT_NAME_SIZE];
	char password[PASSWORD_SIZE];
	uint8 fm;							// 0 未填写实名信息 1填写了实名信息且已经成年 2填写了实名但未成年
	uint16 zoneId;						//大区ID
	AccountLoginCMsg()
        : MsgBase(id, sizeof(*this))
        , accuid(0)
        , fm(0)
        , zoneId(0)
	{
		bzero(accountName, sizeof(accountName));
		bzero(password, sizeof(password));
	}
};

/**
 * \brief PlatformAccountLoginMsg 平台账号登陆消息
 */

struct SessionIDLoginCMsg: public MsgBase
{
	enum{ id = 0x14 };

	accuid_t accuid;					//账号Uid
	uint32 time;							//当前时间戳
	char sign[PLAYER_SIGN_SIZE];			//平台account uid+time+fm+SERVER_KEY的MD5
	uint8 fm;								// 0 未填写实名信息 1填写了实名信息且已经成年 2填写了实名但未成年
	uint16 zone;							//大区
	SessionIDLoginCMsg() 
        : MsgBase(id, sizeof(*this))
        , accuid(0)
        , time(0)
        , fm(0)
        , zone(0)
	{
		bzero(sign, sizeof(sign));
	}
};


/**
 * \brief ZoneListMsg 服务器向客户端发送大区列表
 */
struct ZoneListSMsg : public MsgBase
{
	enum{ id = 0x15 };
	accuid_t accuid;					//账号Uid
	uint32 time;							//当前时间

	uint16 count;
	struct ZoneInfo
	{
		uint16 zoneId;
		char   zoneName[32];
		char   domainName[32];
		uint16 port;
	}data[0];
	ZoneListSMsg() : MsgBase(id, sizeof(*this)), count(0) {}

	uint32 getSize()
	{
		return sizeof(*this) + count * sizeof(ZoneInfo);
	}
};

struct LoginZoneListSMsg : public MsgBase
{
    enum { id = 0x16 };
    accuid_t accuid;
    uint16 Zoneid[LOGIN_ZONE_COUNT];

    LoginZoneListSMsg()
        : MsgBase(id, sizeof(*this))
        , accuid(0)
    {
        bzero(Zoneid, sizeof(Zoneid));
    }
};

struct GuestAccountCMsg : public MsgBase
{
    enum { id = 0x17 };

    GuestAccountCMsg()
        : MsgBase(id, sizeof(*this))
    {}
};

struct GuestAccountSMsg : public MsgBase
{
    enum { id = 0x18 };

	char accountName[ACCOUNT_NAME_SIZE];
	char password[PASSWORD_SIZE];
    uint64 accuid;
    char sign[PLAYER_SIGN_SIZE];
    
    GuestAccountSMsg()
        : MsgBase(id, sizeof(*this))
    {}
};

struct AllZoneListCMsg : public MsgBase
{
    enum { id = 0x19 };
    accuid_t accuid;

	AllZoneListCMsg()
        : MsgBase(id, sizeof(*this))
		, accuid(0)
    {} 
};
    
struct AllZoneListSMsg : public MsgBase
{
    enum { id = 0x1A };

	uint16 lastZoneId;
    uint16 count;
    struct ZoneInfo
	{
		uint16 zoneId;
        uint8 state;
		char   zoneName[TINYSTR];
	}data[0];

    AllZoneListSMsg()
        : MsgBase(id, sizeof(*this))
		, lastZoneId(0)
        , count(0)
    {}

    uint32 getSize()
    {
        return sizeof(*this) + count * sizeof(data[0]);
    }
};

struct AccountLoginSMsg : public MsgBase
{
    enum { id = 0x1B };
	
	playerid_t uid;							//帐号Id
    uint8 ret;
    char sign[PLAYER_SIGN_SIZE];            //平台account uid+time+fm+SERVER_KEY的MD5
    AccountLoginSMsg()
        : MsgBase(id, sizeof(*this))
    {}
};

struct ZoneListCMsg : public MsgBase
{
    enum { id = 0x1C };

    accuid_t accuid;
    uint16 zoneId;
    
    ZoneListCMsg()
        : MsgBase(id, sizeof(*this))
    {}
};

/**
 * \brief BindAccountCMsg 绑定账号
 */
struct BindAccountCMsg: public MsgBase
{
	enum{ id = 0x1D };

    AccountInfo account;
    
	BindAccountCMsg() : MsgBase(id, sizeof(*this))
	{}
};

/**
 * \brief BindAccountSMsg 绑定账号返回
 */
struct BindAccountSMsg: public MsgBase
{
	enum{ id = 0x1E };
	enum RET_CODE
	{
		RET_CODE_INVALID_ID = 1,		//无效的ID
	};
	uint8 ret;
	uint64 accuid;
	char accountName[ACCOUNT_NAME_SIZE];
	BindAccountSMsg()
	: MsgBase(id, sizeof(*this))
	, ret(0)
	, accuid(0)
	{
		accountName[0] = '\0';
	}
};

/**
 * 登录前公告消息
 */
struct NoticeSMsg : public MsgBase
{
    enum { id = 0x1F };

    uint16 len;
    
    struct {
        uint16 titlelen;
        char title[0];

        uint16 textlen;
        char text[0];
    } notice[0];

    NoticeSMsg()
        : MsgBase(id, sizeof(*this))
        , len(0)
    {}

    uint32 getSize()
    {
        return sizeof(*this) + len;
    }
};

struct NoticeCMsg : public MsgBase
{
    enum { id = 0xB0 };

    NoticeCMsg()
        : MsgBase(id, sizeof(*this))
    {}
};

struct CheckPlayerName : public MsgBase
{
    
};

/**
 * \brief AllocServerIdMsg 给SceneServer和GatewayServer分配服务ID
 */
struct AllocServerIdMsg: public MsgBase				
{
	enum{ id = 0x20 };
	uint16 zoneId;
	uint8 serverId;
	AllocServerIdMsg(uint16 _zoneId = 0, uint8 _serverId = 0)
		: MsgBase(id, sizeof(*this))
        , zoneId(_zoneId)
        , serverId(_serverId)
	{
	}
};

/**
 * \brief ReportGatewayInfoMsg CentralServer 向 AccountServer 报告网关信息
 */
struct ReportGatewayInfoMsg : public MsgBase				
{
	enum{ id = 0x21 };
	uint8 count;
	struct GatewayInfo 
	{
		uint8 serverId;
		char domainName[32];
		uint32 ip;
		uint16 port;
		uint16 users;
	}data[];
    ReportGatewayInfoMsg() : MsgBase(id), count(0) {}
    uint32 getSize()
	{
		return sizeof(*this) + count * sizeof(GatewayInfo);
	}
};

/**
 * \brief ReportGatewayCloseMsg
*/
struct ReportGatewayCloseMsg : public MsgBase				
{
	enum{ id = 0x22 };
	uint8 serverId;
	ReportGatewayCloseMsg() : MsgBase(id, sizeof(*this)), serverId(0) {}
};


/**
 * \brief ReportGatewayUsersMsg
*/
struct ReportGatewayUsersMsg: public MsgBase				
{
	enum{ id = 0x23 };
	uint8 serverId;
	uint16 users;
	ReportGatewayUsersMsg() : MsgBase(id, sizeof(*this)), serverId(0), users(0){}
};

/**
 * \brief RegistSceneMapMsg SceneServer注册地图
 */
struct RegistSceneMapMsg: public MsgBase				
{
	enum{ id = 0x24 };
	uint16 mapId;
	RegistSceneMapMsg() 
		: MsgBase(id, sizeof(*this))
		, mapId(0)
	{

	}
};

struct ConfrimReportGatewayInfoMsg : public MsgBase
{
    enum { id = 0x25 };
    ConfrimReportGatewayInfoMsg()
        : MsgBase(id, sizeof(*this))
    {}
};
/**
* \brief 每日刷新
*/
struct DailyUpdateSMsg: public MsgBase				
{
	enum{ id = 0x25 };
	uint8 wDay;				//日星期
	uint8 hour;				//日更新小时
	DailyUpdateSMsg() 
		: MsgBase(id, sizeof(*this))
		  , wDay(0)
		  , hour(0)
	{}
};

/**
 * \brief LaunchPVPMsg 发起PVP
 */
struct LaunchPVPMsg: public PlayerMsg
{
	enum{ id = 0x100};
	uint64 playerGuid;
	uint32 playerId;
	uint8 PVPType;
	uint32 param;

	LaunchPVPMsg()
		: PlayerMsg(id, sizeof(*this))
		, playerGuid(0)
		, playerId(0)
		, PVPType(0)
		, param(0)
	{

	}
};

/**
 * \brief ResponsePVPMsg PVP结果回应
 */
struct ResponsePVPMsg: public PlayerMsg
{
	enum{ id = 0x101};

	uint8 result;   // 2 耐力不足
	uint32 playerId;
	uint8 PVPType;
	uint8 victory; 
	uint32 param;
	playerid_t playerGuid;
	ResponsePVPMsg()
		: PlayerMsg(id, sizeof(*this))
		 , result(0)
		 , playerId(0)
		 , PVPType(0)
		 , victory(0)
		 , param(0)
		 , playerGuid(0)
	{}
};
/**
 * \brief KickPlayerMsg 踢玩家下线
 */
struct KickPlayerMsg: public PlayerMsg 
{
	enum{ id = 0x400};
	
	int32 fd;
	uint8 result;	//0为正常断开 1为被查封, 2,被另外帐号登录踢掉

	KickPlayerMsg()
		: PlayerMsg(id, sizeof(*this))
		, fd(0)
		, result(0)
	{
	}
};

/**
 * \brief PlayerOnlineMsg 角色上
 */
struct PlayerOnlineMsg: public PlayerMsg
{
	enum{ id = 0x401 };
	playerid_t playerGuid;					//角色唯一ID
	uint8 serverId;							//服务器Id
	char playerName[PLAYER_NAME_SIZE];		//角色名
	accuid_t accuid;					//帐号Uid
	PlayerOnlineMsg()
		: PlayerMsg(id, sizeof(*this))
		, playerGuid(0)
		, accuid(0)
	{
	}
};

/**
 * \brief PlayerOfflineMsg 角色下线
 */
struct PlayerOfflineMsg: public PlayerMsg
{
	enum{ id = 0x402 };
    uint64 bindTimeStamp;
	PlayerOfflineMsg()
		: PlayerMsg(id, sizeof(*this))
        , bindTimeStamp(0)
	{}
};

/**
 * \brief PlayerInitDataMsg 初始化玩家数据
 */
struct PlayerInitDataMsg: public PlayerMsg
{
	enum{ id = 0x403 };
	playerid_t playerGuid;							//角色唯一ID
	char playerName[PLAYER_NAME_SIZE];				//角色名
	accuid_t accuid;							//账号Uid
	PlayerInitDataMsg()
		: PlayerMsg(id, sizeof(*this))
		, playerGuid(0)
		, accuid(0)
	{
		playerName[0] = '\0';
	}
};

struct SetSessionIDMsg : public PlayerMsg
{
    enum { id = 0x404 };
    playerid_t playerGuid;
    char sign[PLAYER_SIGN_SIZE];

    SetSessionIDMsg()
        : PlayerMsg(id, sizeof(*this))
        , playerGuid(0)
    {
        bzero(sign, sizeof(sign));
    }
};

struct CheckSessionIDMsg : public PlayerMsg
{
    enum { id = 0x405 };
    accuid_t accuid;
    char sign[PLAYER_SIGN_SIZE];
    int fd;
    uint64 bindTimeStamp;
    
    CheckSessionIDMsg()
        : PlayerMsg(id, sizeof(*this))
        , accuid(0)
        , fd(0)
        , bindTimeStamp(0)
    {
        bzero(sign, sizeof(sign));
    }
};

struct CheckSessionIDRetMsg : public PlayerMsg
{
    enum { id = 0x406 };

    enum {
        RET_OK     = 0,
        RET_FAILED = 1,
    };

    int fd;
    uint8 ret;
    
    CheckSessionIDRetMsg()
        : PlayerMsg(id, sizeof(*this))
        , fd(0)
        , ret(0)
    {}
};

struct SyncPlayerPowerMsg : PlayerMsg
{
    enum { id = 0x407 };
    
    playerid_t playerGuid;
    uint16 level;
    uint16 leadcard;
    uint32 power;
    uint32 leadCardLv;
    uint8  viplevel;
    uint8  sp;
    uint8  pvpsp;
    
    SyncPlayerPowerMsg()
        : PlayerMsg(id, sizeof(*this))
        , playerGuid(0)
        , level(0)
        , leadcard(0)
        , power(0)
        , leadCardLv(0)
        , viplevel(0)
        , sp(0)
        , pvpsp(0)
    {}
};

struct PlayerArenaRewardMsg: PlayerMsg
{
	enum { id = 0x408 };

	uint8 rewardType;		//1每日奖励 2 周奖励
	uint8 rewardId;			//ID
	
	PlayerArenaRewardMsg()
		: PlayerMsg(id, sizeof(*this))
		, rewardType(0)
		, rewardId(0)
	{

	}
};

struct ResPlayerArenaRewardMsg: PlayerMsg
{
	enum { id = 0x409 };

	uint8 result;			//
	uint8 rewardType;		//1每日奖励 2 周奖励
	uint8 rewardId;			//ID
	
	ResPlayerArenaRewardMsg()
		: PlayerMsg(id, sizeof(*this))
		, result(0)
		, rewardType(0)
		, rewardId(0)
	{

	}
};

struct ArenaMsg : PlayerMsg
{
    enum { id = 0x410 };

    uint32 fromUser;
    char   toUser[32];

    ArenaMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

struct GetSpMsg : PlayerMsg
{
    enum { id = 0x411 };

    uint8 sp;

    GetSpMsg()
        : PlayerMsg(id, sizeof(*this))
		, sp(0)
    {}
};

struct FriendBySlotMsg : PlayerMsg
{
    enum { id = 0x412 };

    uint32 gold;

    FriendBySlotMsg()
        : PlayerMsg(id, sizeof(*this))
		, gold(0)
    {}
};

struct ResFriendBySlotMsg : PlayerMsg
{
    enum { id = 0x413 };

    uint8 ret;

    ResFriendBySlotMsg()
        : PlayerMsg(id, sizeof(*this))
		, ret(0)
    {}
};

struct GiveSpMsg : PlayerMsg
{
    enum { id = 0x414 };

    GiveSpMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_ACCOUNTMSG__


