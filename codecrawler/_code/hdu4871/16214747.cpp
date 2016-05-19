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
const int mod=1e6+3;
const int INF=0x3f3f3f3f;
const double eqs=1e-9;
const int MAXN=30000+10;
vector<pair<int,int> >G[MAXN];
int head[MAXN], cnt, root, k, min1, ff, ansdep, Maxdep;
LL ansnum;
int d[MAXN], vis[MAXN], siz[MAXN];
int dep[MAXN], flag[MAXN], Max[MAXN];
LL dp[MAXN], Maxcnt[MAXN];
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
void spfa()
{
        queue<int>q;
        q.push(1);
        memset(vis,0,sizeof(vis));
        memset(d,INF,sizeof(d));
        d[1]=0;
        vis[1]=1;
        while(!q.empty()){
                int u=q.front();
                q.pop();
                vis[u]=0;
                for(int i=0;i<G[u].size();i++){
                        int v=G[u][i].first;
                        if(d[v]>d[u]+G[u][i].second){
                                d[v]=d[u]+G[u][i].second;
                                if(!vis[v]){
                                        vis[v]=1;
                                        q.push(v);
                                }
                        }
                }
        }
}
void dfs(int u)
{
        vis[u]=1;
        for(int i=0;i<G[u].size();i++){
                int v=G[u][i].first;
                if(vis[v]) continue ;
                if(d[v]==d[u]+G[u][i].second){
                        add(u,v,G[u][i].second);
                        add(v,u,G[u][i].second);
                        //printf("%d %d\n",u,v);
                        dfs(v);
                }
        }
}
void build_tree(int n)
{
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
                sort(G[i].begin(),G[i].end());
        }
        dfs(1);
}
void init(int n)
{
        for(int i=1;i<=n;i++){
                G[i].clear();
        }
        memset(head,-1,sizeof(head));
        cnt=0;
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
void getMaxdep(int depp, int u, int fa)
{
        Maxdep=max(Maxdep,depp);
        for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(v==fa||vis[v]) continue ;
                getMaxdep(depp+1,v,u);
        }
}
void getdep(int depp, int len, int u, int fa)
{
        if(dep[depp]<len){
                dep[depp]=len;
                dp[depp]=1;
        }
        else if(dep[depp]==len) dp[depp]++;
        if(depp>=k) return ;
        for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(v==fa||vis[v]) continue ;
                getdep(depp+1,len+edge[i].w,v,u);
        }
}
void work(int u)
{
        vis[u]=1;
        int i, j, tmp;
        for(i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(vis[v]) continue ;
                min1=INF;
                getsize(v,-1);
                getroot(v,-1,siz[v]);
                work(root);
        }
        ff++;
        flag[0]=ff;
        dep[0]=0;
        dp[0]=1;
        Maxcnt[0]=1;
        Max[0]=0;
        for(i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(vis[v]) continue ;
                Maxdep=-1;
                getMaxdep(1,v,u);
                for(j=0;j<=Maxdep&&j<=k;j++) dep[j]=-1;
                getdep(1,edge[i].w,v,u);
                for(j=0;j<=Maxdep&&j<k;j++){
                        tmp=k-j-1;
                        if(flag[tmp]!=ff) continue ;
                        if(ansdep<Max[tmp]+dep[j]){
                                ansdep=Max[tmp]+dep[j];
                                ansnum=Maxcnt[tmp]*dp[j];
                        }
                        else if(ansdep==Max[tmp]+dep[j]){
                                ansnum+=Maxcnt[tmp]*dp[j];
                        }
                }
                for(j=1;j<=Maxdep&&j<k;j++){
                        if(flag[j]!=ff||Max[j]<dep[j]){
                                Max[j]=dep[j];
                                Maxcnt[j]=dp[j];
                                flag[j]=ff;
                        }
                        else if(flag[j]==ff&&Max[j]==dep[j]){
                                Maxcnt[j]+=dp[j];
                        }
                }
        }
        vis[u]=0;
}
int main()
{
        int t, n, m, i, u, v, w;
        scanf("%d",&t);
        while(t--){
                scanf("%d%d%d",&n,&m,&k);
                init(n);
                while(m--){
                        scanf("%d%d%d",&u,&v,&w);
                        G[u].push_back(make_pair(v,w));
                        G[v].push_back(make_pair(u,w));
                }
                spfa();
                build_tree(n);
                memset(vis,0,sizeof(vis));
                memset(flag,-1,sizeof(flag));
                ff=0;
                ansdep=0;
                min1=INF;
                getsize(1,-1);
                getroot(1,-1,n);
                work(root);
                printf("%d %I64d\n",ansdep,ansnum);
        }
        return 0;
}
