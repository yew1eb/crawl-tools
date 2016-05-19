#include <cstdio>
#include <cstring>
int dp[22][2];
int main()
{
    dp[0][0] = dp[0][1] = 0;
    for (int i=1; i<=20; i++){
        dp[i][0] = 2*dp[i-1][0]+dp[i-1][1]+1;
        dp[i][1] = dp[i-1][0]+2*dp[i-1][1]+1;
    }
    int t, n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        printf("%d\n",dp[n-1][0]+dp[n-1][1]+2);
    }
    return 0;
}