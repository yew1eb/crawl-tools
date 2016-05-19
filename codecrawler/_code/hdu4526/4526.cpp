#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 105;

int dp[N][N];

int main()
{
    int T,n,k,d,s;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&k,&d,&s);
        memset(dp,63,sizeof(dp));
        const int inf = dp[0][0];
        dp[0][n] = 0;
        for(int i=1;i<=k;i++)
        {
            int t,z;
            scanf("%d%d",&t,&z);
            dp[i][0] = dp[i-1][0];
            for(int j=1;j<=z;j++)
                dp[i][0] = min(dp[i][0],dp[i - 1][j] + d + t * j);
            for(int j=1;j<=n;j++)
                if(j + z <= n)
                    dp[i][j] = min(dp[i - 1][j],dp[i - 1][j + z] + d + t * z);
                else
                    dp[i][j] = dp[i-1][j];
        }
        if(dp[k][0] == inf)
            puts("impossible");
        else
            printf("%d\n",dp[k][0]);
    }
    return 0;
}