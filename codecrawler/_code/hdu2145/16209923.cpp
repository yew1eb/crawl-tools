#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
#define inf 0x3fffffff
int map[310][310],n,m,k,ren[310],v[310],st,flag[310],d[310];
struct op
{
    int dis,id;
    double t;
}p[310];
int cmp(const void *a,const void *b)
{
    struct op *c,*d;
    c=(struct op *)a;
    d=(struct op *)b;
    if(c->t>d->t)
        return 1;
    else if(c->t<d->t)
        return -1;
    else if(c->dis!=d->dis)
        return d->dis-c->dis;
    else return d->id-c->id;
}
void SPFA()
{
    queue<int >Q;
   int i,x;
   memset(flag,0,sizeof(flag));
   for(i=1;i<=n;i++)
       d[i]=inf;
   d[st]=0;
   Q.push(st);
   flag[st]=1;
   while(!Q.empty())
   {
       x=Q.front();
       Q.pop();
       flag[x]=0;
       for(i=1;i<=n;i++)
       {
           if(d[i]>d[x]+map[x][i])
           {
               d[i]=d[x]+map[x][i];
               if(!flag[i])
               {
                   Q.push(i);
                   flag[i]=1;
               }
           }
       }
   }
}
int main()
{
    int i,j,x,y,c;
    while(scanf("%d%d%d",&n,&m,&k)!=-1)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                map[i][j]=inf;
            for(i=1;i<=k;i++)
            {
                scanf("%d%d%d",&x,&y,&c);
                if(map[y][x]>c)
                    map[y][x]=c;//å»ºåå¾ï¼æåå¾ï¼åå¼å§ä»¥ä¸ºæ åå¾Wäº7æ¬¡
            }
            scanf("%d",&st);
            SPFA();
            for(i=1;i<=m;i++)
                scanf("%d",&ren[i]);
            for(i=1;i<=m;i++)
                scanf("%d",&v[i]);
            for(i=1;i<=m;i++)
            {
                p[i-1].id=i;
                p[i-1].dis=d[ren[i]];                
                p[i-1].t=p[i-1].dis*1.0/v[i];
            }
            qsort(p,m,sizeof(p[0]),cmp);
            if(p[0].dis==inf)puts("No one");
            else 
            printf("%d\n",p[0].id);
    }
    return 0;
}

