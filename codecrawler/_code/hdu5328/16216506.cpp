#include <iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
using namespace std;
const int N=1e6+10;
int INF=0x7f7f7f7f;
int T,n,m,k,tot;
const int MOD=1e9+7;
int a[N];
int main()
{
#ifndef  ONLINE_JUDGE
   freopen("aaa","r",stdin);
#endif
    int T;
   scanf("%d",&T);
   while(T--){
      scanf("%d",&n);
      for(int i=1;i<=n;i++) scanf("%d",&a[i]);
      if(n<=2){
           printf("%d\n",n);
           continue;
      }
      int res=2;
      int l=1,r=2;
      for(int i=3;i<=n;i++){
            if(a[i-2]+a[i]==2*a[i-1]){
                r=i;
            }else{
                res=max(res,r-l+1);
                l=i-1;r=i;
            }
      }
    res=max(res,r-l+1);
      l=1,r=2;
      for(int i=3;i<=n;i++){
            if((long long)a[i-2]*a[i]==(long long)a[i-1]*a[i-1]){
                r=i;
            }else{
                res=max(res,r-l+1);
                l=i-1;r=i;
            }
      }
      res=max(res,r-l+1);
      printf("%d\n",res);
   }
    return 0;
}
