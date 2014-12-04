/**
 * \filename   GatewayMsg.h		v1.0
 * \brief      
 *             
 * \author     zhufang(zhufang666@gmail.com)
 * \created    2012-10-23 12:26
 */
#ifndef __NXCORE_GATEWAYMSG__
#define __NXCORE_GATEWAYMSG__

#include <string.h>

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * \brief RequestRoleListMsg 请求角色列表
 */
struct RequestRoleListMsg : public PlayerMsg 
{
	enum{ id = 0x700 };
    
    int fd;
	playerid_t accuid;
    
	RequestRoleListMsg() : PlayerMsg(id, sizeof(*this))
        , fd(0)
        , accuid(0)
	{}
};

/**
 * \brief CreateRoleMsg 客户端请求创建角色
 */
struct CreateRoleMsg : public PlayerMsg
{
	enum{ id = 0x701 };
	char playerName[PLAYER_NAME_SIZE];  //角色名称
	playerid_t accuid;                  //账号Uid
	uint32 cardKey;                     //卡牌
    int fd;
	CreateRoleMsg()
		: PlayerMsg(id, sizeof(*this))
		, accuid(0)
		, cardKey(0)
        , fd(0)
	{
		bzero(playerName, PLAYER_NAME_SIZE);
	}
};

/**
 * \brief ChooseRoleMsg 网关转发选择角色消息
 */
struct ChooseRoleMsg: public PlayerMsg
{
	enum{ id = 0x702 };
    
    int fd;
	uint32 playerId;  //角色临时ID
	playerid_t CharId;//角色Uid
	uint32 loginIp;
    ChooseRoleMsg()
		: PlayerMsg(id, sizeof(*this))
        , fd(0)
        , playerId(0)
		, CharId(0)
		, loginIp(0)
	{}
};

/**
 * 选择初始卡牌
 */
struct ChoosePlayerRoleCardMsg : public PlayerMsg
{
    enum { id = 0x703 };

    playerid_t CharId;
    uint32 card;

    ChoosePlayerRoleCardMsg()
        : PlayerMsg(id, sizeof(*this))
        , CharId(0)
        , card(0)
    {}
};

/**
 * \brief 绑定角色ID 和 fd 
 */
struct BindRoleWithFdMsg: public PlayerMsg
{
	enum{ id = 0x704 };
    int fd;                //文件描述符
	uint32 playerId;       //角色临时ID
	playerid_t CharId;     //角色Uid
    uint64 bindTimeStamp;  //绑定时刻时间戳
    
    BindRoleWithFdMsg()
		: PlayerMsg(id, sizeof(*this))
        , fd(0)
        , playerId(0)
		, CharId(0)
        , bindTimeStamp(0)
	{}
};


#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_GATEWAYMSG__

