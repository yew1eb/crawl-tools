#include<cstdio>
#include<cstring>
int dp[35];
int main ()
{
    int n, m;
    while(scanf("%d %d", &n, &m) , n||m)
    {
        
        if(n == 1) {puts("1"); continue;}
        if(m == 0) {puts("0"); continue;}
        
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(i - j == 0) break;
                dp[i] += dp[i-j];
            }
        }
        printf("%d\n", dp[n]);

    }
    return 0;
}
