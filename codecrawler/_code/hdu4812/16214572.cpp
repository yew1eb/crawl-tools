#pragma comment(linker,"/STACK:102400000,102400000")
#include<iostream>
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
const int maxn=100000+10;
const int mod=1000000+3;
struct Edge
{
    int v,next;
    Edge(){}
    Edge(int v,int next):v(v),next(next){}
}edges[maxn<<1];
int head[maxn],sons[maxn],wroot,wval,nEdge;
int inv[mod+10],flag[mod+10],fff[mod+10],val[maxn];
int S[maxn],id[maxn],ans[2],cnt,tot,n,K;
bool vis[maxn];
void AddEdge(int u,int v)
{
    edges[++nEdge]=Edge(v,head[u]);
    head[u]=nEdge;
    edges[++nEdge]=Edge(u,head[v]);
    head[v]=nEdge;
}
ll ext_gcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    ll d=ext_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
void Init()
{
    memset(head,0xff,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(flag,0,sizeof(flag));
    nEdge=-1;cnt=0;tot=1;
    ans[0]=ans[1]=inf;
}
inline void Update(int x,int y)
{
    if(x>y) swap(x,y);
    if(x<ans[0]) ans[0]=x,ans[1]=y;
    else if(x==ans[0]&&y<ans[1]) ans[1]=y;
}
void getRoot(int u,int fa)
{
    sons[u]=1;
    int maxv=0;
    for(int k=head[u];k!=-1;k=edges[k].next)
    {
        int v=edges[k].v;
        if(v==fa||vis[v]) continue ;
        getRoot(v,u);
        sons[u]+=sons[v];
        maxv=max(maxv,sons[v]);
    }
    maxv=max(maxv,sons[0]-sons[u]);
    if(maxv<wval) {wval=maxv;wroot=u;}
}
void dfs(int u,int fa,int prev)
{
    int tmp=S[cnt]=(ll)val[u]*prev%mod;
    id[cnt++]=u; sons[u]=1;
    for(int k=head[u];k!=-1;k=edges[k].next)
    {
        int v=edges[k].v;
        if(v==fa||vis[v]) continue;
        dfs(v,u,tmp);
        sons[u]+=sons[v];
    }
}
void solve(int u,int cnode)
{
    if(cnode==1) return ;
    sons[0]=cnode;
    wval=inf;
    getRoot(u,-1);
    int x;
    for(int k=head[wroot];k!=-1;k=edges[k].next)
    {
        int v=edges[k].v;
        if(vis[v]||v==wroot) continue;
        cnt=0;
        dfs(v,wroot,val[wroot]);
        for(int i=0;i<cnt;++i)
        {
            if(S[i]==K) Update(wroot,id[i]);
            x=(ll)S[i]*inv[val[wroot]]%mod;
            x=(ll)K*inv[x]%mod;
            if(flag[x]==tot) Update(fff[x],id[i]);
        }
        for(int i=0;i<cnt;++i)
        {
            if(flag[S[i]]==tot)
                fff[S[i]]=min(id[i],fff[S[i]]);
            else
            {
                flag[S[i]]=tot;
                fff[S[i]]=id[i];
            }
        }
    }
    tot++;
    vis[wroot]=true;
    for(int k=head[wroot];k!=-1;k=edges[k].next)
    {
        int v=edges[k].v;
        if(v==wroot||vis[v]) continue;
        solve(v,sons[v]);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll x,y;
    for(int i=0;i<mod;++i)
    {
        ext_gcd(i,mod,x,y);
        x%=mod;
        if(x<0) x+=mod;
        inv[i]=x;
    }
    while(~scanf("%d%d",&n,&K))
    {
        Init();
        for(int i=1;i<=n;++i)
            scanf("%d",&val[i]);
        int u,v;
        for(int i=1;i<n;++i)
        {
            scanf("%d%d",&u,&v);
            AddEdge(u,v);
        }
        solve(1,n);
        if(ans[0]==inf) printf("No solution\n");
        else printf("%d %d\n",ans[0],ans[1]);
    }
    return 0;
}
