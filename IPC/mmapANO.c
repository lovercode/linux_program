#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/mman.h>
int
main()
{
    char* p = NULL;

    //NULL 文件大小
    p = mmap(NULL, 10240, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANON, -1, 0);
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

    return 0;
}
