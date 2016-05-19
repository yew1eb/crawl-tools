//author: CHC
//First Edit Time:  2015-08-27 17:33
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long LL;
const int MAXN=1e+4;
const int MAXM=1e+6 * 2 + 10;
const int INF = numeric_limits<int>::max();
const LL LL_INF= numeric_limits<LL>::max();
int T,N,h[MAXN],d[MAXN],a[MAXN];
int cmp(int x,int y){
    if(h[x]!=h[y])return h[x]>h[y];
    return d[x]<d[y];
}
struct Edge
{
    int from,to,ci,cost,next;
    Edge(){}
    Edge(int _from,int _to,int _ci,int _cost,int _next):from(_from),to(_to),ci(_ci),cost(_cost),next(_next){}
}e[MAXM];
int head[MAXN],tot;
int q[MAXM];
int dis[MAXN],pre[MAXN],rec[MAXN],vis[MAXN];
inline void init(){
    memset(head,-1,sizeof(head));
    tot=0;
}
inline void AddEdge1(int u,int v,int ci,int cost){
    e[tot]=Edge(u,v,ci,cost,head[u]);
    head[u]=tot++;
    e[tot]=Edge(v,u,0,-cost,head[v]);
    head[v]=tot++;
    //while(tot>MAXM)puts("fuck");
}
inline bool spfa(int S,int T,LL &cost,LL &flow){
    int i;
    for(i=0;i<MAXN;i++){
        dis[i]=INF;
        vis[i]=false;
        pre[i]=-1;
    }
    int top=0;
    q[top++]=S;
    dis[S]=0;
    vis[S]=true;
    while(top>0){
        int u=q[--top];
        //printf("u:%d\n",u);
        vis[u]=false;
        for(i=head[u];~i;i=e[i].next){
            int v=e[i].to;
            if(e[i].ci>0&&dis[v]>dis[u]+e[i].cost){
                dis[v]=dis[u]+e[i].cost;
                pre[v]=i;
                //rec[v]=i;
                if(!vis[v]){
                    vis[v]=true;
                    q[top++]=v;
                }
            }
        }
    }
    if(dis[T]==INF)return false;
    int minn=INF;
    int k;
    for(i=T;i!=S;i=e[k^1].to){
        k=pre[i];
        //printf("%d\n",i);
        if(e[k].ci<minn)
            minn=e[k].ci;
    }
    for(i=T;i!=S;i=e[k^1].to){
        k=pre[i];
        //printf("%d ",i>>1);
        //cost+=minn*e[rec[i]].cost;
        e[k].ci-=minn;
        e[k^1].ci+=minn;
    }
    //puts("");
    //printf("%d %d\n",dis[T],minn);
    cost+=dis[T]*minn;
    flow+=minn;
    return true;
}
inline void mincostmaxflow(int S,int T,LL &cost,LL &flow){
    while(spfa(S,T,cost,flow));
}
int res[MAXN*2];
int main()
{
    //int cas=0;
    //freopen("1001.in","r",stdin);
    //freopen("10011.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        res[0]=0;
        for(int i=1;i<=N;i++){
            a[i]=i;
            scanf("%d%d",&h[i],&d[i]);
            res[++res[0]]=d[i];
        }
        sort(a+1,a+1+N,cmp);
        sort(res+1,res+1+res[0]);
        res[0]=unique(res+1,res+1+res[0])-res-1;
        //printf("res0:%d\n",res[0]);
        init();
        int st=0,et=1,sst=N*2+2;
        for(int i=1;i<=N;i++){
            AddEdge1(st,i<<1,1,0);
            AddEdge1(i<<1,i<<1|1,1,-1);
            AddEdge1(i<<1,i<<1|1,1,0);
            AddEdge1(i<<1|1,et,1,0);
            int x=INF;
            for(int j=i+1;j<=N;j++)
                if(d[a[i]]<=d[a[j]]&&d[a[j]]<x)
                    AddEdge1(i<<1|1,j<<1,2,0),x=d[a[j]];
        }
        AddEdge1(sst,st,2,0);
        LL flow=0,cost=0;
        mincostmaxflow(sst,et,cost,flow);
        //printf("%d\n",++cas);
        printf("%I64d\n",-cost);
    }
    return 0;
}

