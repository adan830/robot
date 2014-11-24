#ifndef __NXCORE_PLAYERMSG__
#define __NXCORE_PLAYERMSG__

#include <string.h>

#include "MsgDefine.h"
#include "Define.h"
#include "DBEntity.h"

CORE_NAMESPACE_START

/**
 * \brief  平台消息 消息ID：0x600 ~ 0x6A0
 */
#include "PlatformMsg.h"

/**
 * \brief 角色消息 消息 ID : 0x800 ~ 0x8FF
 */
#include "RoleMsg.h"

/**
 * \brief 聊天消息定义 消息ID: 0x940 ~ 0x94F
 */
#include "HuntingMsg.h"

/**
 * \brief 聊天消息定义 消息ID: 0x950 ~ 0x95F
 */
#include "ChatMsg.h"

/**
 * \brief 竞技场系统消息定义 消息ID: 0x960 ~ 0x970
 */
#include "ArenaMsg.h"
/**
 * \brief 好友系统消息定义 消息ID: 0x970 ~ 0x980
 */
#include "SocialMsg.h"
/**
 * \brief 战斗系统消息定义 消息ID: 0xA00 ~ 0xA2F
 */
#include "BattleMsg.h"

/**
 * \brief 战斗系统消息定义 消息ID: 0xA30 ~ 0xA4F
 */
//#include "PlayerCardMsg.h"

/**
 * \brief 卡牌抽奖 消息ID: 0xA50 ~ 0xA5F
 */
//#include "LotteryMsg.h"

/**
 * \brief 战役关卡 消息ID: 0xA60 ~ 0xA6F
 */
//#include "DungeonMsg.h"

/**
 * \brief 装备背包 消息ID: 0xA70 ~ 0xA7F
 */
//#include "EquipMsg.h"

/**
 * \brief 道具背包 碎片背包 消息ID: 0xA80 ~ 0xA87
 */
//#include "SundryMsg.h"

/**
 * \brief 碎片背包 消息ID: 0xA88 ~ 0xA8F
 */
//#include "ChipsMsg.h"

/**
 * \brief 商城、购物 消息ID: 0xA90 ~ 0xA97
 */
//#include "ShoppingMsg.h"

/**
 * \brief 任务 消息ID: 0xA98 ~ 0xA9F
 */
//#include "QuestMsg.h"

/**
 * \brief VIP VIP相关的功能 消息ID: 0xAA0 ~ 0xAAF
 */
//#include "VipMsg.h"

/**
 * \brief 签到相关的功能 消息ID: 0xAB0 ~ 0xAB8
 */
//#include "DaySignMsg.h"

/**
 * \brief 通天塔相关的功能 消息ID: 0xAC0 ~ 0xACF
 */
//#include "BabelMsg.h"

/**
 * \brief 炼化与重生 消息ID: 0xAD0 ~ 0xADF
 */
//#include "MeltMsg.h"

#pragma pack(push, 1)


#pragma pack(pop)

CORE_NAMESPACE_END

#endif//__NXCORE_LOGINMSG__

