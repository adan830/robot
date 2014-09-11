#include "Robot.h"

void Robot::HandlerGuestAccountOpcode(Buffer* recvPacket)
{
    /*
    string account     = recvPacket->retrieveAsString(ACCOUNT_NAME_SIZE);
    string password    = recvPacket->retrieveAsString(PASSWORD_SIZE);
    uint64 uid         = recvPacket->readInt64();
    string sign        = recvPacket->retrieveAsString(PLAYER_SIGN_SIZE);
    tableSessions.AddSession(uid, account, sign);
    */
}

void Robot::HandlerRoleListOpcode(Buffer* recvPacket)
{
    uint8 count = recvPacket->readInt8();
    for (int i = 0; i < count; ++i) {
//        uint32 RoleId = recvPacket->readInt32();
//        string name   = recvPacket->retrieveAsString(PLAYER_NAME_SIZE);
//        LOG_INFO << "RoleId" << RoleId << "Name" << name;
    }
}

