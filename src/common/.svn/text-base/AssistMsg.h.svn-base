#ifndef __ASSIST_MSG__
#define __ASSIST_MSG__

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

struct AssistOpCMsg : public PlayerMsg
{
    enum { id = 0xB20 };

    int        Op;
    playerid_t AssistCharId;
        
    AssistOpCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

struct AssistListSMsg : public PlayerMsg
{
    enum { id = 0xB21 };

    int count;
    
    struct Player {
        playerid_t CharId;
        char       Name[TINYSTR];
        int        Level;
        int        LeadCard;
        int        LeadCardLv;
    } list[0];
    
    AssistListSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}

    int getSize()
    {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};
#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_BATTLEMSG__

