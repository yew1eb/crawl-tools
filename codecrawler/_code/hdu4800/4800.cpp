#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 147;
double dp[10017][maxn], p[maxn][maxn];
//dp[i][j]：战胜第i支队伍时，当前的队伍为j！
int a[10017];
int n, m;

void solve()
{
    for(int i = 0; i <= m; i++)
    {
        dp[0][i] = 1;//初始值
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]*p[j][a[i+1]]);//不换
            dp[i+1][a[i+1]] = max(dp[i+1][a[i+1]], dp[i][j]*p[j][a[i+1]]);//换
        }
    }
}
int main()
{
    while(~scanf("%d",&m))
    {
        memset(dp,0,sizeof(dp));
        m = m*(m-1)*(m-2)/6;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%lf",&p[i][j]);
            }
        }
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        solve();
        double ans = 0;
        for(int i = 0; i < m; i++)
        {
            ans = max(ans,dp[n][i]);
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}
