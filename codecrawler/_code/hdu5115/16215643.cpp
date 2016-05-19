#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[222][222];
int a[222];
int n;

int min(int a,int b)
{
    return a<b?a:b;
}

int solve(int l,int r)
{
    if (dp[l][r]!=-1)
        return dp[l][r];
    if (l==r)
        return a[l-1]+a[l+1];
    dp[l][r]=min(solve(l+1,r),solve(l,r-1))+a[l-1]+a[r+1];
    for (int i=l;i+1<r;i++)
        dp[l][r]=min(dp[l][r],solve(l,i)+solve(i+2,r)+a[l-1]+a[r+1]);
    return dp[l][r];
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int r=1;r<=T;r++)
    {
        scanf("%d",&n);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int b;
            scanf("%d",&b);
            ans+=b;
        }
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[0]=a[n+1]=0;
        memset(dp,-1,sizeof(dp));
        ans+=solve(1,n);
        printf("Case #%d: %d\n",r,ans);
    }
}