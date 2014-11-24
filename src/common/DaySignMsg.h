#ifndef __DAY_SIGN_MSG__
#define __DAY_SIGN_MSG__

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

// 签到、补签
struct DaySignCMsg : public PlayerMsg
{
    enum { id = 0xAB0 };

    uint32 optype;
    
    DaySignCMsg()
        : PlayerMsg(id, sizeof(*this))
        , optype(0)
    {}
};

// 结果
struct DaySignSMsg : public PlayerMsg
{
    enum { id = 0xAB1 };

    uint32 optype;
    uint32 ret;
    
    DaySignSMsg()
        : PlayerMsg(id, sizeof(*this))
        , optype(0)
        , ret(0)
    {}
};

// 签到信息
struct DaySignInfoSMsg : public PlayerMsg
{
    enum { id = 0xAB2 };

    uint16 year;     // 年
    uint8 month;     // 月份
    uint8 day;       // 日
    uint8 daycount;  // 该月天数
    uint8 today;     // 今天是否可以签
    uint8 sign;      // 签到次数
    uint8 fill;      // 补签次数
    uint8 reward[5]; // 奖励领取标志

    DaySignInfoSMsg()
        : PlayerMsg(id, sizeof(*this))
        , year(0)
        , month(0)
        , day(0)
        , daycount(0)
        , today(0)
        , sign(0)
        , fill(0)
    {}
};

// 领取多次奖励
struct MulDaySignCMsg : public PlayerMsg
{
    enum { id = 0xAB3 };

    uint32 optype;
    
    MulDaySignCMsg()
        : PlayerMsg(id, sizeof(*this))
        , optype(0)
    {}
};

// 结果
struct MulDaySignSMsg : public PlayerMsg
{
    enum { id = 0xAB4 };

    uint32 optype;
    uint32 ret;
    
    MulDaySignSMsg()
        : PlayerMsg(id, sizeof(*this))
        , optype(0)
        , ret(0)
    {}
};

struct DailySpCMsg : public PlayerMsg
{
    enum { id = 0xAB5 };
    
    uint8 op;
    
    DailySpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
    {}
};

struct DailySpSMsg : public PlayerMsg
{
    enum { id = 0xAB6 };

    uint8 op;
    uint8 ret;
    
    DailySpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , ret(0)
    {}
};

#pragma pack(pop)

CORE_NAMESPACE_END
#endif

