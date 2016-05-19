#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include<stdio.h>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;
const int mmax = 100010;
const int inf=0x3fffffff;
struct edge
{
    int st,en;
    int next;
}E[2*mmax];
int p[mmax],fa[mmax],son[mmax],top[mmax],ID[mmax];
int deep[mmax],id_[mmax];
bool vis[mmax];
int w[mmax];
int num;
void add(int st,int en)
{
    E[num].st=st;
    E[num].en=en;
    E[num].next=p[st];
    p[st]=num++;
}
void init()
{
    memset(p,-1,sizeof p);
    num=0;
}
struct tree
{
    int l,r;
    int sum;
    int mid()
    {
        return (l+r)>>1;
    }
}T[4*mmax];
void build(int id,int l,int r)
{
    T[id].l=l,T[id].r=r;
    if(l==r)
    {
        T[id].sum=w[ID[l]];
        return ;
    }
    int mid=T[id].mid();
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    T[id].sum=T[id<<1].sum^T[id<<1|1].sum;
}
void updata(int id,int pos,int val)
{
    if(T[id].l==T[id].r)
    {
        T[id].sum=val;
        return ;
    }
    int mid=T[id].mid();
    if(mid>=pos)
        updata(id<<1,pos,val);
    else
        updata(id<<1|1,pos,val);
    T[id].sum=T[id<<1].sum^T[id<<1|1].sum;
}
int query(int id,int l,int r)
{
    if(l<=T[id].l&&T[id].r<=r)
        return T[id].sum;
    int mid=T[id].mid();
    int ans=0;
    if(mid>=l)
        ans^=query(id<<1,l,r);
    if(mid<r)
        ans^=query(id<<1|1,l,r);
    return ans;
}

int dfs(int u)
{
    vis[u]=1;
    int cnt=1,tmp=0,e=0;
    for(int i=p[u];i+1;i=E[i].next)
    {
        int v=E[i].en;
        if(!vis[v])
        {
            fa[v]=u;
            deep[v]=deep[u]+1;
            int tt=dfs(v);
            cnt+=tt;
            if(tmp<tt)
            {
                tmp=tt;
                e=v;
            }
        }
    }
    son[u]=e;
    return cnt;
}
int now_cnt;
void new_id(int u)
{
    ID[now_cnt]=u;
    id_[u]=now_cnt;
    now_cnt++;
    vis[u]=1;
    if(son[u])
    {
        top[son[u]]=top[u];
        new_id(son[u]);
    }
    for(int i=p[u];i+1;i=E[i].next)
    {
        int v=E[i].en;
        if(!vis[v])
            new_id(v);
    }
}
int solve(int x,int y)
{
    int ans=0;
    while(top[x]!=top[y])
    {
        if(deep[top[x]]<deep[top[y]])
            swap(x,y);
        ans^=query(1,id_[top[x]],id_[x]);
        x=fa[top[x]];
    }
    if(deep[x]>deep[y])
        swap(x,y);
    ans^=query(1,id_[x],id_[y]);
    return ans;
}


int main()
{
    int n,q;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        init();
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            add(u,v);
            add(v,u);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
            if(w[i]==0)
                w[i]=mmax;
        }
        fa[1]=1;
        deep[1]=0;
        memset(vis,0,sizeof vis);
        for(int i=1;i<=n;i++)
            top[i]=i;
        dfs(1);
        memset(vis,0,sizeof vis);
        now_cnt=1;
        new_id(1);
        build(1,1,n);
        while(q--)
        {
            int d,x,y;
            scanf("%d %d %d",&d,&x,&y);
            if(d==0)
            {
                if(y==0)
                    y=mmax;
                updata(1,id_[x],y);
            }
            else
            {
                if(x>y)
                    swap(x,y);
                int tmp=solve(x,y);
                if(tmp==0)
                    puts("-1");
                else
                {
                    if(tmp==mmax)
                        tmp=0;
                    printf("%d\n",tmp);
                }
            }
        }
    }

    return 0;
}