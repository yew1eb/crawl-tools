#include <cstdio>
#include <cstring>

typedef long long ll;

const ll MOD = 1000000007;

const int N = 105;

int n, a[N];
ll dp[N][N], C[N][N];

int main() {
    C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= 100; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
    }
    while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int len = 1; len < n; len++) {
        for (int l = 1; l + len <= n; l++) {
        int r = l + len;
        for (int k = l; k <= r; k++) {
            if (l == k) dp[l][r] = (dp[l][r] + dp[k + 1][r]) % MOD;
            else if (r == k) dp[l][r] = (dp[l][r] + dp[l][k - 1]) % MOD;
            else if (a[k - 1] == a[k + 1]) dp[l][r] = (dp[l][r] + (dp[l][k - 1] * dp[k + 1][r] % MOD * C[r - l][k - l]) % MOD) % MOD;
        }
        }
    }
    printf("%lld\n", dp[1][n]);
    }
    return 0;
}