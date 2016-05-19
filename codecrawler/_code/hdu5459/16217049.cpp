#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300000;
const long long MOD=530600414;
long long f[MAXN];
long long g[MAXN];
long long s[MAXN];
long long mod(long long a)
{
    a=a%MOD;
    if(a<0) a+=MOD;
    return a;
}
void init()
{
    ///all function start from 1;
    f[0]=f[1]=f[2]=1;
    for(int i=3;i<MAXN;i++)
        f[i]=mod(f[i-1]+f[i-2]);

    g[0]=g[1]=g[2]=g[3]=0;
    for(int i=4;i<MAXN;i++)
        g[i]=mod(g[i-1]+g[i-2]+mod(f[i-3]*f[i-1]));

    s[0]=s[1]=s[2]=s[3]=s[4]=0;

    for(int i=5;i<MAXN;i++)
        s[i]=s[i-1]+s[i-2]+mod(f[i-3]*mod(f[i-1]*f[i-4]-g[i-2]))+mod(f[i-4]*g[i-1]),
        s[i]=mod(s[i]);
}

int main()
{
    init();
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %lld\n",cas++,s[n]);
    }
    return 0;
}
