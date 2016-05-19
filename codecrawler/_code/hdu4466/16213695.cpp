#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 5*1e6 + 10;
const int mod = 1000000007;

int Pow2[maxn];
int f[maxn];

int main()
{
//    freopen("data.in", "r", stdin);

    Pow2[0] = 1;
    for(int i = 1; i < maxn; i++){//è®¡ç®å¨é¿ä¸ºiçä¸è§å½¢çä¸ªæ° a<=b<=c
        f[i] = f[i-1] + (i-1)/2 - i/3 + (i%3?0:1);
        if (!(i&1)) f[i] -= i/4;
        if (f[i] >= mod) f[i] -= mod;
        if (f[i] < mod) f[i] += mod;

        Pow2[i] = (Pow2[i-1]<<1)%mod;
    }

    //è®¡ç®å¨é¿ä¸ºiçä¸è§å½¢çä¸ªæ° gcd(a,b,c) = 1, a<=b<=c
    //è¥gcd(a,b,c)>1 åå¯ä»¥æ¾å°å¨é¿ç­äºjä¸j|içä¸è§å½¢
    //é£æä»¬å°±æè¿ç§ä¸è§å½¢æ¾åºæ¥å¹¶ä¸æé¤
    for(int i = 3; i < maxn; i++){
        for(int j = i+i; j < maxn; j+=i){
            f[j] -= f[i];
            if (f[j] < 0) f[j] += mod;
        }
    }

    int n, cas = 1;
    LL ans;
    while(scanf("%d", &n)!=EOF){
        ans = 0;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                ans = (ans + (LL)f[i]*Pow2[n/i-1])%mod;
                if (i*i != n){
                    ans = (ans + (LL)f[n/i]*Pow2[i-1])%mod;
                }
            }
        }
        printf("Case %d: %I64d\n", cas++, ans);
    }

    return 0;
}
