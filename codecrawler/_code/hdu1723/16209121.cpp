#include<stdio.h>
int main()
{
    int n, m, i, j, dp[50];

    while(~scanf("%d%d", &n,&m), n+m)
    {
        for(i=1; i<=n; i++)
        {
            dp[i] = (i == 1 ? 1 : 0);
            for(j=i-1; j>=1 && j>=i-m; j--)
                dp[i] += dp[j];
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
