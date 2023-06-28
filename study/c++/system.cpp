#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

using namespace std;

#define MAX_BUF_SIZE 1024

pid_t child_pid = -1;

void sig_handler(int signum)
{
    if (child_pid > 0) {
        kill(child_pid, SIGTERM); // 发送SIGTERM信号终止子进程
    }
}

int main()
{

    signal(SIGALRM, sig_handler); // 注册SIGALRM信号处理函数

    char command[MAX_BUF_SIZE];
    sprintf(command, "%s", "/bin/mount -t nfs -o nolock,retry=1,namlen=896,port=2049 172.16.10.29:/nfs_send /srv/war/nfs/ ;echo $?");

    FILE* fp = popen(command, "r"); // 执行命令并获取输出流
    if (!fp) {
        cout << "popen error!" << endl;
        return -1;
    }

    alarm(3); // 设置闹钟3秒后发送SIGALRM信号

    char buf[MAX_BUF_SIZE];
    while (fgets(buf, MAX_BUF_SIZE, fp)) {
        cout << buf; // 输出命令执行结果
    }

    pclose(fp);

    return 0;
}