#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/fcntl.h>

void init()
{
    int fd;
    pid_t pid, sid;
    pid = fork();
    if(pid < 0){

    } else if(pid == 0){
        //设置会话,脱离终端
        sid = setsid();
        //切换工作目录
        if(chdir("/home/codelover/") < 0){
            printf("error\n");
            exit(1);
        }
        //更改文件权限, 第一个0 二进制
        // umask(0002);
        //重定向标准输入输出错误
        close(0);
        fd = open("/dev/null",O_RDWR);
        dup2(0, STDERR_FILENO);
        dup2(0, STDOUT_FILENO);
    }else{
        exit(0);
    }
}

int main()
{
    init();
    while(1)
    {

    }
    return 0;
}
