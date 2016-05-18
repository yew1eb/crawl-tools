#include<stdio.h>
#include<string.h>
#define INF 100000000
int map[210][210],pre[210],weight[210];
int n,m,start,end;
int bfs(){
	int h=0,t=1,q[40100];
	q[h]=start;
	memset(pre,0,sizeof(pre));
	while(h<t){
		int cur=q[h];
		for(int i=1;i<=2*n;i++){
			if(pre[i]==0&&map[cur][i]>0){
				q[t++]=i;
				pre[i]=cur;
				if(i==end)	return 1;		
			}
		}
		h++;
	}
	return 0;
}
int query(){
	int min=2*INF,u=end,v;
	while(u!=start){
		v=pre[u];
		if(min>map[v][u])	min=map[v][u];
		u=v;
	}
	return min;
}
void update(int min){
	int u,v;
	u=end;
	while(u!=start){
		v=pre[u];
		map[v][u]-=min;
		map[u][v]+=min;
		u=v;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&start,&end);
		memset(map,0,sizeof(map));
		for(int i=1;i<=n;i++){
			scanf("%d",&weight[i]);
			map[i*2-1][i*2]=weight[i];
		}
		map[start*2-1][start*2]=map[end*2-1][end*2]=0;
		start*=2;
		end=end*2-1;
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			map[y*2][x*2-1]=map[x*2][y*2-1]=INF;
		}
		int ans=0;
		while(bfs()){
			int min=query();
			ans+=min;
			update(min);
		}
		printf("%d\n",ans);
	}
	return 0;
}