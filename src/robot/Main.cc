#include "Opcodes.h"
#include "Client.h"

int main(int argc, char** argv) {
    tableOpcodes.BuildOpcodeList();
    tableOpcodes.BuildCmdList();
    tableSessions.InitFromFile();

    EventLoop loop;
    if (argc > 1) {
        InetAddress account("221.228.205.91", 9002);
        InetAddress gateway("221.228.205.91", 11002);
    
        Client client(&loop, account, gateway, 1, 10, 2);
        loop.loop();
    } else {
        InetAddress account("192.168.0.243", 6668);
        InetAddress gateway("192.168.0.243", 6607);
    
        Client client(&loop, account, gateway, 1, 10, 2);
        loop.loop();
    }
    
    return 0;
}

