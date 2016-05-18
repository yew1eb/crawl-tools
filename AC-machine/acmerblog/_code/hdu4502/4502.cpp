#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[105][105];
int dp[105];
int main()
{
	int t;
	scanf("%d",&t);
	for(;t--;)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		int i;
		for(i=0;i<n;i++)
		{
			int t1,t2,t3;
			scanf("%d%d%d",&t1,&t2,&t3);
			if(t1>m||t2>m)
				continue;
			if(t3>a[t1][t2])
				a[t1][t2]=t3;
		}
		for(i=1;i<=m;i++)
		{
			for(int j=0;j<=i;j++)
			{
				dp[i]=max(dp[i],dp[j]+a[j+1][i]);
			}
		}
		printf("%d\n",dp[m]);
	}
}