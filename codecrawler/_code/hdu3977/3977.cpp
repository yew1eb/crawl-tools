#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 1000005
bool isprime[maxn];
typedef long long ll;
ll prime[maxn],nprime;
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
void getprime()
{
    ll i,j;
    memset(isprime,1,sizeof(isprime));
    nprime=0;
    for(i=2; i<maxn; i++)
        if(isprime[i])
        {
            prime[nprime++]=i;
            for(j=i*i; j<maxn; j+=i) isprime[j]=0;
        }
}
ll factor[100][2],tol;
void findfac(ll n)
{
    ll x=n,l=(ll)sqrt((double)n);
    tol=0,memset(factor,0,sizeof(factor));
    for(int i=0; prime[i]<=l; i++)
        if(x%prime[i]==0)
        {
            factor[tol][0]=prime[i];
            while(x%prime[i]==0) factor[tol][1]++,x/=prime[i];
            tol++;
        }
    if(x>1) factor[tol][0]=x,factor[tol++][1]++;
}
ll exp_mod(ll a,ll b,ll c)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%c;
        b>>=1,a=a*a%c;
    }
    return ret;
}
ll getPrimeLoop(ll p)//求一个素数的循环节
{
    ll pos=3,f1=1,f2=1,f3=2%p,k=1e9,l=(ll)sqrt((double)p-1);
    while(f3) f1=f2,f2=f3,f3=(f1+f2)%p,pos++;//找到第一个值是0的点
    for(ll i=1; i<=l; i++)
        if((p-1)%i==0)
        {
            if(exp_mod(f2,(p-1)/i,p)==1) k=min(k,(p-1)/i);
            if(exp_mod(f2,i,p)==1) k=min(k,i);
        }
    return pos*k;
}
ll solve(ll p,ll k)//求一个素数的k次方的循环节
{
    ll ans=getPrimeLoop(p);
    for(int i=0; i<k-1; i++) ans*=p;
    return ans;
}
int main()
{
    int t,ca=0;
    ll n,ans;
    getprime();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        findfac(n);
        ans=1;
        ll temp;
        for(int i=0; i<tol; i++)
            temp=solve(factor[i][0],factor[i][1]),ans=ans/gcd(ans,temp)*temp;
        printf("Case #%d: %I64d\n",++ca,ans);
    }
    return 0;
}
