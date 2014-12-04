#ifndef __ROBOT_H__
#define __ROBOT_H__

#include <functional>
#include <map>
#include "Opcodes.h"
#include "Sessions.h"
#include "Common.h"
#include "Codec.h"

using namespace muduo;
using namespace muduo::net;

typedef void (*robotcmd)();
typedef std::map<std::string, robotcmd> cmdmap;
typedef std::function<void (uint32 code, Buffer&)> HandlerCallBack;
typedef std::function<void (Buffer&, std::string&)> CmdCallBack;

class Client;
class Robot : boost::noncopyable
{
  public:
  Robot(EventLoop* loop,
        const InetAddress& AccountServer,
        const InetAddress& GatewayServer,
        const string& name,
        Client* owner
        )
      : account_(loop, AccountServer, name),
        gateway_(loop, GatewayServer, name),
        owner_(owner),
        mCmdThread(boost::bind(&Robot::OpReadCmd, this), "CmdThread"),
        bytesRead_(0),
        bytesWritten_(0),
        messagesRead_(0),
        codec_(boost::bind(&Robot::onPlayerMsg, this, _1, _2, _3, _4)),
        mCharId(0)
    {
        account_.setConnectionCallback(boost::bind(&Robot::onAccountConnection, this, _1));
        account_.setMessageCallback(boost::bind(&LengthHeaderCodec::onMessage, &codec_, _1, _2, _3));
        
        gateway_.setConnectionCallback(boost::bind(&Robot::onGatewayConnection, this, _1));
        gateway_.setMessageCallback(boost::bind(&LengthHeaderCodec::onMessage, &codec_, _1, _2, _3));
    }

    void AccountConnect() { account_.connect(); }
    void AccountStop() { account_.disconnect(); }

    void GatewayConnect() { gateway_.connect(); }
    void GatewayStop() { gateway_.disconnect(); }
    
  public :
    void OpReadCmd();
    void SetHandlerCallBack(HandlerCallBack cb) { HandlerFunc = cb; }
    void SetExecCmdCallBack(CmdCallBack cb) { ExecCmdFunc = cb; }
    void OpLoginAccount();
    void OpLoginGatewayBySession();
    void OpCreateRole();
    void OpChooseRole();
    void OpSendCmd();
    void OpStartInput();
    
  public :
    void SetCharId(uint64 charid) { mCharId = charid; }
    void SetSessAccUid(uint64 accuid);
    void SetSessAccount(string& account);
    void SetSessSign(string& sign);
    void SetDestZone(int zoneid);

  public :
    void ApplyAccount();
    void ReqAllZoneList();
    void RequestVerifySession();

    void GetSession();
  private:
    void run(uint16 Opcode, Buffer* recvPacket);
    void getcmd();
    void execcmd();
    
    void onAccountConnection(const TcpConnectionPtr& conn);
    void onGatewayConnection(const TcpConnectionPtr& conn);
    void onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp) {}

    void onPlayerMsg(const TcpConnectionPtr& conn, uint16 opcode, Buffer* buffer, Timestamp) {
        run(opcode, buffer);
    }

    void sendAccount();
    void sendGateway();
    
    TcpClient    account_;
    TcpClient    gateway_;
    Buffer       m_buffer;
    Client*      owner_;
    Thread       mCmdThread;
    HandlerCallBack HandlerFunc;
    CmdCallBack  ExecCmdFunc;

    int64_t      bytesRead_;
    int64_t      bytesWritten_;
    int64_t      messagesRead_;
    std::string       cmd;
    SessionParam m_sess;
    uint16       mDestZone;
    LengthHeaderCodec codec_;
  private :
    uint64 mCharId;
};

#endif

