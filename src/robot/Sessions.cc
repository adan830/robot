#include <fstream>
#include <sstream>
#include "Sessions.h"

void Sessions::AddSession(uint64 uid, string& account, string& session)
{
    mSessionMap[account].set(uid, account, session);
    SaveToFile(uid, account, session);
}

bool Sessions::GetSession(SessionParam& sess)
{
    if (mSessionMap.size() == 0) {
        return false;
    } else {
        sess = mSessionMap.begin()->second;
        return true;
    }
}

void Sessions::RemoveSession(string& account)
{
    SessionMap::iterator it = mSessionMap.find(account);
    if (it != mSessionMap.end())
        mSessionMap.erase(it);
}

size_t Sessions::size()
{
    return mSessionMap.size();
}

bool Sessions::empty()
{
    return mSessionMap.empty();
}

bool Sessions::SaveToFile(uint64 uid, string& account, string& session)
{
    std::fstream fs;
    fs.open("account.txt", std::fstream::out | std::fstream::app);
    fs << uid << "\t"
       << account.c_str() << "\t"
       << session.c_str() << "\n";
    
    fs.close();
    return true;
}

bool Sessions::InitFromFile()
{
    std::fstream fs;
    fs.open("account.txt", std::fstream::in);
    if (!fs.is_open())
        return false;

    char line[256];
    uint64 uid;
    string account;
    string password;
    string session;

    while (fs.getline(line, 256)) {
        std::stringstream ss(line);
        ss >> uid >> account >> session;
        if (uid > 0)
        {
            mSessionMap[account].set(uid, account, session);
            LOG_INFO << "InitFromFile " << account << session;
        }
    }

    LOG_INFO << "读入了" << mSessionMap.size() << "条 Session";

    fs.close();

    return true;
}

