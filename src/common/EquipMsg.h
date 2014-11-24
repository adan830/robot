#ifndef _NXCORE_EQUIP_MSG_H_
#define _NXCORE_EQUIP_MSG_H_

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

// 背包中的装备
struct EquipListSMsg : public PlayerMsg
{
    enum { id = 0xA70 };

    uint16 count;
    struct Equip {
        uint16 slot;
        uint16 equipID;
        uint8 level;
        uint8 rank;
        uint16 fightSlot;
        uint32 cost;
    } list[0];
    
    EquipListSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

// 穿上装备
struct SlotEquipTakeOnCMsg : public PlayerMsg
{
    enum { id = 0xA72 };
    uint16 fromslot;
    uint16 toslot;

    SlotEquipTakeOnCMsg()
        : PlayerMsg(id, sizeof(*this))
        , fromslot(0)
        , toslot(0)
    {}
};

// 穿上装备服务端回应
struct SlotEquipTakeOnSMsg : public PlayerMsg
{
    enum { id = 0xA73 };

    uint8 ret;

    SlotEquipTakeOnSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};
      
// 脱下装备
struct SlotEquipTakeOffCMsg : public PlayerMsg
{
    enum { id = 0xA74 };
    uint16 slot;

    SlotEquipTakeOffCMsg()
        : PlayerMsg(id, sizeof(*this))
        , slot(0)
    {}
};

// 脱下装备服务端回应
struct SlotEquipTakeOffSMsg : public PlayerMsg
{
    enum { id = 0xA75 };

    uint8 ret;

    SlotEquipTakeOffSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

// 装备升级
struct EquipLevelUpCMsg : public PlayerMsg
{
    enum { id = 0xA76 };

    uint8  mode;      // 1 自动升级  2 单次升级
    uint16 slot;

    EquipLevelUpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , mode(0)
        , slot(0)
    {}
};

// 升级回应
struct EquipLevelUpSMsg : public PlayerMsg
{
    enum { id = 0xA77 };

    uint8 ret;
    uint8 slot;
    uint16 level;
    
    EquipLevelUpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
        , slot(0)
        , level(0)
    {}
};

// 装备合成
struct EquipProduceCMsg : public PlayerMsg
{
    enum { id = 0xA78 };

    uint16 slot;

    EquipProduceCMsg()
        : PlayerMsg(id, sizeof(*this))
        , slot(0)
    {}
};

// 合成结果
struct EquipProduceSMsg : public PlayerMsg
{
    enum { id = 0xA79 };

    uint8 ret;

    EquipProduceSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

// 一键换装
struct EquipQuickChangeCSMsg : public PlayerMsg
{
    enum { id = 0xA7A };

    uint16 slot;
    uint8  ret;
    
    EquipQuickChangeCSMsg()
        : PlayerMsg(id, sizeof(*this))
        , slot(0)
        , ret(0)
    {}
};

// 装备升级暴击
struct EquipLevelUpCritSMsg : public PlayerMsg
{
    enum { id = 0xA7B };

    uint16 count;

    struct Crit {
        uint16 level;
        uint8  add;
    } crits[0];

    EquipLevelUpCritSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}
    
    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(crits[0]);
    }
};

// 背包中的装备
struct EquipDetailSMsg : public PlayerMsg
{
    enum { id = 0xA7C };

    playerid_t CharId;
    char name[32];
    
    uint16 count;
    struct Equip {
        uint16 slot;
        uint16 equipID;
        uint8 level;
        uint8 rank;
        uint16 fightSlot;
    } list[0];
    
    EquipDetailSMsg()
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

#endif//DungeonMsge _DUNGEON_MSG_H_
