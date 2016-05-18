#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=3100;
int a[maxn],dp[maxn][maxn],ans;
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
	    scanf("%d",&a[i]);
	    a[i+n]=a[i];
	}
	int m=2*n;
	for(int i=1;i<=m;i++)
	    dp[i][i]=1;
	for(int i=1;i<n;i++)
	    for(int j=1;i+j<=m;j++)
	    {
		dp[j][i+j]=max(dp[j][i+j-1],dp[j+1][i+j]);
		if(a[j]==a[i+j])
		    dp[j][i+j]=max(dp[j][i+j],dp[j+1][i+j-1]+2);
	    }
	int ans=0;
	for(int i=1;i<=n;i++)
	    ans=max(ans,dp[i][i+n-1]);
	for(int i=1;i<=n;i++)
	    ans=max(ans,dp[i][i+n-2]+1);
	printf("%d\n",ans);
    }
    return 0;
}

