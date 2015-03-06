#ifndef __NXCORE_SHOPPING_MSG_
#define __NXCORE_SHOPPING_MSG_

#include "MsgDefine.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)

/**
 * 商城请求信息，购买
 */
struct NormalShopOpCMsg : public PlayerMsg
{
    enum { id = 0xA90 };

    // 0 请求商品
    // 1 刷新商城
    // 2 购买商品
    uint32 op;
    uint32 shoptype; // 商城类型
    uint32 slot;     // 购买第几号商品
    uint32 num;      // 购买多少物品
    
    NormalShopOpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , shoptype(0)
        , slot(0)
        , num(0)
    {}
};

/**
 * 处理结果
 */ 
struct NormalShopOpSMsg : public PlayerMsg
{
    enum { id = 0xA90 };

    uint32 op;
    uint32 shoptype;
    uint32 itemid;
    uint32 ret;
    
    NormalShopOpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , shoptype(0)
        , itemid(0)
        , ret(0)
    {}
};


struct NormalShopInfoSMsg : public PlayerMsg
{
    enum { id = 0xA91 };

    uint32 count;
    struct ShopItem
    {
        uint32 id;
        uint32 count;
    } lists[0];

    NormalShopInfoSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(lists[0]);
    }
};

/**
 * 商城请求信息，购买
 */
struct RandShopOpCMsg : public PlayerMsg
{
    enum { id = 0xA92 };

    // 0 请求商品
    // 1 刷新商城
    // 2 购买商品
    uint32 op;
    uint32 shoptype; // 商城类型
    uint32 slot;     // 购买第几号商品
    uint32 num;      // 购买多少物品
    
    RandShopOpCMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , shoptype(0)
        , slot(0)
        , num(0)
    {}
};

/**
 * 处理结果
 */ 
struct RandShopOpSMsg : public PlayerMsg
{
    enum { id = 0xA92 };

    uint32 op;
    uint32 shoptype;
    uint32 itemid;
    uint32 ret;
    uint32 nextclock;
    uint32 lefttime; // 多少秒之后刷新商城
    RandShopOpSMsg()
        : PlayerMsg(id, sizeof(*this))
        , op(0)
        , shoptype(0)
        , itemid(0)
        , ret(0)
        , nextclock(0)
        , lefttime(0)
    {}
};

/**
 * 商城列表
 */
struct RandShopListSMsg : public PlayerMsg
{
    enum { id = 0xA93 };

    uint32 shoptype;     // 商城类型
    uint32 buycount;     // 购买刷新的次数
    uint32 count;         // 商品个数

    struct ShopItem
    {
        uint32 slot;     // 位置
        uint32 id;       // 物品ID
        uint32 rand;     // 随机序号
        uint32 count;    // 堆叠个数
        uint32 oneprice; // 物品单价
        uint32 type;     // 物品类型
        uint32 restype;  // 资源消耗类型
        uint32 state;    // 商品状态
    } lists[0];

  RandShopListSMsg()
        : PlayerMsg(id, sizeof(*this))
        , shoptype(0)
        , buycount(0)
        , count(0)
    {}

    uint16 getSize()
    {
        return sizeof(*this) + count * sizeof(lists[0]);
    }
};

#pragma pack(pop)

CORE_NAMESPACE_END

#endif//

