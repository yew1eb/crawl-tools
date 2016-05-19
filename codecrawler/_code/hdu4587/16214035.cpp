#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 5050
int adj[N*2],head[N],edge[N*2],e,n,m,vis[N*2],deg[N];
int low[N],dfn[N],cnt,cut[N],root,insta[N];
int del;
void tarjan(int u,int fa)
{
    dfn[u]=low[u]=++cnt;
    insta[u]=1;
    int tot=0;
    for(int i=head[u];i+1;i=adj[i])
    {
        if(edge[i]==fa||edge[i]==del) continue;
        else if(dfn[edge[i]]==0)
        {
            tarjan(edge[i],u);
            low[u]=min(low[u],low[edge[i]]);
            tot++;
            if(u!=root&&low[edge[i]]>=dfn[u])
                cut[u]++;
        }
        else if(insta[edge[i]])
            low[u]=min(low[u],dfn[edge[i]]);
    }
    if(u==root)
        cut[u]=tot-1; // å½è¯¥è¿éåæ¯åªæä¸ä¸ªç¹æ¶ä¸º-1
    insta[u]=0;
}

void init()
{
    cnt=0;
    memset(dfn,0,sizeof(dfn));
    memset(cut,0,sizeof(cut));
    memset(insta,0,sizeof(insta));
}
void addedge(int u,int v)
{
    edge[e]=v;adj[e]=head[u];head[u]=e++;
}
int main ()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        e=0;
        for(int i=1,v,u;i<=m;++i)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        int ans=0;
        for(int u=0;u<n;++u)
        {
            init();
            del=u;
            int sum=0;
            for(int i=0;i<n;++i)
                if(i!=u&&!dfn[i])
            {
                root=i;sum++;
                tarjan(i,-1);
            }
            for(int i=0;i<n;++i)
                if(i!=u)
                ans=max(ans,sum+cut[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

