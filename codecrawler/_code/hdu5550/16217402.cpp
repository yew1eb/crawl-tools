#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 4005;
const int INF = 0x3f3f3f3f;
int n;
long long a[2][MAXN], sum[2][MAXN], value[2][MAXN], dp[MAXN][2];

long long leftCal(int l, int r, int s)
{
    long long x = value[s][r] - value[s][l-1];
    long long y = sum[s][r] - sum[s][l-1];
    return abs(x - y * (l - 1));
}

long long rightCal(int l, int r, int s)
{
    long long x = value[s][r] - value[s][l-1];
    long long y = sum[s][r] - sum[s][l-1];
    return abs(x - y * (r + 1));
}

long long areaDist(int l, int r, int s)
{
    if (l == 1) return rightCal(l, r, s);
    else if (r == n) return leftCal(l, r, s);
    else
    {
        int mid = (l + r) >> 1;
        return leftCal(l, mid, s) + rightCal(mid + 1, r, s);
    }
}

int main()
{
    int T; scanf("%d", &T);
    for (int kk = 1; kk <= T; kk++)
    {
        //input
        scanf("%d", &n);
        sum[0][0] = sum[1][0] = 0LL;
        value[0][0] = value[1][0] = 0LL;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld", &a[0][i], &a[1][i]);
            sum[0][i] = sum[0][i-1] + a[0][i];
            sum[1][i] = sum[1][i-1] + a[1][i];
            value[0][i] = value[0][i-1] + a[0][i] * i;
            value[1][i] = value[1][i-1] + a[1][i] * i;
        }

        //initialize
        memset(dp, INF, sizeof(dp));
        for (int i = 1; i < n; i++)
        {
            for (int s = 0; s <= 1; s++)
                dp[i][s] = areaDist(1, i, s);
        }

        //dp
        for (int i = 1; i <= n; i++)
        {
            for (int s = 0; s <= 1; s++)
            {
                for (int j = 1; j < i; j++)
                    dp[i][s] = min(dp[i][s], dp[j][s^1] + areaDist(j + 1, i, s));
            }
        }

        //output
        printf("Case #%d: %lld\n", kk, min(dp[n][0], dp[n][1]));
    }
    return 0;
}