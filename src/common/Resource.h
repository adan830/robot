#ifndef __NXCORE_RESOURCE__
#define __NXCORE_RESOURCE__

#include <vector>
#include <algorithm>
#include <DataTable.h>
#include <Define.h>
#include <Helper.h>
#include <LootType.h>
#include <DBEntity.h>

USING_NXCORE

typedef char CHAR;

#define siCardBaseTable Singleton<DataTable<CardBase> >::getInstance()
#define siSkillTable Singleton<DataTable<SkillBase> >::getInstance()
#define siSkillEffectTable Singleton<DataTable<SkillEffectBase> >::getInstance()
#define siStaticSkillTable Singleton<DataTable<StaticSkillBase> >::getInstance()
#define siExtraStrikeTable Singleton<DataTable<ExtraStrikeBase> >::getInstance()
#define siTargetTable Singleton<DataTable<TargetBase> >::getInstance()
#define siPlayerLevelTable Singleton<DataTable<PlayerLevelBase> >::getInstance()
#define siMonsterTable Singleton<DataTable<MonsterBase> >::getInstance()
#define siMonsterGroupTable Singleton<DataTable<MonsterGroupBase> >::getInstance()
#define siSmallLevelTable Singleton<DataTable<SmallLevelBase> >::getInstance()
#define siFirstBonusTable Singleton<DataTable<FirstBonusBase> >::getInstance()
#define siSmallBonusTable Singleton<DataTable<SmallBonusBase> >::getInstance()
#define siFormationTable Singleton<DataTable<FormationBase> >::getInstance()
#define siMonsterFormationTable Singleton<DataTable<MonsterFormationBase> >::getInstance()
#define siLootTable Singleton<DataTable<LootBase> >::getInstance()
#define siLvlupTable Singleton<DataTable<LvlupBase> >::getInstance()
#define siEvolutionTable Singleton<DataTable<EvolutionBase> >::getInstance()
#define siSkillUpgradeTable Singleton<DataTable<SkillUpgradeBase> >::getInstance()
#define siRuneTable Singleton<DataTable<RuneBase> >::getInstance()
#define siStarTable Singleton<DataTable<StarBase> >::getInstance()
#define siBigLevelTable Singleton<DataTable<BigLevelBase> >::getInstance()
#define siBigBonusTable Singleton<DataTable<BigBonusBase> >::getInstance()
#define siObjectTable Singleton<DataTable<ObjectBase> >::getInstance()
#define siEquipTable Singleton<DataTable<EquipBase> >::getInstance()
#define siEquipLvlupTable Singleton<DataTable<EquipLvlupBase> >::getInstance()
#define siGachaTable Singleton<DataTable<GachaBase> >::getInstance()
#define siGachaBonusTable Singleton<DataTable<GachaBonusBase> >::getInstance()
#define siLoveTable Singleton<DataTable<LoveBase> >::getInstance()
#define siGameSettingsTable Singleton<DataTable<GameSettingsBase> >::getInstance()
#define siInitialTable Singleton<DataTable<InitialBase> >::getInstance()
#define siCardProduceTable Singleton<DataTable<CardProduceBase> >::getInstance()
#define siCardChipsTable Singleton<DataTable<CardChipsBase> >::getInstance()
#define siEquipProduceTable Singleton<DataTable<EquipProduceBase> >::getInstance()
#define siEquipChipsTable Singleton<DataTable<EquipChipsBase> >::getInstance()
#define siSundryTable Singleton<DataTable<SundryBase> >::getInstance()
#define siStarMissionTable Singleton<DataTable<StarMissionBase> >::getInstance()
#define siArenaBaseTable Singleton<DataTable<ArenaBase> >::getInstance()
#define siArenaDailyRewardTable Singleton<DataTable<ArenaDailyRewardBase> >::getInstance()
#define siArenaWeekRewardTable Singleton<DataTable<ArenaWeekRewardBase> >::getInstance()
#define siMissionTable Singleton<DataTable<MissionBase> >::getInstance()
#define siGiftTable Singleton<DataTable<GiftBase> >::getInstance()
#define siVipTable Singleton<DataTable<VipBase> >::getInstance()
#define siFriendTable Singleton<DataTable<FriendBase> >::getInstance()
#define siVipTimesTable Singleton<DataTable<VipTimesBase> >::getInstance()
#define siSignTable Singleton<DataTable<SignBase> >::getInstance()
#define siSignCostTable Singleton<DataTable<SignCostBase> >::getInstance()
#define siMulSignTable Singleton<DataTable<MulSignBase> >::getInstance()
#define siUnlockTable Singleton<DataTable<UnlockBase> >::getInstance()
#define siGmTable Singleton<DataTable<GmBase> >::getInstance()
#define siVipEquipCritTable Singleton<DataTable<VipEquipCritBase> >::getInstance()
#define siBabelTable Singleton<DataTable<BabelBase> >::getInstance()
#define siArenaRankRewardTable Singleton<DataTable<ArenaRankRewardBase> >::getInstance()
#define siAchievementTable Singleton<DataTable<AchievementBase> >::getInstance()
#define siArenaRobotTable Singleton<DataTable<ArenaRobotBase> >::getInstance()
#define siTopUpTable Singleton<DataTable<TopUpBase> >::getInstance()
#define siGrabMineTable Singleton<DataTable<GrabMineBase> >::getInstance()
#define siLandingRewardTable Singleton<DataTable<LandingRewardBase> >::getInstance()

///~RESOURCE_TABLE_DEFINE_END

#define MAKE_WORD(hbyte,lbyte) ((((uint16)hbyte) << 8) | (lbyte))
#define MAKE_DWORD(hword,lword) ((((uint32)hword) << 16) | (lword))
#define MAKE_UINT64(hdword,ldword) ((((uint64)hdword) << 32) | (ldword))

/**
 * 将byte,byte,word转换成dword
 */
#define MAKE_DWORD_BBW(byte_a, byte_b, lword)   \
	((((unsigned int)byte_a) << 24) |           \
	 (((unsigned int)byte_b) << 16) |           \
	 (lword))
#define HIWORD(dword)	(((uint16)((((uint32)(dword)) >> 16) & 0xffff)))
#define LOWORD(dword) (((uint16)(((uint32)(dword)) & 0xffff)))
#define HIBYTE(word)	(((uint8)((((uint16)(word)) >> 8) & 0xff)))
#define LOBYTE(word) (((uint8)(((uint16)(word)) & 0xff)))

#define HIDWORD(i64)	(((uint32)((((uint64)(i64)) >> 32) & 0xffffffff)))
#define LODWORD(i64) (((uint32)(((uint64)(i64)) & 0xffffffff)))

#pragma pack(push, 1)

struct TableBase {
    struct ExtCells {};
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }
};

struct SkillObject {};
/**
 * \brief StaticSkill表结构定义
*/
struct StaticSkillBase
{
	typedef WORD KEY_TYPE;

	struct SkillPropInfo
	{
		BYTE	PropType;	//目标属性ID
		BYTE	ChangeType;	//目标算法ID1. 减少2. 增加
		WORD	ValuePer;	//目标效果%
		WORD	Value;		//目标效果值
	};

	WORD	ID;	//ID
	WORD	PowerRate;	//技能战力百分比*100，计算时除以100
	SkillPropInfo SkillProps[3];	//技能属性

	struct ExtCells
	{

	};

	KEY_TYPE getId()
	{
		return ID;
	}

	size_t getFixSize()
	{
		return sizeof(*this);
	}

	size_t getExtSize()
	{
		return 0;
	}

	bool parse(ExtCells* ext)
	{
		DEBUG_LOG("StaticSkillTable: %u\n", getId());
		return true;
	}

	bool check()
	{
		return true;
	}

};


/**
* \brief ExtraStrike表结构定义
*/
struct ExtraStrikeBase
{
	typedef WORD KEY_TYPE;

	WORD	ID;	//ID
	WORD	Condition ;	//促发条件类型1. 武将ID2. 武将星级3. 武将性别4. 武将职业属性5. 武将职业6. 武将阵营7. 武力区间8. 统率区间9. 智力区间
		
	VECTOR_CONTAINER(uint32) paramVect;
	struct ExtCells
	{
		char	Param[500];	//促发条件参数1

	};

	KEY_TYPE getId()
	{
		return ID;
	}

	size_t getFixSize()
	{
		return 4;
	}

	size_t getExtSize()
	{
		return sizeof(ExtCells);
	}

	bool parse(ExtCells* ext)
	{
		DEBUG_LOG("ExtraStrikeTable: %u\n", getId());
		ext->Param[499] = '\0';
        Helper::ArrayBuffer<uint32> arrbuf;
        Helper::splitInto(arrbuf, ext->Param, "|");
        for(uint8 i= 0; i<arrbuf.size(); i++)
        {
			paramVect.push_back(arrbuf[i]);
		}

		return true;
	}
	
	uint32 getParam(uint8 index)
	{
		if (paramVect.size() > index)
		  return paramVect[index];

		return 0;
	}

	bool findParam(uint32 param, uint8 start = 1)
	{
		VECTOR_CONTAINER(uint32)::iterator iter = paramVect.begin();
		uint8 index = 0;
		for (; iter != paramVect.end(); ++iter, ++index)
		{
			if (index >= start && param == *iter)
			{
				return true;
			}
		}

		return false;
	}

	bool check()
	{
		return true;
	}

};

/**
 * \brief SkillEffectTable
 */
struct SkillEffectBase
{
	typedef DWORD KEY_TYPE;
	
	DWORD	ID;
    DWORD   effectID;
    DWORD   ExtraStrikeID;
	WORD	StrikePer;
    BYTE    triggerToge;
	BYTE	CalculatSeq;
	WORD	EffectType;
	BYTE	ChangeType;
	DWORD	Param1;
	DWORD	Param2;
	DWORD	Param3;
	DWORD	Param4;
	DWORD	Param5;
	DWORD	Param6;
	DWORD	Param7;
	
	ExtraStrikeBase* pExtraStrikeBase;
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;                      }
	size_t getFixSize()       {return sizeof(SkillEffectBase) - sizeof(pExtraStrikeBase); }
	size_t getExtSize()       {return 0;                       }
	bool parse(ExtCells* ext) 
	{
		if (ExtraStrikeID != 0)
		{
			pExtraStrikeBase = siExtraStrikeTable.find(ExtraStrikeID);
			if (pExtraStrikeBase == NULL)
			{
				ERROR_LOG("SkillEffect:%u can't find ExtraStrike :%u\n", ID, ExtraStrikeID);
				return false;
			}
		}
#ifdef __DEBUG__
        if (ID == 30060)
        {
            StrikePer = 10000;
        }
#endif
		return true;                    
	}
	bool check()              {return true;                    }
};


/**
 * \brief TargetTable
 */
struct TargetBase
{
	typedef WORD KEY_TYPE;
	
	WORD	ID;
	BYTE	region;
	BYTE	refPoint;
	BYTE	matrixType;
	WORD	matrixValue;

	struct ExtCells {};
	KEY_TYPE getId()    {return ID;                 }
	size_t getFixSize() {return sizeof(TargetBase); }
    size_t getExtSize() {return 0;                  }

	bool parse(ExtCells* ext) {
        DEBUG_LOG("target:%u region:%u refPoint:%u matrixType:%u matrixValue:%u\n", ID, region, 
                  refPoint, matrixType, matrixValue);
        return true;
    }
	bool check() {return true;}
};

/**
 * \brief SkillTable
 */
struct SkillBase
{
	typedef WORD KEY_TYPE;
	
	WORD	ID;
    BYTE	skillType;				//技能类型 1主动 2被动 3普攻 4队长技 5组合技
    BYTE	releaseRound;			//释放回合数
	BYTE	CD;						//冷却回合数
    WORD    powerRate;
    DWORD   powerNum;

	struct ExtCells
	{
		WORD	target1;
		DWORD	target1Effect;
		DWORD	target1buff;
		DWORD	target1extra;
		WORD	target2;
		DWORD	target2Effect;
		DWORD	target2buff;
		DWORD	target2extra;
		WORD	target3;
		DWORD	target3Effect;
		DWORD	target3buff;
		DWORD	target3extra;
	};

	struct
	{
		TargetBase* pTarget;
		SkillEffectBase* pEffects[3];
	}targetEffects[3];
	KEY_TYPE getId() {return ID;}
	size_t getFixSize() {return 11;}
	size_t getExtSize() {return sizeof(ExtCells);}

	bool parse(ExtCells* ext) {
        DEBUG_LOG("SkillTable ID %u\n", getId());
        bzero(targetEffects, sizeof(targetEffects));
        if(ext->target1)
        {
            targetEffects[0].pTarget = siTargetTable.find(ext->target1);
#ifndef __DEBUG__
            DEBUG_LOG("skill %u target %u \n", getId(), ext->target1);
            if(!targetEffects[0].pTarget)
            {
                ERROR_LOG("skill %u target1 %u not find\n", getId(), ext->target1);
                return false;
            }
#endif
        }
		
        if (ext->target1Effect)
        {
            targetEffects[0].pEffects[0] = siSkillEffectTable.find(ext->target1Effect);
#ifndef __DEBUG__
            if (!targetEffects[0].pEffects[0])
            {
                ERROR_LOG("skill %u effect1 %u not find\n", getId(), ext->target1Effect);
                return false;
            }
#endif
        }
        
        if (ext->target1buff)
        {
            targetEffects[0].pEffects[1] = siSkillEffectTable.find(ext->target1buff);
            if (!targetEffects[0].pEffects[1])
            {
                ERROR_LOG("skill %u buff1 %u not find\n", getId(), ext->target1buff);
                return false;
            }
        }
		
        if (ext->target1extra)
        {
            targetEffects[0].pEffects[2] = siSkillEffectTable.find(ext->target1extra);
            if (!targetEffects[0].pEffects[2])
            {
                ERROR_LOG("skill %u extra1 %u not find\n", getId(), ext->target1extra);
                return false;
            }
        }
        
        if(ext->target2)
        {
            targetEffects[1].pTarget = siTargetTable.find(ext->target2);
#ifndef __DEBUG__
            DEBUG_LOG("skill %u target2 %u \n", getId(), ext->target2);
            if(!targetEffects[1].pTarget)
            {
                ERROR_LOG("skill %u target2 %u not find\n", getId(), ext->target2);
                return false;
            }
#endif
        }
		
        if (ext->target2Effect)
        { 
           targetEffects[1].pEffects[0] = siSkillEffectTable.find(ext->target2Effect);
#ifndef __DEBUG__
            if (!targetEffects[1].pEffects[0])
            {
                ERROR_LOG("skill %u effect2 %u not find\n", getId(), ext->target2Effect);
                return false;
            }
#endif
        }
        
        if (ext->target2buff)
        {
            targetEffects[1].pEffects[1] = siSkillEffectTable.find(ext->target2buff);
            if (!targetEffects[1].pEffects[1])
            {
                ERROR_LOG("skill %u buff2 %u not find\n", getId(), ext->target2buff);
                return false;
            }
        }
		
        if (ext->target2extra)
        {
            targetEffects[1].pEffects[2] = siSkillEffectTable.find(ext->target2extra);
            if (!targetEffects[1].pEffects[2])
            {
                ERROR_LOG("skill %u extra2 %u not find\n", getId(), ext->target2extra);
                return false;
            }
        }
        
		if(ext->target3)
        {
            targetEffects[2].pTarget = siTargetTable.find(ext->target3);
#ifndef __DEBUG__
            DEBUG_LOG("skill %u target3 %u \n", getId(), ext->target3);
            if(!targetEffects[2].pTarget)
            {
                ERROR_LOG("skill %u target2 %u not find\n", getId(), ext->target3);
                return false;
            }
#endif
        }
		
        if (ext->target3Effect)
        {
            targetEffects[2].pEffects[0] = siSkillEffectTable.find(ext->target3Effect);
#ifndef __DEBUG__
            if (!targetEffects[2].pEffects[0])
            {
                ERROR_LOG("skill %u effect3 %u not find\n", getId(), ext->target3Effect);
                return false;
            }
#endif
        }
        
        if (ext->target3buff)
        {
            targetEffects[2].pEffects[1] = siSkillEffectTable.find(ext->target3buff);
            if (!targetEffects[2].pEffects[1])
            {
                ERROR_LOG("skill %u buff3 %u not find\n", getId(), ext->target3buff);
                return false;
            }
        }
		
        if (ext->target3extra)
        {
            targetEffects[2].pEffects[2] = siSkillEffectTable.find(ext->target3extra);
            if (!targetEffects[2].pEffects[2])
            {
                ERROR_LOG("skill %u extra3 %u not find\n", getId(), ext->target3extra);
                return false;
            }
        }
        return true;
    }

	bool check() {return true;}
};

struct ObjectBase
{
    typedef DWORD KEY_TYPE;
    
    WORD id;
    BYTE activeType;
    struct {
        BYTE type;
        DWORD param;
    } trigger[2];
    DWORD moneyBase;
    
    struct ExtCells {};
	KEY_TYPE getId() {return id;}
	size_t getFixSize() {return sizeof(*this);}
	size_t getExtSize() {return 0;}
	bool parse(ExtCells* ext) {
        DEBUG_LOG("EquipTable id %u\n", id);
        return true;
    }
	bool check() {return true;}
};

struct EquipBase
{
    typedef WORD KEY_TYPE;
    
    WORD  id;
    BYTE  objectType;
    BYTE  EquipType;
    BYTE  star;
    WORD  useLevel;
    WORD  chipsNum;
    DWORD chipsMoney;
    DWORD moneyBase;
    struct {
        BYTE type;
        DWORD num;
        DWORD gr; 
    } act[3];

    WORD power;
    WORD agile;
    WORD wisdom;
    DWORD sale;
    DWORD soulstone;
    
    struct ExtCells {};
	KEY_TYPE getId()    {return id;            }
	size_t getFixSize() {return sizeof(*this); }
	size_t getExtSize() {return 0;             }
	bool parse(ExtCells* ext) {
        DEBUG_LOG("EquipTable id %u\n", id);
        return true;
    }
	bool check() {return true;}
};

struct LoveBase
{
    typedef WORD KEY_TYPE;

    WORD   ID;
    WORD   equip;
    BYTE   propType1;
    WORD   value1;
    WORD   value2;
    BYTE   propType2;
    WORD   value3;
    WORD   value4;
    char   cardstr[64];

    FightProperties   fightProps;
    FightPropsPercent fightPropsPerc;

    typedef VECTOR_CONTAINER(uint16) vec_lovecards;
    vec_lovecards cards;
    
    struct ExtCells {};

    KEY_TYPE getId() {return ID;}
    size_t getFixSize() {
        return ((char*)cardstr - (char*)this) + sizeof(cardstr);
    }
    size_t getExtSize() {return 0;}
    bool parse(ExtCells* ext) {
        Helper::ArrayBuffer<uint16> buf;
        Helper::splitInto(buf, cardstr, "|");

        for (uint16 i = 0; i < buf.size(); ++i)
        {
            cards.push_back(buf[i]);
            DEBUG_LOG("LoveTable Cards %u\n", buf[i]);
        }
        TRACE_LOG("LoveTable %u\n", ID);
        fightPropsPerc.zero();
        fightPropsPerc.AddProps(FightPropIndex(propType1), value1);
        fightProps.AddProps(FightPropIndex(propType1),     value2);
        fightPropsPerc.AddProps(FightPropIndex(propType2), value3);
        fightProps.AddProps(FightPropIndex(propType2),     value4);
        return true;
    }
	bool check() {return true;}
};

typedef LoveBase ComradeBase;

/**
 * \brief CardBaseTable
 */

struct CardBase
{
	typedef WORD KEY_TYPE;
	
	WORD	ID;					//ID
	WORD	heroKey;			//武将ID
	BYTE	star;				//星级
    BYTE    sexID;              //性别ID
	BYTE	attribute;			//属性1.力	2.敏 3.智
	BYTE	career;				//职业1猛将2力士3豪杰4游侠5方士6策士
    BYTE    nationality;
    WORD    power;
    WORD    powerGr;
    WORD    agile;
    WORD    agileGr;
    WORD    wisdom;
    WORD    wisdomGr;
    WORD    chipsNum;           //合成碎片消耗
    DWORD   chipsMoney;         //合成铜钱消耗
	WORD	expBase;			//合成经验基数
	WORD	moneyBase;			//出售铜钱基数
	BYTE	leadPoint;			//消费领导力
    BYTE    leadPointGr;        //领导力成长
	BYTE	expType;			//经验值类型
	BYTE	limitLv;			//等级上限
	BYTE	speed;				//速度
	DWORD	HP;					//血量
	DWORD	HPGr;				//血量成长
	DWORD	MP;					//魔法
	DWORD	MPGr;				//魔法成长
	DWORD	ATK;				//攻击力
	DWORD	ATKGr;				//攻击力成长
	WORD	defence;			//护甲
	WORD	defenceGr;			//护甲成长
    WORD    defencePen;         //破甲
    WORD    defencePenGr;       //破甲成长
	WORD	mdefence;			//法抗
	WORD	mdefenceGr;			//法抗成长
    WORD    mdefencePen;        //基础法穿
    WORD    mdefencePenGr;      //法穿成长
	WORD	crit;				//暴击
    WORD    critGr;
	WORD	toughness;			//韧性
    WORD    toughnessGr;
	WORD	accuracy;			//命中
    WORD    accuracyGr;
	WORD	dodge;				//闪避
    WORD    dodgeGr;
	WORD	ATKID;				//普通攻击ID
	WORD	skillID;			//主动技能ID
	SkillUnlock	skillUnlock[MAX_SKILL_UNLOCK_COUNT];		//主动技能解锁
    TriggerSkillUnlock pSkillUnlock[MAX_PSKILL_UNLOCK_COUNT];	//被动技能解锁
	WORD	pieceID;			//碎片编号
	WORD	pieceNum;			//碎片数量
    DWORD   cardCombo[MAX_COMBO_SKILL];       //情缘关系表
	DWORD   sale;
    DWORD   rankcost;
    DWORD   soulstone;
    
	SkillBase* pAttackSkillBase;
	SkillBase* pSkillBase;
    SkillBase* pActSkillBase[MAX_SKILL_UNLOCK_COUNT];		//主动技能解锁
    StaticSkillBase* pUnActSkillBase[MAX_PSKILL_UNLOCK_COUNT];		//被动技能解锁
    SkillBase* pTriggerSkillBase[MAX_PSKILL_UNLOCK_COUNT];		// 战斗中触发的被动
    
    ComradeBase* pCombo[MAX_COMBO_SKILL];
    
	struct ExtCells     {};
	KEY_TYPE getId()    {return ID; }
	size_t getFixSize() {return ((char*)&soulstone - (char*)this) + sizeof(soulstone); }
	size_t getExtSize() {return 0;}
	bool parse(ExtCells* ext) {
        DEBUG_LOG("CardBaseTable ID %u\n", getId());
        pAttackSkillBase = siSkillTable.find(ATKID);
        if (!pAttackSkillBase)
        {
            ERROR_LOG("cardBase %u ATKID %u not find\n", getId(), ATKID);
            return false;
        }
        if (skillID != 0)
        {
            pSkillBase = siSkillTable.find(skillID);
            if (!pSkillBase)
            {
                ERROR_LOG("cardBase %u SkillD %u not find\n", getId(), skillID);
                return false;
            }
        }
        else
        {
            pSkillBase = NULL;
        }
        
        for (int i = 0; i < MAX_SKILL_UNLOCK_COUNT; ++i)
        {
            SkillUnlock cond = skillUnlock[i];
            
            SkillBase* pSkillBase = siSkillTable.find(cond.skillId);
            if (cond.skillId > 0 && pSkillBase == NULL)
            {
                ERROR_LOG("cardBase %u 主动技能 %u 没有对应配置\n",
                          getId(), cond.skillId);
                return false;
            }
            
            EquipBase* pEquip = siEquipTable.find(cond.unlockEquip);
            if (cond.unlockEquip > 0 && pEquip == NULL)
            {
                ERROR_LOG("cardBase %u 主动技能 %u 的解锁装备 %u 没有对应配置\n",
                          getId(), cond.skillId, cond.unlockEquip);
                return false;
            }
            pActSkillBase[i] = pSkillBase;
        }
        
        for (int i = 0; i < MAX_PSKILL_UNLOCK_COUNT; ++i)
        {
            TriggerSkillUnlock cond = pSkillUnlock[i];
            StaticSkillBase* pStatic = siStaticSkillTable.find(cond.skillId);
            SkillBase* pSkill = siSkillTable.find(cond.skillId);
            
            if (cond.unlockEquip > 0 && siEquipTable.find(cond.unlockEquip) == NULL)
            {
                ERROR_LOG("cardBase %u 被动技能 %u 的解锁装备 %u 没有对应配置\n",
                          getId(), cond.skillId, cond.unlockEquip);
                return false;
            }
            
            if (cond.touchType == 1)
            {
                if (cond.skillId > 0 && pStatic == NULL)
                {
                    ERROR_LOG("cardBase %u 被动技能 %u 没有对应配置\n",
                              getId(), cond.skillId);
                    return false;
                }
                else
                {
                    pUnActSkillBase[i] = pStatic;
                }
            }
            
            if (cond.touchType == 2)
            {
                if (cond.skillId > 0 && pSkill == NULL)
                {
                    ERROR_LOG("cardBase %u 被动技能 %u 没有对应配置\n",
                              getId(), cond.skillId);
                    return false;
                }
                else
                {
                    pTriggerSkillBase[i] = pSkill;
                }
            }
        }
        
        for (int i = 0; i < MAX_COMBO_SKILL; ++i)
        {
            if (cardCombo[i] != 0)
            {
                pCombo[i] = siLoveTable.find(cardCombo[i]);
                if (!pCombo[i])
                {
                    DEBUG_LOG("卡牌 %u 的情缘没有找到 情缘ID %u\n", ID,  cardCombo[i]);
                    return false;
                }
                else
                {
                    DEBUG_LOG("cardCombo %u finded\n", cardCombo[i]);
                }
            }
        }
        TRACE_LOG("CardTable Id %u 血量成长 %u\n", ID, HPGr);
        return true;
    }
    
	bool check() {return true;}
};

/**
 * \brief MonsterTable
 */
struct MonsterBase
{
	typedef DWORD KEY_TYPE;
	
	DWORD	ID;					//ID
	DWORD	cardID;				//怪物卡牌ID
	BYTE	level;				//等级
    BYTE    rank;               //怪物卡品阶
	BYTE	career;				//职业1猛将2力士3豪杰4游侠5方士6策士
	BYTE	speed;				//速度
	DWORD	HP;					//血量
	DWORD	MP;					//法力
	DWORD	ATK;				//攻击力
	WORD	crit;				//暴击值
	WORD	toughness;			//韧性
	WORD	accuracy;			//命中值
	WORD	dodge;				//闪避值
	WORD	defence;			//物防
	WORD	mdefence;			//法防
	WORD	critDmgAmend;		//暴击伤害修正

	struct ExtCells {}; 
	KEY_TYPE getId()          {return ID;            } 
	size_t getFixSize()       {return sizeof(*this); } 
	size_t getExtSize()       {return 0;             } 
	bool parse(ExtCells* ext) {
        DEBUG_LOG("MonsterTable ID %u\n", ID);
        return true;
    } 
	bool check()              {return true;          }
};

/**
 * \brief MonsteriGroupTable
 */
struct MonsterGroupBase
{
	typedef WORD KEY_TYPE;
	
	WORD	ID;
	BYTE	formation;			//阵型

	struct ExtCells
	{
		DWORD	monsterID[MAX_MONSTER_COUNT];
	};
	
	MonsterBase* monsterBaseList[MAX_MONSTER_COUNT];
	KEY_TYPE getId() {return ID;}
	size_t getFixSize() {
        return  ((char*)&formation - (char*)this) + sizeof(formation);
    }
	size_t getExtSize() {return sizeof(ExtCells);}
	bool parse(ExtCells* ext) {
        for (uint8 n = 0; n < MAX_MONSTER_COUNT; ++n)
        {
            if (ext->monsterID[n])
            {
                MonsterBase* pBase = siMonsterTable.find(ext->monsterID[n]);
                if (!pBase)
                    ERROR_LOG("MonsterGroupTable: grpid: %u, monstId:%u grid:%u monster not find!\n", getId(), ext->monsterID[n], n + 1);
                monsterBaseList[n] = pBase;
            }
            else
            {
                monsterBaseList[n] = NULL;
            }

        }
        return true;
    }
    bool check() {return true;}
};

/**
 * \brief FormationTable
 */
struct FormationBase
{
	typedef WORD KEY_TYPE;
	
	WORD	ID;						//
	DWORD	requireMoney;			//升级需求铜钱
	DWORD	requireGold;			//升级需求元宝
	DWORD	requireID[3];			//升级需求卡牌ID
	WORD	nextID;					//升级后阵法ID

	struct ItemDetail
	{
		uint8 pos;   //阵法位置
		uint8 param; //战斗属性索引
		uint8 value; //属性值百分比
	};
	VECTOR_CONTAINER(ItemDetail) itemDetails;
	struct ExtCells {
        char info[300];
    }; 
	KEY_TYPE getId() {return ID;} 
	size_t getFixSize() {return ((char*)&nextID - (char*)this) + sizeof(nextID);} 
	size_t getExtSize() {return sizeof(ExtCells);}

	bool parse(ExtCells* ext) {
        ext->info[299] = '\0';
        Helper::ArrayBuffer<std::string> arrbuf;
        Helper::splitInto(arrbuf, ext->info, "|");
        DEBUG_LOG("info %s\n", ext->info);
        for (uint8 n = 0; n < arrbuf.size(); ++n)
        {
            Helper::ArrayBuffer<uint32> arrbuf2;
            Helper::splitInto(arrbuf2, arrbuf[n], ",");	
            if (arrbuf2.size() != 3)
            {
                ERROR_LOG("FormationTable ID:%u error, %s\n", ID, arrbuf[n].c_str());
                return false;
            }
            ItemDetail itemDetail;
            itemDetail.pos = arrbuf2[0];
            itemDetail.param = arrbuf2[1];
            itemDetail.value = arrbuf2[2];
            itemDetails.push_back(itemDetail);
        }
        return true;
    }

	bool check() {return true;}
};

/**
 * \brief MonsterFormationTable
 */
struct MonsterFormationBase
{
	typedef BYTE KEY_TYPE;
	
	BYTE	ID;						//

	struct ItemDetail
	{
		uint8 pos;			//阵法位置
		uint8 value;		//属性值百分比
	};
	VECTOR_CONTAINER(ItemDetail) itemDetails;
	struct ExtCells
	{
		char info[300];
	};

	KEY_TYPE getId()    {return ID;               } 
	size_t getFixSize() {return 1;                } 
	size_t getExtSize() {return sizeof(ExtCells); }

	bool parse(ExtCells* ext) {
        ext->info[299] = '\0';
        Helper::ArrayBuffer<uint8> arrbuf;
        Helper::splitInto(arrbuf, ext->info, ",");
        for (uint8 n = 0; n < arrbuf.size(); ++n)
        {
            ItemDetail itemDetail;
            itemDetail.pos = n;
            itemDetail.value = arrbuf[n];
            itemDetails.push_back(itemDetail);
        }
        return true;
    }

	bool check() {return true;}
};

/**
 * \brief PlayerLevelTable
 */
struct PlayerLevelBase
{
	typedef WORD KEY_TYPE;
	
	WORD	ID;						//玩家等级
	DWORD	exp;					//升级所需经验
	BYTE	spLimit;				//体力上限
	BYTE	cardBagLimit;				//携带卡牌上限
    BYTE    equipBagLimit;             //装备背包上限
	WORD	leadLimit;				//领导力上限
	WORD	friendLimit;			//好友上限
	BYTE	spGrow;					//增加体力
	DWORD	moneyGrow;				//增加铜钱
	DWORD	goldGrow;				//增加元宝
    BYTE    pvpspLimit;             //耐力上限
    BYTE    pvpspGrow;              //升级之后增加的耐力
	DWORD	pvpExp;					//PVP经验
    
	static WORD topLevel;
	struct ExtCells {};
	KEY_TYPE getId()    {return ID;} 
	size_t getFixSize() {return sizeof(PlayerLevelBase);} 
	size_t getExtSize() {return 0;}
	bool parse(ExtCells* ext) {
        if (ID > topLevel)
        {
            topLevel = ID;
        }
        return true;
    }
	bool check() {return true;}
};

struct SundryBase
{
    typedef DWORD KEY_TYPE;

    WORD ID;
    BYTE  objectType;
    BYTE  activeMode;
    BYTE  triggerType;
    DWORD param;
    BYTE  star;
    DWORD moneyBase;
    BYTE  useLevel;

    struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }
};

/**
 * \brief LootTable
 */
struct LootBase
{
	typedef WORD KEY_TYPE;

	WORD	ID;						//ID
	BYTE	lootNums;				//Nums

	struct LootDetail
	{
		uint16 itemId;
		uint8 level;
		uint8 dropType;
		uint32 minNum;
		uint32 maxNum;
        uint32 sep;
		uint32 probable;
        LootDetail()
            : itemId(0)
            , level(0)
            , dropType(LootType_None)
            , minNum(0)
     		, maxNum(0)
            , probable(0)
        {}
	};

	VECTOR_CONTAINER(LootDetail) lootDetails;
	DWORD maxProbable;

	struct ExtCells
	{
		char	lootDes[2048];		//掉落详尽
	};

	KEY_TYPE getId() {return ID;} 
	size_t getFixSize() {return 3;} 
	size_t getExtSize() {return sizeof(ExtCells);}

	bool parse(ExtCells* ext) {
        ext->lootDes[2047] = '\0';
        //DEBUG_LOG("LootBase:%u %s\n" , getId(), ext->lootDes);
        maxProbable = GetLootDetail(ext->lootDes, lootDetails);
        DEBUG_LOG("id:%u LootBase maxProbable %u\n", ID, maxProbable);
        return true;
    }

	bool check() {return true;} 
	static DWORD GetLootDetail(char* LootDesc, VECTOR_CONTAINER(LootDetail)& lootDetails) {	
        Helper::ArrayBuffer<std::string> arrbuf;
        Helper::splitInto(arrbuf, LootDesc, "|");
        DWORD maxPro = 0;
        for(uint8 i=0; i<arrbuf.size(); i++)
        {
            Helper::ArrayBuffer<uint32> arrbuf2;
            Helper::splitInto(arrbuf2, arrbuf[i], ",");
            if(arrbuf2.size() == 7)
            {
                LootDetail detail;
                detail.itemId	= arrbuf2[0];
                detail.level	= arrbuf2[1];
                detail.dropType = arrbuf2[2];
                detail.minNum	= arrbuf2[3];
                detail.maxNum	= arrbuf2[4];
                detail.sep      = arrbuf2[5];
                detail.probable	= arrbuf2[6];
                if (detail.sep == 0)
                {
                    maxPro	+= detail.probable;
                }
                if (detail.dropType == 0)
                    continue;
                
                LootType lt = LootType(detail.dropType);
                if (LootTrade::ResTypeTrans(lt) == ResType_Unknow && LootTrade::BagTypeTrans(lt) == BagType_Unknow)
                {
                    ERROR_LOG("LootTable 不存在的掉落类型 ItemID %u LootType %u\n",
                              detail.itemId, detail.dropType);
                }
                else
                {
                    DEBUG_LOG("LootBase %u itemId %u item.probable %u maxPro %u\n", i, detail.itemId, detail.probable, maxPro);
                }
                if (lt == LootType_Equip && siEquipTable.find(detail.itemId) == false)
                {
                    ERROR_LOG("装备ID不存在 %u\n", detail.itemId);
                    continue;
                }
                else if (lt == LootType_Sundry && siSundryTable.find(detail.itemId) == false)
                {
                    ERROR_LOG("道具ID不存在 %u\n", detail.itemId);
                    continue;
                }
                else if (lt == LootType_Card && siCardBaseTable.find(detail.itemId) == false)
                {
                    ERROR_LOG("卡牌ID不存在 %u\n", detail.itemId);
                    continue;
                }
                lootDetails.push_back(detail);
            }
        }
        return maxPro;
    }
};

struct SmallBonusBase : public LootBase {};
struct FirstBonusBase : public LootBase {};

struct LvlupBase
{
    typedef BYTE KEY_TYPE;

    BYTE level;
    DWORD exp[5];		//升级所需经验
	DWORD coin[5];      //升级铜币参数 
	struct ExtCells {};

	KEY_TYPE getId() {return level;} 
	size_t getFixSize() {return sizeof(*this);} 
	size_t getExtSize() {return 0;}
    bool parse(ExtCells* ext) {return true;}
    bool check() {return true;}
};

struct EvolutionBase
{
    typedef DWORD KEY_TYPE;

    uint16 id;
    uint8  rank;
    uint16 requireCardNum;
    struct {
        uint16 requireItemID;
        uint16 requireItemNum;
        uint8  requireItemType;
    } reqs[3];
    
    uint32 costMoney;
    uint32 hp;
    uint32 atk;
    uint32 def;
    uint32 mdef;
    
	struct ExtCells {}; 
	KEY_TYPE getId()          {return MAKE_DWORD(id, rank);  } 
	size_t getFixSize()       {return sizeof(*this);         }
	size_t getExtSize()       {return 0;                     } 
	bool parse(ExtCells* ext) {
        TRACE_LOG("EvolutionTable id %u costMoney %u hp %u atk %u def %u mdef %u\n",
                  id, costMoney, hp, atk, def, mdef);
        return true;
    } 
	bool check()              {return true;                  }
};

struct SkillUpgradeBase
{
    typedef BYTE KEY_TYPE;

    BYTE Level;

    struct {
        BYTE color;
        WORD num;
    } runes[4];
    
	struct ExtCells {}; 
	KEY_TYPE getId()          {return Level;                    } 
	size_t getFixSize()       {return sizeof(*this); } 
	size_t getExtSize()       {return 0;                        } 
	bool parse(ExtCells* ext) {return true;                     } 
	bool check()              {return true;                     }
};

struct RuneBase
{
    typedef WORD KEY_TYPE;

    BYTE id;
    BYTE type;
    BYTE quality;
    BYTE level;

	struct ExtCells {}; 
	KEY_TYPE getId()          {return id;               } 
	size_t getFixSize()       {return sizeof(*this); } 
	size_t getExtSize()       {return 0;                }
    bool parse(ExtCells* ext) {return true;             }
    bool check()              {return true;             }    
};

struct StarBase
{
    typedef BYTE KEY_TYPE;

    BYTE starId;
    WORD maxLevel;
    WORD maxLevelGr;

    struct ExtCells {}; 
	KEY_TYPE getId()          {return starId;           }
    size_t getFixSize()       {return sizeof(*this);    }
    size_t getExtSize()       {return 0;                }
    bool parse(ExtCells* ext) {return true;             }
    bool check()              {return true;             }
};

struct BigLevelBase
{
    typedef DWORD KEY_TYPE;
    DWORD id;
    DWORD preId;
    DWORD Level;
    DWORD Limit;
    BYTE  UnLock;
    WORD  LockValue;
    BYTE  mistype;

    struct Reward {
        WORD  passId;
        BYTE  star;
    } reward[3];
    
    struct ExtCells
	{
        char weekday[32];
        char startTime[32];
        char endTime[32];
		char smallLevelStr[200];		//小关卡
	};
    
    uint8 weekdays[8];
    uint32 starttime;
    uint32 endtime;
    
    VECTOR_CONTAINER(uint16) smallLevels;
    uint16 endLevel;
    
	KEY_TYPE getId() {return id;} 
	size_t getFixSize() {return 29;} 
	size_t getExtSize() {return sizeof(ExtCells);} 
	bool parse(ExtCells* ext) {
        // 转换成星期几
        {
            bzero(weekdays, sizeof(weekdays));
            Helper::ArrayBuffer<int> wds;
            Helper::splitInto(wds, ext->weekday, ",");
            for (int i = 0; i < int(wds.size()); ++i)
            {
                int wd = wds[i];
                if (wd <= 7 && wd >= 0)
                {
                    weekdays[wd] = 1;
                }
            }
        }
        
        // 转换成Unix时间
        if (UnLock == 2)
        {
            Helper::ArrayBuffer<int> start;
            Helper::splitInto(start, ext->startTime, "-");
            if (start.size() < 6)
            {
                return false;
            }

            Helper::ArrayBuffer<int> end;
            Helper::splitInto(end, ext->endTime, "-");
            if (end.size() < 6)
            {
                return false;
            }
            
            enum {YEAR, MONTH, DAY, HOUR, MIN, SEC};

            struct tm clock;
            clock.tm_year    = start[YEAR] - 1900;
            clock.tm_mon     = start[MONTH] - 1;
            clock.tm_mday    = start[DAY];
            clock.tm_hour    = start[HOUR];
            clock.tm_min     = start[MIN];
            clock.tm_sec     = start[SEC];

            starttime = mktime(&clock);
            
            clock.tm_year    = end[YEAR] - 1900;
            clock.tm_mon     = end[MONTH] - 1;
            clock.tm_mday    = end[DAY];
            clock.tm_hour    = end[HOUR];
            clock.tm_min     = end[MIN];
            clock.tm_sec     = end[SEC];

            endtime = mktime(&clock);

            DEBUG_LOG("starttime %u endtime %u\n", starttime, endtime);
        }
        else if (UnLock == 4)
        {
            Helper::ArrayBuffer<uint32> timebuf;
            Helper::splitInto(timebuf, ext->startTime, "-");
            Helper::splitInto(timebuf, ext->endTime, "-");
            
            starttime = timebuf[0] * 3600 + timebuf[1] * 60 + timebuf[2];
            endtime   = timebuf[3] * 3600 + timebuf[4] * 60 + timebuf[5];
        }
        Helper::ArrayBuffer<uint32> arrbuf;
        Helper::splitInto(arrbuf, ext->smallLevelStr, ",");
        for (uint8 i = 0; i < arrbuf.size(); ++i)
        {
            DEBUG_LOG("BigLevelTable SmallTable %u\n", arrbuf[i]);
            smallLevels.push_back(arrbuf[i]);
            endLevel = arrbuf[i];
        }

        return true;
    }
    
	bool check() {return true;}
};

struct BigBonusBase
{
    typedef WORD KEY_TYPE;

    WORD id;
    struct {
        DWORD bonusId;
        DWORD bonusNum;
        BYTE  bonusType;
    } reward[3];

    struct ExtCells {}; 
	KEY_TYPE getId()    {return id;            } 
	size_t getFixSize() {return sizeof(*this); } 
	size_t getExtSize() {return 0;             } 
	bool parse(ExtCells* ext) {
        DEBUG_LOG("BigBonusTable id %u\n", id);
        return true;
    }

	bool check() {return true;}
};

struct SmallLevelBase
{
    typedef DWORD KEY_TYPE;
    
    DWORD id;
    DWORD nextID;
    DWORD bigLvId;
    BYTE  levelNum;
    BYTE  LevelLimit;
    BYTE  appraise;
    BYTE  battleType;
    WORD  monsterGroupID;
    DWORD  bossID;
    DWORD limit;
    BYTE  spCost;
    DWORD rewardCoin;
    DWORD rewardExp;
    WORD rewardGroupID;
    WORD StarMissionID[3];

    static DWORD firstID;
    struct ExtCells {};
    
	KEY_TYPE getId() {
        return id;
    }
	
	size_t getFixSize() {
        return sizeof(*this);
    }

	size_t getExtSize()
        {
            return 0;
        }

	bool parse(ExtCells* ext) {
        if (firstID == 0)
        {
            firstID = id;
        }
        DEBUG_LOG("SmallLevelTable id %u\n", id);

        if (siMonsterGroupTable.find(monsterGroupID) == false)
        {
            ERROR_LOG("SmallLevelTable 场景 %u 怪物组不存在 MonsterGroupID %u\n",
                      id, monsterGroupID);
            monsterGroupID = 1010;
            return true;
        }
        return true;
    }
    
	bool check() {
        return true;
    }
};

struct EquipLvlupBase
{
    typedef BYTE KEY_TYPE;
    
    BYTE id;
    DWORD coin[5][6];

    
    struct ExtCells {};
        
	KEY_TYPE getId()
        {
            return id;
        }
	
	size_t getFixSize()
        {
            return sizeof(*this);
        }

	size_t getExtSize()
        {
            return 0;
        }

	bool parse(ExtCells* ext)
        {
            DEBUG_LOG("EquipLvlup id %u\n", id);
            return true;
        }

	bool check()
        {
            return true;
        }
};


struct GachaBase
{
    typedef BYTE KEY_TYPE;
    
    BYTE id;
    WORD ItemID;
    WORD UseResType;
    DWORD UseResNum;
    DWORD FreeCD;
    BYTE FreeNum;
    WORD OneGaID;
    WORD TenGaID;
    
    struct ExtCells {};
        
	KEY_TYPE getId()
        {
            return id;
        }
	
	size_t getFixSize()
        {
            return sizeof(*this);
        }

	size_t getExtSize()
        {
            return 0;
        }

	bool parse(ExtCells* ext)
        {
            DEBUG_LOG("EquipLvlup id %u\n", id);
            return true;
        }

	bool check()
        {
            return true;
        }
};


struct GachaBonusBase : public LootBase
{
    
};


/**
 * \brief GameSettings表结构定义
 */
struct GameSettingsBase
{
	typedef WORD KEY_TYPE;

	WORD	Id;	//配置Id
	DWORD	Value;	//配置

	struct ExtCells     {};
	KEY_TYPE getId()    {return Id;            } 
	size_t getFixSize() {return sizeof(*this); } 
	size_t getExtSize() {return 0;             } 
	bool parse(ExtCells* ext) {
        DEBUG_LOG("GameSettingsTable: id %u value %u\n", getId(), Value);
        return true;
    }

	bool check() {return true;}
};

/**
 * \brief  InitialTable表结构定义
 */
struct InitialBase
{
	typedef BYTE KEY_TYPE;

	BYTE ID;	
	WORD cardID;   //
	BYTE HP;	   //1低 2中 3高
	BYTE ATK;	   //
	BYTE defence;  //
	BYTE crit;	   //
	BYTE dodge;	   //
	BYTE accuracy; //
    WORD follower[3]; // 随从
    DWORD money;
    WORD gold;
    
	struct ExtCells {}; 
	KEY_TYPE getId()          {return ID;            } 
	size_t getFixSize()       {return sizeof(*this); } 
	size_t getExtSize()       {return 0;             } 
	bool parse(ExtCells* ext) {
        DEBUG_LOG("InitialTable %u %u %u\n", follower[0], follower[1], follower[2]);
        return true;
    } 
	bool check()              {return true;          }
};


struct CardProduceBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD ChipsID;
    WORD NeedNum;
    WORD Money;

	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }
};

struct CardChipsBase
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

struct EquipProduceBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD ChipsID;
    WORD Money;

	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }
};

struct EquipChipsBase : public TableBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD EquipID;

    KEY_TYPE getId() { return ID; }
};


struct StarMissionBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    BYTE missType;
    BYTE cardType;
    WORD param;

    struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }
};

/**
* \brief ArenaDailyReward表结构定义
*/
struct ArenaDailyRewardBase
{
	typedef BYTE KEY_TYPE;

	BYTE	ID;	//ID
	BYTE	requirePoints;	//领取奖励需求积分
	WORD	lootId;			//奖励货币值


	struct ExtCells {};

	KEY_TYPE getId() {return ID;}

	size_t getFixSize() {return sizeof(*this);}

	size_t getExtSize() {return 0;}

	bool parse(ExtCells* ext)
	{
		DEBUG_LOG("ArenaDailyRewardTable: %u\n", getId());
		return true;
	}

	bool check() {return true;}
};

/**
* \brief ArenaWeekReward表结构定义
*/
struct ArenaWeekRewardBase
{
	typedef BYTE KEY_TYPE;

	BYTE	ID;	//ID
	WORD	minRank;	//周排行奖励最小名次
	WORD	maxRank;	//周排行奖励最大名次
	WORD	lootId;	//掉落1

	struct ExtCells
	{

	};

	KEY_TYPE getId()
	{
		return ID;
	}

	size_t getFixSize()
	{
		return sizeof(*this);
	}

	size_t getExtSize()
	{
		return 0;
	}

	bool parse(ExtCells* ext)
	{
		DEBUG_LOG("ArenaWeekRewardTable: %u\n", getId());
		return true;
	}

	bool check()
	{
		return true;
	}

};

struct MissionBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    BYTE missionType;
    WORD Level;
    BYTE requireType;
    WORD requireCond;
    int requireParam;
    BYTE rewardType;
    WORD rewardID;
    int rewardParam;
    WORD prevID;
    WORD nextID;
    WORD point;
    
    QuestCond cond;
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return 25;            }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        cond.k1 = requireType;
        cond.k2 = requireCond;
        DEBUG_LOG("MissionTable %u cond k1 %u k2 %u k3 %u k4 %u\n",
                  ID, cond.k1, cond.k2, cond.k3, cond.k4);
        return true;
    }
	bool check()              {return true;          }    
};

struct AchievementBase
{
    typedef DWORD KEY_TYPE;

    DWORD ID;
    BYTE  rewardType;
    WORD  rewardID;
    int   rewardParam;

    LootTrade tradein;

    static int StartID;
    static int FinishID;
    
    struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return 11;            }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        if (StartID == 0) {
            StartID = ID;
        }

        if (ID > static_cast<uint32>(FinishID)) {
            FinishID = ID;
        }
        LootItem item;
        item.type     = LootType(rewardType);
        item.itemId   = rewardID;
        item.number   = rewardParam;

        tradein.add(item);
        return true;
    }
	bool check()              {return true;          }    
};

struct GiftBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD ItemID;
    BYTE Num;
    WORD LootId;
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }    
};

struct VipBase
{
    typedef WORD KEY_TYPE;

    WORD  ID;
    BYTE  ison;
    BYTE  vartype;
    DWORD conf[13];
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        DEBUG_LOG("VipTable id %u\n", getId());
        return true;
    }
	bool check()              {return true;          }    
};

/**
* \brief Friend表结构定义
*/
struct FriendBase
{
	typedef WORD KEY_TYPE;
	
	WORD	ID;
	WORD	PhysicalNum;	//好友赠送体力数量
	WORD	Cost;			//扩充5个好友上限所花费的元宝数

	KEY_TYPE getId()          {return ID;            }
	struct ExtCells
	{

	};
    
	size_t getFixSize()
	{
		return sizeof(*this);
	}

	size_t getExtSize()
	{
		return 0;
	}

	bool parse(ExtCells* ext)
	{
		return true;
	}

	bool check()
	{
		return true;
	}

};

struct VipTimesBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD spCost;
    WORD pvpspCost;
    WORD normalResetCost;
    WORD eliteResetCost;
    WORD expDunEnterCount;
    WORD moneyDunEnterCount;
	WORD HuntingCost;		//购买狩猎投掷次数消耗元宝数
    WORD horseDunEnterCount;
    WORD scrollDunEnterCount;
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }    
};

struct SignBase
{
    typedef BYTE KEY_TYPE;

    BYTE ID;
    struct {
        uint16 id;
        uint16 type;
        uint32 count;
    } rewards[12];

    WORD CardID;
    
	struct ExtCells {
        char str[12][32];
    };
    
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return 1;             }
	size_t getExtSize()       {return 384;           }
	bool parse(ExtCells* ext) {
        DEBUG_LOG("SignTable Id %u\n", getId());
        for (int i = 0; i < 12; ++i)
        {
            ext->str[i][31] = 0;
            std::string str(ext->str[i]);
            std::replace(str.begin(), str.end(), ',', ' ');
            std::istringstream inputstr(str);
            inputstr >> rewards[i].id >> rewards[i].type >> rewards[i].count;
            DEBUG_LOG("SignTable %u %u %u\n",
                      rewards[i].id, rewards[i].type, rewards[i].count);
        }
        return true;
    }
	bool check()              {return true;          }    
};

struct SignCostBase
{
    typedef BYTE KEY_TYPE;

    BYTE ID;
    BYTE Cost;

    struct ExtCells {};

    KEY_TYPE getId()          { return ID;            }
    size_t getFixSize()       { return sizeof(*this); }
    size_t getExtSize()       { return 0;             }
    bool parse(ExtCells* ext) {
        TRACE_LOG("SignCostTable ID %u Cost %u\n", ID, Cost);
        return true;
    }
    bool check()              { return true;          }
};

struct MulSignBase
{
    typedef BYTE KEY_TYPE;

    BYTE ID;
    struct Reward {
        uint16 id;
        uint16 type;
        uint32 count;
    };
    
    VECTOR_CONTAINER(Reward) rewards[12];
    
	struct ExtCells {
        char str[12][128];
    };
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return 1;             }
	size_t getExtSize()       {return 1536;          }
	bool parse(ExtCells* ext) {
        DEBUG_LOG("MulSignTable Id %u\n", getId());

        for (int i = 0; i < 12; ++i)
        {
            ext->str[i][127] = 0;
            std::string str(ext->str[i]);
            std::replace(str.begin(), str.end(), ',', ' ');
            std::replace(str.begin(), str.end(), '|', ' ');
            std::istringstream inputstr(str);
            while (inputstr)
            {
                Reward rd;
                bzero(&rd, sizeof(rd));
                inputstr >> rd.id >> rd.type >> rd.count;
                if (rd.id == 0)
                    break;
                rewards[i].push_back(rd);
                DEBUG_LOG("MulSignTable %u %u %u\n",
                          rd.id, rd.type, rd.count);
            }
        }
        return true;
    }
	bool check()              {return true;          }    
};

/**
 * \brief Unlock表结构定义
 */
struct UnlockBase
{
	typedef WORD KEY_TYPE;

	WORD	ID;	    //功能ID
	BYTE	Level;	//开启等级

	struct ExtCells           {                      };
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        DEBUG_LOG("UnlockTable: %u\n", getId());
        return true;
    }
	bool check()              {return true;          }
};

struct GmBase
{
    typedef WORD KEY_TYPE;

    DWORD ID;
    char config[2048];

    struct card {
        uint16 id;
        uint16 level;
        uint16 rank;
    };

    struct equip {
        uint16 id;
        uint16 level;
    };

    VECTOR_CONTAINER(card) cards;
    VECTOR_CONTAINER(equip) equips;
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return 2052;          }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        config[2047] = 0;
        std::string gmconfig(config);
        size_t m = gmconfig.find_first_of(']');
        std::string cardconfig = gmconfig.substr(0, m);
        std::string equipconfig = gmconfig.substr(m);
        
        std::replace(cardconfig.begin(), cardconfig.end(), ',', ' ');
        std::replace(cardconfig.begin(), cardconfig.end(), '|', ' ');
        std::replace(cardconfig.begin(), cardconfig.end(), '[', ' ');
        std::replace(cardconfig.begin(), cardconfig.end(), ']', ' ');

        std::istringstream cardinput(cardconfig);
        while (cardinput) {
            card c;
            cardinput >> c.id >> c.level >> c.rank;
            if (c.id == 0 || c.level == 0 || c.rank == 0)
                continue;
            
            cards.push_back(c);
            DEBUG_LOG("GmTable Card %u %u %u\n", c.id, c.level, c.rank);
        }

        std::replace(cardconfig.begin(), cardconfig.end(), ',', ' ');
        std::replace(cardconfig.begin(), cardconfig.end(), '|', ' ');
        std::replace(cardconfig.begin(), cardconfig.end(), '[', ' ');
        std::replace(cardconfig.begin(), cardconfig.end(), ']', ' ');

        std::istringstream equipinput(equipconfig);
        while (equipinput) {
            equip e;
            equipinput >> e.id >> e.level;
            if (e.id == 0 || e.level == 0)
                continue;
            
            equips.push_back(e);
            DEBUG_LOG("GmTable Equip %u %u\n", e.id, e.level);
        }
        return true;
    }
	bool check()              {return true;          }    
};

struct VipEquipCritBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD Level[6];
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }
};

struct BabelBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD DungeonID;
    BYTE Open;
    DWORD Reward;

    static WORD top;
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        if (Open == 1 && ID > top)
        {
            top = ID + 1;
        }
        else
        {
            return true;
        }
        return true;
    }
	bool check()              {return true;          }    
};

struct ArenaRankRewardBase
{
    typedef BYTE KEY_TYPE;

    BYTE ID;
    WORD MinRank;
    WORD MaxRank;
    char reward[128];

    LootTrade trade;
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return 133;           }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        std::string rewardconfig(reward);
        std::replace(rewardconfig.begin(), rewardconfig.end(), ',', ' ');
        std::replace(rewardconfig.begin(), rewardconfig.end(), '|', ' ');
        std::istringstream rewardinput(rewardconfig);
        while (rewardinput) {
            LootItem item;
            int type = 0;
            rewardinput >> item.itemId >> type >> item.number;
            item.type = LootType(type);
            if (item.itemId == 0 || item.type == 0 || item.number == 0)
                continue;

            trade.add(item);
            DEBUG_LOG("ArenaRankTable id %u type %u number %u\n",
                      item.itemId, uint8(item.type), item.number);
        }
        
        return true;
    }
	bool check()              {return true;          }    
};

struct ArenaBase
{
    typedef BYTE KEY_TYPE;

    BYTE ID;
    BYTE WinPoint;
    BYTE LosePoint;
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        TRACE_LOG("ArenaBase WinPoint %u LosePoint %u\n",
                  WinPoint, LosePoint);
        return true;
    }
	bool check()              {return true;          }    
};

struct ArenaRobotBase
{
    typedef DWORD KEY_TYPE;

    DWORD Rank;
    DWORD PlayerLevel;

    struct {
        DWORD CardId;
        DWORD CardLevel;
        DWORD CardRank;

        struct {
            DWORD ID;
            DWORD Level;
        } equip[6];
    } list[6];
    
	struct ExtCells {};
	KEY_TYPE getId()          {return Rank;          }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        TRACE_LOG("ArenaRobotTable Rank %u CardId %u\n",
                  Rank, list[0].CardId);
        return true;
    }
	bool check()              {return true;          }
};


#define siHuntingMapTable Singleton<DataTable<HuntingMapBase> >::getInstance()

/**
 * \brief HuntingMap表结构定义
 */
struct HuntingMapBase
{
	typedef WORD KEY_TYPE;
	
	DWORD	id;	//格子ID
	BYTE	Type;	//格子类型：1起点2绿色3蓝色4紫色5橙色6赌坊7特殊事件
	WORD	lootID;	//奖励物品,对应掉落表

	static BYTE MaxId;

	struct ExtCells
	{

	};

	KEY_TYPE getId()
	{
		return id;
	}

	size_t getFixSize()
	{
		return sizeof(*this);
	}

	size_t getExtSize()
	{
		return 0;
	}

	bool parse(ExtCells* ext)
	{
		DEBUG_LOG("HuntingMapTable: %u\n", getId());
		if(getId() > MaxId)
		{
			MaxId = getId();
		}
		return true;
	}

	bool check()
	{
		return true;
	}
	
};

#define siHuntingMissionTable Singleton<DataTable<HuntingMissionBase> >::getInstance()

/**
 * \brief HuntingMission表结构定义
 */
struct HuntingMissionBase
{
	typedef WORD KEY_TYPE;
	
	DWORD	ID;	//任务id
	WORD	lootID;	//奖励物品,对应掉落表

	struct ExtCells
	{
		CHAR	lootDes[2048];	//任务池

	};

	struct MissionLoot
	{
		uint8 type;
		uint8 number1;
		uint8 number2;
		uint32 prob;
	};
	VECTOR_CONTAINER( MissionLoot) MissionList;

	uint32 getMaxProb()
	{
		if(MissionList.size())
		{
			return MissionList[MissionList.size()-1].prob;
		}
		else
		{
			return 0;
		}
	}

	KEY_TYPE getId()
	{
		return ID;
	}

	size_t getFixSize()
	{
		return ((char*)&lootID - (char*)this) + sizeof(lootID);
	}

	size_t getExtSize()
	{
		return sizeof(ExtCells);
	}

	bool parse(ExtCells* ext)
	{
		DEBUG_LOG("HuntingMissionTable: %u\n", getId());
		Helper::ArrayBuffer<std::string> abuf;
		Helper::splitInto(abuf, ext->lootDes, "|");
		uint16 total = 0;
		for(uint32 i=0; i<abuf.size(); ++i)
		{
			Helper::ArrayBuffer<uint32> abuf2;
			Helper::splitInto(abuf2, abuf[i], ",");
			if(abuf2.size() != 4)
			{
				return false;
			}
			total += abuf2[3];
			MissionLoot loot;
			loot.type = abuf2[0];
			loot.number1 = abuf2[1];
			loot.number2 = abuf2[2];
			loot.prob = total;
			TRACE_CLOG(LogLevel_SkyBlue, "\t%u, %u, %u, %u\n", loot.type, loot.number1, loot.number2, total);
			MissionList.push_back(loot);
		}
		return true;
	}

	bool check()
	{
		return true;
	}
	
};

/**
 * \brief LuckyDraw表结构定义
 */
#define siLuckyDrawTable Singleton<DataTable<LuckyDrawBase> >::getInstance()
struct LuckyDrawBase
{
	typedef DWORD KEY_TYPE;
	
	WORD	groupID;				//组编号（共6组）
	WORD	number;					//组内编号
	WORD	showWeight;				//随机到的权重
	WORD	luckyWeight;			//抽到的权重
	WORD	objectType;				//道具类型 物品类型： 3卡牌 4装备 5卡牌碎片 6装备碎片 9道具
	WORD	objectID;				//道具id

	union
	{
		struct
		{
			DWORD	num1;					//数量1
			WORD	numProbability1;		//数量1概率
			DWORD	num2;					//数量2
			WORD	numProbability2;		//数量2概率
			DWORD	num3;					//数量3
			WORD	numProbability3;		//数量3概率
			DWORD	num4;					//数量4
			WORD	numProbability4;		//数量4概率
			DWORD	num5;					//数量5
			WORD	numProbability5;		//数量5概率
		};
		struct
		{
			DWORD	num;
			WORD	numProb;
		}probs[5];
	};

	struct ExtCells
	{

	};

	KEY_TYPE getId()
	{
		return MAKE_DWORD(groupID, number);
	}

	size_t getFixSize()
	{
		return sizeof(*this);
	}

	size_t getExtSize()
	{
		return 0;
	}

	bool parse(ExtCells* ext)
	{
		DEBUG_LOG("LuckyDrawTable: %u\n", getId());
		for(uint8 i=1; i<5; ++i)
		{
			probs[i].numProb  += probs[i-1].numProb;
		}
		return true;
	}

	bool check()
	{
		return true;
	}
	
};

/**
 * \brief LuckyDrawBase表结构定义
 */
#define siLuckyDrawBaseTable Singleton<DataTable<LuckyDrawBaseBase> >::getInstance()
struct LuckyDrawBaseBase
{
	typedef WORD KEY_TYPE;
	
	WORD	times;					//次数
	WORD	objectType;				//消耗道具类型
	WORD	objectID;				//消耗道具ID
	WORD	luckyWeight;			//消耗道具数量

	struct ExtCells
	{

	};

	KEY_TYPE getId()
	{
		return times;
	}

	size_t getFixSize()
	{
		return sizeof(*this);
	}

	size_t getExtSize()
	{
		return 0;
	}

	bool parse(ExtCells* ext)
	{
		DEBUG_LOG("LuckyDrawBaseTable: %u\n", getId());
		return true;
	}

	bool check()
	{
		return true;
	}
	
};

//OpenTime表结构定义
#define siOpenTimeTable Singleton<DataTable<OpenTimeBase> >::getInstance()
struct OpenTimeBase
{
	typedef WORD KEY_TYPE;
	
	WORD	ID;						//世界BOSS ID
	WORD	OpenDate;				//开放日期(填一周的日期）
	WORD	AnTime;					//单次开放时间（分钟）

	//Helper::ArrayBuffer<uint16> OpenTime1;
	//Helper::ArrayBuffer<uint16> OpenTime2;
	DWORD	OpenTime1;
    DWORD   EndTime1;
    
	DWORD	OpenTime2;
    DWORD   EndTime2;
    
	struct ExtCells
	{
		CHAR	OpenTime1[50];			//开放时间1（24小时制）
		CHAR	OpenTime2[50];			//开放时间2（24小时制）
	};

	KEY_TYPE getId()
	{
		return OpenDate;
	}

	size_t getFixSize()
	{
		return ((char*)&AnTime - (char*)this) + sizeof(AnTime);
	}

	size_t getExtSize()
	{
		return sizeof(ExtCells);
	}

	bool parse(ExtCells* ext)
	{
        //Helper::splitInto(OpenTime1, ext->OpenTime1, ":");
        //Helper::splitInto(OpenTime2, ext->OpenTime2, ":");

		Helper::ArrayBuffer<uint16> abuf1;
        Helper::splitInto(abuf1, ext->OpenTime1, "-");
		if(abuf1.size() > 1)
		{
			OpenTime1 = 3600U*abuf1[0] + 60 * abuf1[1];
		}
		else
		{
			OpenTime1 = 0;
		}

		Helper::ArrayBuffer<uint16> abuf2;
		Helper::splitInto(abuf2, ext->OpenTime2, "-");
		if(abuf2.size() > 1)
		{
			OpenTime2 = 3600U*abuf2[0] + 60 * abuf2[1];
		}
		else
		{
			OpenTime2 = 0;
		}

        EndTime1 = OpenTime1 + 60 * AnTime;
        EndTime2 = OpenTime2 + 60 * AnTime;
        
		DEBUG_LOG("OpenTimeTable: %u open:%s(%u) %s(%u)\n",
                  getId(), ext->OpenTime1, OpenTime1, ext->OpenTime2, OpenTime2);
		return true;
	}

	bool check()
	{
		return true;
	}
	
};

//HurtRanking表结构定义
#define siHurtRankingTable Singleton<DataTable<HurtRankingBase> >::getInstance()
struct HurtRankingBase
{
	typedef WORD KEY_TYPE;
	
	WORD	minRank;				//活动结束最小排名
	WORD	maxRank;				//活动结束最大排名 （0为无限制）
	WORD	lootID;					//BOSS对应排行奖励（对应掉落表）


	struct ExtCells
	{

	};

	KEY_TYPE getId()
	{
		return minRank;
	}

	size_t getFixSize()
	{
		return sizeof(*this);
	}

	size_t getExtSize()
	{
		return 0;
	}

	bool parse(ExtCells* ext)
	{
		DEBUG_LOG("HurtRankingTable: %u\n", getId());
		return true;
	}

	bool check()
	{
		return true;
	}
	
};

//BossInformation表结构定义
#define siBossInformationTable Singleton<DataTable<BossInformationBase> >::getInstance()
struct BossInformationBase
{
	typedef WORD KEY_TYPE;
	
	WORD	ID;						//世界BOSS ID
	WORD	cardID;					//BOSS卡牌ID（对应卡牌表的卡牌ID）
    DWORD   sceneID;                // 关卡ID
    DWORD   FinalSceneID;           // 最后一击关卡ID
	BYTE	Type;					//特殊攻击条件类型1： 0.为无此条件 Ø
                                    //1.魏国武将对BOSS伤害增加 Ø
                                    //2.蜀国武将对BOSS伤害增加 Ø
                                    //3.吴国武将对BOSS伤害增加 Ø
                                    //4.群雄武将对BOSS伤害增加 Ø 
	WORD	Param1;					//伤害百分比（具体数值1~100）
	BYTE	Type2;					//特殊攻击条件类型2： Ø0.为无此条件  Ø 1.女性武将对BOSS伤害增加    2.男性武将对boss伤害增加
	WORD	Param2;					//伤害百分比（具体数值）
	WORD	lootID1;				//单次攻击奖励（对应掉落表）
	WORD	lootID2;				//击杀奖励（对应掉落表）
	WORD	lootID3;				//幸运奖励（对应掉落表，随机发放10人）

	struct ExtCells
	{
		CHAR	lootDes[2048];			//等级（BOSS等级随开服时间上升）
	};

	struct LevelupInfo
	{
		uint16 OpenDay1;
		uint16 OpenDay2;
		uint16 Level;
	};

	VECTOR_CONTAINER(LevelupInfo) LevelupConfig;

	KEY_TYPE getId()
	{
		return ID;
	}

	size_t getFixSize()
	{
		return ((char*)&lootID3 - (char*)this) + sizeof(lootID3);
	}

	size_t getExtSize()
	{
		return sizeof(ExtCells);
	}

	bool parse(ExtCells* ext)
	{
		Helper::ArrayBuffer<std::string> abuf;
		Helper::splitInto(abuf, ext->lootDes, "|");
		for(uint32 i=0; i<abuf.size(); ++i)
		{
			Helper::ArrayBuffer<uint16> abuf2;
			Helper::splitInto(abuf2, abuf[i], ",");
			if(abuf2.size() == 3)
			{
				LevelupInfo info;
				info.OpenDay1 = abuf2[0];
				info.OpenDay2 = abuf2[1];
				info.Level = abuf2[2];
				LevelupConfig.push_back(info);
				TRACE_LOG("\topenday: %u ~ %u level: %u\n", abuf2[0], abuf2[1], abuf2[2]);
			}
			else
			{
				ERROR_LOG("BossInformationTable: %u Levelup config error.\n", getId());
			}
		}
		DEBUG_LOG("BossInformationTable: %u\n", getId());
		return true;
	}

	bool check()
	{
		return true;
	}
	
};

#define siBossLevelTable Singleton<DataTable<BossLevelBase> >::getInstance()
struct BossLevelBase
{
    typedef WORD KEY_TYPE;

    DWORD ID;
    DWORD Level;
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        TRACE_LOG("BossLevelTable %u %u\n", ID, Level);
        return true;
    }
	bool check()              {return true;          }
};
/**
 * \brief LevelTurn表结构定义
 */
#define siLevelTurnTable Singleton<DataTable<LevelTurnBase> >::getInstance()
struct LevelTurnBase
{
	typedef DWORD KEY_TYPE;
	
	DWORD	level;					//转盘开启等级
	DWORD	nextlevel;				//下次开启等级
	WORD	lootID;					//奖励物品，对应掉落表

	static DWORD MinLevel;					//最小等级

	struct ExtCells
	{

	};

	KEY_TYPE getId()
	{
		return level;
	}

	size_t getFixSize()
	{
		return sizeof(*this);
	}

	size_t getExtSize()
	{
		return 0;
	}

	bool parse(ExtCells* ext)
	{
		if(level < MinLevel)
		{
			MinLevel = level;
		}
		DEBUG_LOG("LevelTurnTable: %u\n", getId());
		return true;
	}

	bool check()
	{
		return true;
	}
	
};

struct TopUpBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD Price;
    WORD IsMonthCard;
    WORD GoldDaily;
    WORD Validity;
    WORD GoldOnece;
    WORD ExtraGold;
    WORD BuyLimit;
    WORD GoldLimit;
    WORD ExtraGoldLimit;
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }
};

/**
 * \brief GrabMine表结构定义
 */
struct GrabMineBase
{
	typedef DWORD KEY_TYPE;

	DWORD	ID;				// id
	DWORD	minearea;		// 矿区1普通2高级
	DWORD	number;			// 页数
	DWORD	minestation;	// 矿的位置
	DWORD	minetype;		// 位置1矿类型1铁矿2铜矿3银矿4金矿
	DWORD	reward;			// 每小时铜币产量

	struct ExtCells
	{

	};

	KEY_TYPE getId()
	{
		return ID;
	}

	size_t getFixSize()
	{
		return sizeof(*this);
	}

	size_t getExtSize()
	{
		return 0;
	}

	bool parse(ExtCells* ext)
	{
		//DEBUG_LOG("GrabMineTable: %u\n", getId());
		return true;
	}

	bool check()
	{
		return true;
	}

};

struct LandingRewardBase
{
    typedef DWORD KEY_TYPE;

    DWORD ID;
    DWORD LootID;

	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return 8;             }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        return true;
    }
	bool check()              {return true;          }
};

//
// 供人复制用的一段代码，请保留
//
#if 0
struct SampleBase : public TableBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD CardID;
    
	KEY_TYPE getId()          {return ID;            }
};

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
 
