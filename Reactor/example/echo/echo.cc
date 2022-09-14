#include <iostream>
#include "net/TcpServer.h"

using namespace sunwar::net;

int main(int argc, char *argv[])
{
    HostAddr addr(8082);
    TcpServer server(addr);
    server.startLoop();
    return 0;
}   