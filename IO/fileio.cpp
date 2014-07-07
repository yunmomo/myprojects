#include"IO.h"
#define DEF_MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH
#define DEF_UNMASK S_IWGRP|S_IWOTH
#define DEF_FLAGS O_CREAT|O_TRUNC|O_RDWR //O_CREAT|O_TRUNC|O_RDWR
int main()
{
int fd;
int r;
rio_t rio;
char buf[1024];
char buff[1024];
memset(buf,0,sizeof(buf));
memset(buff,0,sizeof(buff));
fd = open("test.txt",DEF_FLAGS,DEF_MODE);
rio_readinitb(&rio,fd);
sprintf(buf,"%s","nihao");
cout<<buf<<endl;
if((r = rio_writen(fd,buf,strlen(buf)))==-1)
cout<<"write error!"<<endl;
cout<<lseek(fd,0,SEEK_SET)<<endl;//SEEK_:set为文件开始0，cur为当前位置1，end为文件末尾2,对于fopen，有ftell,fseek
if((r = rio_readlineb(&rio,buff,2))==-1)
cout<<"read error!"<<endl;
cout<<buff<<endl;
/*if((r = rio_readlineb(&rio,buff,2))==-1)
cout<<"read error!"<<endl;
cout<<buff<<endl;*/
memset(buff,0,sizeof(buff));
cout<<lseek(fd,0,SEEK_SET)<<endl;
rio_readinitb(&rio,fd);//清空缓存
if((r = rio_readnb(&rio,buff,2))==-1)
cout<<"read error!"<<endl;
cout<<buff<<endl;
}
