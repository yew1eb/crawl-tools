#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAXM 50005
int dp[2][MAXM];
int main()
{
    int _,n,m;
    for(int kcas = scanf("%d",&_);kcas <= _;kcas++)
    {
        scanf("%d%d",&n,&m);
        int l = sqrt(2.0 * n + 1);
        memset(dp,0,sizeof(dp));
        dp[1][1] = 1;
        int ans = 0;
        for(int j = 1;j <= l;j++)
        {
            for(int i = 1;i <= n && i + j <= n;i++)
            {
                dp[j & 1][i + j] = (dp[j & 1][i] + dp[j & 1][i + j]) % m;
                dp[(j + 1) & 1][i + j + 1] = (dp[j & 1][i] + dp[(j + 1) & 1][i + j + 1]) % m;
            }
            ans = (ans + dp[j & 1][n]) % m;
            memset(dp[j & 1],0,sizeof(dp[j & 1]));
        }
        printf("Case #%d: %d\n",kcas,ans);
    }
}
