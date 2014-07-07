#include"threadpool.h"
threadpool::threadpool(int min,int max)
{
pool_min_num = min;
pool_max_num = max;
pool_cur_num = min;
is_running = true;

pthread_mutex_init(&pool_mutex,NULL);


threadinfo = (WorkThread *)malloc(sizeof(WorkThread)*pool_max_num);
WorkThread *temp;
for(int i=0;i<pool_min_num;i++)
{
temp = threadinfo + i;

pthread_cond_init(&(temp->thread_cond),NULL);
if(pthread_create(&(temp->thread_id),NULL,tp_work_proc,temp)!=0)
{
cout<<"create thread error!"<<endl;
exit(0);
}


temp->is_busy = false;
temp->proc_fun = NULL;
temp->parameter = NULL;
temp->thread_pool = this;
idle_q.push(temp);
}

if(pthread_create(&(pool_manage_id),NULL,tp_manage_proc,this)!=0)
{
cout<<"create thread error!"<<endl;
exit(0);
}
}

threadpool::~threadpool()
{
shutdownwait();
}


void threadpool::shutdownwait()
{
if(is_running)
{
is_running = false;
int i=0;
for(;i<pool_cur_num;i++)
{
pthread_cond_signal(&(threadinfo[i].thread_cond));
}
for(i=0;i<pool_cur_num;i++)
{
pthread_join(threadinfo[i].thread_id,NULL);
//pthread_destroy(&(threadinfo[i].thread_id));
pthread_cond_destroy(&(threadinfo[i].thread_cond));
cout<<"thread: "<<threadinfo[i].thread_id<<" exit!"<<endl;
}
kill((pid_t)pool_manage_id,SIGKILL);
pthread_mutex_destroy(&(pool_mutex));
free(threadinfo);
threadinfo = NULL;
}
}


void threadpool::shutdown()
{
if(!is_running)return;
is_running = false;
for(int i=0;i<pool_cur_num;i++)
{
kill((pid_t)threadinfo[i].thread_id,SIGKILL);
pthread_cond_destroy(&(threadinfo[i].thread_cond));
}

kill((pid_t)pool_manage_id,SIGKILL);
pthread_mutex_destroy(&(pool_mutex));
free(threadinfo);
threadinfo = NULL;
}


void threadpool::process_job(work_proc job,WorkPara *para)
{
if(is_running)
{
WorkThread *temp;
if(!idle_q.empty())
{
pthread_mutex_lock(&(pool_mutex));
temp = idle_q.front();
idle_q.pop();
pthread_mutex_unlock(&(pool_mutex));
}
else if(pool_cur_num<pool_max_num)
temp = add_thread();
else 
{
cout<<"Thread pool is full,please wait for idle thread!"<<endl;
return ;
}
if(temp == NULL)
return ;
temp->is_busy = true;
temp->proc_fun = job;
temp->parameter = para;
pthread_cond_signal(&(temp->thread_cond));
}
}


void* threadpool::tp_work_proc(void *arg)
{
WorkThread *php = (WorkThread *)arg;
cout<<"thread :"<<pthread_self()<<" is running"<<endl;
while(php->thread_pool->is_running)
{
pthread_mutex_lock(&(php->thread_pool->pool_mutex));
pthread_cond_wait(&(php->thread_cond),&(php->thread_pool->pool_mutex));
pthread_mutex_unlock(&(php->thread_pool->pool_mutex));

php->is_busy = true; 
if(php->proc_fun !=NULL)
(*(php->proc_fun))(php->parameter);

php->is_busy = false;
php->proc_fun = NULL;
php->parameter = NULL;

php->thread_pool->idle_q.push(php);
cout<<"thread: "<<pthread_self()<<" is idle now!"<<endl;
return NULL;
}
}


WorkThread* threadpool::add_thread()
{
if(is_running&&(pool_cur_num<pool_max_num))
{
WorkThread *temp = threadinfo + pool_cur_num;
pthread_cond_init(&(temp->thread_cond),NULL);

temp->is_busy = true;
temp->proc_fun = NULL;
temp->parameter = NULL;
temp->thread_pool = this;
if(pthread_create(&(temp->thread_id),NULL,this->tp_work_proc,temp)!=0)
{
cout<<"create thread error!"<<endl;
return NULL;
}
pool_cur_num++;
return temp;
}
return NULL;
}
bool threadpool::get_status()
{
int idle = idle_q.size();
int cur = pool_cur_num;
int busy = cur - idle;
pthread_mutex_lock(&(pool_mutex));
cout<<"Pool status: thread idle: "<<idle<<";thread current: "<<cur<<"thread busy: "<<busy<<endl;
pthread_mutex_unlock(&(pool_mutex));
if((pool_min_num<pool_cur_num)&&idle/(float)cur>0.5)return true;
else return false;
}

void threadpool::delete_thread()
{
if(!idle_q.empty())
{
WorkThread *temp = idle_q.front();
idle_q.pop();
WorkThread php;
idle_q.pop();
pool_cur_num--;
memcpy(&php,temp,sizeof(WorkThread));
memcpy(temp,threadinfo+pool_cur_num,sizeof(WorkThread));
kill((pid_t)php.thread_id,SIGKILL);
pthread_cond_destroy(&(php.thread_cond));
}
}


void *threadpool::tp_manage_proc(void *arg)
{
threadpool *php = (threadpool *)arg;
cout<<"thread :"<<pthread_self()<<" is running"<<endl;
while(php->is_running)
{
sleep(1000);
while(1)
{
pthread_mutex_lock(&(php->pool_mutex));
if(!php->get_status())
break;
php->delete_thread();
pthread_mutex_unlock(&(php->pool_mutex));
}
}
}
