#ifndef SGROBOT_OPCODES_H
#define SGROBOT_OPCODES_H
#include "Common.h"
#include "Handler.h"
#include "Commander.h"

using namespace muduo;
using namespace muduo::net;

class Handler;
class Commander;
enum OpcodesList
{
    GUEST_ACCOUNT      = 0x18,
    ALL_ZONE_LIST      = 0x1A,
    ROLE_LIST          = 0x801,
    ACCOUNT_LOGIN_SMSG = 0x1B,
};

struct OpcodeHandle
{
    void (Handler::*handler)(Buffer& recvPacket);
};

struct Command
{
    void (Commander::*handler)(Buffer& sendPacket);
};

typedef std::map<int, OpcodeHandle> OpcodeMap;
typedef std::map<std::string, Command>      CmdMap;
class Opcodes
{
  public :
    Opcodes();
    ~Opcodes();

    void BuildOpcodeList();
    void BuildCmdList();
    
    void StoreOpcode(int Opcode, void (Handler::*handler)(Buffer& recvPacket))
    {
        OpcodeHandle& ref = mOpcodeMap[Opcode];
        ref.handler = handler;
    }

    void StoreCmdCode(std::string cmd, void (Commander::*handler)(Buffer& sendPacket))
    {
        Command& ref = mCmdMap[cmd];
        ref.handler = handler;
    }
    
    inline OpcodeHandle const* LookupOpcode(int id) const
    {
        OpcodeMap::const_iterator itr = mOpcodeMap.find(id);
        if (itr != mOpcodeMap.end())
        {
            return &itr->second;
        }
        return NULL;
    }
    
    inline OpcodeHandle const& operator[](int id) const
    {
        OpcodeMap::const_iterator itr = mOpcodeMap.find(id);
        if (itr != mOpcodeMap.end())
        {
            return itr->second;
        }
        return emptyHandler;
    }

    inline Command const* LookupCmd(std::string cmd) const
    {
        CmdMap::const_iterator itr = mCmdMap.find(cmd);
        if (itr != mCmdMap.end())
        {
            return &itr->second;
        }
        return NULL;
    }

    static OpcodeHandle const emptyHandler;
    static Command const emptyCmd;
    
    OpcodeMap mOpcodeMap;
    CmdMap    mCmdMap;
};

#define tableOpcodes Singleton<Opcodes>::instance()
#endif

