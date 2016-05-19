#include <stdio.h>
#include <string.h>
#define INF 0xf7fffffff
const int maxn = 105;

int dp[maxn], a[maxn], price[maxn], sum[maxn];

int main()
{
    int t, n, i, j, min;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        sum[0] = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d%d", &a[i], &price[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        for (i = 1; i <= n; i++) {
            min = INF;
            for (j = 0; j < i; j++)
                if (min > dp[j] + (sum[i] - sum[j] + 10)* price[i])
                    min = dp[j] + (sum[i] - sum[j] + 10) * price[i];
            dp[i] = min;
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
