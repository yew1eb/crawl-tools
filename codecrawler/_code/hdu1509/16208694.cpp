/*
 * hdu-1509
 * mike-w
 * 2012-4-14
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HEAP_SIZE 66666
#define MSG_SIZE 50

#define LC(X) (2*(X))
#define RC(X) (2*(X)+1)
#ifndef true
#define true 1
#endif

typedef struct _node
{
    char msg[MSG_SIZE];
    int op;
    int nice;
    int time;
}node;

node heap[HEAP_SIZE];
int heap_size;
int counter;

int swap(node *e1, node *e2)
{
    node e;
    memmove(&e,e1,sizeof(node));
    memmove(e1,e2,sizeof(node));
    memmove(e2,&e,sizeof(node));
    return 0;
}

int comp(node *e1, node *e2)
{
    if(e1->nice != e2->nice)
        return e1->nice - e2->nice;
    else
        return e1->time - e2->time;
}

int heap_in(node *e)
{
    if(heap_size==HEAP_SIZE)
        return -1;
    heap_size++;
    /* copy node */
    strcpy(heap[heap_size].msg,e->msg);
    heap[heap_size].op=e->op;
    heap[heap_size].nice=e->nice;
    heap[heap_size].time=e->time;
    /* update heap */
    int x=heap_size;
    int p=x/2;
    while(p>0 && comp(heap+x,heap+p)<0)
        swap(heap+x,heap+p),x=p,p/=2;
    return 0;
}

int heap_out(node *e)
{
    if(heap_size==0)
        return -1;
    /* copy node */
    strcpy(e->msg,heap[1].msg);
    e->op=heap[1].op;
    e->nice=heap[1].nice;
    e->time=heap[1].time;
    /* update heap */
    swap(heap+1,heap+heap_size);
    heap_size--;
    int p=1,x;
    int lc,rc;
    while(true)
    {
        lc=LC(p);
        rc=RC(p);
        x=p;
        if(lc<=heap_size && comp(heap+lc,heap+x)<0)
            x=lc;
        if(rc<=heap_size && comp(heap+rc,heap+x)<0)
            x=rc;
        if(x==p)
            break;
        swap(heap+x,heap+p);
        p=x;
    }
    return 0;
}


int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    char buf[MSG_SIZE];
    int time=0;
    node e;
    while(scanf("%s",buf)!=EOF)
    {
        time++;
        if(strcmp(buf,"GET")==0)
        {
            if(heap_out(&e)==-1)
                puts("EMPTY QUEUE!");
            else
                printf("%s %d\n",e.msg,e.op);
        }
        else
        {
            scanf("%s%d%d",e.msg,&(e.op),&(e.nice));
            e.time=time;
            heap_in(&e);
        }
    }
    return 0;
}
