#include "select.h"
#include <sys/socket.h>
#include <iostream>
#include <strings.h>
#include <unistd.h>

using namespace std;
const unsigned int RECVBUFSIZE = 4096;

Select::Select(int listenfd)
{
    FD_ZERO(&rfds);
    FD_ZERO(&wfds);

    FD_SET(listenfd, &rfds);
    listenfd_ = listenfd;
}

Select::~Select()
{

}

void Select::loop()
{
    int maxfd = listenfd_;
    int recvNum  = 0;
    unsigned char buf[RECVBUFSIZE];
    while(true) {
        rset = rfds;
        wset = wfds;

        int ready = ::select(maxfd + 1, &rset, &wset, nullptr, nullptr);
    
        if (FD_ISSET(listenfd_, &rset)) {
            sockaddr clientaddr;
            socklen_t clientlen = static_cast<socklen_t>(sizeof(clientaddr));
            
            int clientfd = ::accept4(listenfd_, &clientaddr, &clientlen, /*SOCK_NONBLOCK |*/ SOCK_CLOEXEC);
            if (-1 == clientfd) {
                cout << "accept4 error" << endl;
                return;
            } else {
                cout << "======client connect success fd:" << clientfd << "=====" << endl;
            }

            maxfd = (clientfd > maxfd) ? clientfd : maxfd;
            FD_SET(clientfd, &rfds);
            if (--ready == 0) continue;
        }

        cout << "recv success " << maxfd << endl;
        for (int i = listenfd_ + 1; i <= maxfd; ++i) {
            if (FD_ISSET(i, &rset)) {
                bzero(buf, sizeof(buf));
                recvNum = recv(i, buf, sizeof(buf), 0);
                if (recvNum == 0) {
                    cout << "client closed!!!" << endl;
                    FD_CLR(i, &rfds);
                    ::close(i);
                } else if (recvNum > 0) {
                    cout << " recv success size: " << recvNum << endl;
                    FD_SET(i, &wfds);
                }
            } else if (FD_ISSET(i, &wset)) {
                ::send(i, buf, recvNum, 0);
                FD_CLR(i, &wfds);
                cout << "send success" << endl;
            } 
        }        
    }
}