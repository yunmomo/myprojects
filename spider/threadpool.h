#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H
#include<iostream>
using namespace std;
#include<pthread.h>
#include<errno.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<list>
#include<queue>
typedef struct tp_work_parameter WorkPara;//任务所需参数
typedef struct tp_work_thread WorkThread;//每个任务所属到线程
typedef class threadpool TPool;
typedef void (*work_proc)(WorkPara *arg);//需要执行的任务
struct tp_work_parameter
{
void *reg;//任务所需输出
void *arg;//任务所需输入参数
};
struct tp_work_thread
{
pthread_t thread_id;
pthread_cond_t thread_cond;
work_proc proc_fun;
WorkPara *parameter;
bool is_busy;
threadpool *thread_pool;
};
class threadpool
{
public:
threadpool(int min=5,int max=10);
virtual ~threadpool();
void process_job(work_proc job,WorkPara *para);
void shutdown();//强行关闭线程池
void shutdownwait();
pthread_mutex_t pool_mutex;
private:
bool is_running;
WorkThread* add_thread();
void delete_thread();
static void* tp_work_proc(void *arg);
static void* tp_manage_proc(void *arg);
bool get_status();
pthread_t pool_manage_id;
int pool_min_num;
int pool_max_num;
int pool_cur_num;
queue<WorkThread *>idle_q;
WorkThread *threadinfo;
};
void* tp_work_proc(void *arg);
#include"threadpool.cpp"
#endif
