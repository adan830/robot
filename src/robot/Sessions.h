#ifndef SESSION_H
#define SESSION_H
#include "Common.h"

using namespace muduo;
using namespace muduo::net;

struct SessionParam {
    uint64 accuid;
    string account;
    string session;

    SessionParam() : accuid(0) {}
    void set(uint64 _uid, string& _act, string& _sess) {
        accuid  = _uid;
        account = _act;
        session = _sess;
    }
};

typedef std::map<string, SessionParam> SessionMap;
class Sessions
{
  public :
    void AddSession(uint64 uid, string& account, string& session);

    // 多线程情况下，可能存在问题
    bool GetSession(SessionParam& sess);
    void RemoveSession(string& account);
    size_t size();
    bool SaveToFile(uint64 uid, string& account, string& session);
    bool InitFromFile();
    
  private :
    SessionMap mSessionMap;
};
#define tableSessions Singleton<Sessions>::instance()
#endif
