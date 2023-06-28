#include <signal.h>
#include <stdio.h>

#include <cstdio>
#include <iostream>
#include <string>
#include <regex>



int GetSystemRet(const std::string &cmd) {			//获取执行命令的返回值
	FILE *lp_fd;
	char  lz_line[64]={0};
	signal(SIGCHLD,SIG_DFL);
	if((lp_fd = popen(cmd.c_str(), "r")) == NULL){
		return -1;
	}
	memset(lz_line, '\0', sizeof(lz_line));
	while ((fgets(lz_line, sizeof(lz_line), lp_fd)) != NULL) {
		pclose(lp_fd);
		printf("result=[%s]\n",lz_line);
		return atoi(lz_line);
	}
	pclose(lp_fd);
	return -1;	
}

int main()
{
    std::string cmd = R"(/bin/mount -t nfs -o nolock,retry=1,namlen=896,port=2049 172.16.10.29:/nfs_send /srv/war/nfs/ ;echo $?)";
    std::system(cmd.c_str());
	return 0;
}



#include <iostream>
#include <boost/process.hpp>

namespace bp = boost::process;

int main()
{
    bp::ipstream output;
    bp::system("ls -l", bp::std_out > output); // 运行'ls -l'命令并将输出存储在output变量中

    std::string line;
    while (std::getline(output, line))
    {
        std::cout << line << std::endl; // 输出每一行
    }

    return 0;
}