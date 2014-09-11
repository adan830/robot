#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "Client.h"
#include "Robot.h"

using namespace muduo;
using namespace muduo::net;

void Robot::onAccountConnection(const TcpConnectionPtr& conn)
{
    if (conn->connected()) {
        LOG_INFO << conn->name() << "onAccountConnection";
        /*
        VerifyCMsg msg;
        GuestAccountCMsg gmsg;

        buf.append(&msg, sizeof(msg));
        buf.append(&gmsg, sizeof(gmsg));
        */
        Buffer buf;
        conn->setTcpNoDelay(true);
        conn->send(&buf);
        owner_->onConnect();
    } else {
        GatewayConnect();
    }
}

void Robot::onGatewayConnection(const TcpConnectionPtr& conn)
{
    if (conn->connected()) {
        LOG_INFO << conn->name() << "onGatewayConnect";
        conn->setTcpNoDelay(true);
        /*
        VerifyCMsg msg;
        msg.taskType = 1;
        m_buffer.append(&msg, sizeof(msg));
        */
        conn->send(&m_buffer);
        OpLoginBySession();
        owner_->onConnect();
    } else {
        owner_->onDisconnect(conn);
    }
}

void Robot::run(uint16 Opcode, Buffer* recvPacket)
{
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
    account_.connection()->send(&m_buffer);
}
