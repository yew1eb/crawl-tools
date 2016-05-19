#include<cstdio>
 #include<cstring>
 #include<iostream>
 #include<algorithm>
 using namespace std;
 #define M 1100
 #define mem0(f) memset(f,0,sizeof(f))
 int dp[M];
 int t,n,v,m;
 int val[M];
 int solve()
 {
     for(int i=0;i<n-1;i++)
     {
         for(int k=m-5;k>=val[i];k--)
         {
             dp[k]=max(dp[k],dp[k-val[i]]+val[i]);
         }
     }
     return dp[m-5];
 }
 int main()
 {
     while(~scanf("%d",&n)&&n)
     {
         mem0(val);
         mem0(dp);
         for(int i=0;i<n;i++)
             scanf("%d",&val[i]);
         sort(val,val+n);
         scanf("%d",&m);
         int cc=solve();
         if(m<5)printf("%d\n",m);
         else
         printf("%d\n",m-cc-val[n-1]);
     }
     return 0;
 }