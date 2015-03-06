#include <vector>
#include <sstream>
#include <algorithm>
#include <DBEntity.h>
#include <BattleMsg.h>
#include <WorshipMsg.h>
#include <OfficerMsg.h>
#include "Commander.h"

void Commander::Op(Buffer& buffer, std::string& cmdstr)
{
    std::for_each(cmdstr.begin(), cmdstr.end(), [](char c) {
            if (c >= 'A' && c <= 'Z') {
                c = static_cast<char>(c + 'a' - 'A');
            }
        });
    
    std::istringstream inputstr(cmdstr);
    std::string cmd;
    std::vector<std::string> params(10, "0");
    
    inputstr >> cmd;
    
    uint8 i = 0;
    while (i < 10 && inputstr) {
        inputstr >> params[i];
        i++;
    }

    s1  = params[0]; p1  = atol(s1.c_str());
    s2  = params[1]; p2  = atol(s2.c_str());
    s3  = params[2]; p3  = atol(s3.c_str());
    s4  = params[3]; p4  = atol(s4.c_str());
    s5  = params[4]; p5  = atol(s5.c_str());
    s6  = params[5]; p6  = atol(s6.c_str());
    s7  = params[6]; p7  = atol(s7.c_str());
    s8  = params[7]; p8  = atol(s8.c_str());
    s9  = params[8]; p9  = atol(s9.c_str());
    s10 = params[8]; p10 = atol(s10.c_str());

    Command const* Cmd = tableOpcodes.LookupCmd(cmd);
    if (Cmd) {
        (this->*Cmd->handler)(buffer);
    }
}

void Commander::OpDungeonFight(Buffer& buffer)
{
    DungeonFightCMsg msg;
    msg.dungeon = p1;
    msg.hard = static_cast<uint8>(std::min(std::max(1, p2), 3));
    msg.mode = static_cast<uint8>(std::min(std::max(1, p3), 2));
    buffer.append(&msg, sizeof(msg));
}

void Commander::OpWorship(Buffer& buffer)
{
    WorshipOpCMsg msg;
    msg.op    = p1;
    msg.param = p2;
    buffer.append(&msg, sizeof(msg));
}

void Commander::OpOfficer(Buffer& buffer)
{
    OfficerOpCMsg msg;
    msg.op    = p1;
    msg.param = p2;
    buffer.append(&msg, sizeof(msg));
}
