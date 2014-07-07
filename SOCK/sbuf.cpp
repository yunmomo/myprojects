void sbuf_init(sbuf_t *sp, int n)
{
sp->buf = calloc(n,sizeof(int));
sp->n = n;
sp->front = sp->rear = 0;
sem_init(&sp->mutex,0,1);//binary semphore for locking
sem_init(&sp->slots,0,n);//initially,buf has n empty slots
sem_init(&sp->items,0,0);//inityally,buf has zero data items
}

void deinit(sbuf_t *sp)
{
free(sp->buf);
}

void sbuf_t insert(sbuf_t *sp,int item)
{
sem_wait(&sp->slots);
sem_wait(&sp->mutex);
sp->buf[(++sp->rear)%(sp->n)] = item;
sem_wait(&sp->mutex);
sem_wait(&sp->slots);
}

int sbuf_t remove(sbuf_t *sp)
{
int item;
sem_wait(&sp->items);
sem_wait(&sp->mutex);
item = sp->buf[(++sp->front)%(sp->n)];
sem_wait(&sp->mutex);
sem-wait(&sp->slots);
return item;
}
