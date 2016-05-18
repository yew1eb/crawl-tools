#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define inf 0x3fffffff

int N,M;//N represents the number of points,and M stands for the number of edges;

int map[1024][1024];

int cnt;

int ans;

int dis[1024];

int visit[1024];

const int sta=1;

const int end=2;

struct Edge{
	int v;
	int val;
	int next;
}e[1111111];

int head[1024];

int idx;

int dijkstra()
{
	memset(visit,0,sizeof(visit));
	for(int i=1;i<=N;i++)
		dis[i]=inf;
	dis[sta]=0;
	for(int j=1;j<=N;j++)
	{
		int t=inf;
		int pos;
		for(int i=1;i<=N;i++)
		{
			if(!visit[i]&&t>dis[i])
			{
				t=dis[i];
				pos=i;
			}
		}
		visit[pos]=1;
		for(i=1;i<=N;i++)
		{
			if(!visit[i]&&dis[i]>dis[pos]+map[pos][i]&&map[pos][i]!=0x3f3f3f3f)
			{
				dis[i]=dis[pos]+map[pos][i];
			}
		}
	}
	if(dis[end]==inf)
		return -1;
	else
		return dis[end];
}

void addedge(int a,int b,int val)
{
	e[idx].v=b;
	e[idx].val=val;
	e[idx].next=head[a];
	head[a]=idx++;
}

void DFS(int index,int val)
{
//	printf("%d___%d___\n",index,val);
	if(index==end)
	{
		if(val==ans)
		{
			cnt++;
			return;
		}
		else
			return;
	}
	if(val>=ans)
		return;
	else
	{
		for(int p=head[index];p!=-1;p=e[p].next)
		{
			int v=e[p].v;
			if(!visit[v])
			{
				visit[v]=1;
				DFS(v,val+e[p].val);
				visit[v]=0;
			}
		}
	}
}





int main()
{
	int aa,bb,cc;
	while(scanf("%d",&N)!=EOF,N)
	{
		memset(head,-1,sizeof(head));
		memset(map,0x3f,sizeof(map));
		scanf("%d",&M);
		int t=inf;
		idx=0;
		for(int i=1;i<=M;i++)
		{
			scanf("%d%d%d",&aa,&bb,&cc);
			if(map[aa][bb]>cc)//判断重边
			{
				map[aa][bb]=cc;
				map[bb][aa]=cc;
				addedge(aa,bb,cc);
				addedge(bb,aa,cc);
			}
		}
		ans=dijkstra();
	//	printf("%d____\n",ans);
		if(ans==-1)
			printf("0\n");
		else
		{
			cnt=0;
			memset(visit,0,sizeof(visit));
			visit[sta]=1;
			DFS(sta,0);
			printf("%d\n",cnt);
		}
	}
	return 0;
}