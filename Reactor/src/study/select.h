#ifndef _SELECT_H_
#define _SELECT_H_

#include <sys/select.h>

class Select{
public:
    explicit Select(int listenfd);
    ~Select();

    void loop();
private:
    fd_set  rfds;
    fd_set  rset;
    fd_set  wfds;
    fd_set  wset;

    int listenfd_ = 0;
    int maxFd_ = 0;
};

#endif