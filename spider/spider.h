#ifndef _SPIDER_H
#define _SPIDER_H
#include<iostream>
using namespace std;
#include"IO.h"
#include"sock.h"
#include"threadpool.h"
#include<semaphore.h>
#include<list>
#include<queue>
#include<cstring>
#define DEF_MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH
#define DEF_UMASK S_IWGRP|S_IWOTH
list<string> cur_url;
list<string> former_url;
list<string> web_file;
threadpool *pool;
sem_t item;
sem_t solt;
void spider_init();
void spider();
void spider_thread(WorkPara *arg);
void spiderweb(string url);
void urlparser(string url,string &hostname,string &getmsg,string &filename);
void webparse();
void webparse_thread(WorkPara *arg);
void geturl(string content);

#include"spider.cpp"
#endif
