/********************************************************************************
 * 文件名：MartMsg.h
 * 创建人：宋斌
 * 创建时间：2015-1-15
 * 版本：1.0
 * 本文件版本号：1.0
 * 最后更新：
 * 功能说明：限购
 * 历史修改记录：
 * <author>  <time>           <version >   <desc>
 *********************************************************************************/
#ifndef __NXCORE_MART_MSG_H__
#define __NXCORE_MART_MSG_H__

#include <MsgDefine.h>
#ifndef __SGROBOT__
#include <MemRoster.h>
#endif

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * \brief 限购操作
 */
struct MartOpCSMSg: public PlayerMsg
{
    enum { id = 0xB40};

	uint32	op;				// 1:获取限购列表	返回 MartListSMsg
							// 2:购买道具		param1=道具Id param2=数目
	uint32	param1;
	uint32	param2;
	uint32	ret;			// 返回值 0:表示成功 否则失败

    MartOpCSMSg()
        : PlayerMsg(id, sizeof(*this))
		, op(0)
		, param1(0)
		, param2(0)
		, ret(0)
    {

	}
};

/**
 * \brief 限购列表
 */
struct MartListSMsg: public PlayerMsg
{
    enum { id = 0xB41};

	uint32 count;								// 总数

	struct tarTarget
	{
		uint32	itemId;							// 道具Id
		uint32	times;							// 已经购买的次数
		uint32	totalTimes;						// 总共购买的次数
	} data[0];

    MartListSMsg()
        : PlayerMsg(id, sizeof(*this))
		, count(0)
    {
		bzero(data, sizeof(data));
	}

	uint16 getSize() const
	{
		return sizeof(*this) + sizeof(data[0]) * count;
	}

	static MartListSMsg* create(uint16 count)
	{
		// 统计消息的长度
		uint16 msgSize	= sizeof(MartListSMsg) + sizeof(tarTarget) * count;

		NEW_MSG(MartListSMsg, msgSize);
		newmsg->size	= msgSize;
		newmsg->count	= count;

		if(count)
		{
			bzero(newmsg->data, sizeof(tarTarget) * count);
		}
		return newmsg;
	}
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_MART_MSG_H__
