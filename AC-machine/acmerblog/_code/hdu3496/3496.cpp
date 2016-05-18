#include<stdio.h>
#include<string.h>
#define inf 999999
int dp[102][1002],t[102],v[102];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n,m,i,j,k,L,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&L);
        for(i=0;i<n;i++)
            scanf("%d%d",&t[i],&v[i]);
        for(i=0;i<=m;i++)
            for(j=0;j<=L;j++)
            {
                if(i==0)
                    dp[i][j]=0;
                else
                    dp[i][j]=-inf; //注意初始化为负无穷，价值可能是负值
            }
        for(i=0;i<n;i++)
            for(j=m;j>=1;j--)
                for(k=L;k>=t[i];k--)
                    dp[j][k]=max(dp[j][k],dp[j-1][k-t[i]]+v[i]);
        if(dp[m][L]<0)
            dp[m][L]=0;
        printf("%d\n",dp[m][L]);
    }
    return 0;
}
