#include<iostream>
#include<vector>
using namespace std;
#define N 201
vector<int> E[N];
int dp_temp[N][N],dp[N][N];
int val[N],n,m;
bool h[N];

void init(int n){
	val[0]=0;
	for(int i=0;i<=n;i++)
		E[i].clear();
	memset(h,0,sizeof(h));
	memset(dp,-1,sizeof(dp));
	memset(dp_temp,-1,sizeof(dp_temp));
}

void dfs(int u){
	if(h[u]) return;
	h[u]=1;
	dp_temp[u][0]=0;
	for(int i=0;i<E[u].size();i++){
		int v=E[u][i];
		if(!h[v])
			dfs(v); //叶子节点未访问过则继续访问 
		for(int j=m;j>=0;j--)
			for(int k=1;k+j<=m;k++)
				if(dp_temp[u][j]!=-1&&dp[v][k]!=-1){
					if(dp_temp[u][j+k]<dp_temp[u][j]+dp[v][k])
						dp_temp[u][j+k]=dp_temp[u][j]+dp[v][k];
				}
	}
	for(int i=0;i<=m;i++)
		if(dp_temp[u][i]!=-1)
			dp[u][i+1]=dp_temp[u][i]+val[u];
}
int main(void){
	while(scanf("%d%d",&n,&m),n||m){
		init(n);
		for(int i=1;i<=n;i++){
			int u;
			scanf("%d%d",&u,&val[i]);
			E[u].push_back(i);
		}
		dfs(0);
		printf("%d\n",dp[0][m+1]);
	}
}

/*

dp[i][j]代表以i为根节点，一共选取j个节点所取得的最大价值，i这个节点一定要选
dp_temp[i][j]代表以i为根节点，一共选取j个节点所取得的最大价值，i这个节点一定不选

那么	 dp[i][j+1]=dp_temp[i][j]+val[i];
		 dp_temp[i][j+k]=max(dp_temp[i][j+k],dp_temp[i][j]+dp[son[i]][k]);
		
解释一下 dp_temp[i][j]+dp[son[i]][k]，其中 son[i]代表i这个节点的孩子节点，
		 假设son[i]这个节点中存在选取K个节点这个状态，那么这个孩子节点就
		 可以向dp_temp[i][j+k]转移，因为转移的时候都是从孩子转移过来的，
		 那么要是选择了son[i]这个节点，这个节点本身是一定要选择的，
		 所以转移方程不是 + dp_temp[son[i]][k],而是 +dp[son[i]][k] 
		 
*/