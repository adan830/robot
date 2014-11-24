#ifndef __ARENA_ENUMS_H__
#define __ARENA_ENUMS_H__

enum
{
    ARENAOP_REQUEST_DATA = 0, //请求竞技场数据
    ARENAOP_VIEW_ENERMY  = 1, //请求对手
    ARENAOP_CHALLENGE    = 2, //挑战对手
    ARENAOP_REWARD       = 3, //领取奖励 param1
    ARENAOP_BUYLIFE      = 4, //购买挑战次数
    ARENAOP_CLEARCD      = 5, //清楚冷却CD
    ARENAOP_RANK         = 6, //竞技场排名
    ARENAOP_RANK_HIS     = 7, //竞技场昨日排名
};
#endif

