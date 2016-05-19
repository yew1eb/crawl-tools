#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100000
#define mod 1000000007
#define ll long long
ll p[N+10];

void init()
{
    p[0]=p[1]=1;
    for(int i=2;i<=N;++i)
    {
        p[i]=0;int x=1;
        for(int k=1,j=1;x>=0;++k,j*=-1)
        {
            x=i-(3*k*k+k)/2;
            if(x>=0) p[i]+=p[x]*j;
            x=i-(3*k*k-k)/2;
            if(x>=0) p[i]+=p[x]*j;
            if(p[i]>=mod||p[i]<0)
                p[i]=(p[i]%mod+mod)%mod;
        }
    }
}

int main ()
{
    init();
    int T;scanf("%d",&T);
    while(T--)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        ll ans=p[n];
        int x=1;
        for(int k=1,j=-1;x>=0;++k,j*=-1)
        {
            x=n-(3*k*k+k)/2*K;
            if(x>=0) ans+=p[x]*j;
            x=n-(3*k*k-k)/2*K;
            if(x>=0) ans+=p[x]*j;
            if(ans>=mod||ans<0)
                ans=(ans%mod+mod)%mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

