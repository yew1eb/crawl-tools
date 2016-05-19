#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 105;
typedef long long ll;
const ll mod = 1e9+7;

int N, v[maxn];
ll dp[maxn][maxn], C[maxn][maxn];

void init (int n) {
    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
}

int solve() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++)  dp[i][i] = 1;
    for (int len = 1; len < N; len++) {
        for (int l = 1; l + len <= N; l++) {
            int r = l + len;
            for (int k = l; k <= r; k++) {
                if (k == l)
                    dp[l][r] = (dp[l][r] + dp[k+1][r]) % mod;
                else if (k == r)
                    dp[l][r] = (dp[l][r] + dp[l][k-1]) % mod;
                else if (v[k-1] == v[k+1])
                    dp[l][r] = (dp[l][r] + dp[l][k-1] * dp[k+1][r] % mod * C[r-l][k-l] % mod) % mod;
            }
        }
    }
    return dp[1][N];
}

int main () {
    init(100);
    while (scanf("%d", &N) == 1) {
        for (int i = 1; i <= N; i++)
            scanf("%d", &v[i]);
        printf("%d\n", solve());
    }
    return 0;
}
