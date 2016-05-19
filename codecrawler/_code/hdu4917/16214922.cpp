#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
const long long M=1e9+7;
vector<int>g[44];
vector<int>d[44];
vector<int>pr[44];
long long dp[1<<21];
int p[44],pp[44];
int num;
int res;
long long ans;
int n,m;
long long c[44][44];
bool vis[44];
void pre()
{
    for(int i=0;i<=40;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i)c[i][j]=1;
            else
            {
                c[i][j]=c[i-1][j]+c[i-1][j-1];
                c[i][j]%=M;
            }
        }
    }
}
void init()
{
    ans=1;
    res=n;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
        pr[i].clear();
    }
}
void dfs(int u)
{
    vis[u]=1;
    pp[num]=u;
    p[u]=num++;
    int size=g[u].size();
    for(int i=0;i<size;i++)
    {
        int v=g[u][i];
        if(!vis[v])dfs(v);
    }
}
void solve()
{
    for(int i=0;i<num;i++)
    {
        d[i].clear();
        int u=pp[i];
        int size=pr[u].size();
        for(int j=0;j<size;j++)d[i].push_back(p[pr[u][j]]);
    }
    int nn=(1<<num);
    for(int i=0;i<nn;i++)dp[i]=0;
    dp[0]=1;
    for(int i=0;i<nn;i++)
    {
        if(dp[i]==0)continue;
        for(int j=0;j<num;j++)
        {
            if((i&(1<<j))==(1<<j))continue;
            bool ok=0;
            int size=d[j].size();
            for(int k=0;k<size;k++)
            {
                int v=d[j][k];
                if((i&(1<<v))!=(1<<v))
                {
                    ok=1;
                    break;
                }
            }
            if(ok==0)
            {
                dp[i|(1<<j)]+=dp[i];
                dp[i|(1<<j)]%=M;
            }
        }
    }
    ans*=(c[res][num]*dp[nn-1])%M;
    ans%=M;
    res-=num;
}
int main()
{
    int u,v;
    pre();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
            pr[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                num=0;
                dfs(i);
                solve();
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
