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
    exit_status* ret = (exit_status*)malloc(sizeof(exit_status));
    ret->status = 100;
    strcpy(ret->msg, "线程退出");
    pthread_exit((void*)ret);
    return NULL;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, fun, NULL);
    exit_status* ret;
    pthread_join(thread, (void**)&ret);
    printf("%d,%s\n",ret->status,ret->msg);
    return 0;
}
