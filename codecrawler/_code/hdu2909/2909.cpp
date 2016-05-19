#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int N=100000;
int dp[2][N];
int main()
{
	int n,m,k;
	while(scanf("%d %d %d",&n,&m,&k)!=EOF)
	{
		if(n==m&&m==k&&k==0)
			break;
		memset(dp,false,sizeof(dp));
		for(int i=1;i<=m;i++)
			dp[1][i]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=i*m;j++)
				for(int t=1;t<=m;t++)
					dp[i&1][j+t]+=dp[(i-1)&1][j];
			memset(dp[(i-1)&1],false,sizeof(dp[(i-1)&1]));
		}
		double ans=0.0;
		int i,j;
		for(i=1;i<=k+1;i++)
			ans+=dp[n&1][i];
		j=2;
		while(i<=n*m)
		{
			ans+=dp[n&1][i]*j;
			i++;
			j++;
		}
		int tmp=1;
		i=1;
		while(i<=n)
		{
			tmp=tmp*m;
			i++;
		}
		printf("%.8lf\n",ans/tmp);
	}
	return 0;
}