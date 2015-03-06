/**
 * \filename   LootType.h		v1.0
 * \brief      
 *             
 * \author     zhufang(zhufang666@gmail.com)
 * \created    2012-12-06 19:31
 */
#ifndef __NXCORE_LOOTTYPE__
#define __NXCORE_LOOTTYPE__

#include <Manager.h>
#include <DBEntity.h>

USING_NXCORE

enum LootType
{
    LootType_None            = 0,
    LootType_Money           = 1,   //铜钱
    LootType_Gold            = 2,   //元宝
    LootType_Card            = 3,   //卡牌
    LootType_Equip           = 4,   //装备
    LootType_CardPiece       = 5,   //卡牌碎片
    LootType_EquipPiece      = 6,   //装备碎片
    LootType_Loot            = 7,   //掉落组
    LootType_Exp             = 8,   //经验值
    LootType_Sundry          = 9,   //道具、杂货
    LootType_Sp              = 10,  //体力
    LootType_CardContainer   = 11,  //卡牌背包容器大小
    LootType_EquipContainer  = 12,  //装备背包容器大小
    LootType_SundryContainer = 13,  //道具背包容器大小
    LootType_Box             = 14,  //宝箱，需要使用钥匙开启
    LootType_ArenaPoint      = 20,  //竞技场勋章
    LootType_Renown          = 21,  //声望
    LootType_HorseSoul       = 22,  //马魂
    LootType_Scroll          = 23,  //残卷
    LootType_TigerSoul       = 24,  //虎魂
    LootType_PicScroll       = 25,  //残画
    LootType_SoulStone       = 26,  //灵石
    LootType_SoulRefined     = 27,  //精魄
    LootType_FriendPoint     = 28,  //侠义点
    LootType_Null			 = 255, //空
};

#pragma pack(push, 1)

struct LootItem
{
	uint16 itemId;
	LootType type;
	uint32 number;
	uint8 level;
    LootItem()
        : itemId(0)
		, type(LootType_None)
		, number(0)
		, level(1)
        {}
};

struct LootTrade
{
    vec_card  cards;
    map_trade bags;        // 需要占用背包的物品
    map_res   res;         // 各种资源，不需要占用背包

    void merge(LootTrade& lt) {
        cards.insert(cards.end(), lt.cards.begin(), lt.cards.end());
        
        map_trade::iterator bag_it = lt.bags.begin();
        for (; bag_it != lt.bags.end(); ++bag_it) {
            vec_item::iterator vec_it = bag_it->second.begin();
            for (; vec_it != bag_it->second.end(); ++vec_it) {
                LootItem item;
                item.itemId = vec_it->id;
                item.number = vec_it->count;
                item.level  = vec_it->equip.level;
                addItem(bag_it->first, item);
            }
        }

        map_res::iterator res_it = lt.res.begin();
        for (; res_it != lt.res.end(); ++res_it) {
            addRes(res_it->first, res_it->second);
        }
    }
    
    void add(LootItem& item) {
        BagType bt = BagTypeTrans(item.type);
        ResType rt = ResTypeTrans(item.type);

        if (rt != ResType_Unknow)
        {
            addRes(rt, item.number);
            return;
        }
        else if (bt != BagType_Unknow)
        {
            addItem(bt, item);
            return;
        }
    }

    void addItem(BagType bt, LootItem& item) {
        if (bt == BagType_Card)
        {
            for (uint32 i = 0; i < item.number; ++i)
            {
                NewCard card(item.itemId);
                if (item.level > 0)
                    card.level = item.level;
                cards.push_back(card);
            }
            return;
        }
        map_trade::iterator bag_it = bags.find(bt);
        if (bag_it == bags.end())
        {
            vec_item vec;
            std::pair<map_trade::iterator, bool> ret;
            ret = bags.insert(map_trade::value_type(bt, vec));
            if (ret.second == false)
                return;
            
            bag_it = ret.first;
        }

        vec_item::iterator item_it = bag_it->second.begin();
        for (; item_it != bag_it->second.end(); ++item_it)
        {
            if (item_it->id == item.itemId && item_it->equip.level == item.level)
            {
                item_it->count += item.number;
                return;
            }
        }
        
        Item newitem(item.itemId, item.number);
        if (item.level > 0)
            newitem.equip.level = item.level;
        bag_it->second.push_back(newitem);
    }

    void addRes(ResType rt, uint32 num) {
        if (num == 0)
            return;
        
        map_res::iterator it = res.find(rt);
        if (it == res.end()) {
            std::pair<map_res::iterator, bool> ret;
            ret = res.insert(map_res::value_type(rt, 0));
            if (ret.second == false)
                return;

            it = ret.first;
        }
        it->second += num;
    }

    static ResType ResTypeTrans(LootType loottype)
    {
        if (loottype == LootType_Money)
            return ResType_Money;

        if (loottype == LootType_Gold)
            return ResType_Gold;

        if (loottype == LootType_Exp)
            return ResType_Exp;

        if (loottype == LootType_Sp)
            return ResType_Sp;

        if (loottype == LootType_Loot)
            return ResType_None;

        if (loottype == LootType_ArenaPoint)
            return ResType_ArenaPoint;

        if (loottype == LootType_Renown)
            return ResType_Renown;

        if (loottype == LootType_HorseSoul)
            return ResType_HorseSoul;

        if (loottype == LootType_Scroll)
            return ResType_Scroll;
        
        if (loottype == LootType_TigerSoul)
            return ResType_TigerSoul;

        if (loottype == LootType_PicScroll)
            return ResType_PicScroll;

        if (loottype == LootType_SoulStone)
            return ResType_SoulStone;

        if (loottype == LootType_SoulRefined)
            return ResType_SoulRefined;

        if (loottype == LootType_FriendPoint)
            return ResType_FriendPoint;

        return ResType_Unknow;
    }
    
    static BagType BagTypeTrans(LootType loottype)
    {
        if (loottype == LootType_Card)
            return BagType_Card;

        if (loottype == LootType_Equip)
            return BagType_Equip;

        if (loottype == LootType_CardPiece)
            return BagType_CardChips;

        if (loottype == LootType_EquipPiece)
            return BagType_EquipChips;

        if (loottype == LootType_Sundry)
            return BagType_Sundry;

        return BagType_Unknow;
    }

    static LootType ResToLoot(ResType restype)
    {
        if (restype == ResType_Money)
            return LootType_Money;

        if (restype == ResType_Gold)
            return LootType_Gold;

        if (restype == ResType_Exp)
            return LootType_Exp;

        if (restype == ResType_Sp)
            return LootType_Sp;

        if (restype == ResType_ArenaPoint)
            return LootType_ArenaPoint;

        if (restype == ResType_Renown)
            return LootType_Renown;

        if (restype == ResType_HorseSoul)
            return LootType_HorseSoul;

        if (restype == ResType_Scroll)
            return LootType_Scroll;
        
        if (restype == ResType_TigerSoul)
            return LootType_TigerSoul;

        if (restype == ResType_PicScroll)
            return LootType_PicScroll;

        if (restype == ResType_SoulStone)
            return LootType_SoulStone;

        if (restype == ResType_SoulRefined)
            return LootType_SoulRefined;

        if (restype == ResType_FriendPoint)
            return LootType_FriendPoint;

        return LootType_None;
    }

    static LootType BagToLoot(BagType bagtype)
    {
        if (bagtype == BagType_Card)
            return LootType_Card;

        if (bagtype == BagType_Equip)
            return LootType_Equip;

        if (bagtype == BagType_CardChips)
            return LootType_CardPiece;

        if (bagtype == BagType_EquipChips)
            return LootType_EquipPiece;

        if (bagtype == BagType_Sundry)
            return LootType_Sundry;

        return LootType_None;
    }
    
    void clear()
    {
        bags.clear();
        res.clear();
    }          
};

typedef VECTOR_CONTAINER(LootItem) LootVect;
                                       
#pragma pack(pop)

#endif//__NXCORE_LOOTTYPE__


