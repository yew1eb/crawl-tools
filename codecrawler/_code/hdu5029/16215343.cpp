#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=100010;
typedef long long ll;
#pragma comment(linker,"/STACK:1024000000,1024000000")
#define lson L,mid,ls
#define rson mid+1,R,rs
int sz[maxn],dep[maxn],fa[maxn],son[maxn],id[maxn],top[maxn],rd[maxn];
int col[maxn<<2],num[maxn<<2],cnum[maxn],ccol[maxn],ans[maxn],cnt,ptr,ccl;
struct node
{
    int v;
    node *next;
} ed[maxn<<1],*head[maxn];
struct qnode
{
    int u,v,cc;
} qq[maxn];
bool cmp(qnode a,qnode b)
{
    return a.cc<b.cc;
}
void adde(int u,int v)
{
    ed[cnt].v=v;
    ed[cnt].next=head[u];
    head[u]=&ed[cnt++];
}
void build(int L,int R,int rt)
{
    col[rt]=num[rt]=0;
    if(L==R)
    {
        ccol[L]=cnum[L]=0;
        return;
    }
    int ls=rt<<1,rs=ls|1,mid=(L+R)>>1;
    build(lson);
    build(rson);
}
void PushDown(int L,int R,int rt)
{
    int ls=rt<<1,rs=ls|1,mid=(L+R)>>1;
    if(mid==L)
    {
        if(col[ls]==col[rt]||col[ls]==0)
        {
            col[ls]=col[rt];
            num[ls]+=num[rt];
        }
        else
        {
            if(ccol[L]!=col[rt])
                ccol[L]=col[rt],cnum[L]=num[rt];
            else
                cnum[L]+=num[rt];
            if(cnum[L]>num[ls])
            {
                num[ls]=cnum[L];
                col[ls]=col[rt];
            }
        }
    }
    else if(col[ls]==col[rt]||col[ls]==0)
    {
        col[ls]=col[rt];
        num[ls]+=num[rt];
    }
    else
    {
        if(num[ls]<num[rt]||ccl==col[rt])
        {
            PushDown(L,mid,ls);
            col[ls]=col[rt];
            num[ls]=num[rt];
        }
    }
    if(mid+1==R)
    {
        if(col[rs]==col[rt]||col[rs]==0)
        {
            col[rs]=col[rt];
            num[rs]+=num[rt];
        }
        else
        {
            if(ccol[R]!=col[rt])
                ccol[R]=col[rt],cnum[R]=num[rt];
            else
                cnum[R]+=num[rt];
            if(cnum[R]>num[rs])
            {
                num[rs]=cnum[R];
                col[rs]=col[rt];
            }
        }
    }
    else if(col[rs]==col[rt]||col[rs]==0)
    {
        col[rs]=col[rt];
        num[rs]+=num[rt];
    }
    else
    {
        if(num[rs]<num[rt]||ccl==col[rt])
        {
            PushDown(mid+1,R,rs);
            col[rs]=col[rt];
            num[rs]=num[rt];
        }
    }
    //printf("push %d->%d col %d num %d\n",L,mid,col[ls],num[ls]);
    //printf("push %d->%d col %d num %d\n",mid+1,R,col[rs],num[rs]);
    col[rt]=num[rt]=0;
}
void update(int L,int R,int rt,int l,int r,int c)
{
    if(l<=L&&R<=r)
    {
        if(c==col[rt]||col[rt]==0)
        {
            col[rt]=c;
            num[rt]++;
            //printf("X %d->%d col %d num %d\n",L,R,col[rt],num[rt]);
            return;
        }
        if(L!=R)
        {
            PushDown(L,R,rt);
            col[rt]=c;
            num[rt]=1;
        }
        else
        {
            if(ccol[L]!=c)
                ccol[L]=c,cnum[L]=1;
            else
                cnum[L]++;
            if(cnum[L]>num[rt])
            {
                num[rt]=cnum[L];
                col[rt]=c;
            }
        }
        //printf("X %d->%d col %d num %d\n",L,R,col[rt],num[rt]);
        return;
    }
    int ls=rt<<1,rs=ls|1,mid=(L+R)>>1;
    if(col[rt]!=0)
        PushDown(L,R,rt);
    if(l<=mid)
        update(lson,l,r,c);
    if(r>mid)
        update(rson,l,r,c);
    //printf("X %d->%d col %d num %d\n",L,R,col[rt],num[rt]);
}
void qu(int L,int R,int rt)
{
    if(L==R)
    {
        if(cnum[L]>num[rt])
            col[rt]=ccol[L];
        ans[rd[L]]=col[rt];
        return;
    }
    int ls=rt<<1,rs=ls|1,mid=(L+R)>>1;
    if(col[rt]!=0)
        PushDown(L,R,rt);
    qu(lson);
    qu(rson);
}
void dfs(int u)
{
    int v,ms=0;
    sz[u]=1,son[u]=-1;
    for(node *p=head[u];p!=NULL;p=p->next)
    {
        v=p->v;
        if(v==fa[u])
            continue;
        dep[v]=dep[u]+1;
        fa[v]=u;
        dfs(v);
        if(sz[v]>ms)
            ms=sz[v],son[u]=v;
        sz[u]+=sz[v];
    }
}
void getid(int u,int ft)
{
    id[u]=++ptr,top[u]=ft,rd[ptr]=u;
    if(son[u]!=-1)
        getid(son[u],top[u]);
    for(node *p=head[u];p!=NULL;p=p->next)
    {
        if(p->v==son[u]||p->v==fa[u])
            continue;
        getid(p->v,p->v);
    }
}
void init(int rt)
{
    fa[rt]=-1;
    dep[rt]=ptr=0;
    dfs(rt);
    getid(rt,rt);
}
void uppath(int u,int v,int d)
{
    //printf("u %d v %d c %d\n",u,v,d);
    int f1=top[u],f2=top[v];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
            swap(f1,f2),swap(u,v);
        //printf("%d->%d\n",id[f1],id[u]);
        update(1,ptr,1,id[f1],id[u],d);
        u=fa[f1],f1=top[u];
    }
    if(dep[u]>dep[v])
        swap(u,v);
    //printf("%d->%d\n",id[u],id[v]);
    update(1,ptr,1,id[u],id[v],d);
}
int main()
{
    int n,m,i,rt,u,v;

    //freopen("in.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
    while(scanf("%d%d",&n,&m),n||m)
    {
        cnt=0;
        memset(head,0,sizeof head);
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            adde(u,v);
            adde(v,u);
        }
        rt=(n+1)/2;
        init(rt);
        build(1,ptr,1);
        for(i=0;i<m;i++)
            scanf("%d%d%d",&qq[i].u,&qq[i].v,&qq[i].cc);
        sort(qq,qq+m,cmp);
        //for(i=1;i<=n;i++)
            //printf("i %d id %d\n",i,id[i]);
        for(i=0;i<m;i++)
        {
            ccl=qq[i].cc;
            uppath(qq[i].u,qq[i].v,qq[i].cc);
        }
        ccl=-1;
        qu(1,ptr,1);
        for(i=1;i<=n;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}