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
	DWORD	LevelLimit;			// �ȼ�����
	DWORD	Renown;				// ����Ҫ��
	DWORD	OfficerLimit;		// ��������
	DWORD	MonsterGID;			// ս��ID
	DWORD	Money;				// ����ٺ»��ͭ�ң�
	DWORD	PVPLimit;			// Ȩ������
	DWORD	PVPreward1;			// Ȩ����սͬƷ���ʤ���������
	DWORD	PVPreward2;			// Ȩ����ս��һƷ���ʤ���������
	DWORD	PVPreward3;			// Ȩ����ս�߶�Ʒ���ʤ���������
	DWORD	PVPreward4;			// Ȩ����ս��һƷ���ʤ���������
	DWORD	ReductionPrestige;	// Ȩ��ʧ�ܿ۳�������ֵ
	DWORD	WorshipCnt;			// ���״���
	DWORD	WorshipReward;		// ���׻��������
	DWORD	IncreasePrestige;	// �����׵�������ӵ�����ֵ
	DWORD	AwardCnt;			// �ʹʹ���
	DWORD	AwardCost;			// �ʹ�����ͭ����
	DWORD	AwardReward;		// �ʹͻ��������
	DWORD	PromoteCnt;			// ��δ���
	DWORD	DemoteCnt;			// ��ְ����

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
