#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 55;
int t, n, a[N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        double ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans += pow(0.95, n - 1 - i) * a[i];
        }
        printf("%.10lf\n", ans);
    }
    return 0;
}