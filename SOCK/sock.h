#ifndef _SOCK_H
#define _SOCK_H
#include"IO.h"
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdlib.h>
typedef struct sockaddr SA;
#define	MAXLINE	 8192  /* max text line length */
#define MAXBUF   8192  /* max I/O buffer size */
#define LISTENQ  1024  /* second argument to listen() */
int open_clientfd(char *hostname,int port);
int open_listenfd(int port);
#include"sock.cpp"
#endif
