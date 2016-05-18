#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
double l,r,m;
int n;
double dp[103][222][222];
void solve()
{
    m=1-r-l;
    dp[0][100][100]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=100-i;j<=100+i;j++)
        {
            for(int k=max(100,j);k<=100+i;k++)  //一定有k>=j>=100
            {
                if(j==k) dp[i][j][k]=dp[i-1][j][k]*m+dp[i-1][j-1][k-1]/*第一次到k点*/*r+dp[i-1][j-1][k]/*之前已经到过k点*/*r;
                else dp[i][j][k]=dp[i-1][j][k]*m+dp[i-1][j-1][k]*r+dp[i-1][j+1][k]*l;//k点是之前到的
            }
        }
    }
}
int main()
{
    int cas,id;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d %d %lf %lf",&id,&n,&l,&r);
        solve();
        double ans=0;
        for(int i=100;i<=100+n;i++)
            for(int j=100-n;j<=100+n;j++)
                ans+=dp[n][j][i]*(i-100);
        printf("%d %.4lf\n",id,ans);
    }
    return 0;
}
