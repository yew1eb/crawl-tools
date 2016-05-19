#include <stdio.h>
#include <string.h>
#define ll __int64
const int maxn=5+1e6;
const ll mod=258280327;
int num[maxn];
int prime[maxn];
ll s[maxn];
ll t[maxn];
ll g[maxn];
ll f[maxn];
void getg()
{
    int all=0;
    memset(num,0,sizeof(num));
    g[1]=1;
    g[0]=0;
    for(int i=2;i<maxn;i++)
    {
        if(!num[i])
        {
            g[i]=2;
            prime[all++]=i;
        }
        for(int j=0;j<all&&i*prime[j]<maxn;j++)
        {
            num[i*prime[j]]=1;
            if(i%prime[j])
            {
                g[i*prime[j]]=g[i]*2%mod;
            }
            else
            {
                g[i*prime[j]]=g[i];
                break;
            }
        }
    }
    return ;
}
void gett()
{
    memset(t,0,sizeof(t));
    for(int i=1;i<maxn;i++)
    {
        for(int j=i;j<maxn;j+=i)
        {
            t[j]=(t[j]+g[j/i-1])%mod;
        }
    }
    return ;
}
void gets()
{
    f[1]=1;
    s[1]=1;
    for(int i=2;i<maxn;i++)
    {
        f[i]=(f[i-1]+2*i-1-t[i-1])%mod;
        s[i]=((s[i-1]+f[i])%mod+mod)%mod;
    }
    return ;
}
int main()
{
    getg();
    gett();
    gets();
    int t,n;
    while(scanf("%d",&t)!=-1)
    {
        while(t--)
        {
            scanf("%d",&n);
            printf("%I64d\n",s[n]);
        }
    }
    return 0;
}
