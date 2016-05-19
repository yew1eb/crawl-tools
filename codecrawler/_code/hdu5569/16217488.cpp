#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;
typedef long long LL;

#define N 1010
#define INF 0x3f3f3f3f
#define PI acos (-1.0)
#define EPS 1e-8
#define met(a, b) memset (a, b, sizeof (a))

int dp[N][N], g[N][N];

int main ()
{
    int n, m;

    while (scanf ("%d %d", &n, &m) != EOF)
    {
        for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        scanf ("%d", &g[i][j]);

        for (int i=0; i<=n+1; i++)
        for (int j=0; j<=m+1; j++)
        dp[i][j] = INF;

        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                if ((i+j)&1)
                    dp[i][j] = min (dp[i-1][j] + g[i-1][j]*g[i][j], dp[i][j-1] + g[i][j-1]*g[i][j]);
                else dp[i][j] = min (dp[i-1][j], dp[i][j-1]);
                if (i == 1 && j == 1) dp[i][j] = 0;
            }
        }
        printf ("%d\n", dp[n][m]);
    }
    return 0;
}
