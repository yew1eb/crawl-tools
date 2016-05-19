#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 3000;
const int inf = 0x3f3f3f3f;

int N, F[maxn], dp[maxn];

int solve (int n) {
    for (int i = 0; i <= n; i++) dp[i] = -inf;

    dp[0] = 0;
    for (int i = 2; i < N; i++) {
        for (int j = 0; j + i - 1 <= n; j++)
            dp[i+j-1] = max(dp[i+j-1], dp[j] + F[i]);
    }
    return dp[n];
}

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &N);
        for (int i = 1; i < N; i++) scanf("%d", &F[i]);
        int ans = F[1] * N;
        for (int i = 2; i < N; i++) F[i] -= F[1];
        printf("%d\n", ans + solve(N-2));
    }
    return 0;
}