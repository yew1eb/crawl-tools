#include <cstdio>
#include <cstring>

typedef long long ll;
const ll MOD = 1000000007;

int n, m;

ll pow_mod(ll x, int k) {
    x %= MOD;
    ll ans = 1;
    while (k) {
    if (k&1) ans = ans * x % MOD;
    x = x * x % MOD;
    k >>= 1;
    }
    return ans;
}

const int N = 55;

ll C[N][N];

int main() {
    for (int i = 1; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
    }
    while (~scanf("%d%d", &n, &m)) {
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        if (i % 2) {
        ans = ((ans - pow_mod((1LL<<(m - i)) - 1LL, n) * C[m][i] % MOD) % MOD + MOD) % MOD;
        }
        else ans = (ans + pow_mod((1LL<<(m - i)) - 1LL, n) * C[m][i] % MOD) % MOD;
    }
    printf("%lld\n", ans);
    }
    return 0;
}