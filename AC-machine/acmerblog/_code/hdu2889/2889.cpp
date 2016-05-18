#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
char a[20], b[20];__int64 getValue(char * p){//Without Zero进制转化为10进制
__int64 v = 0;
for(int i = 0; i < strlen(p); ++i){
   v = v * 9 + p[i] - '0';
}
return v;
}int main(){
while(scanf("%s%s", b, a) != EOF){
   __int64 sb = 0, sa = 0;
   sb = getValue(b);
   sa = getValue(a);
   sb -= sa;
   sa = 0;   memset(a, '1', sizeof(a));//计算Without Zero进制有多少位
   a[19] = 0;
   int idx = 0;
   for(; ; ++idx){
    sa = sa * 9 + a[idx] - '0';
    if(sa == sb){
     a[idx+1] = 0;
     printf("%s\n", a);
     goto Exit;
    }
    else if(sa > sb){
     a[idx] = 0;
     break;
    }
   }
   for(int i = 0; i < idx; ++i){//计算Without Zero进制
    for(char j = '2'; j <= '9'; ++j){
     a[i] = j;
     sa = getValue(a);
     if(sa == sb){
      printf("%s\n", a);
      goto Exit;
     }
     if(sa > sb){
      a[i] = j - 1;
      break;
     }
    }
   }
Exit:;
}
return 0;
}