#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#define inf 1<<27
#define N 105
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define LL long long
using namespace std;
int dp[105][105];
int val[105],sum[105];
int main(){
	int n,t,cas=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sum[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&val[i]);
			sum[i]=sum[i-1]+val[i];
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				dp[i][j]=inf;
		for(int l=1;l<=n-1;l++){
			for(int i=1;i<=n-l;i++){
				int j=i+l;
				//dp[i][j]=min(dp[i][j],dp[i+1][j]+sum[j]-sum[i]);
				for(int k=i;k<=j;k++)
					dp[i][j]=min(dp[i][j],val[i]*(k-i)+(k-i+1)*(sum[j]-sum[k])+dp[i+1][k]+dp[k+1][j]);
			}
		}
		printf("Case #%d: %d\n",++cas,dp[1][n]);
	}
	return 0;
}
