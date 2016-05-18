#include<iostream>
 #include<stdio.h>
 #include<algorithm>
 #include<iomanip>
 #include<cmath>
 #include<cstring>
 #include<vector>
 #define ll __int64
 using namespace std;
 int dp[45][310],b,m,bit[45];
 int dfs(int pos,int mm,bool f)
 {
     if(pos==-1) return mm==m;
     if(!f&&dp[pos][mm]!=-1) return dp[pos][mm];
     int ans=0;
     int e=f?bit[pos]:(b-1);
     for(int i=0;i<=e;i++){
         ans+=dfs(pos-1,mm+i,f&&i==bit[pos]);
     }
     if(!f) dp[pos][mm]=ans;
     return ans;
 }
 int solve(int n)
 {
     if(n<=0) return n==m;
     int s=0;
     while(n){
         bit[s++]=n%b;
         n/=b;
     }
     return dfs(s-1,0,1);
 }
 int main(){
     int q,x,y,n,k,ca=0;
     while(scanf("%d%d%d%d%d",&q,&x,&y,&b,&m)!=EOF){
         memset(dp,-1,sizeof(dp));
         printf("Case %d:\n",++ca);
         if(x>y) swap(x,y);
         if(q==1) printf("%d\n",solve(y)-solve(x-1));
         else{
             scanf("%d",&k);
             int low=solve(x-1);
             int high=solve(y);
             if(high-low<k){
                 puts("Could not find the Number!");
                 continue;
             }
             int l=x,r=y,mid,ans=0;
             while(l<=r){
                 mid=(int)(((ll)l+(ll)r)>>1);
                 int t=solve(mid);
                 if(t-low>=k) r=mid-1,ans=mid;
                 else l=mid+1;
             }
             printf("%d\n",ans);
         }
     }
     return 0;
 }