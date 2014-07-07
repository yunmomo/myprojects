#include"sock.h"

void echo(int connfd)
{
size_t n;
char buf[MAXLINE];
rio_t rio;
rio_readinitb(&rio,connfd);
while((n = rio_readlineb(&rio,buf,sizeof(buf)))!=0)
{
cout<<"server received "<<n<<" bytes"<<endl;
rio_writen(connfd,buf,n);
if(!strncmp(buf,"quit",4))
break;
}
}
int main(int argc,char *argv[])
{
int listenfd,connfd,port,clientlen;
struct sockaddr_in clientaddr;
struct hostent *hp;
char *haddrp;

if(argc!=2)
{
fprintf(stderr,"usage: %s <port>\n",argv[0]);
exit(0);
}
port = atoi(argv[1]);
listenfd = open_listenfd(port);
while(1)
{
clientlen = sizeof(clientaddr);
connfd = accept(listenfd,(SA *)&clientaddr,(unsigned int *)&clientlen);

hp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,sizeof(clientaddr.sin_addr.s_addr),AF_INET);
haddrp = inet_ntoa(clientaddr.sin_addr);
cout<<"server connected to "<<hp->h_name<<" ( "<<haddrp<<" )"<<endl;

echo(connfd);
close(connfd);
}
exit(0);
}
