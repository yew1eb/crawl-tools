#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int N=10005;
struct Edge
{
    int v;
    Edge* nxt;
}memo[N*10],*cur,*org[N],*adj[N];

int n,m,mi,sum,valu[N],cnt[N];
int dfn[N],low[N],id[N],idx,scnt;
bool insta[N],vis[N];
stack<int> st;

int iabs(int x){return x>0?x:-x;}
void dfs(int u,int fa)
{
    vis[u]=1;
    for(Edge* it=adj[u];it;it=it->nxt)
    {
        int v=it->v;
        if(v==fa||vis[v]) continue;
        dfs(v,u);
        cnt[u]+=cnt[v];
    }
    mi=min(mi,iabs(sum-2*cnt[u]));
}
void tarjan(int u,int fa)
{
    dfn[u]=low[u]=idx++;
    st.push(u); insta[u]=1;
    int v,flag=1;
    for(Edge* it=org[u];it;it=it->nxt)
    {
        v=it->v;
        if(v==fa&&flag){flag=0;continue;}
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(insta[v]&&dfn[v]<low[u]) low[u]=dfn[v];
    }
    if(low[u]==dfn[u])
    {
        while(1)
        {
            int top=st.top(); st.pop();
            insta[top]=0;
            id[top]=scnt;
            if(top==u) break;
        }
        scnt++;
    }
}
void addEdge(int u,int v,Edge* head[])
{
    cur->v=v;
    cur->nxt=head[u];
    head[u]=cur++;
}
void init()
{
    cur=memo;
    idx=1,scnt=1,sum=0,mi=(1<<30);
    memset(adj,0,sizeof(adj));
    memset(org,0,sizeof(org));
    memset(dfn,0,sizeof(dfn));
    memset(insta,0,sizeof(insta));
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();

        int u,v;
        for(int i=0;i<n;i++) scanf("%d",&valu[i]);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            addEdge(u,v,org);
            addEdge(v,u,org);
        }
        for(int i=0;i<n;i++) if(!dfn[i]) tarjan(i,-1);
        if(scnt<=2) puts("impossible");
        else
        {
            for(int i=0;i<n;i++)
            {
                cnt[id[i]]+=valu[i]; sum+=valu[i];
                for(Edge* it=org[i];it;it=it->nxt)
                {
                    u=id[i],v=id[it->v];
                    if(u!=v) addEdge(u,v,adj),addEdge(v,u,adj);
                }
            }
            dfs(1,-1);
            printf("%d\n",mi);
        }
    }
    return 0;
}
