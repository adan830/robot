#ifndef __NXCORE_SPEND_DEFINE__
#define __NXCORE_SPEND_DEFINE__

// 资源增加消耗类型
enum ResChgType 
{
    ResChgType_None             = 0,  //默认
    ResChgType_GM               = 1,  //GM
    ResChgType_DungeonFight     = 2,  //副本战斗奖励
    ResChgType_CardLevelUp      = 3,  //卡牌升级
    ResChgType_CardRankUp       = 4,  //卡牌升阶
    ResChgType_EquipLevelUp     = 5,  //装备升级
    ResChgType_LotterMoney      = 6,  //花费铜钱探索
    ResChgType_LotterItem       = 7,  //花费道具探索
    ResChgType_LotterGold       = 8,  //花费元宝探索
    ResChgType_LotterFree       = 9,  //免费探索
    ResChgType_CardMove         = 10, //卡牌移动
    ResChgType_Sell             = 11, //售卖
    ResChgType_RefreshShop      = 12, //刷新商城
    ResChgType_BuyShopItem      = 13, //购买商城物品
    ResChgType_ProduceCard      = 14, //购买商城物品
    ResChgType_ProduceEquip     = 15, //购买商城物品
    ResChgType_DungeonReward    = 16, //领取副本奖励
    ResChgType_ArenaReward      = 17, //竞技奖励
    ResChgType_QuestReward      = 18, //竞技奖励
    ResChgType_UseItem          = 19, //使用道具
    ResChgType_UseBox           = 20, //使用宝箱
    ResChgType_Friend           = 21, //好友
    ResChgType_DungeonAutoFight = 22, // 副本扫荡
    ResChgType_Levelup          = 23, // 人物升级
    ResChgType_BuyBagSlot       = 24, // 购买背包
    ResChgType_DaySign          = 25, // 签到
    ResChgType_BabelFight       = 26, // 通天塔战斗
    ResChgType_BabelAuto        = 27, // 通天塔收割
    ResChgType_Arena            = 28, // 竞技场战斗
    ResChgType_VipBuySp         = 29, // VIP购买体力
    ResChgType_Hunting			= 30, // 狩猎
    ResChgType_HuntingMission   = 31, // 狩猎任务
    ResChgType_NormalDun        = 32, // 重置普通副本
    ResChgType_EliteDun         = 33, // 重置精英副本
    ResChgType_ExpDun           = 34, // 购买经验副本次数
    ResChgType_MoneyDun         = 35, // 购买铜钱副本次数
    ResChgType_CardMelt         = 36, // 卡牌炼化
    ResChgType_EquipMelt        = 37, // 装备炼化
    ResChgType_CardReborn       = 38, // 卡牌重生
    ResChgType_EquipReborn      = 39, // 装备重生
    ResChgType_CreateRole       = 40, // 初始创建角色，系统赠送
    ResChgType_ArenaBuyLife     = 41, // 竞技场购买进入次数
    ResChgType_ArenaClearCD     = 42, // 竞技场清除挑战CD
    ResChgType_DrawCard			= 43, // 点神兵
    ResChgType_HorseDun         = 44, // 购买战马副本次数
    ResChgType_ScrollDun        = 45, // 购买兵书副本次数
    ResChgType_RefineCardLevel  = 46, // 利用精魄升级卡牌
    ResChgType_OfficerApply     = 47, // 爵位晋升
    ResChgType_OfficerPVP       = 48, // 爵位权斗
    ResChgType_OfficerWorship   = 49, // 爵位俯首
    ResChgType_OfficerAward     = 50, // 爵位打赏
    ResChgType_OfficerPromote   = 51, // 爵位提拔
    ResChgType_OfficerDemote    = 52, // 爵位贬职
    ResChgType_OfficerSalary    = 53, // 爵位薪水
    ResChgType_LevelTurn		= 54, // 等级转盘
    ResChgType_MailAttach		= 55, // 邮件附件
    ResChgType_WorldBossRevive  = 56, // 世界Boss复活
    ResChgType_Encourage        = 57, // 世界Boss鼓舞
    ResChgType_WorldBossKill    = 58, // 世界Boss击杀
    ResChgType_WorldBossRank    = 59, // 世界Boss伤害排名
    ResChgType_WorldBossLuck    = 60, // 世界Boss幸运奖励
    ResChgType_WorldBossFight   = 61, // 世界Boss战斗
    ResChgType_Mart             = 62, // 抢矿
    ResChgType_BeenWorship      = 63, // 被人俯首
    ResChgType_MonthCard        = 64, // 购买月卡
    ResChgType_Appoint          = 64, // 册封
    ResChgType_Init             = 1000, // 初始化
};

#endif

