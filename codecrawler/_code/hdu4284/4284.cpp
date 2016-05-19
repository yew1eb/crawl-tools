#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#define inf 1<<28
#define N 105
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,money,h;
int path[N][N];
int dp[20][1<<16];
int work[20],c[20],d[20];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&money);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				path[i][j]=inf;
			path[i][i]=0;
		}
		for(int i=0;i<m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			u--;v--;
			path[u][v]=Min(path[u][v],w);
			path[v][u]=path[u][v];
		}
		//Floyd预处理
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(i!=k&&i!=j&&j!=k)
						path[i][j]=Min(path[i][k]+path[k][j],path[i][j]);
		scanf("%d",&h);
		int pos=-1;
		for(int i=0;i<h;i++){
			scanf("%d%d%d",&work[i],&c[i],&d[i]);
			work[i]--;
			if(work[i]==0) pos=i;   //说明必需点中包含了起点1
		}
		//如果不包含，我们加入冗余点，便于后面处理，c和d都为0
		if(pos==-1){
			work[h]=0;c[h]=0;d[h]=0;
			pos=h++;
		}
		memset(dp,-1,sizeof(dp));
		if(money-d[pos]>=0) dp[pos][1<<pos]=money-d[pos]+c[pos];dp[pos][0]=money;
		for(int i=0;i<(1<<h);i++){
			for(int j=0;j<h;j++){
				if(dp[j][i]==-1) continue;
				for(int k=0;k<h;k++){
					if(k==j||((1<<k)&i)) continue;
					//钱够在两个城市之间移动，而且够买证
					if(dp[j][i]>=path[work[j]][work[k]]+d[k])
						dp[k][i|(1<<k)]=Max(dp[k][i|(1<<k)],dp[j][i]-path[work[j]][work[k]]-d[k]+c[k]);
				}
			}
		}
		bool ans=false;
		for(int i=0;i<h;i++)
			//最后判断能不能返回起点
			if(dp[i][(1<<h)-1]>=path[work[i]][0]){
				ans=true;
				break;
			}
		puts(ans?"YES":"NO");
	}
	return 0;
}
			