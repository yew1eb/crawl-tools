//分组背包,看背包九讲
/*
for 所有的组k
    for v=V..0
        for 所有的i属于组k
            f[v]=max{f[v],f[v-c[i]]+w[i]}
*/
#include<iostream>
#include<cstdio>
using namespace std;
int a[101][101];
int n,m;
int dp[101]; //dp[i]表示用i天的时间做功课得到的最大收益
int max(int a,int b)
{
	return a>b?a:b;
}
void solve(int x)
{
	int i,j;
	for(i=m;i>=0;i--)
		for(j=1;j<=m;j++)    //对于每个分组里物品
			if(i>=j)
			dp[i]=max(dp[i],dp[i-j]+a[x][j]);
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0))
	{
		int i,j;
		for(i=0;i<n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
			memset(dp,0,sizeof(dp));
			for(i=0;i<n;i++)
				solve(i);
			printf("%d/n",dp[m]);
	}
	return 0;
}