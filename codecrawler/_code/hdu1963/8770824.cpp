#include <stdio.h>
#include <string.h>
#define MAXN 50000
#define max(a,b) ((a)>(b)?(a):(b))
int dp[MAXN];
int v[11], c[11];

int main()
{
    int t, m, year, d, i, j, k, sum;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &year);
        scanf("%d", &d);
        for (i = 0; i < d; i++) {
            scanf("%d%d", &v[i], &c[i]);
            v[i] /= 1000;
        }

        for (i = 1; i <= year; i++) {
            sum = m / 1000;
            memset(dp, 0, (sum + 1)*sizeof(dp[0]));
            for (j = 0; j < d; j++)
                for (k = v[j]; k <= sum; k++)
                    dp[k] = max(dp[k], dp[k - v[j]] + c[j]);
            m += dp[sum];
        }
        printf("%d\n", m);
    }
    return 0;
}
