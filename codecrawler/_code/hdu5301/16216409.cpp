#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
//    freopen("in", "r", stdin);
    int n, m, x, y;
    int cnt;
    while(~scanf("%d %d %d %d", &n, &m, &x, &y)) {
        if(n > m) {
            swap(n, m);
            swap(x, y);
        }

        if(n == m && n%2 && x == (n+1)/2 && y == (m+1)/2) {
            printf("%d\n", n/2);
            continue;
        }

        int maxx = n/2+n%2;

            cnt = maxx;
            if(x == maxx || x == maxx+1 || y == 1 || y == m) {
                printf("%d\n", cnt);
            }

            else {
                int res, ans1, ans2;

                int c = max(x-1, n-x);
                ans1 = min(y, m - y+1);
                if(ans1 <= maxx) printf("%d\n", cnt);
                else printf("%d\n", min(c, ans1));
            }
    }
    return 0;
}
