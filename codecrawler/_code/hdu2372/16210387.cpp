#include <stdio.h>
#include <string.h>
#define LL __int64

int n, m;
int a[110];
LL dp[110][110];

void Solve()
{
    while(~scanf("%d%d", &n, &m))
    {
        memset(dp, 0, sizeof(dp));
        if(!n && !m)
        {
            break;
        }
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; ++i)
        {
            dp[i][1] = 1;
        }
        for(int j = 2; j <= m; ++j)
        {
            for(int i = j-1; i < n; ++i)
            {
                for(int k = j-2; k < i; ++k)
                {
                    if(a[i] > a[k])
                    {
                        dp[i][j] += dp[k][j-1];
                    }
                }
            }
        }
        LL sum = 0;
        for(int i = m-1; i < n; ++i)
        {
            sum += dp[i][m];
        }
        printf("%I64d\n", sum);
    }
}

int main()
{
    Solve();

    return 0;
}