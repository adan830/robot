#ifndef __OFFICER_ENUMS_H__
#define __OFFICER_ENUMS_H__

enum OfficerMode
{
    OFFICER_INFO		= 0,	// 获取信息
    OFFICER_FIGHT		= 1,	// 权斗
    OFFICER_WORSHIP		= 2,	// 俯首
    OFFICER_AWARD		= 3,	// 赏赐
    OFFICER_PROMOTE		= 4,	// 提拔
    OFFICER_DEMOTE		= 5,	// 贬职
    OFFICER_APPLY		= 6,	// 申请晋升
    OFFICER_SALARY		= 7,	// 领取奉禄
    OFFICER_PLAYERS		= 8,	// 玩家数据
	OFFICER_APPLY_LIST	= 9,	// 晋升的列表信息
	OFFICER_ONLINE_NUM	= 10,	// 当前多少人在玩
};

enum OfficerOpResult
{
	OfficerOpResult_Success = 0,		// 操作成功
	OfficerOpResult_PlayerNotExist,		// 查找的玩家不存在
	OfficerOpResult_NoMatch,			// 没有符合条件的玩家
};

#endif
