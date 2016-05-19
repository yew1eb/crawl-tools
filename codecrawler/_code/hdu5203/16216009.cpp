#include <stdio.h>
#include <algorithm>
typedef long long ll;
using namespace std;
const int N = 1005;
int n, m, l, r;
ll res;

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        int a;
        res = 0;
        l = n;
        r = 1;
        for (int i = 0; i < m; i++) {
            scanf("%d", &a);
            l = min(l, a);
            r = max(r, a);
        }
        if (l == 1 || r == n) {
            int len = n - (r - l + 1);
            for (int i = (len + 2) / 3; i * 2 < len; i++) {
                if (i * 3 == len)
                    res++;
                else {
                    res += 3;
                    int a = i - 1;
                    int b = len - i - a;
                    if (a >= b)
                        res += (a - b + 1) * 3;
                }
            }
        }
        else {
            int len1 = l - 1, len2 = n - r;
            if (len1 > len2)
                swap(len1, len2);
            if (len1 < len2) {
                for (int i = 1; i < len2; i++) {
                    int temp = max(len1, max(i, len2 - i));    
                    if (len1 + len2 > 2 * temp)
                        res++;
                }
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}