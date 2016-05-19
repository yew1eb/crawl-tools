#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int fun(int x){
    int s = 0;
    while(x){
      int y = x % 2;
      if(y)
          s++;
      x /= 2;
    }
    return s;
}
__int64 mi(int x){
    __int64 s = 1;
    for(int i = 1; i <= x; ++i)
        s *= 2;
    return s;
}
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
       int cnt = fun(n);
       __int64 ans = mi(cnt);
       printf("%d\n",ans);
    }
    return 0;
}