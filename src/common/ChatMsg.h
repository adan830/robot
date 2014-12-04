#ifndef __NXCORE_CHATMSG__
#define __NXCORE_CHATMSG__

#include <MsgDefine.h>
#ifndef __SGROBOT__
#include <MemRoster.h>
#endif

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * \brief 聊天类型枚举
 */
enum ChatType
{
	ChatType_World		= 1,		//世界聊天
	ChatType_Private	= 2,		//私人聊天
};

/**
 * \brief 客户端请求聊天数据
 */
struct RequestChatDataCMsg: public PlayerMsg
{
    enum { id = 0x950};

	uint8 chatType;				//见 enum ChatType
    
    RequestChatDataCMsg()
        : PlayerMsg(id, sizeof(*this))
		, chatType(1)
    {
	
	}
};

/**
 * \brief 客户端返回个人聊天数据
 */
struct ResponseChatDataSMsg: public PlayerMsg
{
    enum { id = 0x951};

	uint8 chatType;				//见 enum ChatType
	uint32 lastChatTime;		//最后发送聊天的时间
	uint32 freeChatTimes;		//剩余免费聊天次数
	bool newchat;				//有新私聊
	uint8 count;				//聊天内容条数
	struct ChatRecord
	{
		uint64 senderGuid;				//发送者GUID
		uint16 senderLevel;				//发送者等级
		char sender[PLAYER_NAME_SIZE];	//发送者名字
		char content[128];				//内容
		uint32 sendTime;				//发送时间
	}data[];
    
    ResponseChatDataSMsg()
        : PlayerMsg(id, sizeof(*this))
		, chatType(1)
		, lastChatTime(0)
		, freeChatTimes(0)
		, newchat(false)
		, count(0)
    {
	
	}

	static ResponseChatDataSMsg* create(uint8 n)
	{
		NEW_MSG(ResponseChatDataSMsg, sizeof(ResponseChatDataSMsg) + sizeof(ChatRecord) * n);
		bzero(newmsg->data, sizeof(ChatRecord)*n);
		return newmsg;
	}

	uint32 getSize()
	{
		return sizeof(*this) + sizeof(data[0])*count;
	}
};

/**
 * \brief 客户端发送世界聊天
 */
struct SendChatCMsg: public PlayerMsg
{
    enum { id = 0x952};

	char content[128];				//内容

    SendChatCMsg()
        : PlayerMsg(id, sizeof(*this))
    {
		bzero(content, sizeof(content));
	}
};

/**
 * \brief 服务端发送世界聊天
 */
struct SendChatSMsg: public PlayerMsg
{
    enum { id = 0x953};

	uint32 sendTime;				//发送时间
	uint64 senderGuid;				//发送者GUID
	uint16 senderLevel;				//发送者等级
	char sender[PLAYER_NAME_SIZE];	//发送者名字
	char content[128];				//内容

    SendChatSMsg()
        : PlayerMsg(id, sizeof(*this))
		, sendTime(0)
		, senderGuid(0)
		, senderLevel(0)
    {
		bzero(sender, sizeof(sender));
		bzero(content, sizeof(content));
	}
};

/**
 * \brief 客户端发送私人聊天
 */
struct SendPrivateChatCMsg: public PlayerMsg
{
    enum { id = 0x954};

	char recver[PLAYER_NAME_SIZE];	//接收者名字
	char content[128];				//内容

    SendPrivateChatCMsg()
        : PlayerMsg(id, sizeof(*this))
    {
		bzero(recver, sizeof(recver));
		bzero(content, sizeof(content));
	}
};

/**
 * \brief 服务端发送私人聊天
 */
struct SendPrivateChatSMsg: public PlayerMsg
{
    enum { id = 0x955};

	uint32 sendTime;				//发送时间
	uint64 senderGuid;				//发送者GUID
	uint16 senderLevel;				//发送者等级
	char sender[PLAYER_NAME_SIZE];	//发送者名字
	char content[128];				//内容

    SendPrivateChatSMsg()
        : PlayerMsg(id, sizeof(*this))
		, sendTime(0)
		, senderGuid(0)
		, senderLevel(0)
    {
		bzero(sender, sizeof(sender));
		bzero(content, sizeof(content));
	}
};

/**
 * \brief 聊天错误
 */
struct ChatErrorSMsg: public PlayerMsg
{
    enum { id = 0x956};

	uint32 errorCode;

    ChatErrorSMsg()
        : PlayerMsg(id, sizeof(*this))
		, errorCode(0)
    {
	}
};

/**
 * \brief 更新聊天状态
 */
struct UpdateChatStatusSMsg: public PlayerMsg
{
    enum { id = 0x957};

	uint32 lastChatTime;		//最后发送聊天的时间
	uint32 freeChatTimes;		//剩余免费聊天次数
    
    UpdateChatStatusSMsg()
        : PlayerMsg(id, sizeof(*this))
		, lastChatTime(0)
		, freeChatTimes(0)
    {
	
	}
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_CHATMSG__

