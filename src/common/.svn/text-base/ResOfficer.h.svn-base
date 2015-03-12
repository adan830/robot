#ifndef __NXCORE_RES_OFFICER__
#define __NXCORE_RES_OFFICER__

#include <vector>
#include <algorithm>
#include <DataTable.h>
#include <Define.h>
#include <Helper.h>
#include <LootType.h>
#include <DBEntity.h>
#include <VarMacros.h>

USING_NXCORE

#define siOfficerTable Singleton<DataTable<OfficerBase> >::getInstance()
#define siCardAppointTable Singleton<DataTable<CardAppointBase> >::getInstance()
#pragma pack(push, 1)

struct OfficerBase
{
    typedef BYTE KEY_TYPE;

	DWORD	ID;					// ID
	DWORD	LevelLimit;			// 等级限制
	DWORD	Renown;				// 声望要求
	DWORD	OfficerLimit;		// 人数限制
	DWORD	MonsterGID;			// 战役ID
	DWORD	Money;				// 可领俸禄（铜币）
	DWORD	PVPLimit;			// 权斗次数
	DWORD	PVPreward1;			// 权斗挑战同品玩家胜利获得声望
	DWORD	PVPreward2;			// 权斗挑战高一品玩家胜利获得声望
	DWORD	PVPreward3;			// 权斗挑战高二品玩家胜利获得声望
	DWORD	PVPreward4;			// 权斗挑战低一品玩家胜利获得声望
	DWORD	ReductionPrestige;	// 权斗失败扣除的声望值
	DWORD	WorshipCnt;			// 俯首次数
	DWORD	WorshipReward;		// 俯首获得声望数
	DWORD	IncreasePrestige;	// 被俯首的玩家增加的声望值
	DWORD	AwardCnt;			// 赏赐次数
	DWORD	AwardCost;			// 赏赐消耗铜币数
	DWORD	AwardReward;		// 赏赐获得声望数
	DWORD	PromoteCnt;			// 提拔次数
	DWORD	DemoteCnt;			// 贬职次数

    struct ExtCells 
	{

	};

	DWORD PVPRenownReward[4];

	KEY_TYPE getId()
	{
		return ID;
	}

	size_t getFixSize()
	{
		return ((char*)&DemoteCnt - (char*)this) + sizeof(DemoteCnt);
	}

	size_t getExtSize()
	{
		return 0;
	}

	bool parse(ExtCells* ext)
	{
		//DEBUG_LOG("OfficerTable: %u\n", getId());

		RewardAssign(1);
		RewardAssign(2);
		RewardAssign(3);
		RewardAssign(4);

		return true;
	}

	bool check()
	{
		return true;
	}
};

struct CardAppointBase
{
    typedef DWORD KEY_TYPE;

    DWORD ID;
    struct {
        BYTE type; 
        DWORD value;
    } Attr[6];
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }
};

#if 0
struct SampleBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD CardID;
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }
};
#endif

#pragma pack(pop)

#endif//__NXCORE_RESOURCE__
