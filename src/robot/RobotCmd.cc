#include "Robot.h"
#include <AccountMsg.h>
#include <RoleMsg.h>

void Robot::OpLoginAccount()
{
    SessionParam sess;
    if (false == tableSessions.GetSession(sess))
        return;

    tableSessions.RemoveSession(sess.account);

    AccountLoginCMsg msg;
    m_buffer.appendInt16(sizeof(AccountLoginCMsg));
    m_buffer.appendInt16(AccountLoginCMsg::id);
    m_buffer.appendInt64(sess.accuid);
    m_buffer.append(sess.account);
    m_buffer.append(sess.session);
    m_buffer.appendInt8(0);
    m_buffer.appendInt16(1010);

    sendGateway();
}

void Robot::OpLoginGatewayBySession(const TcpConnectionPtr& conn)
{
    VerifyCMsg vmsg;
    vmsg.taskType = 1;
    m_buffer.append(&vmsg, sizeof(vmsg));

    SessionIDLoginCMsg msg;
    m_buffer.appendInt16(sizeof(SessionIDLoginCMsg));
    m_buffer.appendInt16(SessionIDLoginCMsg::id);
    m_buffer.appendInt64(m_sess.accuid);
    m_buffer.appendInt32(0);
    m_buffer.append(m_sess.session);
    m_buffer.appendInt8(0);
    m_buffer.appendInt16(1015);

    sendGateway();
//    conn->send(&m_buffer);
}

void Robot::OpCreateRole()
{
    CreateRoleCMsg msg;
    strcpy(msg.playerName, m_sess.account.c_str());
    msg.cardKey = 0;
    m_buffer.append(&msg, sizeof(msg));
    sendGateway();
}

