#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
#define MAXN 100100
#define MOD 1000000007
typedef long long ll;
int n,m;
vector<int> G[MAXN];
int top[MAXN],siz[MAXN],son[MAXN],par[MAXN],depth[MAXN],out[MAXN],in[MAXN];
ll w[MAXN];
int tot;

void dfs1(int u,int pre)
{
    par[u]=pre;
    siz[u]=1;
    int tp=0;
    for(int i=0,sz=G[u].size();i<sz;i++)
    {
        int v=G[u][i];
        if(v!=pre)
        {
            dfs1(v,u);
            siz[u]+=siz[v];
            if(siz[v]>siz[tp])
                tp=v;
        }
    }
    if(tp) son[u]=tp;
}

void dfs2(int u,int deep,int high)
{
    depth[u]=deep;
    top[u]=high;
    in[u]=++tot;
    //printf("%d %d\n",u,in[u]);
    if(son[u]>0)
        dfs2(son[u],deep+1,high);
    for(int i=0,sz=G[u].size();i<sz;i++)
    {
        int v=G[u][i];
        if(v!=son[u]&&v!=par[u])
        {
            dfs2(v,deep+1,v);
        }
    }
    out[u]=tot;
}

void update(int x,ll val,ll *sum)
{
    while(x<=n)
    {
        sum[x]+=val;
        sum[x]%=MOD;
        x+=x&(-x);
    }
}

ll getsum(int x,ll *sum)
{
    ll ret=0;
    while(x>0)
    {
        ret+=sum[x];
        ret%=MOD;
        x-=x&(-x);
    }
    return ret;
}

ll sum_all[MAXN],sum_double[MAXN];
void init()
{
    siz[0]=0;
    tot=son[0]=0;
    for(int i=1;i<=n;i++)
    {
        G[i].clear();
        son[i]=-1;
        sum_all[i]=0;
        sum_double[i]=0;
        w[i]=0;
    }
}
void change(int x,ll val)
{
    int u=x;
    u=top[u];
    while(par[u]>0)
    {
        ll all=getsum(out[u],sum_all)-getsum(in[u]-1,sum_all);
        ll update_val=(val-w[x])*(val-w[x])%MOD+2*all*(val-w[x])%MOD;
        update(in[par[u]],update_val%MOD,sum_double);
        u=top[par[u]];
    }
    update(in[x],-w[x],sum_all);
    update(in[x],val,sum_all);
    w[x]=val;
}

int inqury(int x,int y)
{
    ll ret=0;
    int pre=0;
    while(top[x]!=top[y])
    {
        if(depth[top[x]]<depth[top[y]]) swap(x,y);
        ret+=getsum(in[x],sum_double)-getsum(in[top[x]]-1,sum_double);
        if(son[x]>0)
        {
            ll all=(getsum(out[son[x]],sum_all)-getsum(in[son[x]]-1,sum_all))%MOD;
            ret+=all*all;
            ret%=MOD;
        }
        if(pre>0)
        {
            ll all=(getsum(out[pre],sum_all)-getsum(in[pre]-1,sum_all))%MOD;
            ret-=all*all;
            ret%=MOD;
        }
        pre=top[x];
        x=par[top[x]];
    }
    if(depth[x]>depth[y]) swap(x,y);
    ret+=getsum(in[y],sum_double)-getsum(in[x]-1,sum_double);
    ret%=MOD;
    if(son[y]>0)
    {
        ll all=(getsum(out[son[y]],sum_all)-getsum(in[son[y]]-1,sum_all))%MOD;
        ret+=all*all;
        ret%=MOD;
    }
    if(par[x]>0)
    {
        ll all=(getsum(out[1],sum_all)-getsum(out[x],sum_all)+getsum(in[x]-1,sum_all))%MOD;
        ret+=all*all;
        ret%=MOD;
    }
    if(pre>0)
    {
        ll all=(getsum(out[pre],sum_all)-getsum(in[pre]-1,sum_all))%MOD;
        ret-=all*all;
        ret%=MOD;
    }
    return ret;
}

int main()
{
    //freopen("in","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1;i<=n;i++)
            scanf("%I64d",&w[i]);
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs1(1,-1);
        dfs2(1,1,1);
        for(int i=1;i<=n;i++)
        {
            ll tp=w[i];
            w[i]=0;
            change(i,tp);
        }
        //printf("%d***\n",getsum(in[5],sum_double)-getsum(in[5]-1,sum_double));
        for(int i=1;i<=m;i++)
        {
            int kind;
            ll all=getsum(out[1],sum_all);
            scanf("%d",&kind);
            if(kind==1)
            {
                int u;
                ll val;
                scanf("%d%I64d",&u,&val);
                change(u,val);
            }
            else{
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",((all*all%MOD-inqury(x,y))%MOD+MOD)%MOD);
            }
        }
    }
}
