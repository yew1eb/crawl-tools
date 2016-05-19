#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=5000+10;
int pre[maxn],vis[maxn],dfs_clock;
int ans,ban,total,step,n,m,temp;
vector<int>G[maxn];
int tarjan(int u,int fa)
{
    bool iscut=false;
    int child=0,cutnum=0;
    int lowu=pre[u]=++dfs_clock;
    for(int i=0;i<G[u].size();++i)
    {
        int v=G[u][i];
        if(v==ban) continue;
        if(!pre[v])
        {
            child++;
            int lowv=tarjan(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u])
            {
                iscut=true;
                cutnum++;
            }
        }
        else if(pre[v]<pre[u]&&v!=fa)
           lowu=min(lowu,pre[v]);
    }
    if(fa<0&&child==1) iscut=false;
    if(child==0&&fa==-1) ans=max(ans,total-1);
    if(iscut)
      ans=max(ans,total+cutnum-(int)(fa==-1));
    return lowu;
}
void dfs(int u)
{
    temp++;
    vis[u]=step;
    for(int i=0;i<G[u].size();++i)
    {
        int v=G[u][i];
        if(vis[v]!=step&&v!=ban)
           dfs(v);
    }
}
void find_conn(int x)
{
    step++;
    total=0;
    ban=x;
    bool flag=false;
    for(int i=0;i<n;++i)
    {
        if(vis[i]!=step&&i!=ban)
        {
            temp=0;
            dfs(i);
            total++;
            if(temp>=2) flag=true;
        }
    }
    if(flag) ans=max(ans,total);
    memset(pre,0,sizeof(pre));
    dfs_clock=0;
    for(int i=0;i<n;++i)
      if(!pre[i]&&i!=ban) tarjan(i,-1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        int a,b;
        for(int i=0;i<n;++i) G[i].clear();
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        memset(vis,0,sizeof(vis));
        ans=0;step=0;
        for(int i=0;i<n;++i)
           find_conn(i);
        printf("%d\n",ans);
    }
    return 0;
}
