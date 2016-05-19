#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long ll;

const ll MOD = 1000000007;
const int N = 35333;

ll n, k, pn, vis[N];
ll prime[N], frc[N], fn, cnt[N];

void getprime() {
    pn = 0;
    for (ll i = 2; i < N; i++) {
    if (vis[i]) continue;
    prime[pn++] = i;
    for (ll j = i * i; j < N; j += i)
        vis[j] = 1;
    }
}

void getfrc(ll n) {
    fn = 0;
    for (ll i = 0; i < pn && n >= prime[i]; i++) {
    if (n % prime[i] == 0) {
        frc[fn] = prime[i];
        cnt[fn] = 0;
        while (n % prime[i] == 0) {
        cnt[fn]++;
        n /= prime[i];
        }
        fn++;
    }
    }
    if (n != 1) {
    frc[fn] = n;
    cnt[fn++] = 1;
    }
}

ll ans = 0;

ll phi(ll n) {
    ll m = (ll)sqrt(n * 1.0);
    ll ans = n;
    for (ll i = 2; i <= m; i++) {
    if (n % i == 0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

void dfs(ll u, ll sum) {
    if (u == fn) {
    ll r = n / sum;
    ans = (phi(n / sum) * phi(sum) % MOD + ans) % MOD;
    return;
    }
    for (ll i = 0; i <= cnt[u]; i++) {
    dfs(u + 1, sum);
    sum *= frc[u];
    }
}

ll solve() {
    getfrc(n);
    ans = 0;
    dfs(0, 1);
    return ans;
}

int main() {
    getprime();
    while (~scanf("%I64d%I64d", &n, &k)) {
    if (n == 1) printf("1\n");
    else if (k == 2) printf("1\n");
    else if (k > 2) printf("0\n");
    else {
        printf("%I64d\n", solve());
    }
    }
    return 0;
}