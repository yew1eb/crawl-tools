#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;

ll h, a, b, k;

int main() {
    int cas = 1;
    while (scanf("%lld%lld%lld%lld", &h, &a, &b, &k) != EOF && h+a+b+k) {
        printf("Case #%d: ", cas++);
        if (h <= a) {
            puts("YES");
            continue;
        }
        if (h-k*a+(k-1)*b <= 0 || ((k+1)*b-k*a) < 0)
            puts("YES");
        else puts("NO");
    }
    return 0;
}