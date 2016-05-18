#pragma comment(linker, "/STACK:1024000000,1024000000")
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
struct Eage
{
    int a,b;
    __int64 len;
}eage[200111];
int pre[200111];
int num[200111];
__int64 sum[200111];
int cmp(const void *a,const void *b)
{
    struct Eage *c,*d;
    c=(struct Eage *)a;
    d=(struct Eage *)b;
    return d->len-c->len;
}
void build(int n)
{
    int i;
    for(i=1;i<=n;i++)   {pre[i]=i;num[i]=1;sum[i]=0;}
}
int find(int k)
{
    if(pre[k]==k)   return k;
    pre[k]=find(pre[k]);
    return pre[k];
}
void Union(int f1,int f2,__int64 dir)
{
    pre[f1]=f2;
    num[f2]+=num[f1];
    sum[f2]+=dir;
}
int main()
{
    int n,t;
    int i,l;
    int f1,f2;
    long long dir1,dir2;
    while(scanf("%d",&n)!=-1)
    {
        build(n);
        t=n-1;
        for(i=0;i<t;i++)    scanf("%d%d%I64d",&eage[i].a,&eage[i].b,&eage[i].len);
        qsort(eage,t,sizeof(eage[0]),cmp);

        for(i=0;i<t;i++)
        {
            f1=find(eage[i].a);
            f2=find(eage[i].b);
            if(f1==f2)  continue;
			dir1=num[f2]*eage[i].len+sum[f1];
			dir2=num[f1]*eage[i].len+sum[f2];
            if(dir1>dir2) Union(f2,f1,dir1-sum[f1]);
            else          Union(f1,f2,dir2-sum[f2]);
        }

        printf("%I64d\n",sum[find(1)]);
    }
    return 0;
}