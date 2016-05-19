#include <iostream>
#include <cstring>
#include <cstdio>
#define inf 0x3f3f3f3f
using namespace std;
int cost[1005][1005];
int m[1005][1005];
int dp[1005][1005];
int main()
{
    int c;
    while(scanf("%d",&c)!=EOF)
    {
        int n;
        scanf("%d",&n);
        memset(cost,0,sizeof(cost));
        int i,j;
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
                scanf("%d",&cost[i][j]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                m[i][j]=cost[i][j]-cost[i][j-1];
            }
        }
        memset(dp,inf,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            if(i==1)
                dp[1][i]=c+m[1][i];
            else
                dp[1][i]=dp[1][i-1]+m[1][i];
        }
        for(i=2;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                if(j>i)
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+m[i][j]);
                else
                {
                    int k;
                    for(k=1;k<=i-1;k++)
                        dp[i][j]=min(dp[i][j],dp[k][j-1]+m[i][j]+c);
                }
            }
        }
        int mm=inf;
        for(i=1;i<=n;i++)
            if(dp[i][n]<mm)
                mm=dp[i][n];
        printf("%d\n",mm);
    }
    return 0;
}
