#include<stdio.h>
int dp[2001][2001];
int main()
{
	int i,j,k;
	for(i=1;i<=2000;i++)
	{
		dp[i][1]=1;
		dp[i][i]=1;
	}
	for(i=2;i<=2000;i++)
	{
		for(j=2;j<i;j++)
		{
			dp[i][j]=(dp[i-1][j-1]+j*dp[i-1][j])%1000;
		}
	}
	int t,n,sum;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			sum=(sum+dp[n][i])%1000;
		printf("%d\n",sum);
	}
	return 0;
}