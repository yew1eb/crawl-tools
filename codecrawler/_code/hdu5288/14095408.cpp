#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 233333;
int n, f[12333][123];
int a[maxn], l[maxn], tmp[maxn];

void factor(int N)
{
    for(int n=1; n<=N; ++n) {
        int k = 0;
        for(int j=1; j*j<=n; ++j) {
            if(n%j==0) {
                f[n][++k] = j;
                if(j!=n/j) f[n][++k]=n/j;
            }
        }
    }
}

int main()
{
    factor(10000);
    while(~scanf("%d", &n)){
        long long  ans = 0;
        memset(tmp, 0, sizeof tmp );
        for(int i=1; i<=n; ++i){
            scanf("%d", &a[i]);
            l[i] = i;
            for(int j=1; f[a[i]][j]; ++j) {
                l[i] = min(l[i], i-tmp[f[a[i]][j]]);
            }
            tmp[a[i]] = i;
        }
        for(int i=1; i<=10000; ++i) tmp[i] = n+1;
        int rr;
        for(int i=n; i>0; --i) {
            rr = n - i + 1;
            for(int j=1; f[a[i]][j]; ++j) {
                rr = min(rr, tmp[f[a[i]][j]] - i);
            }
            tmp[a[i]] = i;
            ans += rr*l[i];
        }
        ans %= mod;
        printf("%I64d\n", ans);
    }
    return 0;
}
