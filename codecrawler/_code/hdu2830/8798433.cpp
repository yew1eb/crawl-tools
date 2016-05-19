#include <cstdiO>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <functional>
#define MAXN 1005
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int sum[MAXN], h[MAXN];

int main()
{
    int n, m, i, j, ans;
    char tmp[MAXN];
    while (~scanf("%d%d%", &n, &m)) {
        memset(h, 0, (n + 1)*sizeof(h[0]));
        ans = 0;
        for (i = 1; i <= n; i++) {
            scanf("%s", &tmp);
            for (j = 1; j <= m; j++) {

                if (tmp[j - 1] == '1') h[j] = h[j]  + 1;
                else h[j] = 0;
                sum[j] = h[j];
            }
            sort(sum + 1, sum + m + 1, greater<int>());
            for (j = 1; j <= m; j++)
                ans = max(ans, sum[j] * j);
        }
        printf("%d\n", ans);
    }
    return 0;
}
