#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef __int64 LL;
LL fac[100005],inv[100005],p;
LL pow(LL a,LL b,LL p)
{
    LL ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}

void init() {
    fac[0] = inv[0] = 1;
    for(int i = 1; i < min(p, 100000LL); ++i) {
        fac[i] = fac[i-1] * i % p;
        inv[i] = pow(fac[i], p - 2,p);
    }
}

LL C(LL n,LL m)
{
    if(n<m) return 0;
    return fac[n]*inv[m]%p*inv[n-m]%p;
}
LL Lucas(LL n,LL m)
{
    if(n<p&&m<p) return C(n,m);
    return Lucas(n/p,m/p)*Lucas(n%p,m%p)%p;
}
int main()
{
    int x1,x2,y1,y2,i;
    while(~scanf("%d%d%d%d%I64d",&x1,&y1,&x2,&y2,&p))
    {
        init();
        LL ans=0;
        for(i=y1+1;i<=y2+1;++i) ans=(ans+Lucas(x2+1,i)-Lucas(x1,i)+p)%p;
        printf("%I64d\n",ans);
    }
    return 0;
}
