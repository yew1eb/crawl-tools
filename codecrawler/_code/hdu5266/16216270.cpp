#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 311111
#define INF 0x3f3f3f3f
struct node
{
    int to,next;
}edge[2*maxn];
int deep[maxn],p[maxn][22],vis[maxn],head[maxn],tot;
int idx,a[maxn],smax[maxn][22],smin[maxn][22];
int n,q,Max,Min;
void ST()
{
    for(int i=0;i<n;i++)smax[i][0]=smin[i][0]=i;
    int k=(int)(log(1.0*n)/log(2.0));
    for(int j=1;j<=k;j++)   
        for(int i=0;i+(1<<j)<=n;i++)  
         {
            if(a[smax[i][j-1]]>a[smax[i+(1<<(j-1))][j-1]])smax[i][j]=smax[i][j-1];
            else smax[i][j]=smax[i+(1<<(j-1))][j-1];
            if(a[smin[i][j-1]]<a[smin[i+(1<<(j-1))][j-1]])smin[i][j]=smin[i][j-1];
            else smin[i][j]=smin[i+(1<<(j-1))][j-1];
         }
}
int query_max(int l,int r)  
{  
    int k=(int)(log(1.0*(r-l+1))/log(2.0));  
    if(a[smax[l][k]]<a[smax[r-(1<<k)+1][k]]) return smax[r-(1<<k)+1][k];
    return smax[l][k];
}
int query_min(int l,int r)  
{  
    int k=(int)(log(1.0*(r-l+1))/log(2.0));  
    if(a[smin[l][k]]>a[smin[r-(1<<k)+1][k]]) return smin[r-(1<<k)+1][k];
    return smin[l][k];
}
void init()
{
    tot=0;idx=1;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(deep,0,sizeof(deep));
    memset(p,-1,sizeof(p));
}
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void dfs(int u)
{
    vis[u]=1;
    a[u-1]=idx++;
    for(int i=head[u];~i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!vis[v])
        {
            p[v][0]=u;
            deep[v]=deep[u]+1;
            dfs(v);
        }
    }
}
void rmq(int n)
{
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++)
            if(~p[i][j-1])
                p[i][j]=p[p[i][j-1]][j-1];
}
int lca(int a,int b)
{
    int i,j;
    if(deep[a]<deep[b])swap(a,b);
    for(i=0;(1<<i)<=deep[a];i++);
    i--;
    for(j=i;j>=0;j--)
        if(deep[a]-(1<<j)>=deep[b])
            a=p[a][j];
    if(a==b)return a;
    for(j=i;j>=0;j--)
        if(p[a][j]!=-1&&p[a][j]!=p[b][j])
            a=p[a][j],b=p[b][j];
    return p[a][0];
}
int main()
{
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v),add(v,u);
        }
        dfs(1);
        rmq(n);
        ST();
        scanf("%d",&q);
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            l--,r--;
            int Max=query_max(l,r)+1,Min=query_min(l,r)+1;
            printf("%d\n",lca(Max,Min));
        }
    }
    return 0;
}