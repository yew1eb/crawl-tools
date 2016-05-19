#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

const int N=100010, E=400010, INF=0x3fffffff;

struct Edge
{
	int en, cap, flow, next, low;
	inline void init(int a, int b, int c, int d, int e)
	{
		en=a, cap=b, flow=c, next=d, low=e;
	}
} edge[E];
int head[N], now[N], dis[N], gap[N], pre[N], D[N];
int source, sink, tot_num, tot, n, m, t;
queue <int> q;

void add_edge(int st, int en, int cap, int low)
{
	edge[tot].init(en, cap, 0, head[st], low), head[st]=tot++;
	edge[tot].init(st, 0, 0, head[en], low), head[en]=tot++;
}

void BFS()
{
	memset(dis, -1, sizeof dis);
	memset(gap, 0, sizeof gap);
	while(!q.empty()) q.pop();
	gap[dis[sink]=0]=1, q.push(sink);
	for(int u=q.front(), i; !q.empty(); q.pop(), u=q.front())
		for(int v=edge[i=head[u]].en; i!=-1; v=edge[i=edge[i].next].en)
		{
			if(edge[i].cap!=0 || dis[v]!=-1) continue;
			q.push(v);
			++gap[dis[v]=dis[u]+1];
		}
}

int SAP()
{
	memset(pre, -1, sizeof pre);
	BFS();
	memcpy(now, head, sizeof head);
	int cur=source, flow=0, cut=INF;
	for(bool fg=0; dis[source]<tot_num; fg=0)
	{
		for(int i=now[cur]; i!=-1; i=edge[i].next)
		{
			if(!(edge[i].cap-edge[i].flow>0 && dis[cur]==dis[edge[i].en]+1)) continue;
			cut=min(cut, edge[i].cap-edge[i].flow);
			now[cur]=i, pre[edge[i].en]=cur;
			cur=edge[i].en;
			if(cur==sink)
			{
				flow+=cut;
				for(int u=source; u!=sink; u=edge[now[u]].en)
					edge[now[u]].flow+=cut, edge[now[u]^1].flow-=cut;
				cur=source, cut=INF;
			}
			fg=true;
			break;
		}
		if(fg) continue;
		if(--gap[dis[cur]]==0) break;
		int Min=tot_num;
		for(int i=head[cur]; i!=-1; i=edge[i].next)
			if(edge[i].cap-edge[i].flow>0 && Min>dis[edge[i].en])
                Min=dis[edge[i].en], now[cur]=i;
		gap[dis[cur]=Min+1]++;
		if(cur!=source) cur=pre[cur];
	}
	return flow;
}

void build(int n,int m)
{
	memset(head, -1, sizeof head);
	tot=0, tot_num=n+1;
	int Min=INF, Max=-INF;
	for(int i=1, x, y; i<=n; i++)
	{
		scanf("%d%d", &x, &y);
		if(Min>x) Min=x, source=i;
		if(Max<x) sink=i, Max=x;
	}
	for(int i=1, a, b, c; i<=m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		add_edge(a, b, c, 0);
		add_edge(b, a ,c, 0);
	}
}

int main()
{
	scanf("%d", &t);
	for(int ca=1; ca<=t; ca++)
	{
		scanf("%d%d", &n, &m);
		build(n, m);
		int ans=SAP();
		printf("%d\n", ans);
	}
	return 0;
}