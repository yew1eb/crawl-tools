#include <stdio.h>
int main()
{
    int dp[10001]={0,2,4,7};
    for(int i=4;i<10000;i++)
        dp[i] = (2*dp[i-1]-dp[i-2]+dp[i-3])%9997;
    int n;
    while(scanf("%d",&n),n+1)
        printf("%d\n",dp[n]);
    return 0;
}
