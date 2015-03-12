#ifndef __MAIL_ENUMS__
#define __MAIL_ENUMS__

enum
{
	MAIL_SYSTEM						= 1,	// 系统邮件
	MAIL_ARENA						= 10,	// 竞技场
	MAIL_FIRST_RECHARGE				= 11,	// 首充

	MAIL_MINE_LOSE					= 12,	// 抢矿失败
	MAIL_MINE_WIN					= 13,	// 抢矿成功
	MAIL_MINE_DEF_LOSE				= 14,	// 矿被抢成功
	MAIL_MINE_DEF_WIN				= 15,	// 矿被抢失败
	MAIL_MINE_OVERDUE				= 16,	// 矿到期了

	MAIL_OFFICER_APPLY_DEF_LOSE		= 17,	// 官职防守失败
	MAIL_OFFICER_APPLY_DEF_WIN		= 18,	// 官职防守成功
	MAIL_OFFICER_FIGHT_DEF_WIN		= 19,	// 权斗防守成功
	MAIL_OFFICER_FIGHT_DEF_LOSE		= 20,	// 权斗防守失败
	MAIL_OFFICER_WORSHIP_RECEIVE	= 21,	// 您被俯首了
	MAIL_OFFICER_REWARD_RECEIVE		= 22,	// 您被赏赐了
	MAIL_OFFICER_PROMOTE_RECEIVE	= 23,	// 您被提拔了
	MAIL_OFFICER_DEMOTE_RECEIVE		= 24,	// 您被贬职了
	MAIL_OFFICER_DEMOTE_SYSTEM		= 25,	// 系统自动降职

    MAIL_OFFICER_BEEN_WORSHIP       = 26,   // 你被俯首
    
    MAIL_WORLDBOSS_RANK				= 27,	// 世界Boss 伤害排行
    MAIL_WORLDBOSS_KILL				= 28,	// 世界Boss 击杀
    MAIL_WORLDBOSS_LUCKY			= 29,	// 世界Boss 幸运奖

    MAIL_CASH_ATTACK_SUCCESS        = 30,	// 镖车被劫
    MAIL_CASH_ATTACK_FAILED         = 31,	// 镖车被劫，但是没成功
    MAIL_CASH_REWARD                = 32,	// 镖车结算
};

enum
{
    MAIL_OP_INFO   = 0, // 查看邮件信息
    MAIL_OP_DETAIL = 1, // 查看邮件详情
    MAIL_OP_REWARD = 2, // 领取附件
    MAIL_OP_DELETE = 3, // 删除邮件
};

enum
{
    MAIL_STATUS_NEW       = 1,  // 新邮件
    MAIL_STATUS_READING   = 2,  // 已读
    MAIL_STATUS_ATTACHING = 3,  // 含有附件
    MAIL_STATUS_EMPTY     = 4,  // 附件已经领取
    MAIL_STATUS_DELETE    = 5,  // 邮件已经删除
};
#endif
