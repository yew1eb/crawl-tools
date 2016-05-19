#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <stdio.h>
#include <time.h>
using namespace std;
#define LL __int64
#define pi acos(-1.0)
#pragma comment(linker, "/STACK:1024000000")
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double eqs=1e-9;
const int MAXN=100000+10;
int head[MAXN], cnt, root, min1, tot;
int siz[MAXN], vis[MAXN], d[MAXN], id[MAXN], ans[MAXN], dis[MAXN];
int color[MAXN];
struct node
{
        int v, w, next;
}edge[MAXN<<1];
void add(int u, int v, int w)
{
        edge[cnt].v=v;
        edge[cnt].w=w;
        edge[cnt].next=head[u];
        head[u]=cnt++;
}
struct N
{
        int dis, id;
}F[MAXN];
bool cmp(N x, N y)
{
        return x.dis<y.dis||(x.dis==y.dis&&x.id<y.id);
}
void init()
{
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(d,INF,sizeof(d));
        memset(id,0,sizeof(id));
        memset(ans,0,sizeof(ans));
        cnt=0;
}
void dfs1(int u, int fa)
{
        if(color[u]){
                id[u]=u;
                d[u]=0;
        }
        for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(v==fa) continue ;
                dfs1(v,u);
                if(d[u]>d[v]+edge[i].w){
                        d[u]=d[v]+edge[i].w;
                        id[u]=id[v];
                }
                else if(d[u]==d[v]+edge[i].w)
                        id[u]=min(id[u],id[v]);
        }
}
void dfs2(int u, int fa)
{
        for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(v==fa) continue ;
                if(d[v]>d[u]+edge[i].w){
                        d[v]=d[u]+edge[i].w;
                        id[v]=id[u];
                }
                else if(d[v]==d[u]+edge[i].w){
                        id[v]=min(id[v],id[u]);
                }
                dfs2(v,u);
        }
}
void getsize(int u, int fa)
{
        siz[u]=1;
        for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(v==fa||vis[v]) continue ;
                getsize(v,u);
                siz[u]+=siz[v];
        }
}
void getroot(int u, int fa, int s)
{
        int max1=0;
        for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(v==fa||vis[v]) continue ;
                getroot(v,u,s);
                max1=max(max1,siz[v]);
        }
        max1=max(max1,s-siz[u]);
        if(min1>max1){
                min1=max1;
                root=u;
        }
}
void getdis(int u, int fa, int l)
{
        dis[u]=l;
        F[tot].dis=d[u]-l;
        F[tot++].id=id[u];
        for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(v==fa||vis[v]) continue ;
                getdis(v,u,l+edge[i].w);
        }
}
int BS(int l, int u)
{
        int low=0, high=tot-1, mid, ans=-1;
        while(low<=high){
                mid=low+high>>1;
                if(F[mid].dis<l||(F[mid].dis==l&&F[mid].id<=u)){
                        low=mid+1;
                        ans=mid;
                }
                else high=mid-1;
        }
        return ans+1;
}
void getans(int u, int fa, int f, int s)
{
        int tmp=BS(dis[u],u);
        ans[u]+=f*(s-tmp);
        for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(v==fa||vis[v]) continue ;
                getans(v,u,f,s);
        }
}
void Cal(int u, int l, int f)
{
        tot=0;
        getdis(u,-1,l);
        sort(F,F+tot,cmp);
        getans(u,-1,f,siz[u]);
}
void work(int u)
{
        vis[u]=1;
        getsize(u,-1);
        Cal(u,0,1);
        for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(vis[v]) continue ;
                Cal(v,edge[i].w,-1);
                min1=INF;
                getroot(v,u,siz[v]);
                work(root);
        }
}
int main()
{
        int n, u, v, w, i, res;
        while(scanf("%d",&n)!=EOF){
                init();
                for(i=1;i<n;i++){
                        scanf("%d%d%d",&u,&v,&w);
                        add(u,v,w);
                        add(v,u,w);
                }
                for(i=1;i<=n;i++){
                        scanf("%d",&color[i]);
                }
                dfs1(1,-1);
                dfs2(1,-1);
                min1=INF;
                getsize(1,-1);
                getroot(1,-1,n);
                work(root);
                res=0;
                for(i=1;i<=n;i++){
                        if(color[i]) continue ;
                        res=max(res,ans[i]);
                }
                printf("%d\n",res);
        }
        return 0;
}
