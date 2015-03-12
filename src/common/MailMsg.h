#ifndef __MAIL_MSG__
#define __MAIL_MSG__

#include "BaseMsg.h"
#include "DBEntity.h"

CORE_NAMESPACE_START

#pragma pack(push, 1)
struct MailOpCMsg : public PlayerMsg
{
    enum { id = 0xB00 };

    int op;     // 0 请求数据 1 查看详情 2 领取奖励 3 删除邮件 
    int param;  // (op = 1,2,3) 表示邮件的 ID

    MailOpCMsg()
        : PlayerMsg(id, sizeof(*this))
    {}
};

struct MailListSMsg : public PlayerMsg
{
    enum { id = 0xB01 };

    int count;

    struct Mail {
        int  Id;            // 邮件ID
        char Title[256];    // 标题
        int  MailType;      // 邮件类型
        int  P1;            // 
        int  P2;            // 
        int  P3;            //
        int  P4;            //
        char Name[32];      // 对方名字
        int  CreateTime;    // 创建时间
        int  ReadTime;      // 阅读时间
        int  Status;        // 邮件状态(0 正常 1 可领取 2 已领取/已阅读
    } list[0];

    MailListSMsg()
        : PlayerMsg(id, sizeof(*this))
        , count(0)
    {}

    int getSize() {
        return sizeof(*this) + count * sizeof(list[0]);
    }
};

struct MailDetailSMsg : public PlayerMsg
{
    enum { id = 0xB02 };

    int  Id;

    Attach list[5];
    
    int  count;
    char content[0];  // 邮件内容
    
    MailDetailSMsg()
        : PlayerMsg(id, sizeof(*this))
        , Id(0)
        , count(0)
    {}

    int getSize() {
        return sizeof(*this) + count;
    }
};

struct NewNoticelSMsg : public PlayerMsg
{
    enum { id = 0xB03 };

    int notice;
    
    NewNoticelSMsg()
        : PlayerMsg(id, sizeof(*this))
        , notice(0)
    {}
};

struct MailTimeSMsg : public PlayerMsg
{
    enum { id = 0x804 };

    int ID;
    int ReadTime;

    MailTimeSMsg()
        : PlayerMsg(id, sizeof(*this))
        , ID(0)
        , ReadTime(0)
    {}
};

#pragma pack(pop)

CORE_NAMESPACE_END
#endif
