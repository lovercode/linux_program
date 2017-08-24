#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>

typedef struct exit_status{
    int status;
    char msg[1024];
}exit_status;

void* fun(void* arg)
{
    //无法被杀死,没有系统调用
    while(1)
    {
        ;
    }
    exit_status* ret = (exit_status*)malloc(sizeof(exit_status));
    ret->status = 100;
    strcpy(ret->msg, "线程退出");
    pthread_exit((void*)ret);
    return NULL;
}

int main()
{
    int st;
    pthread_t thread;
    pthread_create(&thread, NULL, fun, NULL);
    pthread_detach(thread);
    exit_status* ret;
    while((st = pthread_join(thread, (void**)&ret)) != 0)
    {
        printf("回收线程:%s\n",strerror(st));
        sleep(1);
    }

    printf("%d,%s\n",ret->status,ret->msg);
    return 0;
}
