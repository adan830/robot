/**
 * \filename   SocialMsg.h		v1.0
 * \brief      
 *             
 * \author     
 * \created    06/24/2014 03:07:01 PM
 */
#ifndef __NXCORE_SOCIAL_MSG__
#define __NXCORE_SOCIAL_MSG__

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * \brief 好友操作
 */
struct SocialOpCSMsg: public PlayerMsg
{
	enum{ id = 0x970};

	enum
	{
		SocialOp_RequestFriendList = 0,		//请求好友数据
		SocialOp_Invite = 1,			//申请添加好友
		SocialOp_Agree = 2,				//同意添加好友
		SocialOp_Refuse = 3,			//拒绝添加好友
		SocialOp_Delete = 4,			//删除好友
		SocialOp_RequestInviteList = 5,		//请求邀请数据
		SocialOp_BuySlot = 6,				//扩充好友数量
		SocialOp_GiveSp = 7,				//赠送体力
		SocialOp_GetSp = 8,					//领取体力		
		SocialOp_RequestRecommendList = 9,		//请求推荐数据
	};

	enum SocialOp_Result
	{
		SocialOP_Success = 0,					//操作成功
		SocialOP_ErrFailed = 1,					//失败
		SocialOP_FriendExisted = 2,				//申请好友已经存在
		SocialOP_NotExisted = 3,				//申请好友不存在
		SocialOP_FriendOverLimit = 4,			//对方好友数量超过了限制
		SocialOP_OverLimit = 5,					//好友数量超过了限制
		SocialOP_InviteOverLimit = 6,			//对方申请列表超过了限制
		SocialOP_GiveOverLimit = 7,				//赠送体力超过了次数限制
		SocialOP_AddSelfErr = 8,                //申请好友不能添加自己
		SocialOP_BuySlotOverLimit = 9,			//购买列表超过了限制
	};
	uint8 op;						//操作
	uint8 result;					//结果
	union
	{
		struct
		{
			uint32 param1;				//操作参数1
			uint32 param2;				//操作参数2
		};
		uint64 param;					//操作参数
	};

	SocialOpCSMsg()
		: PlayerMsg(id, sizeof(*this))
		, op(0)
		, result(0)
		, param(0)
	{
	}
};

/**
 * \brief 好友列表数据
 */
struct FriendListSMsg: public PlayerMsg
{
	enum{ id = 0x971};
	uint8 getSpCount;			//每天获取体力次数
	uint8 giveCount;			//赠送好友次数
	uint8 buyFriendSlot;		//购买的好友扩展槽
	uint16 count;				//好友个数
	struct DataInfo
	{
		uint64 playerGuidId;		//对手ID
		char playerName[PLAYER_NAME_SIZE];	//好友名称
		uint8 level;			//等级
		uint32 cardId;			//队长卡牌ID
		uint8 cardLevel;		//队长卡牌Level
		uint32 power;           //战力
		uint32 loginTime;		//登录时间
		uint8  giveSp;			//赠送体力标志1可赠送 2已经赠送
		uint8 getSp;			//领取体力标志0无，1可领取，2已经领取
        int AssistTime;         //助战时间戳
	}data[0];

	FriendListSMsg()
		: PlayerMsg(id, sizeof(*this))
		, count(0)
	{
	}
	uint32 getSize()
	{
		return sizeof(*this) + sizeof(data[0]) * count;
	}
};

/**
 * \brief 邀请列表数据
 */
struct InviteListSMsg: public PlayerMsg
{
	enum{ id = 0x972};

	uint8 count;				//好友个数
	struct DataInfo
	{
		uint64 playerGuidId;		//对手ID
		char playerName[PLAYER_NAME_SIZE];	//好友名称
		uint8 level;			//等级
		uint32 cardId;			//队长卡牌ID
		uint8 cardLevel;		//队长卡牌Level
		uint32 power;           //战力
		uint32 loginTime;		//登录时间
	}data[0];

	InviteListSMsg()
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
 * \brief 推荐列表数据
 */
struct RecommendListSMsg: public PlayerMsg
{
	enum{ id = 0x973};

	uint8 count;				//推荐个数
	struct DataInfo
	{
		uint64 playerGuidId;		//对手ID
		char playerName[PLAYER_NAME_SIZE];	//好友名称
		uint8 level;			//等级
		uint32 cardId;			//队长卡牌ID
		uint8 cardLevel;		//队长卡牌Level
		uint32 power;           //战力
		uint32 loginTime;		//登录时间
	}data[0];

	RecommendListSMsg()
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
 * 好友添加通知
 */
struct NewInviteSMsg : public PlayerMsg
{
    enum { id = 0x974 };

    playerid_t uid;
    char name[32];
    
    NewInviteSMsg()
        : PlayerMsg(id, sizeof(*this))
        , uid(0)
    {}
};
#pragma pack(pop) 

CORE_NAMESPACE_END          

#endif//__NXCORE_ARENAMSG__ 
