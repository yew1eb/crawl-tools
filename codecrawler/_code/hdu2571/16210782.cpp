#include<stdio.h>
#define INF -123456789
int dp[22][1003];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
   int T,n,m,i,j,k;
   scanf("%d",&T);
   while(T--)
   {
      scanf("%d%d",&n,&m);
      for(i=0;i<=n;i++) dp[i][0]=INF;
      for(i=0;i<=m;i++) dp[0][i]=INF;  
      dp[1][0]=dp[0][1]=0;
      for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
          scanf("%d",&dp[i][j]);
       for(i=1;i<=n;i++)
          for(j=1;j<=m;j++)
          {
              int ans=INF;
             for(k=1;k<j;k++)
                 if(j%k==0) ans=max(ans,dp[i][k]);
             ans=max(dp[i-1][j],ans);
             dp[i][j]+=max(ans,dp[i][j-1]);
          }
      printf("%d\n",dp[n][m]);
   }
   return 0;
}
