#ifndef __RANK_ENUMS__
#define __RANK_ENUMS__

enum RankType
{
    RANK_BABEL         = 1, // 通天塔等级排行
    RANK_ARENA         = 2, // 竞技场排行榜
    RANK_ARENA_HIS     = 3, // 竞技场昨日排行榜
    RANK_WORLD_BOSS    = 4, //
    RANK_WORSHIP_SCORE = 5, //
    // 增加类型之后，DBEntity.h 中的 RankTypeCount 应该与最后一个类型一致
};
#endif
