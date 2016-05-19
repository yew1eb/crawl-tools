#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define times 10
#define N 5501
using namespace std;
typedef long long LL;
const LL INF=(LL)1<<61;
LL key,ct,cnt,ans;
LL fac[N],num[N];

LL gcd(LL a,LL b)
{
    return b?gcd(b,a%b):a;
}

LL multi(LL a,LL b,LL m)
{
    LL ans=0;
    a%=m;
    while(b)
    {
        if(b&1)
        {
            ans=(ans+a)%m;
            b--;
        }
        b>>=1;
        a=(a+a)%m;
    }
    return ans;
}

LL quick_mod(LL a,LL b,LL m)
{
    LL ans=1;
    a%=m;
    while(b)
    {
        if(b&1)
        {
            ans=multi(ans,a,m);
            b--;
        }
        b>>=1;
        a=multi(a,a,m);
    }
    return ans;
}

bool Miller_Rabin(LL n)
{
    if(n==2) return true;
    if(n<2||!(n&1)) return false;
    LL m=n-1;
    int k=0;
    while(!(m&1))
    {
        k++;
        m>>=1;
    }
    for(int i=0;i<times;i++)
    {
        LL a=rand()%(n-1)+1;
        LL x=quick_mod(a,m,n);
        LL y=0;
        for(int j=0;j<k;j++)
        {
            y=multi(x,x,n);
            if(y==1&&x!=1&&x!=n-1) return false;
            x=y;
        }
        if(y!=1) return false;
    }
    return true;
}

LL Pollard_rho(LL n,LL c)
{
    LL i=1,k=2;
    LL x=rand()%(n-1)+1;
    LL y=x;
    while(true)
    {
        i++;
        x=(multi(x,x,n)+c)%n;
        LL d=gcd((y-x+n)%n,n);
        if(1<d&&d<n) return d;
        if(y==x) return n;
        if(i==k)
        {
            y=x;
            k<<=1;
        }
    }
}

void Find(LL n,LL c)
{
    if(n==1) return ;
    if(Miller_Rabin(n))
    {
        fac[ct++]=n;
        return ;
    }
    LL p=n;
    LL k=c;
    while(p>=n) p=Pollard_rho(p,c--);
    Find(p,k);
    Find(n/p,k);
}


void Solve(LL n)
{
    ct=0;
    Find(n,120);
    sort(fac,fac+ct);
    num[0]=1;
    int k=1;
    for(int i=1;i<ct;i++)
    {
        if(fac[i]==fac[i-1])
            num[k-1]++;
        else
        {
            num[k]=1;
            fac[k++]=fac[i];
        }
    }
    cnt=k;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%lld",&key);
        Solve(key);
        ans=0;
        for(int i=cnt-1;i>=0;i--)
        {
            LL temp=1;
            for(int j=0;j<num[i];j++)
                temp*=fac[i];
            ans+=temp;
        }
        if(cnt==1) ans/=fac[0];//由于L<N，所以当因子数为1时要除去一个因子
        printf("%lld %lld\n",cnt,ans);
    }
    return 0;
}
