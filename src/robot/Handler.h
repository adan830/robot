#ifndef __HANDLER_H__
#define __HANDLER_H__
#include <map>
#include "Opcodes.h"
#include "Sessions.h"
#include "Common.h"
#include "Codec.h"

class Robot;
using namespace muduo;
using namespace muduo::net;

class Handler
{
  public :
    Handler(){}
    ~Handler(){}
    
  public :
    void SetRobot(Robot * const probot);
    void Exec(uint32 code, Buffer& recvPacket);
    void HandleNULL(Buffer& recvPacket);
    void HandlerGuestAccountOpcode(Buffer& recvPacket);
    void HandlerAllZoneListOpcode(Buffer& recvPacket);
    void HandlerRoleListOpcode(Buffer& recvPacket);
    void HandlerAccountLoginSMsgOpcode(Buffer& recvPacket);
    
  private :
    Robot * mRobot;
    int    p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
    std::string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
};
#define siHandler Singleton<Handler>::instance()
#endif

