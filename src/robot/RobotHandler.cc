#include "Define.h"
#include "Robot.h"
void Robot::HandleNULL(Buffer* recvPacket)
{
    LOG_INFO << "Unknow Msg. ";
}

void Robot::HandlerGuestAccountOpcode(Buffer* recvPacket)
{
    string account     = recvPacket->retrieveAsString(ACCOUNT_NAME_SIZE);
    string password    = recvPacket->retrieveAsString(PASSWORD_SIZE);
    uint64 uid         = recvPacket->readInt64();
    string sign        = recvPacket->retrieveAsString(PLAYER_SIGN_SIZE);
    tableSessions.AddSession(uid, account, sign);
    GatewayConnect();
}

void Robot::HandlerRoleListOpcode(Buffer* recvPacket)
{
    uint32 target = recvPacket->readInt32();
    LOG_INFO << "Target : " << target;
    uint8 count = recvPacket->readInt8();
    for (int i = 0; i < count; ++i) {
        uint32 RoleId = recvPacket->readInt32();
        uint64 CharId = recvPacket->readInt64();
        string name   = recvPacket->retrieveAsString(PLAYER_NAME_SIZE);
        uint32 LeadCard = recvPacket->readInt32();
        LOG_INFO << "RoleId : "   << RoleId
                 << "\tCharId : " << CharId
                 << "\tName : "   << name
                 << "\tLeadCard : " << LeadCard;
    }

    // 角色列表为空，申请创角
    if (count == 0)
    {
        OpCreateRole();   
    }
}

void Robot::HandlerAccountLoginSMsgOpcode(Buffer* recvPacket)
{
    LOG_INFO << "HandlerAccountLoginSMsgOpcode";
    uint64 accuid = recvPacket->readInt64();
    recvPacket->readInt8();
    string sign   = recvPacket->retrieveAsString(PLAYER_SIGN_SIZE);

    LOG_INFO << "accuid : " << accuid << "  sign : " << sign;
    m_sess.session = sign;
    GatewayConnect();
}

