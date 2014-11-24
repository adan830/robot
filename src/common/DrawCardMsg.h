/**
 * \filename   DrawCardMsg.h		v1.0
 * \brief      
 *             
 * \author     zhufang(zhufang666@gmail.com)
 * \created    2014-11-20 09:57
 */
#ifndef __NXCORE_DRAWCARDMSG__
#define __NXCORE_DRAWCARDMSG__

#include <MsgDefine.h>
#ifndef __SGROBOT__
#include <MemRoster.h>
#endif

CORE_NAMESPACE_START

#pragma pack(push, 1)

enum DrawCardOp
{
	DrawCard_Data		= 1,		//请求数据 服务端返回消息: DrawCardDataSMsg
	DrawCard_Refresh	= 2,		//换一组   服务端返回消息: 成功DrawCardDataSMsg 失败DrawCardOpCSMsg(ret = 1)
	DrawCard_ViewReward	= 3,		//查看奖励 服务端返回消息: DrawCardDataSMsg
	DrawCard_Draw		= 4,		//翻牌 param=牌号1~6 服务端返回消息: 成功DrawCardRewardSMsg 失败DrawCardOpCSMsg(ret = 1)
};

/**
 * \brief 点神兵系统操作消息定义
 */
struct DrawCardOpCSMsg: public PlayerMsg
{
    enum { id = 0x930};

	uint8 op;						//参加enum DrawCardOp
	uint8 param;					//参数
	uint8 ret;						//返回值 0:表示成功 否则失败
    
    DrawCardOpCSMsg()
        : PlayerMsg(id, sizeof(*this))
		, op(0)
		, param(0)
		, ret(0)
    {
	
	}
};

/**
 * \brief 点神兵数据
 */
struct DrawCardDataSMsg: public PlayerMsg
{
    enum { id = 0x931};

	uint8 op;						//参加enum DrawCardOp
	uint8 remainDrawTimes;			//剩余刷新次数
	struct
	{
		uint16 itemId;				//道具ID 0表示翻牌背面
		uint16 itemCount;			//道具数量
		bool gained;				//是否已经获取
	}data[6];
    
    DrawCardDataSMsg()
        : PlayerMsg(id, sizeof(*this))
		, op(0)
		, remainDrawTimes(0)
    {
		bzero(data, sizeof(data));
	}
};

/**
 * \brief 点神兵翻牌奖励
 */
struct DrawCardRewardSMsg: public PlayerMsg
{
    enum { id = 0x932};

	uint8 cardId;					//牌号1~6
	uint16 itemId;					//道具ID 0表示翻牌背面
	uint16 itemCount;				//道具数量
    
    DrawCardRewardSMsg()
        : PlayerMsg(id, sizeof(*this))
		, cardId(0)
		, itemId(0)
		, itemCount(0)
    {

	}
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_DRAWCARDMSG__

