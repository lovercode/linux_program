#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "../linkTab/linkTab.h"

typedef struct Node
{
	void* next;
	void (*showWay)(void* x);
	int data;
	char msg[64];

}tNode, *pNode;

void show(void* x)
{
    printf("消费者消费:%d,%s\n",((pNode)x)->data,((pNode)x)->msg);
}

//静态初始化
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
plinkTab product;
void* producer(void* arg)
{
    // int i = 0;
    while(1)
    {
        pNode p = malloc(sizeof(tNode));
        p->data = product->sum+1;
        sprintf(p->msg, "数据%d", product->sum+1);
        p->showWay = show;
        printf("-----生产者生产:%d,%s\n",p->data,p->msg);
        //加锁,生产
        pthread_mutex_lock(&lock);
        AddLinkTabNode(product,p);
        pthread_mutex_unlock(&lock);
        //通知消费者
        pthread_cond_signal(&has_product);
        usleep(10);
    }
    return NULL;
}


void* custom(void* arg)
{
    int i = (int)arg;
    while(1)
    {
        pthread_mutex_lock(&lock);
        while(product->sum == 0)
        {
            pthread_cond_wait(&has_product, &lock);
        }
        printf("消费者%d",i);
        show(product->pHead);
        DeleteLinkTabNode(product,product->pHead);
        pthread_mutex_unlock(&lock);
        usleep(50);
    }
    return NULL;
}

int main()
{
    product = CreatLinkTab();

    //pid 生产者,消费者
    pthread_t pid, cid[5];
    srand(time(NULL));
    //生产者
    pthread_create(&pid, NULL, producer, NULL);
    //消费者
    for(int i=0; i<5; i++)
        pthread_create(&cid[i], NULL, custom, (void*)i);

    pthread_join(pid, NULL);
    for(int i=0; i<5; i++)
        pthread_join(cid[i], NULL);
    return 0;
}
