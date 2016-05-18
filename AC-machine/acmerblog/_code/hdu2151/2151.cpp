#include"stdio.h"
int main()
{
	int dp[100][200];
	int i,j;
	int n,sta,time,end;
	while(scanf("%d%d%d%d",&n,&sta,&time,&end)!=EOF)
	{
		for(i=1;i<=n;i++)
			dp[0][i]=0;
		dp[0][sta]=1;
		for(i=1;i<=time;i++)
		{
			dp[i][1]=dp[i-1][2];
			dp[i][n]=dp[i-1][n-1];
			for(j=2;j<n;j++)
				dp[i][j]=dp[i-1][j+1]+dp[i-1][j-1];
		}
		printf("%d\n",dp[time][end]);
	}
	return 0;
}