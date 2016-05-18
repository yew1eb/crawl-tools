#include<iostream>
using namespace std;
int main()
{
	__int64 dp[25][25];
	int n,m;
	dp[1][2]=0;
	for(int i=1;i<=20;i++)
		dp[i][1]=i;
	for(int i=2;i<=20;i++)
		for(int j=2;j<=20;j++)
		{
			if(i>=j)
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			else dp[i][j]=0;
		}
	while(scanf("%d %d",&n,&m)==2)
	{
		printf("%I64d\n",dp[n][m]);
	}
	return 0;
}