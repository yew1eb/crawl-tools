#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define clr0(x) memset(x,0,sizeof(x))
#define clr1(x) memset(x,-1,sizeof(x))
#define eps 1e-9
const double pi = acos(-1.0);
typedef long long LL;
const int inf = 0x7fffffff;
const int maxn = 1005,maxm = 10005;
struct edge{
    int v,w,next;
    edge(){};
    edge(int vv,int ww,int nnext):v(vv),w(ww),next(nnext){};
}e[maxm<<1];
int head[maxn],p[maxn],ecnt,dp[maxn][105];//iåå¸j
bool vis[maxn][105];
int n,m,c,st,en;
void add(int u,int v,int w)
{
    e[ecnt] = edge(v,w,head[u]);
    head[u] = ecnt++;
    e[ecnt] = edge(u,w,head[v]);
    head[v] = ecnt++;
}
void init()
{
    clr1(head),ecnt = 0;
}
struct node{
    int u,cost,last;
    node(){};
    node(int uu,int cc,int tt):u(uu),cost(cc),last(tt){};
    bool operator < (const node &a)const{
        return a.cost < cost;
    }
};
void bfs()
{
    for(int i = 0;i < n;++i)
        for(int j = 0;j <= 100;++j)
            dp[i][j] = inf;
    clr0(vis);
    priority_queue<node> q;
    q.push(node(st,0,0));
    dp[st][0] = 0;
    while(!q.empty()){
        node cur = q.top();q.pop();
        int u = cur.u,cost = cur.cost,last = cur.last;
        if(u == en){
            printf("%d\n",cost);
            return ;
        }
        vis[u][last] = 1;
        if(last + 1 <= c && !vis[u][last + 1] && dp[u][last + 1] > dp[u][last]+p[u]){
            dp[u][last+1] = dp[u][last] + p[u];
            q.push(node(u,dp[u][last+1],last+1));
        }
        for(int i = head[u];i != -1;i = e[i].next){
            int v = e[i].v,w = e[i].w;
            if(last >= w && !vis[v][last - w] && dp[v][last - w] > cost){
                dp[v][last - w] = cost;
                q.push(node(v,cost,last - w));
            }
        }
    }
    puts("impossible");
}
int main()
{
    init();
    RD2(n,m);
    for(int i = 0;i < n;++i)
        RD(p[i]);
    int u,v,w,q;
    while(m--){
        RD3(u,v,w);
        add(u,v,w);
    }
    RD(q);
    while(q--){
        RD3(c,st,en);
        bfs();
    }
    return 0;
}
