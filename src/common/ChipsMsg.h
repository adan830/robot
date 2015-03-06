#ifndef _NXCORE_CHIPS_MSG_H_
#define _NXCORE_CHIPS_MSG_H_

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

// 背包中的道具
struct ChipsListSMsg : public PlayerMsg
{
    enum { id = 0xA88 };
    
    uint8 chipstype;
    uint16 count;
    
    struct Props {
        uint16 slot;
        uint16 chipID;
        uint16 count;
    } list[0];
    
    ChipsListSMsg()
        : PlayerMsg(id, sizeof(*this))
        , chipstype(0)
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

/**
 * 碎片合成
 */
struct ProduceCMsg : public PlayerMsg
{
    enum { id = 0xA89 };

    uint8 chipstype;
    uint16 slot;

    ProduceCMsg()
        : PlayerMsg(id, sizeof(*this))
        , chipstype(0)
        , slot(0)
    {}
};

/**
 * 碎片合成结果
 */
struct ProduceSMsg : public PlayerMsg
{
    enum { id = 0xA8A };

    uint8 ret;

    ProduceSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ret(0)
    {}
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//SundryMsg 
