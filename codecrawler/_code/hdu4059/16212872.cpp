#include<cstdio>

#include<cstring>
typedef long long ll;
const ll MOD=1000000007;
const int nPri=10005;
ll factor[64],res;
int prime[nPri],cnt;
bool is_pri[nPri];

void Prime()
{
    memset(is_pri,1,sizeof(is_pri));
    cnt=0;
    int i,j;
    for(i=2;i<nPri;i++)
    {
        if(is_pri[i])
        {
            prime[cnt++]=i;
            for(j=i+i;j<nPri;j+=i)
            {
                is_pri[j]=false;
            }
        }
    }
}

ll PowMode(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1)
        {
            ret=(ret*a)%MOD;
        }
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}

int getFactor(ll n)
{
    int i,count=0;
    for(i=0;i<cnt;i++)
    {
        if(n<prime[i])
        {
            break;
        }
        if(n%prime[i]==0)
        {
            factor[count++]=prime[i];
            while(n%prime[i]==0)
            {
                n/=prime[i];
            }
        }
    }
    if(n!=1)
    {
        factor[count++]=n;
    }
    return count;
}

ll get_sum(ll n)
{
    ll ans=n;
    ans=(ans*(n+1))%MOD;
    ans=(ans*(2*n+1))%MOD;
    ans=(ans*((3*n*n+3*n-1)%MOD))%MOD;
    ans=(ans*res)%MOD;
    return ans;
}

ll dfs(ll n,int start,int count) //å®¹æ¥åç
{
    ll ans=0;
    int i;
    for(i=start;i<count;i++)
    {
        ll temp=PowMode(factor[i],4);
        ans=(ans+ (temp*get_sum(n/factor[i]))%MOD-
                (temp*dfs(n/factor[i],i+1,count))%MOD + MOD)%MOD;
    }
    return ans;
}

int main()
{
    Prime();
    res=PowMode(30,MOD-2);

    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll n;
        scanf("%I64d",&n);
        int count=getFactor(n);
        ll ans=(get_sum(n)-dfs(n,0,count)+MOD)%MOD;
        printf("%I64d\n",ans);
    }
    return 0;
}
