#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
struct item {
 int p; 
 int q;
 int v;
 bool operator < (const item b)const {
    return q-p<b.q-b.p;
 }
} tm[520];

int max(int a,int  b ){
  return (a>b)?a:b;
}
int n , m;
int dp[5200];
void init(){
   for(int i=0;i<=m;i++){
       dp[i]=0 ;
   }
  
}
int main(){
  while( scanf("%d%d",&n,&m)!=EOF){
  
   for(int i =1;i<=n;i++){
     int pi,qi,vi;
     scanf("%d%d%d",&pi,&qi,&vi);
     tm[i].p=pi;
     tm[i].q=qi;
     tm[i].v=vi;
     
   }
   sort(tm+1,tm+n+1);
   init();
   for(int i=1;i<=n;i++){
       int p = tm[i].p;
       int q = tm[i].q;
       int v = tm[i].v;
     for(int c = m;c>=q;c--){
          dp[c]=max(dp[c],dp[c-p]+v);    
     }
   }
   cout << dp[m]<<endl;
  }
   return 0;
}

