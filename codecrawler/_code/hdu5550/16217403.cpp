#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;

const int maxn = 4*1e3 + 100;
LL num[2][maxn];
LL sum[2][maxn];
LL dsum[2][maxn];
LL dp[2][maxn];
LL goup(int f, int l, int r)
{
    return (sum[f][r]-sum[f][l]) * (r+1) - (dsum[f][r]-dsum[f][l]);
}
LL godown(int f, int l, int r)
{
    return (dsum[f][r]-dsum[f][l]) - (sum[f][r]-sum[f][l]) * l;
}
LL go(int f, int l, int r)
{
    int m = (l + r)>>1;
    return godown(f, l, m) + goup(f, m, r);
}
int main()
{
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld%lld", &num[0][i], &num[1][i]);
            sum[0][i] = sum[0][i-1] + num[0][i];
            sum[1][i] = sum[1][i-1] + num[1][i];
            dsum[0][i] = dsum[0][i-1] + num[0][i] * i;
            dsum[1][i] = dsum[1][i-1] + num[1][i] * i;
        }
        LL ans = 0x3f3f3f3f3f3f3f3f;
        for(int i = 1; i < n; i++)
        {
            dp[0][i] = goup(1, 0, i);
            dp[1][i] = goup(0, 0, i);
            for(int j = 1; j < i; j++)
            {
                dp[0][i] = min(dp[0][i], dp[1][j]+go(1, j, i));
                dp[1][i] = min(dp[1][i], dp[0][j]+go(0, j, i));
            }
            ans = min(ans, dp[0][i]+godown(0, i, n));
            ans = min(ans, dp[1][i]+godown(1, i, n));
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}