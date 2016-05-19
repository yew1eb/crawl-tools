#include<stdio.h>
#include<string.h>
#define size 110
int dp[size][size];
int c[size];
int w[size];
int n,t,m,s;
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int i,j,k;
    while(scanf("%d %d",&n,&t)!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        memset(dp[0],0,sizeof(dp[0]));
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&m,&s);
            for(j=0;j<m;j++)
            {
                scanf("%d %d",&c[j],&w[j]);
            }
            if(s==0)
            {
                for(k=0;k<m;k++)
                {
                    for(j=t;j>=c[k];j--)
                    {
                        if(dp[i][j-c[k]]!=-1)
                            dp[i][j]=max(dp[i][j],dp[i][j-c[k]]+w[k]);
                        if(dp[i-1][j-c[k]]!=-1)
                            dp[i][j]=max(dp[i][j],dp[i-1][j-c[k]]+w[k]);
                    }
                }
            }
            else if(s==1)
            {
                for(j=0;j<=t;j++)
                    dp[i][j]=dp[i-1][j];
                for(k=0;k<m;k++)
                {
                    for(j=t;j>=c[k];j--)
                    {
                        if(dp[i-1][j-c[k]]!=-1)
                            dp[i][j]=max(dp[i][j],dp[i-1][j-c[k]]+w[k]);
                    }
                }
            }
            else
            {
                for(j=0;j<=t;j++)
                    dp[i][j]=dp[i-1][j];
                for(k=0;k<m;k++)
                {
                    for(j=t;j>=c[k];j--)
                    {
                        if(dp[i][j-c[k]]!=-1)
                            dp[i][j]=max(dp[i][j],dp[i][j-c[k]]+w[k]);
                    }
                }
            }
        }
        printf("%d\n",dp[n][t]);
    }
    return 0;
}