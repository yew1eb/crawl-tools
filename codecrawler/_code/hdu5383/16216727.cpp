//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define LL long long
#define MP make_pair
#define INF 0x3f3f3f3f
#define xx first
#define yy second
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1|1
#define CLR(a, b) memset(a, b, sizeof(a))
using namespace std;

const int maxn = 333;

struct Edge
{
    int from, to, cap, flow, cost;
    Edge() {}
    Edge(int a, int b, int c, int d, int e):from(a),  to(b), cap(c), flow(d), cost(e) {}
};
struct MCMF
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];         // æ¯å¦å¨éåä¸­
    int d[maxn];           // Bellman-Ford
    int p[maxn];           // ä¸ä¸æ¡å¼§
    int a[maxn];           // å¯æ¹è¿é

    void init(int n)
    {
        this->n = n;
        for(int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap, int cost)
    {
        Edge e1 = Edge(from, to, cap, 0, cost), e2 = Edge(to, from, 0, 0, -cost);
        edges.push_back(e1);
        edges.push_back(e2);
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool spfa(int s, int t, int &flow, int &cost)
    {
        for(int i = 0; i < n; i ++) d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            inq[u] = 0;
            for(int i = 0; i < G[u].size(); i ++)
            {
                Edge& e = edges[G[u][i]];
                if(e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if(!inq[e.to])
                    {
                        Q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if(d[t] == INF)    return false;
        if(d[t] > 0) return false;///è´¹ç¨åå¤§ï¼åæ­¢å¢å¹¿
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while(u != s)
        {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    // éè¦ä¿è¯åå§ç½ç»ä¸­æ²¡æè´æå
    int Mincost(int s, int t)
    {
        int flow = 0, cost = 0;
        while(spfa(s, t, flow, cost));
        return cost;
    }
} sol;
vector<int> A, B;
int val[maxn][maxn];
int atk[maxn], lvl[maxn];

int cas = 1;

int tmd[maxn];

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    A.clear();
    B.clear();
    sol.init(n + 2);
    int s = 0, t = n + 1;
    int tot = 0;
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d%d%d", &tmd[i], &lvl[i], &atk[i]);
        tot += atk[i];
        if(!tmd[i])
        {
            A.push_back(i);
            sol.AddEdge(s, i, 1, 0);
        }
        else
        {
            B.push_back(i);
            sol.AddEdge(i, t, 1, 0);
        }
    }
    CLR(val, 0);
    for(int i = 1; i <= m; i ++)
    {
        int l, a, r;
        scanf("%d%d%d", &l, &a, &r);
        if(r == 0)
        {
            for(int j = 0; j < A.size(); j ++)
            {
                for(int k = 0; k < B.size(); k ++)
                {
                    int x = A[j], y = B[k];
                    if(lvl[x] + lvl[y] == l)
                    {
                        val[x][y] = max(val[x][y], a - atk[x] - atk[y]);
                    }
                }
            }
        }
        else if(r == 1)
        {
            int b;
            scanf("%d", &b);
            if(tmd[b])
            {
                for(int j = 0; j < A.size(); j ++)
                {
                    int x = A[j], y = b;
                    if(lvl[x] + lvl[y] == l)
                    {
                        val[x][y] = max(val[x][y], a - atk[x] - atk[y]);
                    }
                }
            }
            else
            {
                for(int k = 0; k < B.size(); k ++)
                {
                    int x = b, y = B[k];
                    if(lvl[x] + lvl[y] == l)
                    {
                        val[x][y] = max(val[x][y], a - atk[x] - atk[y]);
                    }
                }
            }
        }
        else
        {
            int b, c;
            scanf("%d%d", &b, &c);
            if(tmd[b]) swap(b, c);
            val[b][c] = max(val[b][c], a - atk[b] - atk[c]);
        }
    }
    for(int i = 0; i < A.size(); i ++)
    {
        for(int j = 0; j < B.size(); j ++)
        {
            int x = A[i], y = B[j];
            if(val[x][y])
                sol.AddEdge(x, y, 1,  - val[x][y]);
        }
    }
    int cc = sol.Mincost(s, t);
    printf("%d\n", tot - cc);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}
