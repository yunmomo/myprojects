/*SBUF包用来构造生产者——消费者程序*/
#ifndef _SBUF_H
#define _SBUF_H
#include<iostream>
using namespace std;
#include<pthread.h>
#include<semaphore.h>
typedef struct
{
int *buf;/* Buffer array*/
int n;/*maximum number of slots*/
int front;/*buf[(front+1)%n] is first item*/
int rear;/*buf[(rear+1)%n] is first item*/
sem_t mutex;/*Projects accesses to buf*/
sem_t slots;/*Counts available slots*/
sem_t items;/*Counts available items*/
}sbuf_t;
#inlcude"sbuf.cpp"
#endif

