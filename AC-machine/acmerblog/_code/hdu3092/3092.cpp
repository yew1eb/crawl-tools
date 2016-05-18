#include<cstdio>
 #include<vector>
 #include<iostream>
 #include<cstring>
 #include<algorithm>
 #include<cmath>
 #define M 10005
 using namespace std;
 double dp[M];
 int p[M];
 int prime[M],cnt,n;
 bool f[M];
 void init()
 {
     cnt=0;
     for(int i=2;i<M;i++){
         if(!f[i]) prime[cnt++]=i;
         for(int j=0;j<cnt&&i*prime[j]<M;j++){
             f[i*prime[j]]=1;
             if(i%prime[j]==0) break;
         }
     }
 }
 void solve(int m)
 {
     memset(dp,0,sizeof(dp));
     for(int i=0;i<=n;i++) p[i]=1;
     for(int i=0;i<cnt&&prime[i]<=n;i++){
         double t=log(prime[i]);
         for(int j=n;j>=prime[i];j--){
             for(int k=prime[i],num=1;k<=j;k*=prime[i],num++)
             if(dp[j-k]+t*num>dp[j]){
                 dp[j]=dp[j-k]+t*num;
                 p[j]=p[j-k]*k%m;
             }
         }
     }
 }
 int main()
 {
     int m;
     init();
     while(scanf("%d%d",&n,&m)!=EOF){
         solve(m);
         printf("%d\n",p[n]);
     }
     return 0;
 }