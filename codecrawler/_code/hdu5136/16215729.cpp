#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#define scnaf scanf
#define cahr char
#define bug puts("bugbugbug");
using namespace std;
typedef long long ll;
const int inf=1000000000;
const int maxn=1e5+100;
const int m=1e5;
const int mod=1e9+7;
ll dp[maxn];//æ·±åº¦ä¸ºiçæ çæ¹æ¡æ°
ll f[maxn];//æ·±åº¦å°äºç­äºiçæ çæ¹æ¡æ°
ll inv2=500000004;
ll inv6=166666668;
void init()
{
    dp[0]=0;
    dp[1]=1;
    f[0]=1;
    f[1]=2;
    for(int i=2;i<=m;i++)
    {
        dp[i] = dp[i-1] * f[i-2] % mod + dp[i-1] * (dp[i-1] - 1 + mod) % mod * inv2 % mod;
        dp[i]=(dp[i-1]+dp[i])%mod;
        f[i]=(dp[i] + f[i-1])%mod;
    }
}
int main()
{
    init();
    int n;
    while(~scanf("%d",&n) && n)
    {
        if(n==1)
        {
            puts("1");
            continue;
        }
        ll zz=dp[n/2];
        ll ans=(zz * (zz - 1 + mod) % mod * inv2 % mod + zz)%mod;
        if(n%2)
        {
          ans = ans * f[n/2-1] % mod;
          ans =( ans+ zz * (zz-1) %mod * (zz-2) %mod * inv6 % mod +zz * (zz-1)  % mod + zz)%mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
