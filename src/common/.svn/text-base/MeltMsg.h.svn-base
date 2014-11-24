#ifndef __MELT_MSG__
#define __MELT_MSG__

#include "MsgDefine.h"
#include "PlayerCardEnums.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * 卡牌炼化
 */
struct PlayerCardMeltCMsg : public PlayerMsg
{
    enum { id = 0xAD0 };

    MeltSlot lists[6];
    
    PlayerCardMeltCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

/**
 * 卡牌炼化结果
 */
struct PlayerCardMeltSMsg : public PlayerMsg
{
    enum { id = 0xAD1 };

    uint32 ret;

    PlayerCardMeltSMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

/*
 * 卡牌重生
 */
struct PlayerCardRebornCMsg : public PlayerMsg
{
    enum { id = 0xAD2 };

    uint16 slottype;
    uint16 slot;

    PlayerCardRebornCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};
    
/*
 * 卡牌炼化结果
 */
struct PlayerCardRebornSMsg : public PlayerMsg
{
    enum { id = 0xAD3 };

    uint32 ret;
    
    PlayerCardRebornSMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_BATTLEMSG__

