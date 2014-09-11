#ifndef SESSION_H
#define SESSION_H
#include "Common.h"

using namespace muduo;
using namespace muduo::net;

struct SessionParam {
    uint64 uid;
    string account;
    string session;

    void set(uint64 _uid, string& _act, string& _sess) {
        uid     = _uid;
        account = _act;
        session = _sess;
    }
};

typedef std::map<string, SessionParam> SessionMap;
class Sessions
{
  public :
    void AddSession(uint64 uid, string& account, string& session) {
        mSessionMap[account].set(uid, account, session);
    }

    // 多线程情况下，可能存在问题
    bool GetSession(SessionParam& sess) {
        if (mSessionMap.size() == 0) {
            return false;
        } else {
            sess = mSessionMap.begin()->second;
            return true;
        }
    }

    void RemoveSession(string& account) {
        SessionMap::iterator it = mSessionMap.find(account);
        if (it != mSessionMap.end())
            mSessionMap.erase(it);
    }
    
    size_t size() {
        return mSessionMap.size();
    }
  private :
    SessionMap mSessionMap;
};
#define tableSessions Singleton<Sessions>::instance()
#endif
