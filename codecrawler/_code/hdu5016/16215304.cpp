#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=100010;
const int INF=1000000000;
int N;
int ans[maxn];
int type[maxn];
int head[maxn],tot;
int vis[maxn];
int size[maxn],maxv[maxn];
pair<int,int> np[maxn];
pair<int,int> pp[maxn];
int Max,root;
struct node
{
    int v,next,w;
}edge[maxn*2];
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int w)
{
    edge[tot].v=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void SPFA()
{
    queue<int> q;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=N;i++)
    {
        if(type[i])
        {
            q.push(i);
            vis[i]=1;
            np[i]=make_pair(0,i);
        }
        else np[i]=make_pair(INF,0);
    }
    while(!q.empty())
    {
        int u=q.front();q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(np[v].first>np[u].first+edge[i].w)
            {
                np[v]=make_pair(np[u].first+edge[i].w,np[u].second);
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}
void dfssize(int u,int fa)
{
    size[u]=1;
    maxv[u]=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==fa||vis[v])continue;
        dfssize(v,u);
        size[u]+=size[v];
        if(size[v]>maxv[u])maxv[u]=size[v];
    }
}
void dfsroot(int r,int u,int f)
{
    if(size[r]-size[u]>maxv[u])
        maxv[u]=size[r]-size[u];
    if(maxv[u]<Max)Max=maxv[u],root=u;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==f||vis[v])continue;
        dfsroot(r,v,u);
    }
}
int ff[maxn];
int cnt;
int dis[maxn];
void dfsdis(int u,int fa,int d)
{
    ff[cnt++]=u;
    dis[u]=d;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(vis[v]||v==fa)continue;
        dfsdis(v,u,d+edge[i].w);
    }
}
void calc(int u,int d)
{
    cnt=0;
    dfsdis(u,0,d);
    for(int i=0;i<cnt;i++)
        pp[i].first=np[ff[i]].first-dis[ff[i]],pp[i].second=np[ff[i]].second;
    sort(pp,pp+cnt);
    for(int i=0;i<cnt;i++)
    {
        if(!type[ff[i]])
        {
            pair<int,int> tmp;
            tmp.first=dis[ff[i]],tmp.second=ff[i];
            int p=lower_bound(pp,pp+cnt,tmp)-pp;
            ans[ff[i]]+=(d>0?p-cnt:cnt-p);
        }
    }
}
void dfs(int u)
{
    Max=INF;
    dfssize(u,0);
    dfsroot(u,u,0);

    calc(root,0);
    vis[root]=1;
    for(int i=head[root];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(vis[v])continue;
        calc(v,edge[i].w);
        dfs(v);
    }
}
void solve()
{
    memset(ans,0,sizeof(ans));
    memset(vis,0,sizeof(vis));
    dfs(1);
    int maxv=0;
    for(int i=1;i<=N;i++)
        maxv=max(ans[i],maxv);
    printf("%d\n",maxv);
}
int main()
{
    int u,v,w;
    while(scanf("%d",&N)!=EOF)
    {
        init();
        for(int i=1;i<N;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        for(int i=1;i<=N;i++)scanf("%d",&type[i]);
        SPFA();
        solve();
    }
    return 0;
}
