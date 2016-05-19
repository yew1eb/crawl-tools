#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
double dp[210][25];
char op[210];
double pi[210];
int a[210];
int main()
{
    //freopen("dd.txt","r",stdin);
    int n,i,j,T=0;
    while(scanf("%d",&n)!=EOF)
    {
        printf("Case %d:\n",++T);
        memset(dp,0,sizeof(dp));
        for(i=0;i<=n;i++)
        scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
        cin>>op[i];
        for(i=1;i<=n;i++)
        scanf("%lf",&pi[i]);
        for(i=0;i<=20;i++)
        {
            dp[0][i]=(double)((a[0]>>i)&1);
        }
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=20;j++)
            {
                int tmp=(1&(a[i]>>j));
                if(op[i]=='&')
                {
                    if(tmp)
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j]=pi[i]*dp[i-1][j];
                    }
                }
                else if(op[i]=='|')
                {
                    if(tmp)
                    {
                        dp[i][j]=pi[i]*dp[i-1][j]+1-pi[i];
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
                else if(op[i]=='^')
                {
                    if(tmp)
                    {
                        dp[i][j]=dp[i-1][j]*pi[i]+(1-pi[i])*(1-dp[i-1][j]);
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        double ans=0;
        for(i=0;i<=20;i++)
        {
            ans+=(double)(1<<i)*dp[n][i];
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}
