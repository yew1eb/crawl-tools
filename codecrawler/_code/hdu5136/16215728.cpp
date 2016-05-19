#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define inf 1<<30
#define eps 1e-8
using namespace std;
const int maxn=100005;
const ll mod=1000000007;
ll f[maxn];
ll dp[maxn];
ll sum[maxn];
ll inv[10];
ll powMod(ll a,ll b)
{
    if(b==0) return 1;
    ll ans=powMod(a,b/2);
    ans=ans*ans%mod;
    if(b&1)
        ans=ans*a%mod;
    return ans;
}
int main()
{
    int k;
    inv[2]=powMod(2,mod-2);
    inv[3]=powMod(3,mod-2);
    f[0]=1;
    dp[0]=1;
    for(int i=1;i<=50000;i++) {
        if(i-2>=0)
            f[i]=f[i-1]*dp[i-2]%mod;
        else
            f[i]=0;
        f[i]=(f[i]+f[i-1]*(f[i-1]+1)%mod*inv[2]%mod)%mod;
        dp[i]=(dp[i-1]+f[i])%mod;
    }
    while(~scanf("%d",&k) && k) {
        ll ans;
        if(k&1) {
            ans=f[k/2]*(f[k/2]+1)%mod*inv[2]%mod*dp[k/2-1]%mod;
            ans=((ans+f[k/2])%mod+f[k/2]*(f[k/2]-1)%mod)%mod;
            ans=(ans+f[k/2]*(f[k/2]-1)%mod*(f[k/2]-2)%mod*inv[2]%mod*inv[3]%mod)%mod;
        }
        else {
            ans=f[k/2]*(f[k/2]+1)%mod*inv[2]%mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
