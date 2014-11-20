#ifndef __CMD_H__
#define __CMD_H__
#include <map>
#include "Opcodes.h"
#include "Sessions.h"
#include "Common.h"
#include "Codec.h"

using namespace muduo;
using namespace muduo::net;

class Cmd
{
  public :
    Cmd(){}
    ~Cmd(){}

    void Op(Buffer& buffer, std::string& cmdstr);
    void OpDungeonFight(Buffer& buffer);
    
  private :
    int    p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
    std::string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
};
#define siCmd Singleton<Cmd>::instance()
#endif

