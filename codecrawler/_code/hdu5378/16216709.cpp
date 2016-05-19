#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
typedef long long ll;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
const ll N = 1005;
int sz[N];
vector<int> g[N];
ll dp[N][N];
int  n, K;
ll fac[N];
ll pmod(ll a, ll n)
{
    ll r  = 1;
    for (; n>0; n>>=1, a=a*a%mod) {
        if (n & 1) r = r * a % mod;
    }
    return r;
}
inline ll inv(ll a)
{
    return pmod(a, mod - 2);
}
void dfs(int u, int fa)
{
    sz[u] = 1;
    for (int v: g[u]) if (v-fa) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}
ll in[N];
int main()
{
    fac[0] = 1; in[1] = 1;
    for (ll i=1;i<N;i++) fac[i]=fac[i-1]*i%mod, in[i]=inv(i);
    int re; scanf("%d", &re); int ca= 1;
    while (re--) {
        memset(sz,0 , sizeof sz);
        scanf("%d%d", &n ,&K);
        for(ll i=0;i<=n;i++) g[i].clear();
        memset(dp, 0, sizeof dp);
        for (ll i=0;i<n-1;i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 1);
        dp[0][0] = 1;
        for (int i=1;i<=n;i++)
        for (int j=0;j<=K;j++) {
            dp[i][j] = dp[i-1][j] * (sz[i] - 1) %mod
            * in[sz[i]] % mod;
            if (j > 0)
                dp[i][j] += dp[i-1][j-1] * in[sz[i]] % mod;
            dp[i][j] %= mod;
        }
        ll ans = dp[n][K] * fac[n] % mod;
        printf("Case #%d: %I64d\n", ca++, ans);
    }
    return 0;
}
