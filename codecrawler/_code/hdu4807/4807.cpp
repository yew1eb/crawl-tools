#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue> 
#include<cmath>
#define inf 0x7fffffff
using namespace std; 
const int nodes=2500+50;
const int edges=10000+50;
int s,t;
int n,m,k;
int pre[nodes],dis[nodes];
class node
{
	public:
		int u,v,next,flow,w;
};
class E
{
	public:
		node e[edges];
		int head[nodes],cnt;
		void init()
		{
			memset(head,-1,sizeof(head));
			cnt=0;
		}
		void add(int a,int b,int c)
		{
			e[cnt].u=a;
			e[cnt].v=b;
			e[cnt].flow=c;
			e[cnt].w=1;
			e[cnt].next=head[a];
			head[a]=cnt++;
		
			e[cnt].u=b;
			e[cnt].v=a;
			e[cnt].flow=0;
			e[cnt].w=-1;
			e[cnt].next=head[b];
			head[b]=cnt++;
		}
}e1;
int spfa()
{
	int vis[nodes]={0};
	queue<int>q;
	while(!q.empty()) q.pop();
	memset(pre,-1,sizeof(pre)); 
	for(int i=0;i<n;i++)
	dis[i]=inf;
	vis[s]=1;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=e1.head[u];i+1;i=e1.e[i].next)
		{
			int v=e1.e[i].v;
			if(dis[v]>dis[u]+e1.e[i].w&&e1.e[i].flow>0)
			{
				dis[v]=dis[u]+e1.e[i].w;
				pre[v]=i;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return pre[t]!=-1;
}
void treatment()
{
	s=0;t=n-1;
	int last_path_len=0,pessnum_per_sec=0;
	int res=k,ans=inf;
	if(res==0)
	{
		printf("0\n");
		return;
	}
	while(spfa())
	{
		int minn=inf;
		for(int i=pre[t];i!=-1;i=pre[e1.e[i].u])
		{
			if(e1.e[i].flow<minn) minn=e1.e[i].flow;
		}
		for(int i=pre[t];i!=-1;i=pre[e1.e[i].u])
		{
			e1.e[i].flow-=minn;
			e1.e[i^1].flow+=minn;
		}
		res-=(dis[t]-last_path_len)*pessnum_per_sec+minn;
		last_path_len=dis[t];
		pessnum_per_sec+=minn;
		int temp=res;
		if(temp<0) temp=0;
		int n_ans=last_path_len+(int)ceil(1.0*temp/pessnum_per_sec);
		if(n_ans<ans) ans=n_ans;
		if(res<=0) break;
	}
	if(ans==inf) printf("No solution\n");
	else printf("%d\n",ans);
}
int main()
{
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		e1.init();
		for(int i=1;i<=m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			e1.add(a,b,c);
		}
		treatment();
	}
	return 0;
}