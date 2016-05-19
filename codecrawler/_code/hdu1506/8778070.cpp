#include <stdio.h>
#include <string.h>

const int maxn = 100000;
typedef long long LL;
LL l[maxn + 10], r[maxn + 10], a[maxn + 10], max;

int main()
{
    int n, i, t;
    while (scanf("%d", &n), n) {
        for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
        l[1] = 1;
        r[n] = n;
        for (i = 2; i <= n; i++) {
            t = i;
            while (t > 1 && a[i] <= a[t - 1]) t = l[t - 1];
            l[i] = t;
        }
        for (i = n - 1; i >= 1; i--) {
            t = i;
            while (t < n && a[i] <= a[t + 1]) t = r[t + 1];
            r[i] = t;

        }
        max = 0;
        for (i = 1; i <= n; i++)
            if (max < (r[i] - l[i] + 1)*a[i])
                max = (r[i] - l[i] + 1) * a[i];
        printf("%I64d\n", max);
    }
    return 0;
}
