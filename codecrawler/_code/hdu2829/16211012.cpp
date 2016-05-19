#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 1010;
int n, m;
int a[maxn], sum[maxn], w[maxn];
int dp[maxn][maxn];
int q[maxn], head, tail;

int dy(int x, int j, int i)
{
    return dp[x][i] - w[i] + sum[i] * sum[i] - (dp[x][j] - w[j] + sum[j] * sum[j]); 
}

int dx(int j, int i)
{
    return sum[i] - sum[j];
}

void DP()
{
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = w[i];
    }
    for (int i = 2; i <= m + 1; ++i) {
        head = tail = 0;
        q[tail++] = i - 1;
        for (int j = i; j <= n; ++j) {
            while (tail - head >= 2) {
                int p = q[head], k = q[head+1];
                if (dy(i - 1, p, k) < sum[j] * dx(p, k)) {
                    head++;
                } else {
                    break;
                } 
            }
            dp[i][j] = dp[i-1][q[head]] + w[j] - w[q[head]] - sum[q[head]] * (sum[j] - sum[q[head]]);
            while (tail - head >= 2) {
                int p = q[tail-2], k = q[tail-1];
                if (dy(i - 1, p, k) * dx(k, j) >= dx(p, k) * dy(i - 1, k, j)) {
                    tail--;
                } else {
                    break;
                }
            }
            q[tail++] = j;
        }
    }
    printf("%d\n", dp[m+1][n]); 
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        sum[0] = 0;
        w[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            sum[i] = sum[i-1] + a[i];
            w[i] = w[i-1] + sum[i-1] * a[i]; 
        }
        DP();
    }
    return 0;
}
