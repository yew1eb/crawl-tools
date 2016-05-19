#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 105;

int main () {
    int cas, n, x, c[maxn];
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        memset(c, 0, sizeof(c));

        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            c[x]++;
        }

        int ans = c[1], idx = 1;
        for (int i = 2; i <= n; i++) {
            if (c[i] > ans) {
                ans = c[i];
                idx = i;
            }
        }
        printf("%d\n", idx);
    }
    return 0;
}
