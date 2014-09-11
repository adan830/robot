#ifndef MUDUO_EXAMPLES_ASIO_CHAT_CODEC_H
#define MUDUO_EXAMPLES_ASIO_CHAT_CODEC_H

#include <muduo/base/Logging.h>
#include <muduo/net/Buffer.h>
#include <muduo/net/Endian.h>
#include <muduo/net/TcpConnection.h>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

class LengthHeaderCodec : boost::noncopyable
{
  public:
    typedef boost::function<void (const muduo::net::TcpConnectionPtr&,
                                  int opcode,
                                  muduo::net::Buffer* message,
                                  muduo::Timestamp)> GameMsgCallback;

    explicit LengthHeaderCodec(const GameMsgCallback& cb)
        : messageCallback_(cb)
    {
    }

    void onMessage(const muduo::net::TcpConnectionPtr& conn,
                   muduo::net::Buffer* buf,
                   muduo::Timestamp receiveTime)
    {
        while (buf->readableBytes() >= kHeaderLen) // kHeaderLen == 4
        {
            // FIXME: use Buffer::peekInt32()
            const void* data = buf->peek();
            size_t len = *static_cast<const int16_t*>(data); // SIGBUS
//            int16_t len = muduo::net::sockets::networkToHost16(be16);
            if (len >= 65535 || len <= 0)
            {
                LOG_ERROR << "Invalid length " << len;
                conn->shutdown();  // FIXME: disable reading
                break;
            }
            else if (len > kHeaderLen && buf->readableBytes() >= (len - kHeaderLen))
            {
                const char * end = buf->peek() + len;
                buf->retrieve(kHeaderLen);
                uint16 opcode = buf->readInt16();
                messageCallback_(conn, opcode, buf, receiveTime);
                if (buf->readableBytes())
                {
                    buf->retrieveUntil(end);
                }
            }
            else
            {
                break;
            }
        }
    }

    // FIXME: TcpConnectionPtr
    void send(muduo::net::TcpConnection* conn,
              const muduo::StringPiece& message)
    {
        muduo::net::Buffer buf;
        buf.append(message.data(), message.size());
        int32_t len = static_cast<int32_t>(message.size());
        int32_t be32 = muduo::net::sockets::hostToNetwork32(len);
        buf.prepend(&be32, sizeof be32);
        conn->send(&buf);
    }

  private:
    GameMsgCallback messageCallback_;
    const static size_t kHeaderLen = sizeof(uint16);
};

#endif  // MUDUO_EXAMPLES_ASIO_CHAT_CODEC_H
