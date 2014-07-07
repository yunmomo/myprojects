#include "spider.h"
int main()
{
spider_init();
pool->process_job(spider_thread,NULL);
pool->process_job(webparse_thread,NULL);
pool->shutdownwait();
return 0;
}
