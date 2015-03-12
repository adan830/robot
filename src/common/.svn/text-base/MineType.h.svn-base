#ifndef __NXCORE_MINE_TYPE__
#define __NXCORE_MINE_TYPE__

// 矿的类型
enum MineType
{
	MineType_None = 0,					// 无
	MineType_Min,
	MineType_Normal = MineType_Min,		// 普通矿
	MineType_Senior,					// 高级矿
	MineType_Max = MineType_Senior,
};

// 矿的子类
enum MineSubType
{
	MineSubType_None = 0,
	MineSubType_Min,
	MineSubType_Fe = MineSubType_Min,	// 铁矿
	MineSubType_Cu,						// 铜矿
	MineSubType_Ag,						// 银矿
	MineSubType_Au,						// 金矿
	MineSubType_Max = MineSubType_Au,
};

// 矿的操作返回值
enum MineOpResult
{
	MineOpResult_Fail = 0,		// 操作失败
	MineOpResult_Success,		// 操作成功
	MineOpResult_Exist,			// 已经有人抢占了
	MineOpResult_Free,			// 该矿已经退出占领
	MineOpResult_NeedStamina,	// 体力不足
};

#endif // __NXCORE_MINE_TYPE__

