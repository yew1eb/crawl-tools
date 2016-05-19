#include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #define N 1001
 int dp[N];
 int c[N],w[N];
 int max(int x,int y)
 {
     return x>y?x:y;
 }
 int main()
 {
     int t,n,v,i,j;
     scanf("%d",&t);
     while(t--)
     {
         scanf("%d%d",&n,&v);
         for(i=0;i<n;i++)
           scanf("%d",&c[i]);
         for(i=0;i<n;i++)
           scanf("%d",&w[i]);
         memset(dp,0,sizeof(dp));
         for(i=0;i<n;i++)
         {
             for(j=v;j>=w[i];j--)
               dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
         }
         printf("%d\n",dp[v]);
     }
     system("pause");
     return 0;
 }