#include "Robot.h"
#include <AccountMsg.h>
#include <RoleMsg.h>

void Robot::SetSessAccUid(uint64 accuid)
{
    m_sess.accuid = accuid;
}

void Robot::SetSessAccount(string& account)
{
    m_sess.account = account;
}

void Robot::SetSessSign(string& sign)
{
    m_sess.session = sign;
}

void Robot::SetDestZone(int zoneid)
{
    mDestZone = static_cast<uint16>(zoneid);
}
