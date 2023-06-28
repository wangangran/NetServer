#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <list>

void handler(int sig, siginfo_t *info, void *extra) {
    printf("Received signal: %d\n", sig);
    printf("Custom parameter: %ld\n", (long) extra);
}

std::list<int> getChildPid(int pid) {
    char cmd[48] = {0};
    memset(cmd, 0, sizeof(cmd));
    snprintf(cmd, sizeof(cmd) - 1, "pstree -p %d", pid);

    std::string cmdRet;
    if (execPopen(cmd, cmdRet) != 0) {
        return std::list<int>();
    }

    boost::regex r("(\\d{1,5})");                               // 匹配数字
    boost::smatch m;
    while (boost::regex_search(cmdRet, m, r)) {                 // 查找所有匹配项
        std::cout << "Match found: " << m.str() << std::endl;
        cmdRet = m.suffix().str();                              // 下一次从剩余字符串中查找
    }
}

int main() {

    struct sigaction sa;
    long parameter = 123;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) != 0) {
        printf("An error occurred while setting the handler.\n");
        exit(EXIT_FAILURE);
    }

    printf("Press CTRL+C...\n");

    while(1) {
        sleep(1);
    }

    return 0;
}