#ifndef __NXCORE_PLAYER_CARD_MSG__
#define __NXCORE_PLAYER_CARD_MSG__

#include "MsgDefine.h"
#include "PlayerCardEnums.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * 卡牌出战
 */
struct PlayerCardActiveOpCMsg : public PlayerMsg
{
    enum { id = 0xA30 };

    uint16 from;           // 卡牌原位置
    uint16 to;             // 卡牌新位置
    
    PlayerCardActiveOpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , from(0)
        , to(0)
    {
    }
};

/**
 * 卡牌出战结果
 */
struct PlayerCardActiveOpSMsg : public PlayerMsg
{
    enum { id = 0xA31 };

    enum {
        RET_OK = 0,
    };
    
    uint8 ret;

    PlayerCardActiveOpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

/**
 * 卡牌升级
 */
struct PlayerCardLevelupOpCMsg : public PlayerMsg
{
    enum { id = 0xA32 };

    uint16 maincard;      // 主卡
    uint16 slots[MAX_LEVELUP_COST];  // 粮食卡

    PlayerCardLevelupOpCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

/**
 * 卡牌升级结果
 */
struct PlayerCardLevelupOpSMsg : public PlayerMsg
{
    enum { id = 0xA33 };

    enum {
        RET_OK = 0,
    };
    
    uint8 ret;

    PlayerCardLevelupOpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

/**
 * 卡牌升阶
 */
struct PlayerCardRankupOpCMsg : public PlayerMsg
{
    enum { id = 0xA34 };
    
    uint16 maincard;
    
    PlayerCardRankupOpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , maincard(0)
    {
    }
};
    
/**
 * 卡牌升阶结果 
 */
struct PlayerCardRankupOpSMsg : public PlayerMsg
{
    enum { id = 0xA35 };

    enum {
        RET_OK = 0,
    };

    uint8 ret;
    PlayerCardRankupOpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

/**
 * 卡牌技能升级
 */
struct PlayerCardSkillUpCMsg : public PlayerMsg
{
    enum { id = 0xA36 };

    uint16 cardslot;
    PlayerCardSkillUpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , cardslot(0)
    {}
};

/**
 * 技能升级结果
 */
struct PlayerCardSkillUpSMsg : public PlayerMsg
{
    enum { id = 0xA37 };

    enum {
        RET_OK = 0
    };

    uint8 ret;
    PlayerCardSkillUpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

/**
 * 队长技能传招
 */
struct PlayerCardSkillMoveCMsg : public PlayerMsg
{
    enum { id = 0xA38 };

    uint16 fromcard;
    uint16 tocard;

    PlayerCardSkillMoveCMsg()
        : PlayerMsg(id, sizeof(*this))
        , fromcard(0)
        , tocard(0)
    {}
};
    
/**
 * 队长技能传招结果
 */
struct PlayerCardSkillMoveSMsg : public PlayerMsg
{
    enum { id = 0xA39 };

    enum {
        RET_OK = 0,
        RET_FAILED,
    };

    uint8 ret;
    PlayerCardSkillMoveSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

/**
 * 队长技能习武
 */
struct PlayerCardLeaderSkillUpCMsg : public PlayerMsg
{
    enum { id = 0xA40 };

    uint16 cardslot;
    PlayerCardLeaderSkillUpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , cardslot(0)
    {}
};

/**
 * 队长技能习武结果
 */
struct PlayerCardLeaderSkillUpSMsg : public PlayerMsg
{
    enum { id = 0xA41 };

    enum {
        RET_OK = 0
    };

    uint8 ret;
    PlayerCardLeaderSkillUpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

/**
 * 卡牌合成
 */
struct PlayerCardComposeCMsg : public PlayerMsg
{
    enum { id = 0xA42 };

    uint16 cardid;
    PlayerCardComposeCMsg()
        : PlayerMsg(id, sizeof(*this))
        , cardid(0)
    {}
};

/**
 * 卡牌合成结果
 */
struct PlayerCardComposeSMsg : public PlayerMsg
{
    enum { id = 0xA43 };

    uint8 ret;
    PlayerCardComposeSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

/**
 * 卡牌属性改变消息
 */
struct PlayerCardPropsChangeSMsg : public PlayerMsg
{
    enum { id = 0xA44 };

    uint8 count;

    struct Props {
        uint16   slot;
        uint16   cardKey;
        uint8    reason;
        uint8    oper;     //1 增加  2 减少 3 更新
        uint8    propId;
        uint32   propValue;
    } lists[0];

    PlayerCardPropsChangeSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(lists[0]);
    }
};

/**
 * 卡牌属性
 */
struct PlayerCardPropsSMsg : public PlayerMsg
{
    enum { id = 0xA45 };

    uint16 count;

    struct Props {
        FightProperties   fp;
        FightPropsPercent fpp;
    } lists[0];

    PlayerCardPropsSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(lists[0]);
    }
};

/**
 * 卡牌部分战斗属性
 */
struct PlayerCardFightPropSMsg : public PlayerMsg
{
    enum { id = 0xA46 };

    uint16 count;

    struct Props {
        uint8  slot;      // 槽位
        uint32 maxhp;     // 生命
        uint32 attack;    // 攻击
        uint32 pdefence;  // 物防
        uint32 pPenetration;
        uint32 mdefence;  // 法防
        uint32 mPenetration;
        uint32 power;     // 战力
        uint32 crit;	  //	暴击值       1-999999
        uint32 accuracy;  //	命中值       1-999999
        uint32 dodge;	  //	躲闪值       1-999999
        uint32 toughness; //	韧性值       1-999999
        uint32 speed;
    } list[0];

    PlayerCardFightPropSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

struct PlayerCardDetailOpCMsg : public PlayerMsg
{
    enum { id = 0xA47 };

    playerid_t CharId;
    uint32     Enermy;
    uint32     Slot;
    
    PlayerCardDetailOpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , CharId(0)
        , Enermy(0)
        , Slot(0)
    {}
};

struct PlayerCardDetailOpSMsg : public PlayerMsg
{
    enum { id = 0xA48 };

    uint32     Enermy;
    uint32     Slot;
    
    PlayerCardDetailOpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , Enermy(0)
        , Slot(0)
    {}
};

/**
 * 卡牌部分战斗属性
 */
struct PlayerCardDetailSMsg : public PlayerMsg
{
    enum { id = 0xA49 };
    
    playerid_t CharId;
    char name[32];
    uint16 count;

    struct Props {
        uint32 cardID;
        uint32 level;
        uint32 rank;
        uint32 exp;
        uint8  slot;      // 槽位
        uint32 maxhp;     // 生命
        uint32 attack;    // 攻击
        uint32 pdefence;  // 物防
        uint32 mdefence;  // 法防
        uint32 power;     // 战力
        uint32 crit;	  // 暴击值 1-999999
        uint32 accuracy;  // 命中值 1-999999
        uint32 dodge;	  // 躲闪值 1-999999
        uint32 toughness; // 韧性值 1-999999
        uint32 speed;
    } list[0];

    PlayerCardDetailSMsg()
        : PlayerMsg(id, sizeof(*this))
        , CharId(0)
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_BATTLEMSG__

