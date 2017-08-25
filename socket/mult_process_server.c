#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/wait.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

void wait_child(int signal)
{
    while(waitpid(0, NULL, WNOHANG) > 0)
    {
        ;
    }
}

int main()
{
    int lfd, cfd;
    struct sockaddr_in server,client;
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(lfd, (struct sockaddr*)&server, sizeof(server));
    listen(lfd, 10);
    socklen_t len;
    len = sizeof(client);
    signal(SIGCHLD, wait_child);
    while(1)
    {
        cfd = accept(lfd, (struct sockaddr*)&client, &len);
        printf("%d,连接\n",cfd);
        pid_t pid;
        pid = fork();
        if(pid == 0)
        {
            close(lfd);
            while(1){
                char buf[1024];
                int n = read(cfd, buf,sizeof buf);
                if(n == 0)
                {
                    close(cfd);
                    return 0;
                }else if(n == -1)
                {
                    printf("error\n");
                    exit(1);
                }
                buf[n] = '\0';
                printf("%d消息,%s\n",cfd,buf);
                char buf1[1024] = "HTTP/1.1 200 OK\r\nDate: Fri, 25 Aug 2017 19:39:53 GMT\r\nServer: Apache/2.4.27 (Debian)\r\nVary: Accept-Encoding\r\nKeep-Alive: timeout=5, max=100\r\nConnection: Keep-Alive\r\nContent-Type: text/html;charset=UTF-8\r\n\r\n<!DOCTYPE><html><body><h1>server</h1></body></html>";

                write(cfd, buf1, strlen(buf1));
                // close(cfd);
            }
        }
        else if(pid > 0){
            close(cfd);

        }
    }

    return 0;
}
