#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int mod=1000000000+7;
const char DNA[4]={'A','C','G','T'};
int dp[2][1<<15],n,m;
int next_state[1<<15][4];
int ans[20],cnt[1<<15];
char s[20];
void Init()
{
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<(1<<15);++i)
    {
        int x=i;
        while(x)
        {
            cnt[i]++;
            x=x&(x-1);
        }
    }
}
void solve()
{
    memset(dp,0,sizeof(dp));
    int cur[20],next[20];
    for(int i=0;i<(1<<n);++i)
    {
        cur[0]=0;
        for(int j=1;j<=n;++j)
            cur[j]=cur[j-1]+((i>>(j-1))&1);
        for(int c=0;c<4;++c)
        {
            next[0]=0;
            for(int j=n;j>=1;--j)
                if(s[j-1]==DNA[c]) next[j]=max(cur[j],cur[j-1]+1);
                else next[j]=cur[j];
            for(int j=1;j<=n;++j)
                next[j]=max(next[j],next[j-1]);
            int tmp=0;
            for(int j=1;j<=n;++j)
                if(next[j]>next[j-1])
                    tmp|=(1<<(j-1));
            next_state[i][c]=tmp;
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=m;++i)
    {
        int p=i&1;
        memset(dp[p],0,sizeof(dp[p]));
        for(int j=0;j<(1<<n);++j)
        {
            if(dp[p^1][j]==0) continue;
            for(int c=0;c<4;++c)
            {
                dp[p][next_state[j][c]]+=dp[p^1][j];
                if(dp[p][next_state[j][c]]>=mod) dp[p][next_state[j][c]]-=mod;
            }
        }
    }

    memset(ans,0,sizeof(ans));
    for(int i=0;i<(1<<n);++i)
    {
        ans[cnt[i]]+=dp[m&1][i];
        if(ans[cnt[i]]>=mod) ans[cnt[i]]-=mod;
    }
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    Init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        scanf("%d",&m);
        n=strlen(s);
        solve();
        for(int i=0;i<=n;++i)
            printf("%d\n",ans[i]);
    }
    return 0;
}
