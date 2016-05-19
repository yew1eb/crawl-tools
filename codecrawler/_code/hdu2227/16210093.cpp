#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 100010;
const int mod = 1000000007;
__int64 num[N];
struct dit{
    int id,value,xuhao;
}dd[N],dd1[N];
bool cmp(dit a,dit b){
    return a.value < b.value;
}
int inline lowbit(int x){
    return x & (-x);
}
__int64 inline sum(int x){
    __int64 s = 0;
    while(x > 0){
      s += num[x];
      if(s > mod)
          s = s % mod;
      x -= lowbit(x);
    }
    return s % mod;
}
void inline update(int x,int add){
    while(x < N){
       num[x] += add;
       if(num[x] > mod)
           num[x] = num[x] % mod;
       x += lowbit(x);
    }
}
int main(){
    //freopen("1.txt","r",stdin);
    int n;
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; ++i){
           scanf("%d",&dd[i].value);
           dd[i].id = i + 1;
           dd1[i] = dd[i];
        }
        memset(num,0,sizeof(num));
        sort(dd1,dd1+n,cmp);
        int k = dd1[0].id;
        dd1[0].xuhao = 1;
        dd[k-1].xuhao = 1;
        for(int i = 1; i < n; ++i){
            k = dd1[i].id - 1;
            if(dd1[i].value == dd1[i-1].value){
               dd1[i].xuhao = dd1[i-1].xuhao;
            }
            else
                dd1[i].xuhao = dd1[i-1].xuhao + 1;
            dd[k].xuhao = dd1[i].xuhao;
        }
        __int64 ans = 0;
        for(int i = 0; i < n; ++i){
           int x = dd[i].xuhao;
           __int64 y = 1 + sum(x);
           if(y > mod) y = y % mod;
           ans += y;
           if(ans > mod) ans = ans % mod;
           update(x,y);
        }
        printf("%I64d\n",ans % mod);
    }
    return 0;
}
