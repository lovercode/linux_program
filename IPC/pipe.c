#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int
main()
{
    int fd[2];
    pipe(fd);

    pid_t pid = fork();
    if(pid == 0)
    {
        char buf[1024];
        int i = 0;
        while(1){
            sprintf(buf, "%s%d", "数据",i++);
            printf("父进程写入数据:%s",buf);
            write(fd[1],buf,1024);
            sleep(2);
        }
    } else if(pid > 0){
        char buf1[1024];
        while(1){
            //阻塞等待
            read(fd[0], buf1, 1024);
            write(STDOUT_FILENO, buf1, strlen(buf1));
        }

    }

    return 0;
}
