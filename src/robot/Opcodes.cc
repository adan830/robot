#include "Opcodes.h"

OpcodeHandle const Opcodes::emptyHandler =
{
    &Handler::HandleNULL
};
    
Opcodes::Opcodes()
{}

Opcodes::~Opcodes()
{}


void Opcodes::BuildOpcodeList()
{
    StoreOpcode(GUEST_ACCOUNT,      &Handler::HandlerGuestAccountOpcode);
    StoreOpcode(ALL_ZONE_LIST,      &Handler::HandlerAllZoneListOpcode);
    StoreOpcode(ROLE_LIST,          &Handler::HandlerRoleListOpcode);
    StoreOpcode(ACCOUNT_LOGIN_SMSG, &Handler::HandlerAccountLoginSMsgOpcode);
}

void Opcodes::BuildCmdList()
{
    StoreCmdCode("df", &Commander::OpDungeonFight);
    StoreCmdCode("ws", &Commander::OpWorship);
    StoreCmdCode("of", &Commander::OpOfficer);
}

