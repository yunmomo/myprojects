#include"sock.h"
void command(int clientfd)
{
char buf[MAXLINE];
if(!fgets(buf,MAXLINE,stdin))
exit(0);
while(fgets(buf,MAXLINE,stdin) !=NULL)
{
rio_writen(clientfd,buf,strlen(buf));
}
}
int main(int argc,char *argv[])
{
int clientfd,port;
char *host,buf[MAXLINE];
rio_t rio;

if(argc!=3)
{
fprintf(stderr,"usage:%s <host> <port>\n",argv[0]);
exit(0);
}

host = argv[1];
port = atoi(argv[2]);

clientfd = open_clientfd(host,port);
rio_readinitb(&rio,clientfd);
fd_set read_set,read_rd_set;
fd_set write_set,write_rd_set;
FD_ZERO(&read_set);
FD_ZERO(&write_set);
FD_SET(STDIN_FILENO,&read_set);
FD_SET(clientfd,&read_set);
while(1)
{
read_rd_set = read_set;
select(clientfd+1,&read_rd_set,NULL,NULL,NULL);
if(FD_ISSET(STDIN_FILENO,&read_rd_set))
command(clientfd);
if(FD_ISSET(clientfd,&read_rd_set))
{
while(rio_readlineb(&rio,buf,MAXLINE)!=0)
fputs(buf,stdout);
}
}
close(clientfd);
exit(0);
}

