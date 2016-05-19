#include"stdio.h"
int min(int a,int b)
{
    return a>b?b:a;
}
int main()
{
    int n;
    int h,s,f;
    int num[15];
    int i,l,j;
    int total;
    int dp[12][1011];
    int ans;
    while(scanf("%d",&n),n)
    {
        scanf("%d%d%d",&h,&s,&f);
        total=0;
        for(i=0;i<n;i++)    //iä»0å¼å§
        {
            scanf("%d",&num[i]);
            if(total<num[i])    total=num[i];
        }
        if(total==0)
        {
            printf("0\n");
            continue;
        }


        for(l=num[0];l<=total;l++)    dp[0][l]=l*(h+s);
        for(i=1;i<n;i++)
        {
            for(l=num[i];l<=total;l++)
            {
                if(num[i-1]>l)    dp[i][l]=dp[i-1][num[i-1]]+l*s+(num[i-1]-l)*f;
                else            dp[i][l]=dp[i-1][num[i-1]]+l*s+(l-num[i-1])*h;
                for(j=num[i-1]+1;j<=total;j++)
                {
                    if(j>l)    dp[i][l]=min(dp[i][l],dp[i-1][j]+l*s+(j-l)*f);
                    else    dp[i][l]=min(dp[i][l],dp[i-1][j]+l*s+(l-j)*h);
                }
            }
        }


        ans=111111111;
        for(l=num[n-1];l<=total;l++)    ans=min(dp[n-1][l],ans);
        printf("%d\n",ans);
    }
    return 0;
}