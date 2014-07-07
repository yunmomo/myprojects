int open_clientfd(char *hostname,int port)
{
int clientfd;
struct hostent *hp;
struct sockaddr_in serveraddr;

if((clientfd = socket(AF_INET,SOCK_STREAM,0))<0 )
return -1;


/*填写服务器端到IP地址与端口号*/
if((hp = gethostbyname(hostname)) == NULL)
return -2;
memset((char *)&serveraddr,0,sizeof(serveraddr));
serveraddr.sin_family = AF_INET;
memcpy((char *)&serveraddr.sin_addr.s_addr,(char *)hp->h_addr_list[0],hp->h_length);
serveraddr.sin_port = htons(port);

/*与服务器建立链接*/
if(connect(clientfd,(SA*)&serveraddr,sizeof(serveraddr))<0)
return -1;
return clientfd;
}


int open_listenfd(int port)
{
int listenfd,optval = 1;
struct sockaddr_in serveraddr;


/*创建套接字描述符*/
if((listenfd = socket(AF_INET,SOCK_STREAM,0))<0)
return -1;

if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,(const void *)&optval,sizeof(int))<0)
return -1;


memset((char *)&serveraddr,0,sizeof(serveraddr));
serveraddr.sin_family = AF_INET;
serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
serveraddr.sin_port = htons((unsigned short)port);

if(bind(listenfd,(SA *)&serveraddr,sizeof(serveraddr))<0)
return -1;


if(listen(listenfd,LISTENQ)<0)
return -1;
return listenfd;
}
