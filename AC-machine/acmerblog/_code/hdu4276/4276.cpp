#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#define inf 1<<27
#define N 105
#define M 505
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
struct Node{
	int v,w,next;
}edge[N*2];
int tot,start[N],val[N],dist[N];
int n,t,dp[N][M],pre[N],p[N];
void _addedge(int u,int v,int w){
	edge[tot].v=v;edge[tot].w=w;
	edge[tot].next=start[u];
	start[u]=tot++;
}
void addedge(int u,int v,int w){
	_addedge(u,v,w);
	_addedge(v,u,w);
}
void spfa(int s){
	queue<int>que;
	int vis[N];
	mem(vis,0);mem(pre,0);
	for(int i=1;i<=n;i++)
		if(i==s)
			dist[i]=0;
		else
			dist[i]=inf;
	que.push(s);
	vis[s]=1;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		vis[u]=0;
		for(int i=start[u];i!=-1;i=edge[i].next){
			int v=edge[i].v,w=edge[i].w;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pre[v]=u;
				p[v]=i;
				if(!vis[v]){
					vis[v]=1;
					que.push(v);
				}
			}
		}
	}
	for(int i=n;i!=1;i=pre[i]){
		edge[p[i]].w=0;
		edge[p[i]^1].w=0;
	}
}
void dfs(int u,int father){
	for(int i=start[u];i!=-1;i=edge[i].next){
		int v=edge[i].v,w=edge[i].w*2;
		if(v==father) continue;
		dfs(v,u);
		for(int i=t;i>=w;i--)
			for(int j=i-w;j>=0;j--)
				dp[u][i]=max(dp[u][i],dp[u][j]+dp[v][i-j-w]);
	}
	for(int i=0;i<=t;i++)
		dp[u][i]+=val[u];
}
int main(){	
	while(scanf("%d%d",&n,&t)!=EOF){
		tot=0;mem(start,-1);
		for(int i=1;i<n;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
		}
		for(int i=1;i<=n;i++)
		    scanf("%d",&val[i]);
		spfa(1);
		if(dist[n]>t){
			puts("Human beings die in pursuit of wealth, and birds die in pursuit of food!");
			continue;
		}
		mem(dp,0);
		t-=dist[n];
		dfs(1,0);
		printf("%d\n",dp[1][t]);
	}
	return 0;
}
