#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef __int64 ll;

ll prime[50000];
bool flag[50000];

void init()
{
    ll i,j,num=0;
    for(i=2;i<50000;i++)
    {
        if(!flag[i])
        {
            prime[num++]=i;
            for(j=i*i;j<50000;j=j+i)
                flag[j]=true;
        }
    }
}

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

ll eular(ll n)
{
    ll i,res=1;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            n=n/i;
            res=res*(i-1);
            while(n%i==0)
            {
                n=n/i;
                res=res*i;
            }
        }
        if(n==1)
            break;
    }
    if(n>1)
        res=res*(n-1);
    return res;
}

ll solve(ll n,ll fac[])
{
    ll i,num=0;
    for(i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            n=n/prime[i];
            fac[num++]=prime[i];
            while(n%prime[i]==0)
            {
                n=n/prime[i];
                fac[num++]=prime[i];
            }
        }
        if(n==1)
            break;
    }
    if(n>1)
        fac[num++]=n;
    return num;
}

ll mmod(ll a,ll b,ll n)
{
    a=a%n;
    ll res=0;
    while(b)
    {
        if(b&1)
        {
            res=res+a;
            if(res>=n)
                res=res-n;
        }
        a=a<<1;
        if(a>=n)
            a=a-n;
        b=b>>1;
    }
    return res;
}

ll exmod(ll a,ll b,ll n)
{
    a=a%n;
    ll res=1;
    while(b>=1)
    {
        if(b&1)
            res=mmod(res,a,n);
        a=mmod(a,a,n);
        b=b>>1;
    }
    return res;
}

void getans(ll n,ll mod)
{
    ll i,num,fac[100],ans=n;
    bool loop=true;
    while(loop)
    {
        loop=false;
        num=solve(n,fac);
        for(i=0;i<num;i++)
        {
            if(exmod(10,n/fac[i],mod)==1)
            {
                loop=true;
                if(n/fac[i]<ans)
                    ans=n/fac[i];
            }
        }
        n=ans;
    }
    printf("%I64d\n",ans);
}

int main()
{
    ll n,t,l,phi;
    int cnt=1;
    init();
    while(scanf("%I64d",&n)!=EOF)
    {
        if(n==0)
            break;
        printf("Case %d: ",cnt++);
        t=gcd(n,8);
        l=9*n/t;
        if(gcd(10,l)!=1)
        {
            printf("0\n");
            continue;
        }
        phi=eular(l);
        getans(phi,l);
    }
    return 0;
}
