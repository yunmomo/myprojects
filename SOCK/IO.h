#ifndef _IO_H
#define _IO_H
#include<iostream>
using namespace std;
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<cstring>
#define RIO_BUFSIZE 8192
typedef struct
{
int rio_fd;                //descriptor for this internal buf  
int rio_cnt;               //Unread bytes in internal buf
char *rio_bufptr;          //next unread byte in internal buf 
char rio_buf[RIO_BUFSIZE]; //internal buffer
}rio_t;
ssize_t rio_readn(int fd,void *usrbuf,size_t n);
ssize_t rio_writen(int fd,void *usrbuf,size_t n);
void rio_readinitb(rio_t *rp,int fd);
static ssize_t rio_read(rio_t *rp, void *usrbuf, size_t n);
ssize_t rio_readlineb(rio_t *rp,void *usrbuf,size_t maxlen);
ssize_t rio_readnb(rio_t *rp,void *usrbuf,size_t n);
#include"IO.cpp"
#endif
