#include <stdio.h>
#include <string.h>
#define MAXN 105
#define INF 0x7fffffff

int DP(int* b, int n)
{
    int sum, max, i;
    sum = 0;
    max = -INF;
    for (i = 0; i < n; i++) {
        sum += b[i];
        if (sum > max) {
            max = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return max;
}
int main()
{
    int n, i, j, k, max, sum;
    int a[MAXN][MAXN], b[MAXN];
    while (~scanf("%d", &n)) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        max = -INF;
        for (i = 0; i < n; i++) {
            memset(b, 0, sizeof(b));
            for (j = i; j < n; j++) {
                for (k = 0; k < n; k++)
                    b[k] += a[j][k];
                sum = DP(b, n);
                if (sum > max) max = sum;
            }

        }
        printf("%d\n", max);
    }
    return 0;
}

