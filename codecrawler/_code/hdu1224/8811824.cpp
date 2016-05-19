#include <stdio.h>
#include <string.h>
#define N 105
int dp[N], pre[N], a[N];
int g[N][N];
int n;
void print(int i)
{
    if (i == 1) {
        printf("1");
        return ;
    }
    print(pre[i]);
    printf("->%d", i);
}

int main()
{
    int T, cas, i, j, m, b, e;
    scanf("%d", &T);
    for (cas = 1; cas <= T; ++cas) {
        if (cas != 1) printf("\n");
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        memset(g, 0, sizeof(g));
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        a[n + 1] = 0;
        scanf("%d", &m);
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &b, &e);
            g[b][e] = 1;
        }

        for (i = 1; i <= n + 1; ++i) {
            for (j = 1; j <= i; j++) {
                if (g[j][i]) {
                    if (dp[j] + a[i] > dp[i]) {
                        dp[i] = dp[j] + a[i];
                        pre[i] = j;
                    }

                }
            }
        }
        printf("CASE %d#\n", cas);
        printf("points : %d\n", dp[n + 1]);
        printf("circuit : ");
        print(pre[n + 1]);
        printf("->%d\n", 1);
    }
    return 0;
}
