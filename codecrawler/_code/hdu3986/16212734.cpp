#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <ctime>
#include <cmath>
#include <cctype>
using namespace std;
#define maxn 200005
#define LL long long
int cas=0,T;
int n,S,E;
const int INF = 0x3f3f3f3f  ;
struct Edge
{
    int from,to,dist;
    Edge(){}
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
struct HeapNode
{
    int d,u;
    bool operator < (const HeapNode &rhs)const
    {
        return d > rhs.d;
    }
};
vector<Edge>edges;
vector<int> G[maxn];
int d[maxn];
int vis[maxn];
int p[maxn];
void init()
{
    for (int i = 0;i<=n;i++)
       G[i].clear();
   edges.clear();
}

void AddEdge(int from,int to,int dist)
{
    edges.push_back(Edge(from,to,dist));
    int mm = edges.size();
    G[from].push_back(mm-1);
}
int dijkstra(int s)               //åæ°sè¡¨ç¤ºä¸èµ°è¿æ¡è¾¹
{
    priority_queue<HeapNode> q;
    for (int i = 1;i<=n;i++)
        d[i]=INF;
    d[1]=0;
    memset(vis,0,sizeof(vis));
    memset(p,0,sizeof(p));
    q.push((HeapNode){0,1});
    while (!q.empty())
    {
        HeapNode x = q.top();q.pop();
        int u = x.u;
        if (vis[u])continue;
        vis[u]=1;
        for (int i = 0;i<G[u].size();i++)
        {
            if (G[u][i]==s)
                continue;
            Edge &e = edges[G[u][i]];
            if (d[e.to] > d[u] + e.dist)
            {
                 d[e.to] = d[u] + e.dist;
                 p[e.to] = G[u][i];
                 q.push((HeapNode){d[e.to],e.to});
            }
        }
    }
    return d[n];
}
int m;
int main()
{
    //freopen("in","r",stdin);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        init();
        for (int i = 0;i<m;i++)
        {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            AddEdge(u,v,d);
            AddEdge(v,u,d);
        }
        if (dijkstra(-1) == INF)          //è¿æ²¡æå é¤è¾¹å°±å·²ç»èµ°ä¸éäº
        {
            printf("-1\n");
            continue;
        }
        vector<int >E;                    //ä¿å­è·¯å¾
        int ed = n;
        while (ed!=1)
        {
            int edge = p[ed];
            E.push_back(edge);
            ed = edges[edge].from;
        }
        int ans = -1;
        for (int i = 0;i<E.size();i++)       //æä¸¾å æçæ¯ä¸æ¡è¾¹æ±ä¸æ¬¡æç­è·¯
            ans = max(ans,dijkstra(E[i]));
        if (ans == INF)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    //printf("time=%.3lf",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
