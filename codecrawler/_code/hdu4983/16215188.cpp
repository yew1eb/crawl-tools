#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 1e5;
const int MOD = 1e9+7;
typedef long long ll;

ll ans;
int N, K, M;
int np, pri[maxn+5], vis[maxn+5];
int nf, fact[maxn+5], coun[maxn+5];

void prime_table (int n) {
    np = 0;
    memset(vis, 0, sizeof(vis));

    for (int i = 2; i <= n; i++) {
        if (vis[i])
            continue;
        pri[np++] = i;
        for (int j = 2 * i; j <= n; j += i)
            vis[j] = 1;
    }
}

void div_factor(int n) {
    nf = 0;
    for (int i = 0; i < np; i++) {
        if (n % pri[i] == 0) {
            coun[nf] = 0;
            while (n % pri[i] == 0) {
                coun[nf]++;
                n /= pri[i];
            }
            fact[nf++] = pri[i];
        }
    }

    if (n != 1) {
        coun[nf] = 1;
        fact[nf++] = n;
    }
}

int euler_phi(int n) {
    int m = (int)sqrt((double)n+0.5);
    int ret = n;
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            ret = ret / i * (i-1);
            while (n%i==0)
                n /= i;
        }
    }

    if (n > 1)
        ret = ret / n * (n - 1);
    return ret;
}

ll add (int s) {
    ll a = euler_phi(N/s);
    ll b = euler_phi(s);
    ll ret = a * b * 2;

    if (s == N / s)
        ret /= 2;
    return ret;
}

void dfs (int s, int d) {
    if (s > M)
        return;

    if (d == nf) {
        ans = (ans + add(s)) % MOD;
        return;
    }

    for (int i = 0; i <= coun[d]; i++) {
        dfs(s, d+1);
        s *= fact[d];
    }
}

int solve () {
    ans = 0;
    M = (int)sqrt((double)N);
    div_factor(N);
    dfs (1, 0);
    return ans % MOD;
}

int main () {
    prime_table(maxn);
    while (scanf("%d%d", &N, &K) == 2) {
        if (N == 1) 
            printf("1\n");
        else if (K > 2)
            printf("0\n");
        else if (K == 2)
            printf("1\n");
        else
            printf("%d\n", solve());
    }
    return 0;
}