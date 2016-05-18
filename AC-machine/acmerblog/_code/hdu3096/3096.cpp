#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
int const maxn = 30;
int mp[maxn][maxn];
int n, m, a, b;
bool dp[maxn][maxn][2020];
int const base = 1000;

int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d", &n, &m);
        scanf("%d%d", &a, &b);
        a += base, b += base;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &mp[i][j]);
            }
        }
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= m; ++i) {
            dp[1][i][mp[1][i] + base] = true;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 0; k <= 2000; ++k) {
                    if (dp[i][j][k]) {
                        if (j > 1) dp[i + 1][j - 1][k + mp[i + 1][j - 1]] = true;
                        if (j < m) dp[i + 1][j + 1][k + mp[i + 1][j + 1]] = true;
                        dp[i + 1][j][k + mp[i + 1][j]] = true;
                    }
                }
            }
        }
        int r_min = inf, r_max = -inf;
        for (int i = 1; i <= m; ++i) {
            for (int j = a; j <= b; ++j) {
                if (dp[n][i][j]) {
                    r_min = min(r_min, j);
                    r_max = max(r_max, j);
                }
            }
        }
        if (r_min == inf) printf("NO "); else printf("%d ", r_min - base);
        if (r_max == -inf) printf("NO\n"); else printf("%d\n", r_max - base);
    }
    return 0;
}