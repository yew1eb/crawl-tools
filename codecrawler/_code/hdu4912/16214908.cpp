#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1e5+100;
const int maxm=maxn*2;
struct Node
{
    int u;
    int v;
    int id;
}s[maxn];
int n,m,dep[maxn],p[maxn],lca[maxn];
int e,pnt[maxm],nxt[maxm],head[maxn];
bool vis[maxn];
vector<pair<int,int> > querys[maxn];
bool cmp(Node a,Node b)
{
    return dep[lca[a.id]]>dep[lca[b.id]];
}
void AddEdge(int u,int v)
{
    pnt[e]=v;nxt[e]=head[u];head[u]=e++;
}
void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
    memset(dep,-1,sizeof(dep));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++)
        querys[i].clear();
}
int find(int x)
{
    if(p[x]==x)
        return x;
    return p[x]=find(p[x]);
}
void DFS(int u,int f)
{
    p[u]=u;
    for(int i=0;i<querys[u].size();i++)
    {
        if(dep[querys[u][i].first]==-1)
            continue;
        lca[querys[u][i].second]=find(querys[u][i].first);
    }
    for(int i=head[u];i!=-1;i=nxt[i])
        if(pnt[i]!=f)
        {
            dep[pnt[i]]=dep[u]+1;
            DFS(pnt[i],u);
            p[pnt[i]]=u;
        }
}
void dfs(int u)
{
    vis[u]=1;
    for(int i=head[u];i!=-1;i=nxt[i])
        if(!vis[pnt[i]]&&dep[pnt[i]]>dep[u])
            dfs(pnt[i]);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        Init();
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            AddEdge(u,v);
            AddEdge(v,u);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&s[i].u,&s[i].v);
            s[i].id=i;
            querys[s[i].u].push_back(make_pair(s[i].v,i));
            querys[s[i].v].push_back(make_pair(s[i].u,i));
        }
        dep[1]=0;
        DFS(1,-1);
        sort(s,s+m,cmp);
        int ans=0;
        for(int i=0;i<m;i++)
        {
            if(!vis[s[i].u]&&!vis[s[i].v])
            {
                ans++;
                dfs(lca[s[i].id]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
