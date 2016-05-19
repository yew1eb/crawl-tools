#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 200010
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
int fact[maxn],inv[maxn],mod;
int Power(int p,int n){
    int ans=1;
    for(;n;n>>=1,p=(LL)p*p%mod)
        if(n&1)
        ans=(LL)ans*p%mod;
    return ans;
}
void Prepare(int n){
    fact[0]=1,inv[0]=1;
    for(int i=1;i<=n&&i<mod;++i)
        fact[i]=(LL)fact[i-1]*i%mod,inv[i]=Power(fact[i],mod-2);
}
int C(int n,int m){
    if(n<m) return 0;
    return (LL)fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int Lucas(int n,int m){
    if(n<mod&&m<mod)
        return C(n,m);
    return (LL)Lucas(n/mod,m/mod)*Lucas(n%mod,m%mod)%mod;
}
int work(int lx,int ly,int rx,int ry){
    LL ans=0,now=0;
    for(int i=ly;i<=ry;++i)
        now=(now+Lucas(lx,i))%mod;
    ans=now;
    for(int i=lx+1;i<=rx;++i)
        now=(now*2-Lucas(i-1,ly)-Lucas(i-1,ry)+Lucas(i,ly)+mod+mod)%mod,ans=(ans+now)%mod;
    return ans;
}
int main()
{
    int xa,ya,xb,yb;
    while(cin>>xa>>ya>>xb>>yb>>mod){
        Prepare(100005);
        cout<<work(xa,ya,xb,yb)<<endl;
    }
    return 0;
}
