#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<cstring>
#include<fstream>
#include<algorithm>
#define rep(i,a,b) for(long long i=(a);i<(b);i++)
#define rev(i,a,b) for(int i=(a);i>=(b);i--)
#define clr(a,x) memset(a,x,sizeof a)
#define inf 0x3f3f3f3f
typedef long long LL;
using namespace std;

const double eps=10e-10;
const LL mod=1000000007 ;
const int maxn=105;
const int maxm=600005;

LL C(LL x)
{
    if(x==0)return 0;
    LL ret=1;
    while(x>1)
    {
        ret=ret*x%mod;
        x--;
    }
    return ret;
}
LL da[105],db[105],sum[105],done[105];
void inn()
{
    db[2]=1;
    rep(i,3,105)
    {
        db[i]=db[i-1];
        rep(j,1,i)
            db[i]=(db[i]+j*C(i-1)+db[i-1])%mod;
    }
}
LL n;
LL qq(LL a,LL b)
{
    LL ans=0;
    rep(i,a+1,n)
        if(da[i]<b)ans++;
    return ans;
}
int main()
{
    inn();
    while(~scanf("%I64d",&n))
    {
        rep(i,0,n)
        scanf("%d",&da[i]);
        LL ans=0;clr(sum,0);clr(done,0);
        rep(i,0,n)
        {
            done[da[i]]=1;
            rep(j,1,da[i])
            if(!done[j])sum[i]+=C(n-1-i);
            rep(j,1,da[i])
            if(!done[j])ans=(ans+db[n-1-i]+C(n-1-i)*qq(i,j))%mod;
        }
        for(int i=n-2;i>=0;i--)
        {
            sum[i]+=sum[i+1];
            ans=(ans+sum[i+1]*qq(i,da[i]))%mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
