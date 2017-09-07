#include <stdio.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define MAX 1024

int main()
{

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server,client;
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    // server.sin_addr.s_addr = inet_pton(SERVER_IP);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(fd, (struct sockaddr *)&server, sizeof(server));
    listen(fd, 10);

    struct epoll_event tep, ep[MAX];
    int epl = epoll_create(10);
    tep.events = EPOLLIN;
    tep.data.fd = fd;
    epoll_ctl(epl, EPOLL_CTL_ADD, fd, &tep);
    while(1)
    {
        int nready = epoll_wait(epl, ep, MAX, -1);
        for(int i=0; i<nready; i++)
        {
            if(!ep[i].events & EPOLLIN)
                continue;
            if(ep[i].data.fd == fd)
            {
                socklen_t len = sizeof(client);
                int con = accept(fd, (struct sockaddr*)&client, &len);
                tep.events = EPOLLIN | EPOLLET;     //边沿触发
                // tep.events = EPOLLIN;   //水平触发
                int flag = fcntl(con, F_GETFL);//获取socket原来的属性
                flag |= O_NONBLOCK;//添加非阻塞属性
                fcntl(con, F_SETFL, flag);//设置非阻塞新属性
                tep.data.fd = con;
                epoll_ctl(epl, EPOLL_CTL_ADD, con, &tep);
            }else{
                char buf[1];

                int n;
                //非阻塞读,轮询
                while((n = read(ep[i].data.fd, buf, sizeof(buf))) > 0 )
                {
                    buf[n] = '\0',
                    printf("%s",buf);
                }
                if(n == 0)
                {
                    printf("关闭\n");
                    epoll_ctl(epl, EPOLL_CTL_DEL, ep[i].data.fd, NULL);
                    close(ep[i].data.fd);
                }

                write(ep[i].data.fd, "server send\0", sizeof("server send\0"));


            }
        }
    }
    return 0;
}
