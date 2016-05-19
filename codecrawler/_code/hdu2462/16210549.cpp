#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
typedef long long ll;
typedef long long LL;
const ll inf = 0x3f3f3f3f;
ll gcd(ll a, ll b)
{
    return b==0 ? a: gcd(b, a%b);
}

ll L;
ll mul(ll a, ll b, ll mod)
{
    ll ret = 0;
    for (; b; b>>=1, a=(a+a)%mod) if (b &1)
    {
        ret = (ret + a) % mod;
    }
    return ret;
}
ll pmod(ll a, ll n, ll mod)
{
    ll r = 1;
    for (; n>0; a=mul(a,a,mod), n>>=1)
        if (n & 1)
        r  = mul(r, a, mod);
    return r;
}
ll phi(ll n)
{
    ll m = sqrt(n + 0.5);
    ll ans = n;
    for (int i=2;i<=m;i++) if(n%i==0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}
bool can(ll x)
{
    return pmod(10, x, L) == 1;
}
int main()
{
    int ca = 1;
    while (cin>>L && L) {
        ll m = L;
        L = 9 * L / gcd(8, 9*L);
        printf("Case %d: ", ca++);
        if (gcd(10, L) > 1) {
            puts("0");
            continue;
        }
        ll n = phi(L);
        ll ans = 1e18;
        for (ll i = 1; i <= sqrt(n+0.5); i++) if (n%i==0)
        {
            if (can(i)) ans = min(ans, i);
            if (can(n / i)) ans = min(ans, n / i);
        }
        printf("%I64d\n", ans>=1e18 ? 0 : ans);
    }
    return 0;
}
