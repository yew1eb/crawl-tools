/*
Pro: 0

Sol:

date:
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 99999999999999999999LL
using namespace std;
int prime[30],sub;
__int64 num[110];
void getprime(){
    bool flag[111] ;    sub = 0;
    memset(flag , true, sizeof(flag));
    for(int i = 2; i <= 110; i ++)
        for(int j = i + i; j <= 110;j += i)
            flag[j] = false;

    for(int i = 2; i <= 100; i ++)
        if(flag[i]) prime[sub ++] = i;
}
__int64 getnum(__int64 x, int p){//
    __int64 sum = 0;
    while(x % p == 0){
        sum ++;
        x /= p;
    }return sum;
}
bool can(__int64 indx){
    for(int i = 0; i < sub; i ++){
//        printf("%d   %d\n",i,prime[i]); 我还以为又是数组越界的奇怪问题呢，原来是这个函数被多次调用
        if(prime[i] && num[prime[i]]){
            __int64 sum = 0;
            for(__int64 k = prime[i]; k <= indx; k *= prime[i])
                sum += indx / k;
            if(sum < num[prime[i]]) return false;
        }
    }
    return true;
}
__int64 bin(){
    __int64 low = 0, high = inf, mid ;
    while(low <= high){
        mid = (low + high) >> 1;
//         printf("%d&&\n",mid);
        if(can(mid))    high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
int main(){
    getprime();
//    __int64 kk = 10000000000000 * 100;  __int64 sum = 0;
//                  99999999999999999999
//    __int64 in  = 33333333333333333333;
//    for(__int64 ka = 97; ka <= in; ka *= 97)
//        sum += in / ka;
//    if(sum >= kk) puts("yes");
//    else puts("no");

    int t,n,a;  __int64 b;
    scanf("%d",&t);
    while(t -- ){
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for(int i = 0; i < n; i ++){
            scanf("%d%I64d",&a,&b);
            for(int j = 0; j < sub; j ++){
                if(a % prime[j] == 0){
                    num[prime[j]] += getnum(a,prime[j]) * b;
                }
            }
        }
        printf("%I64d\n",bin());
    }
    return 0;
}
