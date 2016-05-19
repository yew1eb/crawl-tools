#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 1505;

int N;
double P, Q, dp[maxn], f[maxn];

double get (int x) {
    double tmp = f[0] = 1, p = pow(P, x);
    for (int i = 1; i <= N + 1; i++) {
        f[i] = tmp;
        //for (int j = max(i-x, 0); j < i; j++)
        //f[i] += pow(P, i-j-1) * f[j];
        if (i <= N) f[i] *= (1-P);
        tmp = tmp * P + f[i];
        if (i >= x) tmp -= f[i-x] * p;
    }
    return f[N+1];
}

double solve () {
    dp[0] = 0;
    for (int i = 1; i <= N+1; i++)
        dp[i] = get(i);
    double ans = 0;
    for (int i = 1; i <= N+1; i++)
        ans += i * (dp[i] - dp[i-1]);
    return ans;
}

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%lf%lf", &N, &P, &Q);
        P = Q / P;
        printf("%.3lf\n", solve());
    }
    return 0;
}