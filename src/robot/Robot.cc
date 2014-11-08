#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "Client.h"
#include "Robot.h"
#include <AccountMsg.h>

using namespace muduo;
using namespace muduo::net;

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
    AccountLoginCMsg amsg;
    amsg.accuid = m_sess.accuid;
    amsg.zoneId = 1015;
    strcpy(amsg.accountName, m_sess.account.c_str());
    strcpy(amsg.password,    m_sess.session.c_str());
    
    m_buffer.append(&msg, sizeof(msg));
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
    LOG_INFO << "Robot run" << Opcode;
    OpcodeHandle const& opHandler = tableOpcodes[Opcode];
    (this->*opHandler.handler)(recvPacket);
}

void Robot::getcmd()
{
    char *buf = readline("");
    if (buf == NULL || strlen(buf) < 1) {
        return;
    }

    if (history_search(buf, -1) == -1) {
        add_history(buf);
    }
    
    cmd = buf;
    free(buf);
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
