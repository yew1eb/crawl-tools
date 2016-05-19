#include <stdio.h>
#include <string.h>

const int maxn = 105;
int dp[maxn][maxn];
int n, m, map[maxn][maxn];


int  solve(int x, int y)
{
    if (dp[x][y] >= 0) return dp[x][y];
    int& ans = dp[x][y] = 0 ;
    for (int i = 0; i <= map[x][y]; i++)
        for (int j = 0; j <= map[x][y] - i; j++) {
            if (i + x < 0 || i + x > n || j + y < 0 || j + y > m) continue;
            ans = (ans + solve(x + i, y + j)) % 10000;
        }
    return ans;
}
int main()
{
    int T;
    int i, j;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                scanf("%d", &map[i][j]);
        memset(dp, -1, sizeof(dp));
        dp[n - 1][m - 1] = 1;
        printf("%d\n", solve(0, 0));
    }
    return 0;
}
