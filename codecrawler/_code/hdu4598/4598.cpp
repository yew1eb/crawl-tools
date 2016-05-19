#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

char mp[305][305];
int col[305];
const int T=400;

struct Edge{
	int u,v,w;
	int next;
}edge[300*300*2];
int head[305],tot;
int dis[305],cnt[305],n; bool vis[305];

bool Dcol(int u){
	for(int j=0;j<n;j++){
		if(mp[u][j]=='1'){
			if(col[j]==0){
				col[j]=col[u]*(-1);
				if(!Dcol(j)){ return false;
				}
			}
			else if(col[j]==col[u]) return false;
		}
	}
	return true;
}

void addedge(int u,int v,int w){
	edge[tot].u=u;
	edge[tot].v=v;
	edge[tot].w=w;
	edge[tot].next=head[u];
	head[u]=tot++;
}

bool spfa(){
	queue<int>q;
	for(int i=0;i<=n;i++){
		dis[i]=1<<30;
	}
	dis[0]=0;
	memset(vis,false,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	q.push(0);
	vis[0]=true;
	while(!q.empty()){
		int u=q.front(); q.pop();
		vis[u]=false;
		for(int e=head[u];e!=-1;e=edge[e].next){
			int v=edge[e].v;
			if(dis[u]+edge[e].w<dis[v]){
				dis[v]=dis[u]+edge[e].w;
				cnt[v]++;
				if(cnt[v]>n) return false;
				if(!vis[v]){
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
	return true;
}

int main(){
	int Tc;
	scanf("%d",&Tc);
	while(Tc--){
		scanf("%d",&n);
		memset(col,0,sizeof(col));
		for(int i=0;i<n;i++){
			scanf("%s",mp[i]);
		}
		bool flag=true;
		for(int i=0;i<n;i++){
			if(col[i]==0){
				col[i]=1;
				if(!Dcol(i)){
					flag=false;
					break;
				}
			}
		}
		if(!flag){
			puts("No");
		}
		else{
			memset(head,-1,sizeof(head));
			tot=0;
			int u,v;
			for(int i=0;i<n;i++){
				u=i+1;
				if(col[i]>0){
					addedge(0,u,T-1);
					addedge(u,0,0);
				}
				else{
					addedge(u,0,T-1);
					addedge(0,u,0);
				}
				for(int j=i+1;j<n;j++){
					v=j+1;
					if(col[i]<0) swap(u,v);
					if(mp[i][j]=='1'){
						addedge(u,v,-1*T);
					}
					else{
						if(col[i]==col[j]) continue;
						addedge(v,u,T-1);
					}
				}
			}
			if(spfa()){
				puts("Yes");
			}
			else puts("No");
		}
	}
	return 0;
}
