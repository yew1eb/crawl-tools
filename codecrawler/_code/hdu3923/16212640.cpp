#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

#define Mod 1000000007
__int64 gcd(__int64 a,__int64 b){
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
__int64 mi(int x,int n){
    __int64 s = 1;
    for(__int64 i = 1;i <= n;++i)
        s = ((s%Mod) * (x%Mod))%Mod;
    return s;
}
void extend_Eulid(__int64 a,__int64 b,__int64 &x,__int64 &y){
    if(b == 0){
      x = 1;
      y = 0;
      return;
    }
    extend_Eulid(b,a%b,x,y);
    __int64 temp = x;
    x = y;
    y = temp - a/b * y;
}
int main(){
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    __int64 numcase;
    scanf("%I64d",&numcase);
    for(__int64 k = 1;k <= numcase;++k){
      __int64 color,len;
      scanf("%I64d%I64d",&color,&len);
      __int64 sum = 0;
      for(__int64 i = 1;i <= len;++i){
        __int64 x = gcd(len,i);
        sum += mi(color,x);
      }
      if(len % 2 == 0)
          sum += ((len/2 * mi(color,len/2))%Mod + (len/2 * mi(color,len/2+1)) % Mod) % Mod;
      else
          sum += (len * mi (color,(len-1)/2+1)) % Mod;
      __int64 xx,yy;
      extend_Eulid(2*len,Mod,xx,yy);
      xx = (xx % Mod + Mod) % Mod;
      printf("Case #%I64d: %I64d\n",k,(sum%Mod * (xx%Mod)) % Mod);
    }
    return 0;
}
