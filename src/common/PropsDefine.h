#ifndef __NXCORE_PROPS_DEFINE__
#define __NXCORE_PROPS_DEFINE__

//玩家属性类型索引
enum PropIndex
{
    PropIndex_Money               = 1,  // 铜钱   0-2100000000
    PropIndex_Gold                = 2,  // 元宝   0-99999999
    PropIndex_Exp                 = 3,  // 经验值 0-99999999
    PropIndex_Card                = 4,  // 卡牌
    PropIndex_Level               = 5,  // 等级
    PropIndex_Sp                  = 6,  // 体力
    PropIndex_Equip               = 7,  // 装备
    PropIndex_Sundry              = 8,  // 道具
    PropIndex_Dungeon             = 9,  // 进度
    PropIndex_CardBagSize         = 10, // 卡牌背包大小
    PropIndex_EquipBagSize        = 11, // 装备背包大小
    PropIndex_Lead                = 12, // 领导力
    PropIndex_VipLevel            = 13, // VIP等级
    PropIndex_Recharge            = 14, // 充值获得的元宝总数
    PropIndex_PvpSp               = 15, // 耐力上限
    PropIndex_BuySpCount          = 16, // 购买体力次数
    PropIndex_BuyPvpSpCount       = 17, // 购买耐力次数
    PropIndex_NormalDunResetCount = 18, // 普通副本重置次数
    PropIndex_EliteDunResetCount  = 19, // 精英副本重置次数
    PropIndex_ExpDunBuyCount      = 20, // 经验副本进入次数
    PropIndex_MoneyDunBuyCount    = 21, // 金钱副本进入次数
    PropIndex_Skip1               = 22, // 跳过
    PropIndex_Virgin              = 23, // 初始开启
    PropIndex_ArenaPoint          = 24, // 竞技场勋章
    PropIndex_Renown              = 25, // 声望
    PropIndex_SoulStone           = 26, // 灵石
    PropIndex_SoulRefined         = 27, // 精魄
    PropIndex_DailySp             = 28, // 每日体力值
    PropIndex_HorseSoul           = 29, // 马魂
    PropIndex_Scroll              = 30, // 残卷
    PropIndex_TigerSoul           = 31, // 虎魂
    PropIndex_PicScroll           = 32, // 残画
    PropIndex_HorseDunEnterCount  = 33, // 战马副本的进入次数
    PropIndex_ScrollDunEnterCount = 34, // 兵书副本的进入次数
};

//卡牌属性类型索引
enum CardPropIndex
{
    CARD_PROP_LEVEL       = 1,  // 等级
    CARD_PROP_EXP         = 2,  // 经验
    CARD_PROP_RANK        = 3,  // 品阶
    CARD_PROP_POWER       = 4,  // 武力
    CARD_PROP_AGILE       = 5,  // 统帅
    CARD_PROP_WISDOM      = 6,  // 智力
    CARD_PROP_LEADPOINT   = 7,  // 消费领导力
    CARD_PROP_LEVEL_LIMIT = 8,  // 等级上限
    CARD_PROP_SLOT        = 9,  // 卡牌位置
    CARD_PROP_FIGHTPOS    = 10, // 卡牌在阵法中位置
    CARD_PROP_COSTEXP     = 11, // 累计经验
};

// 资源类型
enum ResType
{
    ResType_Unknow          = 0,   // 未知
    ResType_Money           = 1,   // 铜钱
    ResType_Gold            = 2,   // 元宝
    ResType_Exp             = 3,   // 经验
    ResType_Sp              = 4,   // 体力
    ResType_CardContainer   = 5,   //卡牌背包容器大小
    ResType_EquipContainer  = 6,   //装备背包容器大小
    ResType_SundryContainer = 7,   //道具背包容器大小
    ResType_ArenaPoint      = 8,   //竞技场勋章
    ResType_Renown          = 9,   //声望
    ResType_SoulStone       = 10,  //灵魂石
    ResType_SoulRefined     = 11,  //精魄
    ResType_HorseSoul       = 12,  //马魂
    ResType_Scroll          = 13,  //残卷
    ResType_TigerSoul       = 14,  //虎魂
    ResType_PicScroll       = 15,  //残画
    ResType_None            = 100, //道具背包容器大小
};

// 背包类型
enum BagType
{
    BagType_Unknow    = 0, // 未知
    BagType_Card      = 1, // 卡牌
    BagType_Equip     = 2, // 装备
    BagType_Sundry    = 3, // 杂货、道具
    BagType_CardChips = 4, // 卡牌碎片
    BagType_EquipChips= 5, // 装备碎片
    BagType_Reward    = 6  // 奖励
};

// 背包叠加数
enum BagPile
{
    BagPile_Card       = 1,
    BagPile_Equip      = 1,
    BagPile_Sundry     = 9999,
    BagPile_Chips      = 9999,
    BagPile_CardChips  = 9999,
    BagPile_EquipChips = 9999,
    BagPile_Reward     = 1,
};

enum EquipType
{
    EquipType_Weapon = 1, // 武器
    EquipType_Canque = 2, // 头盔
    EquipType_Armour = 3, // 铠甲
    EquipType_Book   = 4, // 书籍
    EquipType_Mount  = 5, // 坐骑
    EquipType_Orna   = 6  // 饰品
};

enum QuestType
{
    QuestType_Main    = 1, // 主线任务
    QuestType_Achieve = 2, // 成就任务
    QuestType_Daily   = 3, // 日常任务
};
#endif
