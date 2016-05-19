#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1005;

int N, M, dp[maxn][maxn], A[maxn], B[maxn];
int vec[maxn][maxn], c[maxn];

void init () {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d%d", &A[i], &B[i]);

    memset(c, 0, sizeof(c));
    for (int i = 0; i <= M; i++)
        vec[i][c[i]++] = 0;
}

inline int find(int idx, int x) {
    return lower_bound(vec[idx], vec[idx]+c[idx], x) - vec[idx];
}

inline void set(int idx, int pos, int x) {
    if (pos == c[idx])
        vec[idx][c[idx]++] = x;

    while (pos && vec[idx][pos] >= x)
        vec[idx][pos--] = x;
}

int solve() {
    int ans = 0;
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= 0; j--) {
            int t = find(j, A[i]);
            dp[i][j] = max(dp[i][j], t);
            set(j, t, A[i]);

            if (j) {
                int p = find(j-1, B[i]);
                dp[i][j] = max(dp[i][j], p);
                set(j, p, B[i]);
            }
            ans = max(dp[i][j], ans);

            /*
            printf("%d:", j);
            for (int k = 0; k < c[j]; k++)
                printf(" %d", vec[j][k]);
            printf("\n");
            */
        }
    }
    return ans;
}

int main () {
    int cas;
    scanf("%d", &cas);

    while (cas--) {
        init();
        printf("%d\n", solve());
    }
    return 0;
}
