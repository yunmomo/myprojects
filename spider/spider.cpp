void spider_thread(WorkPara *arg)
{spider();}
void webparse_thread(WorkPara *arg)
{webparse();}
void spider_init()
{
string  url = "www.uestc.edu.cn";
cur_url.push_back(url);
pool = new threadpool(5,10);
sem_init(&item,0,0);
//sem_init(&slot,0,0);
sleep(1);
int web_item = open("web_item",O_CREAT|O_TRUNC|O_RDWR,DEF_MODE);
close(web_item);
}
void spider()
{
string url;
while(1)
{
while(!cur_url.empty())
{
pthread_mutex_lock(&pool->pool_mutex);
url = cur_url.front();
cur_url.pop_front();
former_url.push_back(url);
pthread_mutex_unlock(&pool->pool_mutex);
spiderweb(url);
}
break;
sleep(5);
}
}



void spiderweb(string url)
{
char buf[RIO_BUFSIZE];
string hostname,getmsg,filename;
urlparser(url,hostname,getmsg,filename);
sprintf(buf,"GET %s http/1.0\r\n",getmsg.c_str());
sprintf(buf,"%sHost: %s\r\n",buf,hostname.c_str());
sprintf(buf,"%sAccept: */*\r\n",buf);
sprintf(buf,"%sConnection: close\r\n\r\n",buf);
cout<<filename<<endl<<url<<endl<<buf<<endl;
char name[1024];
sprintf(name,"%s",hostname.c_str());
int clientfd = open_clientfd(name,80);
if(clientfd==-1 || clientfd ==-2)
{
cout<<"client open error!: "<<clientfd<<endl;
return;
}
rio_t rio;
rio_readinitb(&rio,clientfd);
if(rio_writen(clientfd,buf,strlen(buf))==-1)
{
cout<<"send message error!"<<endl;
return;
}
int flag =0;
sprintf(name,"web/%s",filename.c_str());
int fd = open(name,O_CREAT|O_TRUNC|O_RDWR,DEF_MODE);
while(rio_readlineb(&rio,buf,MAXLINE)!=0)//读取头部
{
if(!strcmp(buf,"\r\n"))flag++;
else flag = 0;
if(flag == 1)break;
}
while(rio_readlineb(&rio,buf,MAXLINE)!=0)//读取内容
{
rio_writen(fd,buf,strlen(buf));
}
close(fd);
close(clientfd);
static int j=0;
web_file.push_back(filename);
sprintf(buf,"%d %s %s\r\n",j++,filename.c_str(),url.c_str());
pthread_mutex_lock(&pool->pool_mutex);
int fid = open("web_item",O_APPEND|O_RDWR,0);
if(rio_writen(fid,buf,strlen(buf))==-1)
{
cout<<"write web_item error!"<<endl;
return;
}
sem_post(&item);
close(fid);
pthread_mutex_unlock(&pool->pool_mutex);
}

void urlparser(string url,string &hostname,string &getmsg,string &filename)
{
int start_h = 0;
int start_g = 0;
int start_f = 0;
int pos = 0;
static int i = 0;
char buf[1024];
if((pos  = url.find("http://"))!=string::npos)
start_h =pos+1;
if((pos = url.find_first_of('/',start_h))==string::npos)
{
hostname = url.substr(start_h,url.size()-start_h);
getmsg ="/";
sprintf(buf,"default%d.html",i++);
filename = buf;
return;
}
hostname = url.substr(start_h,pos-start_h);
start_g = pos;
getmsg = url.substr(start_g,(url.size()-start_g));
if((pos = url.find_last_of('/'))!=string::npos)
{
start_f = pos+1;
if((pos = url.find_first_of("?&* ()$<>@",start_f))!=string::npos)
filename = url.substr(start_f,pos-start_f);
else filename = url.substr(start_f,(url.size()-start_f));
}


if(filename.empty())
{
sprintf(buf,"default%d.html",i++);
filename = buf;
}
else
{
list<string>::iterator it = web_file.begin();
char k='A';
while(it!=web_file.end())
{
if(*it == filename)
{
sprintf(buf,"%c%s",k++,filename.c_str());
filename = buf;
}
it++;
}
}
}


void webparse()
{
char file[1024];
char buf[MAXLINE];
rio_t rio;
while(1)
{
memset(file,0,1024);
memset(buf,0,MAXLINE);
sem_wait(&item);
pthread_mutex_lock(&pool->pool_mutex);
int fid = open("web_item",O_RDONLY,0);
rio_readinitb(&rio,fid);
rio_readlineb(&rio,buf,MAXLINE);
close(fid);
pthread_mutex_unlock(&pool->pool_mutex);
sscanf(buf,"%*s%s%*s",file);
sprintf(file,"web/%s",string(file).c_str());
cout<<file<<endl;
int fd = open(file,O_RDONLY,0);
if(fd ==-1)
{
cout<<file<<" open failed"<<endl;
return;
}
rio_readinitb(&rio,fd);
string con;
int start=0;
while(rio_readlineb(&rio,buf,MAXLINE)!=0)
{
con = string(buf);
if((start = con.find("href=\"http://"))!=string::npos)
{
con = con.substr(start,con.size()-start);
geturl(con);
}
}
close(fd);
break;
sleep(10);
}
}


void geturl(string content)
{
int start = 13;
int pos;
string url;
if((pos = content.find_first_of('"',start))==string::npos)
{
//cout<<"error line 1"<<endl;
return;
}
url = content.substr(start,pos-start);
if((pos = url.find(".uestc.edu.cn",0))==string::npos)
{
//cout<<"error line 2"<<endl;
return;
}

list<string>::iterator it = former_url.begin();
while(it!=former_url.end())
{
if(url==*it)break;
it++;
}
if(former_url.empty()||(it==former_url.end()))
{
list<string>::iterator it = cur_url.begin();
while(it!=cur_url.end())
{
if(url==*it)break;
it++;
}
if(cur_url.empty()||(it ==cur_url.end()))
{
if(url.find("www",0)==string::npos)
url = "www."+url;
cur_url.push_back(url);
cout<<url<<endl;
}
}
}
