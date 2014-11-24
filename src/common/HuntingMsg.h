/**
 * \filename   HuntingMsg.h		v1.0
 * \brief      狩猎相关消息定义
 *             
 * \author     zhufang(zhufang666@gmail.com)
 * \created    2014-10-30 10:08
 */
#ifndef __NXCORE_HUNTINGMSG__
#define __NXCORE_HUNTINGMSG__

#include <MsgDefine.h>
#ifndef __SGROBOT__
#include <MemRoster.h>
#endif
CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * \brief 狩猎操作
 */
struct HuntingOpCSMsg: public PlayerMsg
{
    enum { id = 0x940};

	uint8 op;				//1:请求狩猎数据 返回消息 HuntingDataSMsg
							//2:狩猎投掷 返消息1，HuntingOpCSMsg param=结果点数 ,返回消息2：HuntingDataSMsg 更新狩猎数据 返回消息3:TradeInSMsg
							//3:领取奖励 param=任务号:1~3 返回消息TradeInSMsg
							//4:购买次数 成功返回消息 HuntingDataSMsg 失败返回HuntingOpCSMsg(param=1)
	uint8 param;			//参数
	uint8 ret;				//返回值 0:表示成功 否则失败

    HuntingOpCSMsg()
        : PlayerMsg(id, sizeof(*this))
		, op(0)
		, param(0)
		, ret(0)
    {
	
	}
};

/**
 * \brief 狩猎数据
 */
struct HuntingDataSMsg: public PlayerMsg
{
    enum { id = 0x941};

	uint8 stayPos;				//当前停留位置
	uint8 remainTimes;			//剩余投掷次数
	uint8 buyTimes;				//已经购买的次数
	uint16 restoreTime;			//次数恢复时间

	struct HuntingMission
	{
		uint8 missionType;		//任务类型
		uint8 require;			//任务需求次数
		uint8 value;			//达成次数
		bool rewarded;			//是否领奖
		uint8 rewardType;		//奖励类型
		uint32 rewardValue;		//奖励数目

		HuntingMission()
			: missionType(0)
			, require(0)
			, value(0)
			, rewarded(false)
			, rewardType(0)
			, rewardValue(0)
		{

		}
	}missions[3];

    HuntingDataSMsg()
        : PlayerMsg(id, sizeof(*this))
		, stayPos(0)
		, remainTimes(0)
		, buyTimes(0)
		, restoreTime(0)
    {
		
	}
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_HUNTINGMSG__

