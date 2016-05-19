#include <iostream>
 #include <cstring>
 #include <cstdio>
 using namespace std;
 const int N = 1010;
 int dp[N][N],s[N][N];
 int val[N],sv[N],dv[N];
 const int infinity=(-1)^(1<<31);
 int S(int i,int j){ // i到j作为一段
     return dv[i]-dv[j]-(sv[i]-sv[j])*sv[j+1];
 }
 int DP(int n,int m){
     if(m >= n-1) return 0;
     m++;
     for(int i=1;i<=n;i++) dp[i][1]=S(i,n),s[i][1]=n;
     for(int mm=2;mm<=m;mm++){
         int maxi=n-mm+1,tmp;
         dp[maxi][mm]=0; s[maxi][mm]=maxi;
         //printf("dp[%d][%d] = %d, s = %d\n",maxi,mm,dp[maxi][mm],s[maxi][mm]);
         for(int i=maxi-1;i>0;i--){
             dp[i][mm]=infinity;
             for(int k=i;k<=s[i+1][mm];k++)
             if((tmp=dp[k+1][mm-1]+S(i,k)) < dp[i][mm])
                 dp[i][mm]=tmp,s[i][mm]=k;
             //printf("dp[%d][%d] = %d, s = %d\n",i,mm,dp[i][mm],s[i][mm]);
         }
     }
     return dp[1][m];
 }
 int main()
 {
     int n,m;
     while(scanf("%d%d",&n,&m)){
         if(n<=0 && m<=0) break;
         for(int i=1;i<=n;i++)
             scanf("%d",&val[i]);
         sv[n+1]=0,dv[n+1]=0;
         for(int i=n;i>0;i--)
             dv[i]=sv[i+1]*val[i]+dv[i+1],sv[i]=sv[i+1]+val[i];// printf("dv[i] = %d, sv[i] = %d\n",dv[i],sv[i]);
         //int i,j; while(cin>>i>>j) printf("sij = %d\n",S(i,j));
         printf("%d\n",DP(n,m));
     }
     return 0;
 }