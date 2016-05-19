#include<iostream>
#include<stdio.h>
using namespace std;
int map[1005][1005];
int dp[1005];
int mini(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
int main()
{
	int c,n,start,end,i,j;
	while(scanf("%d",&c)!=EOF)
	{
		scanf("%d",&n);
		for(start=1;start<=n;start++)
			for(end=start;end<=n;end++)
				scanf("%d",&map[start][end]);
		dp[0]=0;
		for(i=1;i<=n;i++)
		{
			dp[i]=100000000;
			for(j=0;j<i;j++)
				dp[i]=mini(dp[i],dp[j]+c+map[j+1][i]);
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}