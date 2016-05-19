#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>

using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int maxn = 110010;

int n, x;
double p, dp[maxn];

double cal(int k) {
    int len = n/k;
    double ans = 0;
    if(n%k) {
        ans = (dp[len + 1] + x) * (n%k) + (dp[len] + x) * (k - n%k);
    }
    else {
        ans = (dp[len] + x) * k;
    }
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    for(int cas=1; cas<=t; cas++) {
        printf("Case #%d: ", cas);
        scanf("%d%lf%d", &n, &p, &x);
        for(int i=1; i<=n+x; i++) dp[i] = (dp[i-1] + 1) / (1-p);
        double ans = dp[n] + x;
        for(int i=2; i<=n; i++) ans = min(ans, cal(i));
        printf("%.6f\n", ans);
    }
    return 0;
}
