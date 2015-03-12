/**
 * \filename   MineRobMsg.h		v1.0
 * \brief      抢矿相关消息定义
 *             
 * \author     zhufang(zhufang666@gmail.com)
 * \created    2015-01-04 15:43
 */
#ifndef __NXCORE_MINEROBMSG__
#define __NXCORE_MINEROBMSG__

#include <MsgDefine.h>
#ifndef __SGROBOT__
#include <MemRoster.h>
#endif

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * \brief 抢矿操作
 */
struct MineRobOpCSMSg: public PlayerMsg
{
    enum { id = 0xB30};

	uint8	op;				// 1:请求抢矿数据	返回 MineRobDataSMsg
							// 2:请求普通矿场列表 param1=类型 param2=页码	返回 MineListSMsg
							// 3:请求高级矿场列表 param1=类型 param2=页码 返回 MineListSMsg
							// 5:占领空矿场 返回	 param1=类型 param2=矿Id 失败MineListSMsg
							// 6:抢占他人矿场	 param1=类型 param2=矿Id
							// 7:延长占领时间	 param1=类型 param2=矿Id
							// 8:取消占领		 param1=类型 param2=矿Id
							// 9:一键找矿		 param1=类型 param2=矿子Id 返回 MineListSMsg
	uint16	param1;
	uint16	param2;
	uint8	ret;			// 返回值 0:表示成功 否则失败

    MineRobOpCSMSg()
        : PlayerMsg(id, sizeof(*this))
		, op(0)
		, param1(0)
		, param2(0)
		, ret(0)
    {

	}
};

/**
 * \brief 抢矿数据
 */
struct MineRobDataSMsg: public PlayerMsg
{
    enum { id = 0xB31};

	uint8	ret;				// 操作的结果 参见枚举MineOpResult(MineType.h)
	uint8	mineType;			// 类型 参见枚举MineType(MineType.h)
	uint16	mineId;				// 矿Id
	uint32	occupyTime;			// 占领时间
	uint8	times;				// 延长次数

    MineRobDataSMsg()
        : PlayerMsg(id, sizeof(*this))
		, mineType(0)
		, mineId(0)
		, occupyTime(0)
		, times(0)
    {
		
	}
};

/**
 * \brief 矿场列表
 */
struct MineListSMsg: public PlayerMsg
{
    enum { id = 0xB32};

	uint8 mineType;								// 类型
	uint8 page;									// 页码
	uint8 count;								// 总数

	struct MineTarget
	{
		uint16	mineId;							// 矿Id
		char	playerName[PLAYER_SIGN_SIZE];	// 玩家名字
		uint32	playerLevel;					// 玩家等级
		uint32	playerIcon;						// 玩家图标
		uint32	occupyTime;						// 占领时间
		uint8	times;							// 延长次数
	}data[0];

    MineListSMsg()
        : PlayerMsg(id, sizeof(*this))
		, mineType(0)
		, page(0)
		, count(0)
    {
		bzero(data, sizeof(data));
	}

	uint16 getSize() const
	{
		return sizeof(*this) + sizeof(data[0]) * count;
	}

	static MineListSMsg* create(uint16 count)
	{
		// 统计消息的长度
		uint16 msgSize	= sizeof(MineListSMsg) + sizeof(MineTarget) * count;

		NEW_MSG(MineListSMsg, msgSize);
		newmsg->size	= msgSize;
		newmsg->count	= count;

		if(count)
		{
			bzero(newmsg->data, sizeof(MineTarget) * count);
		}
		return newmsg;
	}
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_MINEROBMSG__
