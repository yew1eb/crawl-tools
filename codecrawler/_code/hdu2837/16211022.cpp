// A^x % m = A^(x%phi(m)+phi(m)) % m 
// sure (x >= phi(m))
//
#include <stdio.h>
#include <math.h>
long long powmod(long long a,long long b,long long mod)
{
    long long res=1;
    while(b)
    {
        if(b%2==1)
            res=res*a%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
long long euler(long long x)
{
    long long res=x;
    for(long long i=2;i<(int)sqrt(x*1.0)+1;i++)
        if(x%i==0)
        {
            res=res/i*(i-1);
            while(x%i==0)
                x/=i;
        }
    if(x>1)
        res=res/x*(x-1);
    return res;
}
long long miao(int a,int b,int mod)
{
    long long res=1;
    for(long long i=1;i<=b;i++)
    {
        res*=a;
        if(res>=mod) return res;
    }
    return res;
}
long long fun(long long n,long long m)
{
    long long num=euler(m);
    if(n<10)
        return n;
    long long a=fun(n/10,num);
    long long b=miao(n%10,a,m);
    if(b>=m)
    {
        long long res=powmod(n%10,a+num,m);
        if(res==0)
            res+=m;
        return res;
    }
    return b;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        printf("%I64d\n",fun(m,n)%n);
    }
    return 0;
}
