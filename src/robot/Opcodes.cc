#include "Opcodes.h"

OpcodeHandle const Opcodes::emptyHandler =
{
    &Robot::HandleNULL
};
    
Opcodes::Opcodes()
{}

Opcodes::~Opcodes()
{}


void Opcodes::BuildOpcodeList()
{
    StoreOpcode(GUEST_ACCOUNT,      &Robot::HandlerGuestAccountOpcode);
    StoreOpcode(ALL_ZONE_LIST,      &Robot::HandlerAllZoneListOpcode);
    StoreOpcode(ROLE_LIST,          &Robot::HandlerRoleListOpcode);
    StoreOpcode(ACCOUNT_LOGIN_SMSG, &Robot::HandlerAccountLoginSMsgOpcode);
}

void Opcodes::BuildCmdList()
{
    StoreCmdCode("df", &Commander::OpDungeonFight);
}

