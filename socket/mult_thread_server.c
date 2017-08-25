#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

void* fun(void* arg)
{
    int fd = (int)arg;
    char buf[1024];
    while(1)
    {
        int n = read(fd, buf, sizeof(buf));
        if(n == 0)
            pthread_exit(1);
        buf[n] = '\0';
        printf("%s\n",buf);
    }
}


int main()
{
    pthread_t tid[10];
    int i = 0;
    int sfd,cfd;
    struct sockaddr_in server,client;
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(8080);
    bind(sfd, (struct sockaddr*)&server, sizeof server);
    listen(sfd, 10);

    while(1)
    {
        socklen_t len;
        cfd = accept(sfd, (struct sockaddr*)&client, &len);

        pthread_create(&tid[i], NULL, fun, (void*)cfd);
        pthread_detach(tid[i++]);
    }

    return 0;
}
