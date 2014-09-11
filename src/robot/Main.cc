#include "Client.h"

int main(int argc, char** argv) {
    EventLoop loop;
    InetAddress account("192.168.0.243", 6668);
    InetAddress gateway("192.168.0.243", 6200);
    
    Client client(&loop, account, gateway, 0, 0, 0, 0);

    return 0;
}

