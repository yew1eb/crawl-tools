#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int find (int n, int k) {
    int a = n / k, b = n % k;
    int ret = a * (n + b);
    return ret * k;
}

int solve (int n, int k) {
    int ret = find(n, k), els = 0;

    if (n >= k && n % k) {
        int r = n - (n % k) * 2;
        int s = n * n - r * r;
        els = solve(r, k) + s;
    }

    return max(ret, els);
}

int main () {
    int cas, n, k;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &k);
        printf("%d\n", solve(n, k));
    }
    return 0;
}