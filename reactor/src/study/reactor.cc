#include <iostream>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h>
#include "select.h"

using namespace std;

const unsigned int RECVBUFSIZE = 4096;

void* recvFun (void *arg) {
    int clientfd = *(int*)(arg);
    while (true) {
        unsigned char buf[RECVBUFSIZE];
        bzero(buf, sizeof(buf));
        int ret = recv(clientfd, buf, sizeof(buf), 0);
        if (ret == 0) {
            cout << "client closed!!!" << endl;
            ::close(clientfd);
            return 0;
        } else if (ret > 0) {
            ::send(clientfd, buf, ret, 0);
            cout << "send success" << endl;
        }
    }
}

int main (int argc, char *argv[]) {
    int listenfd = ::socket(AF_INET, SOCK_STREAM | /*SOCK_NONBLOCK |*/ SOCK_CLOEXEC, IPPROTO_TCP);
    if (-1 == listenfd) {
        cout << "open socket error" << endl;        
        return -1;
    }

    int flag = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEPORT, &flag, sizeof(flag));

    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(8888);
    if (-1 == ::bind(listenfd, (const struct sockaddr*)&addr, sizeof(sockaddr))) {
        cout << "bind address port error" << endl;
        return -1;
    }

    if (-1 == ::listen(listenfd, 10)) {
        cout << "listen error" << endl;
        return -1;
    }

    Select sel(listenfd);
    sel.loop();
#if 0
    while (true) {
        sockaddr clientaddr;
        socklen_t clientlen = static_cast<socklen_t>(sizeof(clientaddr));
        
        int clientfd = ::accept4(listenfd, &clientaddr, &clientlen, /*SOCK_NONBLOCK |*/ SOCK_CLOEXEC);
        if (-1 == clientfd) {
            cout << "accept4 error" << endl;
            return -1;
        } 

        pthread_t threadId;
        pthread_create(&threadId, NULL, recvFun, (void*)(&clientfd));
    }
 #endif
    close(listenfd);
    return 0;
}