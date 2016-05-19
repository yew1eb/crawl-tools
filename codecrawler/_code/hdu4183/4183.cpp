#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define N 605
#define inf 10000
#define ll int

using namespace std;
inline ll Max(ll a,ll b){return a>b?a:b;}
inline ll Min(ll a,ll b){return a<b?a:b;}
struct node{
	double fre;
	int x,y, r;
}p[N], s, t;
bool Cross(node a,node b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) < (a.r+b.r)*(a.r+b.r);
}

struct Edge{
	int from, to, cap, nex;
}edge[N*20];
int head[N], edgenum;
void addedge(int u, int v, int cap){
	Edge E ={u, v, cap, head[u]};
	edge[edgenum] = E;
	head[u] = edgenum++;
}

int sign[N*4];
bool BFS(int from, int to){
	memset(sign, -1, sizeof(sign));
	sign[from] = 0;

	queue<int>q;
	q.push(from);
	while( !q.empty() ){
		int u = q.front(); q.pop();
		for(int i = head[u]; i!=-1; i = edge[i].nex)
		{
			int v = edge[i].to;
			if(sign[v]==-1 && edge[i].cap)
			{
				sign[v] = sign[u] + 1, q.push(v);
				if(sign[to] != -1)return true;
			}
		}
	}
	return false;
}
int Stack[N*4], top, cur[N*4];
int dinic(int from, int to){

	int ans = 0;
	while( BFS(from, to) )
	{
		memcpy(cur, head, sizeof(head));
		int u = from;		top = 0;
		while(1)
		{
			if(u == to)
			{
				int flow = inf, loc;//loc 表示 Stack 中 cap 最小的边
				for(int i = 0; i < top; i++)
					if(flow > edge[ Stack[i] ].cap)
					{
						flow = edge[Stack[i]].cap;
						loc = i;
					}

					for(int i = 0; i < top; i++)
					{
						edge[ Stack[i] ].cap -= flow;
						edge[Stack[i]^1].cap += flow;
					}
					ans += flow;
					top = loc;
					u = edge[Stack[top]].from;
			}
			for(int i = cur[u]; i!=-1; cur[u] = i = edge[i].nex)//cur[u] 表示u所在能增广的边的下标
				if(edge[i].cap && (sign[u] + 1 == sign[ edge[i].to ]))break;
			if(cur[u] != -1)
			{
				Stack[top++] = cur[u];
				u = edge[ cur[u] ].to;
			}
			else
			{
				if( top == 0 )break;
				sign[u] = -1;
				u = edge[ Stack[--top] ].from;
			}
		}
	}
	return ans;
}
ll n;

int main(){
	int T, i, j; scanf("%d",&T);
	while(T--)
	{
		memset(head, -1, sizeof(head)); edgenum = 0;

		scanf("%d",&n);
		for(i = 1; i <= n; i++)
			{
				scanf("%lf %d %d %d",&p[i].fre,&p[i].x,&p[i].y,&p[i].r);
				if(p[i].fre == 400)
					t = p[i],i--,n--;
				else if(p[i].fre == 789)
					s = p[i],i--,n--;
		}
		if(Cross(s,t)){printf("Game is VALID\n");continue;}
		for(i = 1; i <= n; i++)
		{
			addedge(i,i+n,1);
			addedge(i+n,i,0);
			if(Cross(p[i],s))
			{
				addedge(0,i,1);
				addedge(i,0,0);
			}
			if(Cross(p[i],t))
			{
				addedge(i+n, 2*n+10,1);
				addedge(2*n+10,i+n,0);
			}
			for(j = 1; j <= n; j++)
				if(Cross(p[i],p[j]) && i!=j)
				{
					if(p[i].fre>p[j].fre)
					{
						addedge(i+n,j,1);
						addedge(j,i+n,0);
					}
					else
					{
						addedge(j+n,i,1);
						addedge(i,j+n,0);
					}
				}
		}
		int ans = dinic(0, 2*n+10);
		if(ans < 2)printf("Game is NOT VALID\n");
		else printf("Game is VALID\n");

	}
	return 0;
}
