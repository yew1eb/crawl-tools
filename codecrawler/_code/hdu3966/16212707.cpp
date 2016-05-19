#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
const int N=51000;
int son[N],sz[N],dep[N],top[N],father[N],head[N],ti[N],num,idx,a[N];
struct edge
{
    int ed,next;
}e[N*4];
void addedge(int x,int y)
{
    e[num].ed=y;e[num].next=head[x];head[x]=num++;
    e[num].ed=x;e[num].next=head[y];head[y]=num++;
}
//*******************æ é¾åå**********************
void find_son(int u)
{
    int i,v;
    sz[u]=1;son[u]=0;
    for(i=head[u];i!=-1;i=e[i].next)
    {
        v=e[i].ed;
        if(v==father[u])continue;
        father[v]=u;dep[v]=dep[u]+1;
        find_son(v);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])son[u]=v;
    }
}
void find_time(int u,int fa)
{
    int i,v;
    ti[u]=idx++;    
    top[u]=fa;
    if(son[u]!=0)find_time(son[u],top[u]);
    for(i=head[u];i!=-1;i=e[i].next)
    {
        v=e[i].ed;
        if(v==son[u]||v==father[u])continue;
        find_time(v,v);
    }
}
//************************çº¿æ®µæ **************************
struct Tree
{
    int R,L,ct;//ct:è¯¥åºé´çå¢é
}T[N*4];
void buildTree(int L,int R,int id)
{
    T[id].L=L;T[id].R=R;T[id].ct=0;
    if(L==R) return ;        
    int mid=(L+R)>>1,li=id<<1,ri=li+1;
    buildTree(L,mid,li);
    buildTree(mid+1,R,ri);
}
void insert(int L,int R,int id,int w)
{
    if(T[id].L==L&&T[id].R==R)
    {
        T[id].ct+=w;
        return ;
    }
    int mid=(T[id].L+T[id].R)>>1,li=id<<1,ri=li+1;
    if(mid>=R)insert(L,R,li,w);
    else if(mid<L)insert(L,R,ri,w);
    else 
    {
        insert(L,mid,li,w);
        insert(mid+1,R,ri,w);
    }
}
int find(int i,int id,int w)
{
    if(T[id].L==T[id].R)
        return w+T[id].ct;
    int mid=(T[id].L+T[id].R)>>1,li=id<<1,ri=li+1;
    if(mid>=i)return find(i,li,w+T[id].ct);
    else return find(i,ri,w+T[id].ct);
}
void lca(int x,int y,int w)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        insert(ti[top[x]],ti[x],1,w);
        x=father[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    insert(ti[x],ti[y],1,w);
}
int main()
{
    int i,n,m,q,x,y,w;
    char str[10];
    while(scanf("%d%d%d",&n,&m,&q)!=-1)
    {
        memset(head,-1,sizeof(head));
        num=0;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y);
        }
        father[1]=sz[0]=0;dep[1]=idx=1;
        find_son(1);
        find_time(1,1);
        buildTree(1,n,1);
        while(q--)
        {
            scanf("%s",str);
            if(str[0]=='Q')
            {
                scanf("%d",&x);
                printf("%d\n",a[x]+find(ti[x],1,0));
            }
            else
            {
                scanf("%d%d%d",&x,&y,&w);
                if(str[0]=='I')    w=-w;                
                lca(x,y,-w);
            }
        }
    }
    return 0;
}
