#ifndef __MELT_MSG__
#define __MELT_MSG__

#include "MsgDefine.h"
#include "PlayerCardEnums.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * 卡牌炼化
 */
struct PlayerCardRefineCMsg : public PlayerMsg
{
    enum { id = 0xAD0 };

    int slottype;
    int slots[5];
    
    PlayerCardRefineCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

/**
 * 卡牌炼化结果
 */
struct PlayerCardRefineSMsg : public PlayerMsg
{
    enum { id = 0xAD1 };

    uint32 ret;

    PlayerCardRefineSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

/*
 * 卡牌重生
 */
struct PlayerCardRevertCMsg : public PlayerMsg
{
    enum { id = 0xAD2 };

    uint16 slottype;
    uint16 slot;

    PlayerCardRevertCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};
    
/*
 * 卡牌炼化结果
 */
struct PlayerCardRevertSMsg : public PlayerMsg
{
    enum { id = 0xAD3 };

    uint32 ret;
    
    PlayerCardRevertSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_BATTLEMSG__

