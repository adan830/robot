/**
 * \filename   Lottery.h		v1.0
 * \brief      
 *             
 * \author     orange
 * \created    2014-4-9
 */

#ifndef __NXCORE_LOTTERY_MSG_
#define __NXCORE_LOTTERY_MSG_

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

struct LotteryOpCMsg : public PlayerMsg
{
    enum { id = 0xA50 };

    uint8 op;								 
    uint8 mode;

    LotteryOpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , mode(0)
    {}
};

struct LotteryOpSMsg : public PlayerMsg
{
    enum { id = 0xA51 };

    uint8 op;
    uint8 mode;
    uint8 cost;   
    uint8 freeCount;
    int   luckyDis;
    uint8 ret;
    LotteryOpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , mode(0)
        , cost(0)
        , freeCount(0)
        , luckyDis(0)
        , ret(0)
    {}
};

struct LotteryInfoSMsg : public PlayerMsg
{
    enum { id = 0xA52 };

    uint16 count;

    struct Props {
        uint8 op;
        uint16 freeCount;
        uint32 time;
        uint16 payCount;
        int   luckyDis;
    } list[0];

    LotteryInfoSMsg()
        : PlayerMsg(id, sizeof(*this))
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

struct LotteryRewardSMsg : public PlayerMsg
{
    enum { id = 0xA53 };

    uint8 op;
    uint8 mode;
    uint16 count;
    
    struct Cards {
        uint8 loottype;
        uint16 id;
        uint16 count;
    } list[0];

    LotteryRewardSMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , mode(0)
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + sizeof(list[0]) * count;
    }
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//

