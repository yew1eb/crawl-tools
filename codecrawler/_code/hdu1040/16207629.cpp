/*
 * hdu-1040
 * mike-w
 * 2012-4-14
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1024
#define HEAP_SIZE 2048
#define LC(X) (2*(X))
#define RC(X) (2*(X)+1)
#ifndef true
#define true 1
#endif

int heap[HEAP_SIZE];
int N,T;

int swap(int *e1, int *e2)
{
    int tmp=*e1;
    *e1=*e2;
    *e2=tmp;
    return 0;
}

int heap_in(int e)
{
    if(heap[0]==HEAP_SIZE)
        return -1;
    heap[++heap[0]]=e;
    int x=heap[0];
    int p=x/2;
    while(p>0 && heap[p]>heap[x])
        swap(heap+p,heap+x),x=p,p/=2;
    return 0;
}

int heap_out(void)
{
    if(heap[0]==0)
        return -1;
    int ret=heap[1];
    swap(heap+1,heap+heap[0]);
    heap[0]--;
    int p=1,x;
    int lc,rc;
    while(true)
    {
        lc=LC(p);
        rc=RC(p);
        x=p;
        if(lc<=heap[0] && heap[lc]<heap[x])
            x=lc;
        if(rc<=heap[0] && heap[rc]<heap[x])
            x=rc;
        if(x==p)
            break;
        swap(heap+x,heap+p);
        p=x;
    }
    return ret;
}

int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    int e;
    scanf("%d",&T);
    while(T-->0)
    {
        heap[0]=0;
        scanf("%d",&N);
        while(N-->0)
            scanf("%d",&e), heap_in(e);
        while(heap[0]>0)
            printf("%d",heap_out()),putchar(heap[0]==0?'\n':' '); /* æ³¨æå¯ä½ç¨ */
    }
    return 0;
}
