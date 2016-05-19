#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2005;
int c[N];

int main () {

    int T;
    int num, h, m;
    int ans, n;
    scanf ("%d", &T);
    while (T--) {

        scanf ("%d", &n);
        memset (c, 0, sizeof (c));
        for (int i = 0; i < n; i++) {
            scanf ("%d", &num);

            scanf ("%d:%d", &h, &m);
            c[h * 60 + m] += num;

            scanf ("%d:%d", &h, &m);
            c[h * 60 + m] -= num;
        }

        int ans = 0;
        int tmp = 0;
        for (int i = 0; i < N; i++) {
            tmp += c[i];
            if (tmp > ans)
                ans = tmp;
        }
        printf ("%d\n", ans);
    }
    return 0;
}