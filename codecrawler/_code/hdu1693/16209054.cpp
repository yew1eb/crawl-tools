#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int gp[12][12];
__int64 dp[13][13][1<<13];
int n,m;
void DP()
{
    memset(dp,0,sizeof(dp));
        dp[0][m][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(1<<m);j++)
           dp[i][0][(j<<1)]=dp[i-1][m][j];
        for(int k=1;k<=m;k++)
        {
            for(int sta=0;sta<(1<<(m+1));sta++)
            {
                int y=1<<k;
                int x=1<<(k-1);
                if(gp[i][k])
                {
                    if((sta&x)!=0&&(sta&y)!=0)
                    {
                            dp[i][k][sta]=dp[i][k-1][sta-x-y];                    
                    }
                    else if((sta&x)==0&&(sta&y)==0)
                            dp[i][k][sta]=dp[i][k-1][sta+x+y];
                    else
                        dp[i][k][sta]=dp[i][k-1][sta^x^y]+dp[i][k-1][sta];
                }
                else
                {
                    if((sta&x)==0&&(sta&y)==0)
                    {
                        dp[i][k][sta]=dp[i][k-1][sta];
                    }
                    else
                        dp[i][k][sta]=0;
                }
            }
        }
    }
    printf("There are %I64d ways to eat the trees.\n",dp[n][m][0]);
}
int main()
{
    int c,cn=0;
    scanf("%d",&c);
    while(c--)
    {
        cn++;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&gp[i][j]);
            }
        }
        printf("Case %d: ",cn);
        DP();
    }
    return 0;
}