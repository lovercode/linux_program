#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/mman.h>
int
main()
{
    char* p = NULL;
    int fd = open("test",O_CREAT|O_RDWR,0644);
    if(fd < 0)
    {
        printf("open error\n");
        exit(1);
    }
    int len = ftruncate(fd, 4);
    //NULL 文件大小
    p = mmap(NULL, 10240, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED)
    {
            printf("map error\n");
    }
    sprintf(p, "%d\n", 9);
    while(1)
    {
        printf("%s",p);
        sleep(1);
    }
    munmap(p,4);
    close(fd);
    return 0;
}
