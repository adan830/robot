#include <fstream>
#include <sstream>
#include <iostream>
#include "Opcodes.h"
#include "Client.h"

Handler   gHandler;
Commander gCommander;

int main(int argc, char** argv) {
    tableOpcodes.BuildOpcodeList();
    tableOpcodes.BuildCmdList();
    tableSessions.InitFromFile();

    std::fstream fs;
    fs.open("server.txt", std::fstream::in);
    if (!fs.is_open()) {
        std::cout << "Need Server Config File\n";
        return false;
    }

    char line[256];
    fs.getline(line, 256);
    fs.close();
    
    string ip;
    uint16_t accountport = 0;
    uint16_t gatewayport = 0;
    
    std::stringstream ss(line);
    ss >> ip >> accountport >> gatewayport;
    
    EventLoop loop;

    InetAddress account(ip.c_str(), accountport);
    InetAddress gateway(ip.c_str(), gatewayport);
    
    Client client(&loop, account, gateway, 1, 10, 1);
    loop.loop();
    
    return 0;
}

