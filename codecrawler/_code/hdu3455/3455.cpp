#include<stdio.h>
#include<string.h>
int dp[12][100005];
int a[100005];
int MIN(int a,int b)
{
if(a<b)
return a;
return b;
}
int main()
{
int n;
while(scanf("%d",&n)&&n)
{
   int i,j,k;
   for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
   memset(dp,-1,sizeof(dp));
   dp[1][2]=0;
   for(i=3;i<=n;i++)
   {
    for(j=1;j<=10;j++)
    {
     if(a[i]-a[i-j]<=10)
     {
      for(k=1;k<=10;k++)
      {
       if(a[i]-a[i-j-k]<=10)
       {
        if(dp[k][i-j]!=-1)
        {
         if(dp[j][i]==-1)
         {
          dp[j][i]=dp[k][i-j]+1;
         }
         else
         {
          dp[j][i]=MIN(dp[j][i],dp[k][i-j]+1); 
         }
        }
       }
      }
     } 
     else
     break;
    }
   }
   int ans=1000000000;
   for(i=1;i<=10;i++)
   {
    if(dp[i][n]!=-1)
    {
     ans=MIN(dp[i][n],ans);  
    }
   }
   if(ans!=1000000000)
   printf("%d\n",ans);
   else
   printf("-1\n");
} 
return 0;
}