#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

#define LL long long
#define CLR(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 13;

LL dp[N][N][1 << N];
int g[N][N];

int main()
{
    int t, n, m, i, j, k, s, cas = 1, p, q;
    bool l, u;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d", &n, &m);
        for(i = 1; i <= n; i ++)
        {
            for(j = 1; j <= m; j ++)
            {
                scanf("%d", &g[i][j]);
            }
        }
        CLR(dp, 0);dp[0][m][0] = 1;
        for(i = 1; i <= n; i ++)
        {
            for(j = 0; j < (1 << m); j ++)
                dp[i][0][j << 1] = dp[i - 1][m][j];
            for(j = 1; j <= m; j ++)
                for(k = 0; k < (1 << m << 1); k ++)
                {
                    p = 1 << j;
                    q = p >> 1;
                    u = k & p;
                    l = k & q;
                    if(g[i][j])
                    {
                        dp[i][j][k] = dp[i][j - 1][k ^ p ^ q];
                        if(l != u) dp[i][j][k] += dp[i][j - 1][k];
                    }
                    else
                    {
                        if(u || l) dp[i][j][k] = 0;
                        else dp[i][j][k] = dp[i][j - 1][k];
                    }
                }
        }
        printf("Case %d: There are %I64d ways to eat the trees.\n", cas ++, dp[n][m][0]);
    }
}