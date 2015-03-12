#ifndef __NXCORE_RES_CASH__
#define __NXCORE_RES_CASH__

#include <vector>
#include <algorithm>
#include <DataTable.h>
#include <Define.h>
#include <Helper.h>
#include <LootType.h>
#include <DBEntity.h>

USING_NXCORE

#define siCashTable Singleton<DataTable<CashBase> >::getInstance()
#define siCashRewardTable Singleton<DataTable<CashRewardBase> >::getInstance()

#pragma pack(push, 1)

struct CashBase {
    typedef DWORD KEY_TYPE;

    DWORD ID;
    DWORD CostType;
    DWORD Cost;
    DWORD Time;
    DWORD RobLimit;
    DWORD RobMin;
    DWORD RobMax;
    DWORD LootID;
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }
};

struct CashRewardBase {
    typedef DWORD KEY_TYPE;

    DWORD ID;
    DWORD Reward[3];
    
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
    typedef DWORD KEY_TYPE;

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
