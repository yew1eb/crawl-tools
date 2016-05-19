#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int maxn=100010;
int N,M;
int val[maxn];
int head[maxn],tot,pos;
int son[maxn];
int num[maxn];
int dep[maxn];
int fa[maxn];
int w[maxn],fw[maxn];
int top[maxn];
struct node
{
    int v,next;
}edge[maxn*2];
void init()
{
    tot=pos=0;
    memset(head,-1,sizeof(head));
    memset(son,-1,sizeof(son));
}

void add_edge(int u,int v)
{
    edge[tot].v=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void dfs1(int u,int f,int depth)
{
    fa[u]=f;
    dep[u]=depth;
    num[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==f)continue;
        dfs1(v,u,depth+1);
        num[u]+=num[v];
        if(son[u]==-1||num[son[u]]<num[v])
        son[u]=v;
    }
}
void dfs2(int u,int sp)
{
    top[u]=sp;
    w[u]=++pos;
    fw[pos]=u;
    if(son[u]!=-1)dfs2(son[u],sp);
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v!=fa[u]&&v!=son[u])
            dfs2(v,v);
    }
}
struct IntervalTree
{
    int sum[maxn<<2];
    int setv[maxn<<2];
    int active[maxn<<2];
    void build(int o,int l,int r)
    {
        sum[o]=setv[o]=active[o]=0;
        if(l==r)
        {
            sum[o]=val[fw[l]];
            return ;
        }
        int mid=(l+r)>>1;
        build(o<<1,l,mid);
        build(o<<1|1,mid+1,r);
        sum[o]=sum[o<<1]+sum[o<<1|1];
    }
    void update(int o,int l,int r,int q1,int q2,int x)
    {
        if(q1<=l&&r<=q2)
        {
            setv[o]=x;
            if(setv[o])active[o]=sum[o];
            else active[o]=0;
            return ;
        }
        pushdown(o);
        int mid=(l+r)>>1;
        if(q1<=mid)update(o<<1,l,mid,q1,q2,x);
        if(q2>mid)update(o<<1|1,mid+1,r,q1,q2,x);
        active[o]=active[o<<1]+active[o<<1|1];
    }
    void pushdown(int o)
    {
        if(setv[o])
        {
            setv[o<<1]=setv[o<<1|1]=setv[o];
            if(setv[o<<1])active[o<<1]=sum[o<<1];
            else active[o<<1]=0;
            if(setv[o<<1|1])active[o<<1|1]=sum[o<<1|1];
            else active[o<<1|1]=0;
            setv[o]=0;
        }
    }
}tree;
void MChange(int l,int r)
{
    int f1=top[l],f2=top[r];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(l,r);
            swap(f1,f2);
        }
        tree.update(1,1,N,w[f1],w[l],1);
        l=fa[f1],f1=top[l];
    }
    if(dep[l]>dep[r])swap(l,r);
    tree.update(1,1,N,w[l],w[r],1);
}
int main()
{
    int T,u,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        init();
        for(int i=1;i<=N;i++)scanf("%d",&val[i]);
        for(int i=1;i<N;i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        dfs1(1,0,0);
        dfs2(1,1);
        tree.build(1,1,N);
        scanf("%d",&M);
        int op,x,y;
        while(M--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d%d",&x,&y);
                MChange(x,y);
            }
            else if(op==2)
            {
                scanf("%d",&x);
                tree.update(1,1,N,w[x],w[x],0);
            }
            else
            {
                scanf("%d",&x);
                tree.update(1,1,N,w[x],w[x]+num[x]-1,1);
            }
            printf("%d\n",tree.active[1]);
        }
    }
    return 0;
}
