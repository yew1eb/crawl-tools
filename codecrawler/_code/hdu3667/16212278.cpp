#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define MAXN 1005
#define LL long long
#define INF 0x3f7f7f7f
const double eps = 1e-10;
struct Edge
{
    int from,to,cap,flow,cost;
    Edge(int from=0,int to=0,int cap=0,int flow=0,int cost=0)
    {
        this->from=from;
        this->to=to;
        this->cap=cap;
        this->flow=flow;
        this->cost=cost;
    }
};
vector<Edge>edges;
vector<int>g[MAXN];
bool vis[MAXN];
int dis[MAXN];
int pre[MAXN];
int a[MAXN];
int s,t;
void init()
{
    for(int i=0;i<MAXN;i++)
    {
        g[i].clear();
    }
    edges.clear();
}
void add(int from,int to,int cap,int cost)
{
    edges.push_back(Edge(from,to,cap,0,cost));
    edges.push_back(Edge(to,from,0,0,-cost));
    int m=edges.size();
    g[from].push_back(m-2);
    g[to].push_back(m-1);
}
bool spfa(int &flow,int &cost)
{
    int i;
    for(i=0;i<MAXN;i++)
        dis[i]=INF;
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(s);
    dis[s]=0;
    vis[s]=1;
    pre[s]=0;
    a[s]=INF;
   while(!q.empty())
   {
       int u=q.front();
       q.pop();
       vis[u]=0;
       int sz=g[u].size();
       for(i=0;i<sz;i++)
       {
           Edge &e=edges[g[u][i]];
           if(e.cap>e.flow&&dis[e.to]>dis[u]+e.cost)
           {
               dis[e.to]=dis[u]+e.cost;
               pre[e.to]=g[u][i];
               a[e.to]=min(a[u],e.cap-e.flow);
               if(!vis[e.to])
               {
                   vis[e.to]=1;
                   q.push(e.to);
               }
           }
       }
   }
   if(dis[t]==INF)
    return false;
   flow+=a[t];
   cost+=dis[t]*a[t];
   int v=t;
   while(v!=s)
   {
       edges[pre[v]].flow+=a[t];
       edges[pre[v]^1].flow-=a[t];
       v=edges[pre[v]].from;
   }
   return true;
}
int n,m,k;
void minCost()
{
    int flow=0,cost=0;
    while(spfa(flow,cost));
    //cout<<flow<<" "<<cost<<endl;
    if(flow!=k)
    {
        puts("-1");return;
    }
    else printf("%d\n",cost);
}

int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        init();
        s=0,t=n;
        add(0,1,k,0);
        for(i=1;i<=m;i++)
        {
            int u,v,ai,c;
            scanf("%d%d%d%d",&u,&v,&ai,&c);
            for(j=0;j<c;j++)
                add(u,v,1,(2*j+1)*ai);
        }
        minCost();

    }
    return 0;
}
