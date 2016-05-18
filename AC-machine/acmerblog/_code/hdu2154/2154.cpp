#include"stdio.h"
int main()
{
	__int64 dp[1005];
	int i;
	int n;
	dp[1]=0;
	dp[2]=2;
	for(i=3;i<=1000;i++)
	{
		dp[i]=dp[i-1]+2*dp[i-2];
		dp[i]%=10000;
	}
	while(scanf("%d",&n)!=EOF&&n!=0)
		printf("%I64d\n",dp[n]);
	return 0;
}