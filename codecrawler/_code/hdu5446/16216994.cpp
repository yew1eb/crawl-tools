#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

ll fac[maxn], inv[maxn];

ll pow_mod(ll a, int n, int mod) {
    ll ret = 1;
    while (n) {
        if (n&1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

void init(int n) {
    fac[0] = 1;
    for (int i = 1; i < n; i++) fac[i] = fac[i-1] * i % n;
    inv[n-1] = pow_mod(fac[n-1], n-2, n);
    for (int i = n - 2; i >= 0; i--) inv[i] = inv[i+1] * (i+1) % n;
}

ll C (int n, int m, int mod) {
    if (m > n || m < 0 || n < 0) return    0;
    return fac[n] * inv[m] % mod * inv[n-m] % mod;
}

ll lucas(ll n, ll m, int mod) {
    if (m == 0) return 1;
    return lucas(n / mod, m / mod, mod) * C(n % mod, m % mod, mod) % mod;
}

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll d = exgcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
}

ll mul(ll a, ll b, ll mod) {
    a = (a % mod + mod) % mod;
    b = (b % mod + mod) % mod;

    ll ret = 0;
    while(b){
        if(b&1){
            ret += a;
            if(ret >= mod) ret -= mod;
        }
        b >>= 1;
        a <<= 1;
        if(a >= mod) a -= mod;
    }
    return ret;
}

ll china(int n, ll* a, ll* m) {
    ll M = 1, d, y, x = 0;
    for (int i = 0; i < n; i++) M *= m[i];
    for (int i = 0; i < n; i++) {
        ll w = M / m[i];
        exgcd(m[i], w, d, y);
        x = (x + mul(mul(y, w, M), a[i], M));
    }
    return (x + M) % M;
}

int main () {
    int cas, k;
    ll n, m, a[15], p[15];
    scanf("%d", &cas);
    while (cas--) {
        scanf("%lld%lld%d", &n, &m, &k);
        for (int i = 0; i < k; i++) {
            scanf("%lld", &p[i]);

            init(p[i]);
            a[i] = lucas(n, m, p[i]);
        }

        printf("%lld\n", china(k, a, p));
    }
    return 0;
}
