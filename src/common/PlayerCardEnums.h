#ifndef PLAYER_CARD_ENUMS_H
#define PLAYER_CARD_ENUMS_H

#include "Define.h"
/**
 * 服务端将非常多的常量定义在Define.h中，不方便查找和维护，
 * 受MangOs风格的启发，将常量按功能定义
 * 
 * 玩家卡牌常量、操作返回码等
 *
 * OrangE 2014.3.29
 */
const uint8 MAX_RANKUP_COST = 10;  // 进阶卡牌最多消耗10张同名卡
const uint8 SLOT_EQUIPS_COUNT = 6; // 每个槽位 6 件装备

enum
{
    CARD_UNKOWN    = 0,          // 未知
    CARD_LEVELUP   = 1,          // 卡牌升级
    CARD_RANKUP    = 2,          // 卡牌升阶
    CARD_MOVE      = 3,          // 卡牌移动
    CARD_DEL       = 4,          // 删除卡牌
};

enum
{
    MODE_AUTO   = 1,  // 自动升级装备
    MODE_SINGLE = 2   // 手动升级装备
};

enum
{
    EQUIP_BAG  = 1,   // 
    EQUIP_SLOT = 2
};

enum
{

};
#endif
