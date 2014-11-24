#ifndef __BABEL_ENUSM_H__
#define __BABEL_ENUMS_H__

enum
{
    BABEL_OP_FIGHT     = 1, // 挑战下一层
    BABEL_OP_AUTOFIGHT = 2, // 扫荡
    BABEL_OP_BUYLIFE   = 3, // 购买进入次数
    BABEL_OP_BUYRESET  = 4, // 购买进入次数
    BABEL_OP_RESET     = 5, // 重置
    BABEL_OP_RANK      = 6  // 获取排名信息
};

enum
{
    BABEL_AUTO_FREE   = 0,
    BABEL_AUTO_COST   = 1,
    BABEL_AUTO_CANCEL = 2,
};
#endif

