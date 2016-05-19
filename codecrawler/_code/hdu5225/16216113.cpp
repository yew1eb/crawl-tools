#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#define scnaf scanf
#define cahr char
#define bug puts("bugbugbug");
using namespace std;
typedef long long ll;
const int mod=1000000007;
const int maxn=1e5+5;
const int inf=1e9;
int N;
const int NV=105;
int c[NV];
inline int lowbit(int t)
{
    return t&(-t);
}
void update(int x,int v)
{
    while(x<=N)
    {
        c[x]+=v;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int findkth(int k)
{
    int idx = 0;
    for(int i=20; i>=0; i--)
    {
        idx |= 1 << i;
        if(idx <= N && c[idx] < k)
            k -= c[idx];
        else idx ^= 1 << i;
    }
    return idx + 1;
}
   ll dp[105],cnt[105];
void init()
{
   dp[1]=0;
   cnt[1]=1;
   for(int i=2;i<=100;i++)
   {
       dp[i]=dp[i-1]*i%mod;
       dp[i]=(dp[i]+cnt[i-1]*(i*(i-1)/2)%mod)%mod;
       cnt[i]=cnt[i-1]*i%mod;
   }
}
int a[105];
int main()
{
    init();
       int n;
    while(~scanf("%d",&n))
    {
        N=n;
       for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        ll ans=0;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++) update(i,1);
        ll fuck=0;
        for(int i=1;i<=n;i++)
        {
            int num=query(a[i]);
            ans += dp[n-i] * (num-1) % mod + cnt[n-i] *((num-1)*(num-2)/2)%mod;
            ans%=mod;
            ans += fuck * (num-1) % mod * cnt[n-i] %mod;
            ans%=mod;
            fuck=fuck+num-1;
            update(a[i],-1);
        }
        memset(c,0,sizeof(c));
        printf("%lld\n",ans);
    }
}