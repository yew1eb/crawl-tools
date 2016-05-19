#include <stdio.h>
#include <string.h>
#define MAXN 100000

int f[MAXN];

int main()
{
    int i, n, sum, ans, cnt, a, b;
    while (~scanf("%d", &n)) {
        for (i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            f[i] = a - b;
        }
        sum = cnt = 0;
        ans = 0;
        for (i = 0; i < n * 2 - 1; i++) {
            sum += f[i % n];
            if (sum >= 0) {
                cnt++;
                if (cnt > ans) ans = cnt;
                if (cnt == n) break;
            } else {
                sum  = cnt = 0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


