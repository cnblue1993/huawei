//
//  main.cpp
//  多线程
//
//  Created by anne on 16/7/10.
//  Copyright © 2016年 anne. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
//#define DEBUG 1
#define NUM 4

int times;
int n=0;
pthread_mutex_t mylock=PTHREAD_MUTEX_INITIALIZER;//互斥量
pthread_cond_t qready=PTHREAD_COND_INITIALIZER;//条件变量


void * thread_func(void *arg)
{
    long param=(long)arg;
    char c='A'+param;
    int ret,i=0;
    for (; i < times; i++)
    {
        pthread_mutex_lock(&mylock);
        while (param != n)  //刚运行时，n = 0， param = 0,条件不成立，所以直接打印A
        {

            ret = pthread_cond_wait(&qready, &mylock);
        }
        printf("%c",c);  //打印A后
        n=(n+1)%NUM;      //n变成了1，对线程2会产出影响！！！！
        pthread_mutex_unlock(&mylock);
        //会唤醒所有的线程，因为当这个线程完后会等pthread_cond_wait()执行两次后才能退出while (param != n)
        pthread_cond_broadcast(&qready);
        
    }
    return (void *)0;
}

int main(int argc, char** argv) {
    
    long i=0,err;
    pthread_t tid[NUM];
    void *tret;
    
    scanf("%d",&times);
    
    for(;i<NUM;i++)
    {
        err=pthread_create(&tid[i],NULL,thread_func,(void *)i);
    }
    for (i = 0; i < NUM; i++)
    {
        err = pthread_join(tid[i], &tret);
    }
    printf("\n");
    return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//#include <pthread.h>
//#include <unistd.h>
//#include <string.h>
////#define DEBUG 1
//#define NUM 4
//
//int n=0;
//pthread_mutex_t mylock=PTHREAD_MUTEX_INITIALIZER;//互斥量
//pthread_cond_t qready=PTHREAD_COND_INITIALIZER;//条件变量
//
//
//void * thread_func(void *arg)
//{
//    long param=(long)arg;
//    char c='A'+param;
//    int ret,i=0;
//    for (; i < 10; i++)
//    {
//        pthread_mutex_lock(&mylock);
//        while (param != n)  //刚运行时，n = 0， param = 0,条件不成立，所以直接打印A
//        {
//#ifdef DEBUG
//            printf("thread %l waiting\n", param);
//#endif
//            ret = pthread_cond_wait(&qready, &mylock);
//            if (ret == 0)
//            {
//#ifdef DEBUG
//                printf("thread %l wait success\n", param);
//#endif
//            } else
//            {
//#ifdef DEBUG
//                printf("thread %l wait failed:%s\n", param, strerror(ret));
//#endif
//            }
//        }
//        // printf("%d ",param+1);
//        printf("%c ",c);  //打印A后
//        n=(n+1)%NUM;      //n变成了1，对线程2会产出影响！！！！
//        pthread_mutex_unlock(&mylock);
//        //会唤醒所有的线程，因为当这个线程完后会等pthread_cond_wait()执行两次后才能退出while (param != n)
//        pthread_cond_broadcast(&qready);
//        
//    }
//    return (void *)0;
//}
//
//#if 0
////假设为线程2
//
//void * thread_func(void *arg)//传入值1
//{
//    int param=(int)arg;
//    char c='A'+param;
//    int ret,i=0;
//    for (; i < 10; i++)
//    {
//        pthread_mutex_lock(&mylock);
//        while (param != n)  //和线程1同时执行，所以刚开始时条件满足
//        {
//#ifdef DEBUG
//            printf("thread %d waiting\n", param);
//#endif
//            //执行到此时，等待线程1发送信号，当线程1的A打印完后，n的值也变成了1，条件就不成立了
//            ret = pthread_cond_wait(&qready, &mylock);
//            if (ret == 0)
//            {
//#ifdef DEBUG
//                printf("thread %d wait success\n", param);
//#endif
//            } else
//            {
//#ifdef DEBUG
//                printf("thread %d wait failed:%s\n", param, strerror(ret));
//#endif
//            }
//        }
//        // printf("%d ",param+1);
//        printf("%c ",c); //此时打印值B
//        n=(n+1)%NUM;    //对打印C的线程3产生影响！！！
//        pthread_mutex_unlock(&mylock);
//        pthread_cond_broadcast(&qready);
//    }
//    return (void *)0;
//}
//
//#endif
//

//int main(int argc, char** argv) {
//    
//    int i=0,err;
//    pthread_t tid[NUM];
//    void *tret;
//    for(;i<NUM;i++)
//    {
//        err=pthread_create(&tid[i],NULL,thread_func,(void *)i);
//        if(err!=0)
//        {
//            printf("thread_create error:%s\n",strerror(err));
//            exit(-1);
//        }
//    }
//    for (i = 0; i < NUM; i++)
//    {
//        err = pthread_join(tid[i], &tret);
//        if (err != 0)
//        {
//            printf("can not join with thread %d:%s\n", i,strerror(err));
//            exit(-1);
//        }
//    }
//    printf("\n");
//    return 0;
//}