#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 222222222
using namespace std;
int h,f,p;
int small(int a,int b)
{
    return a>b?b:a;
}
int a[15];
int dp[13][100000];
int extra(int i,int j)
{
    if(i<j)
        return (j-i)*h;
    else if(i>j)
        return (i-j)*f;
    else 
        return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        scanf("%d%d%d",&h,&p,&f);
        int i;
        int min=222222222,max=0;
        a[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<min)
                min=a[i];
            if(a[i]>max)
                max=a[i];
        }
        int j;
        for(i=0;i<=n;i++)
        {
            for(j=min;j<=max;j++)
            {
                if(i==0)
                    dp[i][j]=0;
                else
                    dp[i][j]=inf;
            }
        }
        int k;
        for(i=1;i<=n;i++)
        {
            for(j=a[i];j<=max;j++)
            {
                if(i==1)
                {
                    dp[i][j]=dp[i-1][0]+extra(0,j)+p*j;
                }
                else
                    for(k=a[i-1];k<=max;k++)
                        dp[i][j]=small(dp[i][j],dp[i-1][k]+extra(k,j)+p*j);
            }
        }
        min=inf;
        for(i=a[n];i<=max;i++)
        {
            if(dp[n][i]<min)
                min=dp[n][i];
        }
        printf("%d\n",min);

    }
}