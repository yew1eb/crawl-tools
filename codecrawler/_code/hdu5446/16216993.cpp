#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
#define ll long long
#define CL(a) memset(a,0,sizeof(a))
const int maxn = 1e5 + 5;

ll fac[maxn]={0,1},inv[maxn]={0,1};

ll pow_mod(ll a, ll n, ll mod)//å¿«éå¹åæ¨¡
{
    ll ret = 1;
    while (n)
    {
        if (n&1)
            ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}

ll Lucas(ll n, ll m, ll mod)//Lucaså®ç
{
    ll ret=1;
    ll mm=m,nn=n;
    while (mm && nn)
    {
        ll mod_m=mm%mod, mod_n=nn%mod;
        if (mod_n>=mod_m)
            ret = ret*fac[mod_n]%mod*inv[mod_m]%mod*inv[mod_n-mod_m]%mod;
        else
        {
            ret = 0;
            break;
        }
        mm/=mod;
        nn/=mod;
    }
    return ret;
}

void exgcd(ll a, ll b, ll &d, ll &x, ll &y)//æ©å±æ¬§å éå¾·æ±éå
{
    if (b == 0)
        d = a, x = 1, y = 0;
    else
    {
        exgcd(b, a%b, d, y, x);
        y -= x * (a / b);
    }
}

ll china(ll n, ll m[], ll a[])//ä¸­å½å©ä½å®çæ±è§£
{
    ll aa = a[0];
    ll mm = m[0];
    for (int i=0; i<n; i++)
    {
        ll sub = (a[i] - aa);
        ll d, x, y;
        exgcd(mm, m[i], d, x, y);
        if (sub % d) return -1;

        ll new_m = m[i]/d;
        new_m = (sub/d*x%new_m+new_m)%new_m;
        aa = mm*new_m+aa;
        mm = mm*m[i]/d;
    }
    aa = (aa+mm)%mm;
    return aa;
}

int main ()
{
    int cas;
    ll n, m, k, a[15], p[15];
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        for (int i=0; i<k; i++)
        {
            scanf("%lld",&p[i]);
            //init(p[i]);
            for (int j=2; j<p[i]; j++)
                fac[j] = fac[j-1]*j%p[i];
            inv[p[i]-1] = pow_mod(fac[p[i]-1], p[i]-2, p[i]);
            for (int j=p[i]-1; j>0; j--)
                inv[j-1] = inv[j]*j%p[i];

            a[i] = Lucas(n, m, p[i]);
        }
        printf("%lld\n",china(k, p, a));
    }
    return 0;
}
