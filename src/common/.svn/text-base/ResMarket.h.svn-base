#ifndef __NXCORE_RES_MARKET_H__
#define __NXCORE_RES_MARKET_H__

#include <vector>
#include <DataTable.h>
#include <Define.h>
#include <Helper.h>
#include <VarMacros.h>
#include <Base.h>
#include <vector>
#include <Common_Utility.h>
#include "../SceneServer/hd_Tools.h"

USING_NXCORE

#pragma pack(push, 1)

#define siMartTreasureTable Singleton<DataTable<MartTreasureBase> >::getInstance()



#define siMartTreasureItemTable Singleton<DataTable<MartTreasureItemBase> >::getInstance()

/**
 * \brief MartTreasureItem表结构定义
 */
struct MartTreasureItemBase
{
	typedef DWORD KEY_TYPE;
	
	DWORD	Id;				// 寻宝编号Id
	DWORD	itemId;			// 道具id
	DWORD	itemType;		// 物品类型
	DWORD	BuyType;		// 货币铜钱元宝
	DWORD	ProPrice;		// 原始价格
	DWORD	DisCount;		// 折扣数
	DWORD	LimitedTimes;	// 限购次数
	DWORD	LimitedCount;	// 限购份数总数

	struct ExtCells
	{

	};

	KEY_TYPE getId()
	{
		return Id;
	}

	size_t getFixSize()
	{
		return ((char*)&LimitedCount - (char*)this) + sizeof(LimitedCount);
	}

	size_t getExtSize()
	{
		return 0;
	}

	bool parse(ExtCells* ext)
	{
		//DEBUG_LOG("MartTreasureItemTable: %u\n", getId());

		return true;
	}

	bool check()
	{
		return true;
	}	
};

/**
 * \brief MartTreasure表结构定义
 */
struct MartTreasureBase
{
	typedef DWORD KEY_TYPE;

	DWORD	ID;			// ID
	DWORD	NextId;		// 下次开放编号
	DWORD	Day1;		// 星期1
	DWORD	Day2;		// 星期2
	DWORD	Day3;		// 星期3
	DWORD	Day4;		// 星期4
	DWORD	Day5;		// 星期5
	DWORD	Day6;		// 星期6
	DWORD	Day7;		// 星期7

	struct ExtCells
	{
		CHAR	StarTtime[128];		// 开始时间段
		CHAR	SverTime[128];		// 结束时间段（时分秒）
		CHAR	ItemLoots[256];		// 道具id_1,物品类型,货币铜钱元宝,原始价格,折扣数,限购次数,限购份数总数
	};

	time_t BeginTime;				// 开始时间
	time_t EndTime;					// 结束的时间
	std::vector<tagItem> itemList;	// 道具列表信息

    static uint32 EveryDayBegin;
    static uint32 EveryDayEnd;
    static uint32 EveryWeekBegin;
    static uint32 EveryWeekEnd;
    
	KEY_TYPE getId()
	{
		return ID;
	}

	size_t getFixSize()
	{
		return ((char*)&Day7 - (char*)this) + sizeof(Day7);
	}

	size_t getExtSize()
	{
		return sizeof(ExtCells);
	}

	bool parse(ExtCells* ext)
	{
		//DEBUG_LOG("MartTreasureTable: %u\n", getId());
		BeginTime	= HD_Tools::GetGlobalTime2(ext->StarTtime, false);
		EndTime		= HD_Tools::GetGlobalTime2(ext->SverTime, false);

		itemList = getItemList(ext->ItemLoots);

        if (ID == 1)
        {
            EveryDayBegin = BeginTime;
            EveryDayEnd   = EndTime;
        }
        else if (ID == 8)
        {
            EveryWeekBegin = BeginTime;
            EveryWeekEnd   = EndTime;
        }
		return true;
	}

	// 将字符串转换成道具
	std::vector<tagItem> getItemList(std::string strItem)
	{
		std::vector<tagItem> list;

		std::vector<uint32> valList = Common::TransToValueVector<uint32>(strItem, "|");
		for (uint32 i = 0; i < valList.size(); ++i)
		{
			// 找到对应的记录
			MartTreasureItemBase* pBase = siMartTreasureItemTable.find(valList[i]);
			if (pBase)
			{
				tagItem item;
				item.id				= pBase->getId();
				item.curMaxTimes	= 0;
				item.overdueTime	= EndTime;

				list.push_back(item);
			}
		}

		return list;
	}

	// 判断是否在活动时间之内
	bool isInTimeRange()
	{
		// 检查是否在大的时间范围之内
		time_t curTime = time(0);
		if ((curTime >= BeginTime) && (curTime <= EndTime))
		{
			// 检查是否在限制的星期之内
			std::vector<uint32> weekList;
			weekList.push_back(Day1);
			weekList.push_back(Day2);
			weekList.push_back(Day3);
			weekList.push_back(Day4);
			weekList.push_back(Day5);
			weekList.push_back(Day6);
			weekList.push_back(Day7);

			return HD_Tools::IsInWeekList(weekList);
		}

		return false;
	}

	bool check()
	{
		return true;
	}
};

#pragma pack(pop)

#endif//__NXCORE_RES_MARKET_H__
