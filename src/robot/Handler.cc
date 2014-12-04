#include "Robot.h"
#include "Handler.h"

void Handler::SetRobot(Robot * const probot)
{
    mRobot = probot;
}

void Handler::Exec(uint32 code, Buffer& recvPacket)
{
    const OpcodeHandle Op = tableOpcodes[code];
    (this->*Op.handler)(recvPacket);
}

void Handler::HandleNULL(Buffer& recvPacket)
{
    LOG_INFO << "Unknow Msg. ";
}

void Handler::HandlerGuestAccountOpcode(Buffer& recvPacket)
{
    string account     = recvPacket.retrieveAsString(ACCOUNT_NAME_SIZE);
    string password    = recvPacket.retrieveAsString(PASSWORD_SIZE);
    uint64 uid         = recvPacket.readInt64();
    string sign        = recvPacket.retrieveAsString(PLAYER_SIGN_SIZE);
    tableSessions.AddSession(uid, account, sign);
    mRobot->GatewayConnect();
}

void Handler::HandlerAllZoneListOpcode(Buffer& recvPacket)
{
    int LastID = recvPacket.readInt16();
    int Count  = recvPacket.readInt16();

    LOG_INFO << "{AllZoneList "
             << "\tLastID : " << LastID
             << "\tCount : " << Count << "}";
    
    for (int i = 0; i < Count; ++i) {
        int ZoneID = recvPacket.readInt16();
        int State  = recvPacket.readInt8();
        string ZoneName = recvPacket.retrieveAsString(TINYSTR);

        // 机器人连接返回的第一个服务器
        mRobot->SetDestZone(ZoneID);
        
        LOG_INFO << "{ZoneID : " << ZoneID
                 << "\tState : " << State
                 << "\tZoneName : " << ZoneName << "}";
        break;
    }

    if (Count > 0) {
        mRobot->RequestVerifySession();
    }
}

void Handler::HandlerRoleListOpcode(Buffer& recvPacket)
{
    uint32 target = recvPacket.readInt32();
    LOG_INFO << "Target : " << target;
    uint8 count = recvPacket.readInt8();
    for (int i = 0; i < count; ++i) {
        uint32 RoleId = recvPacket.readInt32();
        uint64 CharId = recvPacket.readInt64();
        string name   = recvPacket.retrieveAsString(PLAYER_NAME_SIZE);
        uint32 LeadCard = recvPacket.readInt32();
        LOG_INFO << "RoleId : "   << RoleId
                 << "\tCharId : " << CharId
                 << "\tName : "   << name
                 << "\tLeadCard : " << LeadCard;

        mRobot->SetCharId(CharId);
        break;
    }

    // 角色列表为空，申请创角
    if (count == 0)
    {
        mRobot->OpCreateRole();   
    }
    else
    {
        mRobot->OpChooseRole();
    }
}

void Handler::HandlerAccountLoginSMsgOpcode(Buffer& recvPacket)
{
    LOG_INFO << "HandlerAccountLoginSMsgOpcode";
    uint64 accuid = recvPacket.readInt64();
    recvPacket.readInt8();
    string sign   = recvPacket.retrieveAsString(PLAYER_SIGN_SIZE);

    LOG_INFO << "accuid : " << accuid << "  sign : " << sign;
    mRobot->SetSessSign(sign);
    mRobot->GatewayConnect();
    mRobot->OpStartInput();
}


