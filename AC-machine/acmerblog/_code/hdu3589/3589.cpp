#include<stdio.h>
#include<string.h>
#include<math.h>
#define ll __int64
#define maxn 1000010
ll prime[maxn];
bool isprime[maxn];
ll exp(ll a,ll b,ll p)
{
    ll res=1;
    for(;b;b>>=1)
    {
        if(b&1)
        res=(res*a)%p;
        a=(a*a)%p;
    }
    return res;
}

int cal(int a,int n)
{
    if(a%n==0)
    return 0;
    else
    return exp(a,(n-1)/2,n)==1?1:-1;
}
int main()
{
    freopen("in.txt","r",stdin);
    memset(isprime,true,sizeof(isprime));
    for(int i=2;i<maxn;i++)
    {
        for(int j=2;i*j<maxn;j++)
        isprime[i*j]=0;
    }
    int k=0;
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i])
        prime[k++]=i;
    }
    int a,n;
   while(scanf("%d%d",&a,&n)==2)
   {
        int ans;
        if(isprime[n]==0)
        {
        ans=1;
        for(int i=0;n!=1&&i<k;i++)
        {
            if(n%prime[i]==0)
            {
                int total=0;
                while(n%prime[i]==0)
                {
                    total++;
                    n/=prime[i];
                }
                int tmp=cal(a,prime[i]);
                if(total%2==0&&tmp==-1)
                tmp=1;
                ans*=tmp;
            }
        }
        }
        else
        ans=cal(a,n);
        printf("%d\n",ans);
   }
    return 0;
}
