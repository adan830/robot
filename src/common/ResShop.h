#ifndef __NXCORE_RES_SHOP__
#define __NXCORE_RES_SHOP__

#include <vector>
#include <algorithm>
#include <DataTable.h>
#include <Define.h>
#include <Helper.h>
#include <LootType.h>
#include <DBEntity.h>

USING_NXCORE
#define siShopTable Singleton<DataTable<ShopBase> >::getInstance()
#define siShopConstTable Singleton<DataTable<ShopConstBase> >::getInstance()
#define siShopNormalTable Singleton<DataTable<ShopNormalBase> >::getInstance()
#define siShopNormalPriceTable Singleton<DataTable<ShopNormalPriceBase> >::getInstance()
#define siRefreshShopTable Singleton<DataTable<RefreshShopBase> >::getInstance()
#define siHorseSoulTable Singleton<DataTable<HorseSoulBase> >::getInstance()
#define siScrollTable Singleton<DataTable<ScrollBase> >::getInstance()
#pragma pack(push, 1)
/**
 * \brief  商城
 */
struct ShopBase
{
	typedef DWORD KEY_TYPE;

	DWORD ID;
    WORD weight;
    WORD shoptype;
    BYTE itemType;
    WORD MinLevel;
    WORD MaxLevel;
    WORD itemId;
    BYTE moneyType;

    struct {
        WORD num;
        WORD probable;
    } itemNum[5];

    struct {
        DWORD price;
        WORD probable;
        WORD discount;
    } itemPrice[5];

    uint32 maxNumProbable;
    uint32 maxPriceProbable;
    static uint32 maxWeight;
    static uint32 maxArenaWeight;
    
    static uint32 GeneralShopStartId;
    static uint32 GeneralShopEndId;
    
    static uint32 ArenaShopStartId;
    static uint32 ArenaShopEndId;
    
	struct ExtCells {};

	KEY_TYPE getId() {return ID;}
	size_t getFixSize() {
        return sizeof(*this) - sizeof(maxNumProbable) - sizeof(maxPriceProbable);
    }
    size_t getExtSize() {return 0;}
	bool parse(ExtCells* ext) {
        DEBUG_LOG("ShopTable ID %u weight %u type %u id %u moneytype %u\n",
                  ID, weight, itemType, itemId, moneyType);
        if (moneyType == 1 || moneyType == 2)
        {
            if (GeneralShopStartId == 0)
                GeneralShopStartId = ID;
            
            GeneralShopEndId = ID;
            maxWeight += weight;
        }
        else if (moneyType == 3)
        {
            moneyType = uint8(LootType_ArenaPoint);
            if (ArenaShopStartId == 0)
                ArenaShopStartId = ID;

            ArenaShopEndId = ID;
            maxArenaWeight += weight;
        }
        maxNumProbable   = 0;
        maxPriceProbable = 0;
        
        for (int i = 0; i < 5; ++i)
        {
            maxNumProbable   += itemNum[i].probable;
            maxPriceProbable += itemPrice[i].probable;
            DEBUG_LOG("ShopTable DisCount %u\n", itemPrice[i].discount);
        }

        TRACE_LOG("ShopTable ID MoneyType %u GeneralStart %u GeneralEnd %u ArenaStart %u ArenaStart %u\n",
                  moneyType, GeneralShopStartId, GeneralShopEndId, ArenaShopStartId, ArenaShopEndId);
        return true;
    }
	bool check() {return true;}
};

struct RefreshShopBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD price;

	struct ExtCells {}; 
	KEY_TYPE getId() {return ID;} 
	size_t getFixSize() {return sizeof(*this);} 
	size_t getExtSize() {return 0;}
	bool parse(ExtCells* ext) {
        static int index = 0;
        if (ID > 0)
        {
            ++index;
            if (ID != index)
            {
                DEBUG_LOG("RefreshShopTable 的主键应该从 1 开始递增\n");
                return false;
            }
        }
        DEBUG_LOG("RefreshShopTable ID %u\n", ID);
        return true;
    }
	bool check() {return true;}
};

// 指定的商城物品ID
struct ShopConstBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD ItemNum;
    char constids[128];

    VECTOR_CONTAINER(uint32) vecids;
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return 132;           }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        std::string idsstr(constids);
        std::replace(idsstr.begin(), idsstr.end(), ',', ' ');
        std::istringstream ids(idsstr);
        while (ids) {
            uint32 id = 0;
            ids >> id;
            if (id == 0) continue;
            vecids.push_back(id);
            TRACE_LOG("ShopConstTable Id %u ConstId %u\n", ID, id);
        }
        return true;
    }
	bool check()              {return true;          }
};

// 指定的商城物品ID
struct ShopNormalBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD ShopType;
    BYTE ItemType;
    DWORD ItemId;
    WORD PriceType;
    WORD MoneyType;
    WORD Price;
    WORD BuyLimit;
    DWORD Count[13];

	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        TRACE_LOG("ShopNormalTable ID %u\n", ID);
        return true;
    }
	bool check()              {return true;          }
};

struct ShopNormalPriceBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    WORD Price[200];
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {
        TRACE_LOG("ShopNormalPriceTable ID %u\n", ID);
        return true;
    }
	bool check()              {return true;          }
};

struct HorseSoulBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    BYTE ItemType;
    DWORD ItemId;
    WORD PriceType;
    WORD Price;
    DWORD Count[13];
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }    
};

struct ScrollBase
{
    typedef WORD KEY_TYPE;

    WORD ID;
    BYTE ItemType;
    DWORD ItemId;
    WORD PriceType;
    WORD Price;
    DWORD Count[13];
    
	struct ExtCells {};
	KEY_TYPE getId()          {return ID;            }
	size_t getFixSize()       {return sizeof(*this); }
	size_t getExtSize()       {return 0;             }
	bool parse(ExtCells* ext) {return true;          }
	bool check()              {return true;          }    
};
#pragma pack(pop)
#endif
