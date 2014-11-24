/**
 * \filename   CentralMsg.h		v1.0
 * \brief      
 *             
 * \author     zhufang(zhufang666@gmail.com)
 * \created    2012-09-24 12:46
 */
#ifndef __NXCORE_LOGINMSG__
#define __NXCORE_LOGINMSG__

#include <string.h>

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * \brief AllocServerIdMsg 给SceneServer和GatewayServer分配服务ID
 */
struct AllocServerIdMsg: public MsgBase				
{
	enum{ id = 0x20 };
	uint16 zoneId;
	uint8 serverId;
	AllocServerIdMsg(uint16 zoneId = 0, uint8 serverId = 0)
		: MsgBase(id, sizeof(*this)), zoneId(zoneId), serverId(serverId)
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
	uint16 getSize()
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
	playerid_t accountUid;					//帐号Uid
	PlayerOnlineMsg()
		: PlayerMsg(id, sizeof(*this))
		, playerGuid(0)
		, accountUid(0)
	{
	}
};

/**
 * \brief PlayerOfflineMsg 角色下线
 */
struct PlayerOfflineMsg: public PlayerMsg
{
	enum{ id = 0x402 };
	PlayerOfflineMsg()
		: PlayerMsg(id, sizeof(*this))
	{
	}
};

/**
 * \brief PlayerInitDataMsg 初始化玩家数据
 */
struct PlayerInitDataMsg: public PlayerMsg
{
	enum{ id = 0x403 };
	playerid_t playerGuid;							//角色唯一ID
	char playerName[PLAYER_NAME_SIZE];				//角色名
	playerid_t accountUid;							//账号Uid
	PlayerInitDataMsg()
		: PlayerMsg(id, sizeof(*this))
		, playerGuid(0)
		, accountUid(0)
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
    playerid_t playerGuid;
    char sign[PLAYER_SIGN_SIZE];
    int fd;
    
    CheckSessionIDMsg()
        : PlayerMsg(id, sizeof(*this))
        , playerGuid(0)
        , fd(0)
    {
        bzero(sign, sizeof(sign));
    }
};

struct CheckSessionIDRetMsg : public PlayerMsg
{
    enum { id = 0x406 };

    enum {
        RET_OK     = 0,
        RET_FAILED = 1
    };
    
    playerid_t playerGuid;
    int fd;
    uint8 ret;
    
    CheckSessionIDRetMsg()
        : PlayerMsg(id, sizeof(*this))
        , playerGuid(0)
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

#endif//__NXCORE_LOGINMSG__

