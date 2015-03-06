#ifndef __NXCORE_OP_DEFINE__
#define __NXCORE_OP_DEFINE__

// 玩家操作定义

// 探索分类
enum LOTTERY_OP
{
    LOTTERY_OP_INFO   = 0, // 获得存档信息
    LOTTERY_OP_NORMAL = 1, // 普通探索
    LOTTERY_OP_HIGH   = 2, // 高级探索
    LOTTERY_OP_SUPER  = 3  // 超级探索
};

// 探索模式
enum LOTTERY_MODE
{
    LOTTERY_MODE_SINGLE = 1, // 一次
    LOTTERY_MODE_TEN    = 2, // 十次
};

#endif
