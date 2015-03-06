#ifndef _VIP_H_
#define _VIP_H_

enum
{
    VIP_DISABLE = 0,
    VIP_ENABLE  = 1,
};

enum VIPSettings
{
    VIP_Recharge = 1,				//累计充值元宝
    VIP_BuySpCount,					//购买体力次数
    VIP_EliteDunResetCount,  	    //重置精英副本次数
    VIP_BuyMoneyDunCount,			//购买打钱活动副本次数
    VIP_BuyExpDunCount = 5,				//购买经验活动副本次数
    VIP_NoAutoFightCD,				//扫荡普通副本免CD
    VIP_FriendGetSpCount,			//好友领取体力次数
    VIP_FriendGiveSpCount,			//好友赠送体力次数
    VIP_BuyPvpSpCount,				//购买耐力次数
    VIP_UnlockFightFaster = 10,			//解锁战斗3倍速
    VIP_UnlockFightSkip,			//解锁战斗跳过
    VIP_EquipPower,					//装备强化暴击档次
    VIP_FriendLimit,				//初始好友上限值
    VIP_CardPkgLimit,				//初始武将包裹上限值
    VIP_EquipPkgLimit =15,				//初始装备包裹上限值
    VIP_NormalDunResetCount,        //普通副本重置次数
    VIP_DaySignFillCount,           //普通副本重置次数
    VIP_DaySignReward5,             //普通副本重置次数
    VIP_DaySignReward10,            //普通副本重置次数
    VIP_DaySignReward15 = 20,            //普通副本重置次数
    VIP_DaySignReward20,            //普通副本重置次数
    VIP_DaySignReward25,            //普通副本重置次数
    VIP_BabelReset,                 //通天塔可购买的次数
    VIP_ArenaLife,                  //竞技场可购买的次数
    VIP_ArenaClearCD = 25,               //竞技场清楚冷却CD
	VIP_HuntingTimes		= 26,	//狩猎上限
	VIP_HuntingBuyTimes		= 27,	//狩猎购买
    VIP_HorseDunEnterCount,         //战马副本进入次数
    VIP_ScrollDunEnterCount,        //兵书副本进入次数
    VIP_WorshipNormal,              //中级膜拜
    VIP_WorshipHigh,                //高级膜拜
};

enum
{
    VIP_BUY_SP_IS_LIMIT         = 201, // vip买体力次数达到上限
    VIP_BUY_PVPSP_IS_LIMIT      = 202, // vip买耐力次数达到上限
    VIP_BUY_ENTERCOUNT_IS_LIMIT = 203, // vip重置副本进入次数达到上限
    VIP_CLEARCD_IS_LIMIT        = 204, // vip重置副本次数达到上限
    VIP_NOT_ENOUGH_GOLD         = 205, // vip没有足够的元宝
    VIP_DUNGEON_ERROR           = 206, //
    VIP_BAG_MAXIMAL             = 207, // vip背包已经是最大尺寸
};
#endif

