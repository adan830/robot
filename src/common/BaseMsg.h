#ifndef __BASE_MSG_H__
#define __BASE_MSG_H__

CORE_NAMESPACE_START
#pragma pack(push, 1)

static const uint32 SERVER_VERSION  = 100001;

/**
 * \brief MsgBase 网络消息结构父类
 */
struct MsgBase
{
	enum { id = 0x0 };							//消息类型编号
	uint16 size;								//消息体字节数
	const uint16 type;							//消息类型，被自动初始化为消息类型编号
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
 * \brief MsgBase 压缩消息格式
 */
struct ZipMsg : public MsgBase
{
	enum{ id = 0x1 };
	uint16 bytes;								//data的字节数
	uint8 data[];								//变长的压缩数据
	ZipMsg() : MsgBase(id, sizeof(*this)) {}
	uint32 getSize()
	{
		return sizeof(*this) + bytes;
	}
};

/**
 * \brief MsgBase 加密消息格式
 */
struct EncryMsg : public MsgBase
{
	enum{ id = 0x2 };
	uint16 bytes;
	uint8 data[];
	EncryMsg() : MsgBase(id, sizeof(*this)) {}
	uint32 getSize()
	{
		return sizeof(*this) + bytes;
	}
};

/**
 * \brief MsgBase 网络连接验证消息
 */
struct VerifyCMsg : public MsgBase
{
	enum{ id = 0x3 };
	static const uint64 VERIFY_CODE = 9876543210;

	int16 taskType;		     				//连接任务类型
	uint32 version;
	uint64 verifyCode;							//验证码
	VerifyCMsg() 
		: MsgBase(id, sizeof(*this)), taskType(0)
		, version(SERVER_VERSION), verifyCode(VERIFY_CODE)
	{
	}
};

/**
 * \brief MsgBase 返回错误码给客户端
 */
struct CodePageSMsg : public PlayerMsg
{
	enum{ id = 0x4 };
	uint32 code;
	CodePageSMsg(uint32 c = 0)
		: PlayerMsg(id, sizeof(*this)), code(c) {}
};

/**
 * \brief MsgBase 返回错误码给其他服务器
 */
struct CodePageMsg : public PlayerMsg
{
	enum{ id = 0x5 };
	uint32 code;
	CodePageMsg(uint32 c = 0)
		: PlayerMsg(id, sizeof(*this)), code(c) {}
};

/**
 *  \brief BroadcastMsg
 */
struct BroadcastMsg : public PlayerMsg
{
	enum{ id = 0x6 };
	uint16 msgSize;
	uint8 count;
	uint32 targets[0];

	BroadcastMsg()
		: PlayerMsg(id, sizeof(*this))
		, msgSize(0)
		, count(0)
	{
	}

	uint32 getSize()
	{
		return sizeof(*this) + count*4 + msgSize;
	}

	/* static BroadcastMsg* create() */
	/* { */
	/* 	NEW_MAX_MSG(BroadcastMsg); */
	/* 	return newmsg; */
	/* } */
};

/**
 * 操作结果
 */
struct OpRetSMsg : public PlayerMsg
{
    enum { id = 0x888 };

    uint32 msgid;
    uint32 ret;
    int param1;
    int param2;
    uint64 CharId;
    
    OpRetSMsg()
        : PlayerMsg(id, sizeof(*this))
        , msgid(0)
        , ret(0)
        , param1(0)
        , param2(0)
        , CharId(0)
    {}
};

#pragma pack(pop)
CORE_NAMESPACE_END
#endif
