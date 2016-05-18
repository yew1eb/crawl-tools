#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
const int N=1100;
const int inf=0x3fffffff;
using namespace std;
int dis[N],head[N],first[N],tot,gap[N],num,cost[N],n,start,end,ans;
struct edge
{
	int st,ed,w,next;
}E[100100];
struct Edge
{
	int st,ed,flow,next;
}e[300100];
void Addedge(int x,int y,int w)
{
	E[tot].st=x;E[tot].ed=y;E[tot].w=w;E[tot].next=first[x];first[x]=tot++;
}
void addedge(int x,int y,int w)
{
	e[num].ed=y;e[num].flow=w;e[num].next=head[x];head[x]=num++;
	e[num].ed=x;e[num].flow=0;e[num].next=head[y];head[y]=num++;
}
void bfs()
{
	queue<int >Q;
	int i,v,u;
	bool vis[N];
	for(i=1;i<=n;i++)
	{
		cost[i]=inf;vis[i]=false;
	}
	cost[start]=0;vis[1]=true;
	Q.push(start);
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();
		vis[u]=false;
		for(i=first[u];i!=-1;i=E[i].next)
		{
			v=E[i].ed;
			if(cost[v]>cost[u]+E[i].w)
			{
				cost[v]=cost[u]+E[i].w;
				if(!vis[v])
				{
					Q.push(v);
					vis[v]=true;
				}
			}
		}
	}
}
void makemap()
{
	int i,j;
	memset(head,-1,sizeof(head));
	num=0;
	for(i=1;i<=n;i++)
	{
		for(j=first[i];j!=-1;j=E[j].next)
		{
			if(cost[i]+E[j].w==cost[E[j].ed])//可走的边
			{
				addedge(i,E[j].ed,1);
			}
		}
	}
}
int dfs(int u,int minflow)    
{    
    if(u==end)return minflow;    
    int i,v,f,min_dis=ans-1,flow=0;    
    for(i=head[u];i!=-1;i=e[i].next)    
    {    
        v=e[i].ed;    
        if(e[i].flow<=0)continue;    
        if(dis[v]+1==dis[u])    
        {    
            f=dfs(v,e[i].flow>minflow-flow?minflow-flow:e[i].flow);    
            e[i].flow-=f;    
            e[i^1].flow+=f;    
            flow+=f;    
            if(flow==minflow)break;    
            if(dis[start]>=ans)return flow;    
        }    
        min_dis=min_dis>dis[v]?dis[v]:min_dis;    
    }    
    if(flow==0)    
    {    
        if(--gap[dis[u]]==0)    
            dis[start]=ans;    
        dis[u]=min_dis+1;    
        gap[dis[u]]++;    
    }    
    return flow;    
}  
int isap()  
{  
    int maxflow=0;  
    memset(gap,0,sizeof(gap));  
    memset(dis,0,sizeof(dis));  
    gap[0]=ans;  
    while(dis[start]<ans)  
        maxflow+=dfs(start,inf);  
    return maxflow;  
}  
int main()
{
	int i,m,k,t,x,y,w;
	scanf("%d",&t);
	while(t--)
	{
		memset(first,-1,sizeof(first));
		tot=0;
		scanf("%d%d",&n,&m);
		for(k=0,i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&w);
			if(x==y)continue;
			Addedge(x,y,w);
		}
		scanf("%d%d",&start,&end);
		ans=n;
		bfs();
		makemap();
		printf("%d\n",isap());
	}
	return 0;
}