#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int dp[317][50001];

int main()
{
    int T, n, m;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ca++)
    {
        dp[0][0] = 1;
        scanf("%d %d", &n, &m);
        int ans = 0, ma = (sqrt(8 * n + 1) - 1) / 2;
        for(int j = 1; j <= n; j++)
            for(int i = 1; i <= min(j, ma); i++)
                dp[i][j] = (dp[i][j - i] + dp[i - 1][j - i]) % m;
        for(int i = 1; i <= ma; i++) 
            ans = (ans + dp[i][n]) % m;
        printf("Case #%d: %d\n", ca, ans);
    }
}