#include <stdio.h>
#include <string.h>
#define MAX 1010
#define INF -1
#define max(a,b) (a) > (b) ? (a) : (b)


int n,m,len[30],arr[MAX];
int sum[MAX],dp[30][MAX];


int Solve() {

	int i,j,k,ans;
	for (i = 1; i <= m; ++i)
		for (j = 0; j <= n; ++j)
			dp[i][j] = INF;

	
	for (i = 1; i <= m; ++i) 
		for (j = len[i]; j <= n; ++j)
			if (dp[i-1][j-len[i]] != INF) {

				int tp = dp[i-1][j-len[i]];
				tp += sum[j] - sum[j-len[i]];
				dp[i][j] = max(tp,dp[i][j]);
				if (dp[i][j-1] != INF)
					dp[i][j] = max(dp[i][j],dp[i][j-1]);
			}


	ans = INF;
	for (i = 1; i <= n; ++i)
		if (dp[m][i] != INF) ans = max(ans,dp[m][i]);
	return ans == INF ? 0 : ans;
}


int main()
{
	int i,j,k;


	while (scanf("%d",&n) ,n) {

		scanf("%d",&m);
		for (i = 1; i <= m; ++i)
			scanf("%d",&len[i]);
		memset(sum,0,sizeof(sum));
		for (i = 1; i <= n; ++i)
			scanf("%d",&arr[i]),sum[i] = sum[i-1] + arr[i];	

		
		printf("%d\n",Solve());
	}
}