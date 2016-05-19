#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int oo = 1LL << 62;
const int maxn = 500010;
__int64 c[maxn], sum[maxn];
__int64 dp[maxn];
int q[maxn], head, tail;
int n, m;

__int64 dy(int j, int i)
{
    return dp[i] + sum[i] * sum[i] - (dp[j] + sum[j] * sum[j]);
}

__int64 dx(int j, int i)
{
    return 2 * (sum[i] - sum[j]);
}

void DP()
{
    dp[0] = 0;
    head = tail = 0;
    q[tail++] = 0;
    for (int i = 1; i <= n; ++i) {
        while (tail - head >= 2) {
            int k = q[head], j = q[head+1];
            if (dy(k, j) < sum[i] * dx(k, j)) {
                head++;
            } else {
                break;
            }
        }
        dp[i] = dp[q[head]] + (sum[i] - sum[q[head]]) * (sum[i] - sum[q[head]]) + m;
        while (tail - head >= 2) {
            int k = q[tail-2], j = q[tail-1];
            if (dy(k, j) * dx(j, i) >= dx(k, j) * dy(j, i)) {
                tail--;
            } else {
                break;
            }
        }
        q[tail++] = i;
    }
    printf("%I64d\n", dp[n]);
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF) {
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%I64d", &c[i]);
            sum[i] = sum[i-1] + c[i];
        }
        DP();
    }
    return 0;
}
