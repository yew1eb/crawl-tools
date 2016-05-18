#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const long long N = 1000050;
const long long M = 1000000007;
long long next[N];
long long n;
struct p
{
    long long v,e;

    bool operator == (const p & s){
            if(v == s.v && e == s.e) return true;
            return false;
    }
}a[N];
long long power1(long long c,long long n)
{
    long long res = 1;
    while(n){
        if(n&1) res *= c;
        if(res >= M) res %= M;
        c *= c;
        if(c >= M) c %= M;
        n >>= 1;
    }
    return res;
}
int getnext()
{
    int len = n;
    int i  = 0,j = -1;
    next[0] = -1;
    while(i < len){
            if(j == -1 || a[i] == a[j]){
                ++i,++j;
                 next[i] = j;
            }else j = next[j];
    }
   next[len] = len - next[len];
    if( (n % next[len])== 0) return next[len];
    else return n;
}
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}
int main(){
   // freopen("in","r",stdin);
    long long t,c,v,e;
    scanf("%I64d",&t);
    while(t--){
        scanf("%I64d%I64d",&n,&c);
        for(int i = 0;i < n ; ++i) {
            scanf("%I64d",&a[i].v);
        }
        for(int i = 0; i < n; ++i){
            scanf("%I64d",&a[i].e);
        }
        if(n == 1) {
            printf("%I64d\n",c);
            continue;
        }
       long long index = getnext();
       long long ans = 0,num = 0;
       for(int i = 1; i <= n; ++i) {
                if(i % index != 0) continue;
                ans += power1(c, gcd(i, n));
                if(ans >= M) ans -=M;
                ++num;
       }
      printf("%I64d\n",(ans * power1(num,M- 2))%M);
    }
    return 0;



}
