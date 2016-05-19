#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int N = 200005;

int t, n, m, f[N], rf[N];

int pow_mod(int x, int k) {
    int ans = 1;
    while (k) {
        if (k&1) ans = (ll)ans * x % MOD;
        x = (ll)x * x % MOD;
        k >>= 1;
    }
    return ans;
}

int C(int n, int m) {
    return (ll)f[n] * rf[n - m] % MOD * rf[m] % MOD;
}

int cal(int x, int n, int sum) {
    if (n == 0) return sum == 0;
    int ans = 0;
    for (int i = 0; i * x <= sum && i <= n; i++) {
        int tmp = (ll)C(n, i) * C(sum - i * x + n - 1, n - 1) % MOD;
        if (i%2) ans = ((ans - tmp) % MOD + MOD) % MOD;
        else ans = (ans + tmp) % MOD;
    }
    return ans;
}

int main() {
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = (ll)f[i - 1] * i % MOD;
    rf[N - 1] = pow_mod(f[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--)
        rf[i] = (ll)rf[i + 1] * (i + 1) % MOD;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = (ans + cal(i, m - 1, n - i)) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}
