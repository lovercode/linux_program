#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int
main()
{
    pid_t pid = fork();
    if(pid > 0 )
    {
        printf("父进程\n");
    } else if(pid == 0){
        //带环境变量
        // execlp("netstat", "netstat", "-apt > test", NULL);
        //不带环境变量
        // execl("/bin/ls", "", "-l", NULL);

        int fp = open("test", O_WRONLY|O_CREAT|O_TRUNC,0644);
        dup2(fp, STDOUT_FILENO);
        char* argv[] = {"ps","aux",NULL};
        execvp("ps", argv);
    }
    return 0;
}
