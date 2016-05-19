#include<iostream>
 #include<cstdlib>
 #include<stdio.h>
 #define ll long long
 #define M 1000001
 using namespace std;
 ll a[M];
 int prime[79000],cnt;
 bool f[M];
 int fac(int n)
 {
     for(int i=0;i<cnt&&prime[i]*prime[i]<=n;i++){
         if(n%prime[i]==0){
             n/=prime[i];
             while(n%prime[i]==0) n/=prime[i];
             if(n==1) return prime[i];
             return 0;
         }
     }
     return 0;
 }
 void init()
 {
     int i,j,k;
     cnt=0;
     for(i=2;i<M;i++){
         if(f[i]==0) prime[cnt++]=i;
         for(j=0;j<cnt&&i*prime[j]<M;j++){
             f[i*prime[j]]=1;
             if(i%prime[j]==0) break;
         }
     }
 }
 int main()
 {
     int i,k,n;
     init();
     while(scanf("%d",&n)!=EOF){
         ll ans=0;
         for(i=3;i<=n;i++){
             if(f[i]==0) ans+=i;
             else{
                 k=fac(i);
                 if(k) ans+=k;
                 else ans+=1;
             }
         }
         printf("%I64d\n",ans);
     }
     return 0;
 }