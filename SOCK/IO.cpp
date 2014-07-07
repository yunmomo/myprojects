ssize_t rio_readn(int fd,void *usrbuf,int n)
{
size_t nleft = n;
ssize_t nread;
char *bufp = (char *)usrbuf;

while(nleft>0)
{
if((nread = read(fd,bufp,n))<0)
{
if(errno == EINTR)
nread = 0;
else
return -1;
}
else if(nread == 0)
break;
nleft -= nread;
bufp +=nread;
}
return (n-nleft);
}


ssize_t rio_writen(int fd,void *usrbuf,size_t n)
{
size_t nleft = n;
ssize_t nwritten;
char *bufp = (char *)usrbuf;

while(nleft>0)
{
if((nwritten = write(fd,bufp,n))<0)
{
if(errno == EINTR)
nwritten =0;
else 
return -1;
}
nleft -= nwritten;
bufp += nwritten;
}
return n;
}

void rio_readinitb(rio_t *rp,int fd)
{
rp->rio_fd = fd;
rp->rio_cnt = 0;
memset(rp->rio_buf,0,sizeof(rp->rio_buf));
rp->rio_bufptr = rp->rio_buf;
}


static ssize_t rio_read(rio_t *rp, void *usrbuf, size_t n)
{
int cnt;
while(rp->rio_cnt<=0)//防止中断，同时，只有缓存里到字节读完后，才会继续读取文件里面到内容
{
rp->rio_cnt = read(rp->rio_fd,rp->rio_buf,sizeof(rp->rio_buf));
if(rp->rio_cnt<0)
{
if(errno == EINTR)
rp->rio_cnt = 0;
else
return -1;
}
else if(rp->rio_cnt == 0)
return 0;
else
rp->rio_bufptr =rp->rio_buf;
}

cnt = n;
if(rp->rio_cnt<n)
cnt = rp->rio_cnt;
memcpy(usrbuf,rp->rio_bufptr,cnt);
rp->rio_bufptr+=cnt;
rp->rio_cnt-=cnt;
return cnt;
}



/*ssize_t rio_readlineb(rio_t *rp,void *usrbuf,size_t maxlen)
{
size_t left=maxlen;
ssize_t nread;
char temp;
char *bufptr = usrbuf;
while(left>0)
{
if((nread=rio_read(rp,&temp,1))<0)
return -1;
else if(nread ==1)
{
*bufptr++ = temp;
left--;
if(temp =='\n')
break;
}
else if(nread==0)
break;
}
*bufptr = 0;
return (maxlen-nleft);
}*/
ssize_t rio_readlineb(rio_t *rp,void *usrbuf,size_t maxlen)
{
int n,rc;
char c,*bufp = (char *)usrbuf;
for(n=1;n<maxlen;n++)
{
if((rc=rio_read(rp,&c,1))==1)
{
*bufp++ = c;
if(c =='\n')
break;
}
else if(rc ==0)
{
if(n==1)
return 0;
else
break;
}
else
return -1;
}
*bufp = 0;
return n;
}


ssize_t rio_readnb(rio_t *rp,void *usrbuf,size_t n)
{
size_t nleft = n;
ssize_t readn;
char * bufp = (char *)usrbuf;
while(nleft>0)
{
if(readn = rio_read(rp,bufp,nleft)<0)
{
if(errno == EINTR)
readn=0;
else
return -1;
}
else if(readn == 0)
break;
nleft -=readn;
bufp +=readn;
}
return (n-nleft);

}
