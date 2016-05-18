#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define FF(i, a, b) for(int i=a; i<b; i++)
#define FD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0; i<n; i++)
#define CLR(a, b) memset(a, b, sizeof(a))
#define debug puts("**debug**")
#define LL long long
#define PB push_back
using namespace std;

const int maxn = 1010;
int n, m, val[maxn], dp[maxn][101];
int Q, C, S, E;
struct Node
{
    int u, cost, res;//当前节点，花费，剩余油量
    bool operator < (const Node rhs) const
    {
        return cost > rhs.cost;
    }
};
struct Edge
{
    int to, dist;
};
vector<Edge> edges;
vector<int> G[maxn];

inline void init()
{
    REP(i, n) G[i].clear(); edges.clear();
}

void add(int a, int b, int c)
{
    edges.PB((Edge){b, c});
    edges.PB((Edge){a, c});
    int nc = edges.size();
    G[a].PB(nc-2); G[b].PB(nc-1);
}

void bfs()
{
    REP(i, n) REP(j, C+1) dp[i][j] = 0;
    priority_queue<Node> q; q.push((Node){S, 0, 0});
    while(!q.empty())
    {
        Node x = q.top(); q.pop();
        int u = x.u, cost = x.cost, res = x.res, nc = G[x.u].size();
        if(u == E)
        {
            printf("%d\n", cost);
            return ;
        }
        //考虑当前状态，再多加一点油是否会是更优解
        if(res<C && (dp[u][res+1]==0 || dp[u][res+1]>cost+val[u]))
            dp[u][res+1] = cost+val[u],q.push((Node){u,dp[u][res+1],res+1});

        REP(i, nc)
        {
            int v = edges[G[u][i]].to, dist = edges[G[u][i]].dist;
            if(res < dist) continue; //如果油量不够走到下一个节点就continue
            //如果靠当前油量走到下一个节点会是更优解
            if(dp[v][res-dist] == 0 || dp[v][res-dist] > cost)
                dp[v][res-dist] = cost, q.push((Node){v, cost, res-dist});
        }
    }
    puts("impossible");
    return ;
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        init();
        REP(i, n) scanf("%d", &val[i]);
        int a, b, c;
        REP(i, m)
        {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        scanf("%d", &Q);
        while(Q--)
        {
            scanf("%d%d%d", &C, &S, &E);
            bfs();
        }
    }
    return 0;
}