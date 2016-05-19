#include"stdio.h"
#include"string.h"
int main()
{
    int n;
    int dp[130][130];
    int i,l;
    
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for(i=1;i<=130;i++)
    {
        dp[i][1]=1;
        dp[1][i]=1;
    }
    for(i=2;i<=120;i++)
    {
        for(l=2;l<=120;l++)
        {
            if(l>i)
                dp[i][l]=dp[i][i];
            else if(l==i)
                dp[i][l]=dp[i][l-1]+1;
            else
                dp[i][l]=dp[i][l-1]+dp[i-l][l];
        }
    }


    while(scanf("%d",&n)!=EOF)
        printf("%d\n",dp[n][n]);


    return 0;
}