#include "Opcodes.h"
#include "Client.h"

int main(int argc, char** argv) {
    tableOpcodes.BuildOpcodeList();
    tableOpcodes.BuildCmdList();
    tableSessions.InitFromFile();

    EventLoop loop;
    InetAddress account("192.168.0.243", 6668);
    InetAddress gateway("192.168.0.243", 6607);
    
    Client client(&loop, account, gateway, 1, 10, 2);
    loop.loop();
    
    return 0;
}

