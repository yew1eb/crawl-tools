#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int s[12], n;
double dp[1<<12];
vector<int> v;

double cul(int a, int b, int c) {
    if(a + b <= c)
        return 0.0;
    double p = (a + b + c) * 0.5;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main() {
    while (scanf("%d", &n) && n) {
        v.clear();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }
        sort(s, s + n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int st = (1<<i) | (1<<j) | (1<<k);
                    dp[st] = cul(s[i], s[j], s[k]);
                    if (s[i] + s[j] > s[k])
                        v.push_back(st);
                }
            }
        }
        for (int i = 0; i < (1<<n); i++) {
            for (int j = 0; j < v.size(); j++) {
                if (i & v[j])
                    continue;
                dp[i|v[j]] = max(dp[i|v[j]], dp[i] + dp[v[j]]);
            }
        }
        printf("%.2lf\n", dp[(1<<n)-1]);
    }
    return 0;
}
