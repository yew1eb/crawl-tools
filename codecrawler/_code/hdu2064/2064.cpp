#include<cstdio>
 __int64 dp[40];
 void dabiao() {
     dp[0]=0,dp[1]=2,dp[2]=8;
     for(int i=3;i<=35;++i)
     dp[i]=3*dp[i-1]+2;
 }
 int main() {
     dabiao();
     int n;
     while(scanf("%d",&n)!=EOF)
     printf("%I64d\n",dp[n]);
     return 0;
 }