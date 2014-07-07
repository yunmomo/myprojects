#include"threadpool.h"
void function(WorkPara *job)
{
if(job!=NULL)
{
int para = *(int *)job->arg;
cout<<"running: "<<para<<endl;
sleep(3);
cout<<"Game over: "<<para<<endl;
}
}
int main()
{
threadpool *pool = new threadpool;
sleep(1);
int index;
for(int i=0;i<5;i++)
{
index = i;
WorkPara * job = (WorkPara *)malloc(sizeof(WorkPara));
job->arg = (void *)&index;
pool->process_job(function,job);
sleep(1);
}
sleep(2);
pool->shutdownwait();
//pool->shutdown();
}
