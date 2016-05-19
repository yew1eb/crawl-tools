#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const __int64 N=200;
const __int64 E=60000;
const __int64  inf=0x3fffffffffffff;

struct node
{
    __int64 x,y,nxt,w;
    __int64 c;
}edge[E];
__int64 head[N],e;
__int64 Flow,n,Cost;
void addedge(__int64 x,__int64 y, __int64 w,__int64 c)
{
    edge[e].x=x;
    edge[e].y=y;
    edge[e].w=w;
    edge[e].c=c;
    edge[e].nxt=head[x];
    head[x]=e++;

    edge[e].x=y;
    edge[e].y=x;
    edge[e].w=0;
    edge[e].c=-c;
    edge[e].nxt=head[y];
    head[y]=e++;
}

void Maxfminc()
{
    __int64 dist[N];__int64 isque[N],que[N],pre[N];
    __int64 f,r;
    __int64 i,u;
    Flow=0;Cost=0;
    while(1)
    {
     f=0,r=1;
    for(i=0;i<=n;i++)
    {
        dist[i]=inf;
        isque[i]=0;
    }
    dist[0]=0;
    que[0]=0;
    isque[0]=1;
    while(f!=r)
    {
         u=que[f];
        f=(f+1)%N;
        for(i=head[u];i!=-1;i=edge[i].nxt)
        {
            __int64 v=edge[i].y;
            if(edge[i].w>0&&dist[v]>dist[u]+edge[i].c)
            {
                dist[v]=dist[u]+edge[i].c;
                pre[v]=i;
                if(!isque[v])
                {
                    isque[v]=1;
                    que[r]=v;
                    r=(r+1)%N;
                }
            }
        }
        isque[u]=0;
    }
    if(dist[n]==inf)break;
	Flow++;
	Cost +=dist[n];
    __int64 p;
    for(u=n;u!=0;u=edge[pre[u]^1].y)
    {
        p=pre[u];
        edge[p].w-=1;
        edge[p^1].w+=1;
    }
    }
}
int main ()
{
    __int64 i,m,k,j;
    __int64 x,y,c,w;
    while(scanf("%I64d%I64d%I64d",&n,&m,&k)!=EOF)
    {
        memset(head,-1,sizeof(head));
        e=0;
        for(i=0;i<m;i++)
        {
            scanf("%I64d%I64d%I64d%I64d",&x,&y,&c,&w);
		     if(c==0)
				addedge(x,y,w,0);
			else
			{
               for( j=1;j<=w;j++)
                  addedge(x,y,1,(2*j-1)*c);
			}
        }
		if(k!=0)
        addedge(0,1,k,0);
		else addedge(0,1,1,0);
        Maxfminc();
		if(k==0&&Flow==0)
		{	printf("-1\n");continue;}
		else if(k==0&&Flow==1)
		{printf("0\n");continue;}
      if(Flow<k)
            printf("-1\n");
     else
          printf("%I64d\n",Cost);
    }
return 0;
}
