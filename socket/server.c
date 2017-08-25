#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6666

int main()
{
    int fd,ret;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server,client;
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    // server.sin_addr.s_addr = inet_pton(SERVER_IP);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(fd, (struct sockaddr *)&server, sizeof(server));
    listen(fd, 10);
    socklen_t len;
    len = sizeof(client);
    ret = accept(fd, (struct sockaddr*)&client, &len);
    char buf[1024];
    while(1)
    {
        int n = read(ret,buf,sizeof(buf));
        buf[n] = '\0';
        printf("%s\n",buf);
        write(ret, buf, strlen(buf));
    }

    close(fd);
    close(ret);
    return 0;
}
