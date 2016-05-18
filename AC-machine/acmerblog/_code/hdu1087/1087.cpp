#include <stdio.h>
#include <string.h>

int main()
{
    int n,a[1010],dp[1010][2];
    int i,j,max;
    while(scanf("%d", &n), n)
    {
        memset(dp, 0, sizeof(dp));
        for(i = 0; i < n; i++)
            scanf("%d", a+i);
        for(i = max = 0; i < n; i++)
        {
            dp[i][0] = dp[i][1] = a[i];
            for(j = 0; j < i; j++)
                if(dp[j][0] < dp[i][0])
                    if(dp[i][1] < dp[j][1]+a[i]) dp[i][1] = dp[j][1]+a[i];
            if(max < dp[i][1]) max = dp[i][1];
        }
        printf("%d\n", max);
    }
    return 0;
}