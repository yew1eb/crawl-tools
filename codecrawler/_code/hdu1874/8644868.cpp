#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define N 205
#define INF 0x7f7f7f7f
using namespace std;
struct Edge
{
    int from, to , dist;
};
struct HeapNode
{
    int d, u;
    bool operator< (const HeapNode& rhs) const
    {
        return d >rhs.d;
    }
};

struct Dijkstra
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[N];
    bool done[N];
    int d[N];
    int p[N];
    void init(int n)
    {
        this->n = n;
        for(int i=0; i<n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int dist)
    {
        edges.push_back((Edge){from, to, dist});
        m = edges.size();
        G[from].push_back(m-1);
    }

    void dijksra(int s)
    {
        priority_queue<HeapNode> Q;
        for(int i=0; i<n; i++) d[i] = INF;
        d[s] = 0;
        memset(done, 0 , sizeof(done));
        Q.push((HeapNode){0,s});
        while(!Q.empty())
        {
            HeapNode x = Q.top(); Q.pop();
            int u = x.u;
            if(done[u]) continue;
            done[u] = true;
            for(int i=0; i<G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if(d[e.to] > d[u]+e.dist)
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    Q.push((HeapNode){d[e.to], e.to});
            }
        }
    }

};

Dijkstra answer;

int main()
{
    int n, m;
    int s, e, a, b, len, i;
    while(~scanf("%d%d",&n,&m))
    {
        answer.init(n);
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&len);
            answer.AddEdge(a,b,len);
            answer.AddEdge(b,a,len);
        }
        scanf("%d%d",&s,&e);
        answer.dijksra(s);
        if(answer.d[e]>=INF) printf("-1\n");
        else printf("%d\n",answer.d[e]);
    }
    return 0;
}













