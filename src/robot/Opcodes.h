#ifndef SGROBOT_OPCODES_H
#define SGROBOT_OPCODES_H
#include "Common.h"
#include "Robot.h"

using namespace muduo;
using namespace muduo::net;

class Robot;
enum OpcodesList
{
    GUEST_ACCOUNT = 0x18,
    ALL_ZONE_LIST = 0x1A,
    ROLE_LIST     = 0x801,
};

struct OpcodeHandle
{
    void (Robot::*handler)(Buffer* recvPacket);
};

typedef std::map<int, OpcodeHandle> OpcodeMap;
class Opcodes
{
  public :
    Opcodes();
    ~Opcodes();

    void BuildOpcodeList();
    void StoreOpcode(int Opcode, void (Robot::*handler)(Buffer* recvPacket))
    {
        OpcodeHandle& ref = mOpcodeMap[Opcode];
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
    
    static OpcodeHandle const emptyHandler;
    
    OpcodeMap mOpcodeMap;
};

#define tableOpcodes Singleton<Opcodes>::instance()
#endif
