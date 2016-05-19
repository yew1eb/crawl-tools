#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define INF 0x7fffffff
int dp[25][1005];
int map[25][1005];

int main()
{
    int t, i, j, n, m, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                scanf("%d", &map[i][j]);
        for (i = 0; i <= n; i++) dp[i][0] =  -INF;
        for (i = 0; i <= m; i++) dp[0][i] = -INF;
        dp[0][1] = dp[1][0] = 0;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)

            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
                k = 2;
                while (j / k > 0) {
                    if (j % k == 0)
                        dp[i][j] = max(dp[i][j], dp[i][j / k] + map[i][j]);
                    k++;
                }
            }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
