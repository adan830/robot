#include "Robot.h"

void Robot::OpLoginBySession()
{
    SessionParam sess;
    if (false == tableSessions.GetSession(sess))
        return;

    tableSessions.RemoveSession(sess.account);
/*    
    SessionIDLoginCMsg msg;
    m_buffer.appendInt16(sizeof(SessionIDLoginCMsg));
    m_buffer.appendInt16(SessionIDLoginCMsg::id);
    m_buffer.appendInt64(sess.uid);
    m_buffer.appendInt32(0);
    m_buffer.append(sess.session);
    m_buffer.appendInt8(0);
    m_buffer.appendInt16(1010);
*/
    sendGateway();
}

