#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "Client.h"
#include "Robot.h"
#include <AccountMsg.h>
#include "Misc.hpp"

using namespace muduo;
using namespace muduo::net;

extern Handler gHandler;
void Robot::onAccountConnection(const TcpConnectionPtr& conn)
{
    if (conn->connected()) {
        conn->setTcpNoDelay(true);
        LOG_INFO << conn->name() << "onAccountConnection";

        if (m_sess.accuid == 0) {
            ApplyAccount(conn);
        } else {
            RequestVerifySession(conn);
        }
    }
}

void Robot::onGatewayConnection(const TcpConnectionPtr& conn)
{
    if (conn->connected()) {
        LOG_INFO << conn->name() << "onGatewayConnect";
        conn->setTcpNoDelay(true);
        OpLoginGatewayBySession(conn);
    } else {
        owner_->onDisconnect(conn);
    }
}

void Robot::ApplyAccount(const TcpConnectionPtr& conn)
{
    VerifyCMsg msg;
    GuestAccountCMsg gmsg;

    m_buffer.append(&msg, sizeof(msg));
    m_buffer.append(&gmsg, sizeof(gmsg));
    conn->send(&m_buffer);
}

void Robot::RequestVerifySession(const TcpConnectionPtr& conn)
{
    VerifyCMsg msg;
    m_buffer.append(&msg, sizeof(msg));
    
    AllZoneListCMsg zmsg;
    zmsg.accuid = m_sess.accuid;
    m_buffer.append(&zmsg, sizeof(zmsg));
    
    AccountLoginCMsg amsg;
    amsg.accuid = m_sess.accuid;
    amsg.zoneId = mDestZone;
    strcpy(amsg.accountName, m_sess.account.c_str());
    strcpy(amsg.password,    m_sess.session.c_str());
    m_buffer.append(&amsg, sizeof(amsg));
    conn->send(&m_buffer);
}

void Robot::GetSession()
{
    SessionParam sess;
    if (false == tableSessions.GetSession(sess))
        return;

    tableSessions.RemoveSession(sess.account);
    m_sess = sess;
}

void Robot::run(uint16 Opcode, Buffer* recvPacket)
{
    char hex[32] = {0};
    dectohex(hex, Opcode);
    LOG_INFO << "MsgId " << hex;
    gHandler.SetRobot(this);
    HandlerFunc(Opcode, *recvPacket);
}

void Robot::OpReadCmd()
{
    while (true) {
        char *buf = readline("");
        if (buf == NULL || strlen(buf) < 1) {
            continue;
        }

        if (history_search(buf, -1) == -1) {
            add_history(buf);
        }
    
        cmd = buf;
        free(buf);
        ExecCmdFunc(m_buffer, cmd);
        sendGateway();
    }
}

void Robot::execcmd()
{
    printf("%s\n", cmd.c_str());
}


void Robot::sendAccount()
{
    account_.connection()->send(&m_buffer);
}

void Robot::sendGateway()
{
    gateway_.connection()->send(&m_buffer);
}
