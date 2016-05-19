#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl

typedef long long ll;
const ll mod = 1e9 + 7;
ll pmod(ll a, ll n)
{
    ll ret = 1;
    for (; n; n>>=1, a=a*a%mod)
        if (n&1)
        ret = ret * a % mod;
    return ret;
}
ll getinv(ll a)
{
    return pmod(a, mod - 2);
}
const int N = 100100;
ll dp[N + 5], sum[N + 5];
const ll inv2 = getinv(2);
ll sub(ll a, ll b)
{
    return (a - b + mod) % mod;
}
void init()
{
    dp[0] = 1;
    dp[1] = 1;
    sum[0] = 1;
    sum[1] = 2;
    for (int i=1;i<N;i++)
    {
        dp[i+1] = (dp[i] * sum[i-1] % mod);
        dp[i+1] = (dp[i+1] + (dp[i] + 1)%mod * dp[i] % mod * inv2 % mod) % mod;
        sum[i+1] = (sum[i] + dp[i+1]) % mod;
    }
}
ll C3(ll a)
{
    return ((a*sub(a,1)%mod) * sub(a,2) % mod) * getinv(6) % mod;
}
ll f(int K)
{
    int i = K / 2;
    ll ans = ((dp[i] * (dp[i] +  1)%mod) % mod * inv2 % mod ) % mod;
    ll tmp = ans;
    if (K%2==0) {
        return ans;
    }
    ans = (ans * sum[i-1]) % mod;
    ans = (ans + dp[i]) % mod;
    ans = (ans + (dp[i]-1+mod)%mod * dp[i] % mod) % mod;
    ans = (ans + C3(dp[i])) % mod;
    return ans;
}
int main()
{
    int K;
    init();
    while (cin>>K, K)
    {
        ll ans = f(K);
        cout<<ans<<endl;
    }
    return 0;
}
