#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100005
#define MAXM 450
#define MOD 998244353
int n,c,l,r,dp[2][MAXN];
int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d%d",&n,&c,&l,&r);
        l -= c,r = min(r - c,n - 1);
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        int ans = l <= 0 ? 1 : 0;
        for(int i = 1;(i + 1) * i / 2 <= r;i++)
        {
            for(int j = (1 + i) * i / 2;j <= r;j++)
            {
                dp[i & 1][j] = (dp[i & 1][j - i] + dp[(i - 1) & 1][j - i]) % MOD;
                if(l <= j && j <= r)
                    ans = (ans + dp[i & 1][j]) % MOD;
            }
            memset(dp[(i - 1) & 1],0,sizeof(dp[(i - 1) & 1]));
        }
        printf("%d\n",ans);
    }
}
