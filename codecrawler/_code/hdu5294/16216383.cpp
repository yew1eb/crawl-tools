#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
const int INF = 0x7f7f7f;
const int MAXM = 12e4+5;
const int MAXN = 2e3+5;

int n, m;
struct Edge {
    int to, w, next;
}edge[MAXM];
int tot, head[MAXN];
void addedge(int u, int v, int w)
{
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;

    edge[tot].to = u;
    edge[tot].w = w;
    edge[tot].next = head[v];
    head[v] = tot++;

}

int dis[MAXN], vis[MAXN];
int minb[MAXN];
int spfa(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(minb, 0x3f, sizeof(minb));

    queue<int> q;
    dis[s] = 0;
    minb[s] = 0;
    vis[s] = 1;
    q.push(s);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;

        for(int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to, w = edge[i].w;
            if(dis[v] == dis[u] + w) {
                minb[v] = min(minb[v], minb[u] + 1);
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                minb[v] = minb[u] + 1;
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
struct Eg {
    int u, cap, rev;
    Eg(int uu, int cc, int rr) {
        u = uu; cap = cc; rev = rr;
    }
};
vector<Eg> G[MAXN];
bool used[MAXN];
void add(int u, int v, int cap)
{
    G[u].push_back(Eg(v, cap, G[v].size()));
    G[v].push_back(Eg(u, 0, G[u].size()-1));
}
void build()
{
    for(int i = 1; i <= n; ++i) {
        for(int j = head[i]; ~j; j = edge[j].next) {
            int v = edge[j].to, w = edge[j].w;
            if(dis[v] - dis[i] == w) {
                add(i, v, 1);
            }
        }
    }
}
int dfs(int v, int t, int f)
{
    if(v == t) return f;
    used[v] = true;
    for(int i = 0; i < G[v].size(); ++i) {
        Eg &e = G[v][i];
        if(!used[e.u] && e.cap > 0) {
            int d = dfs(e.u, t, min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                G[e.u][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t)
{
    int flow = 0;
    while(1) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0) return flow;
        flow += f;
    }
}
void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
    for(int i = 0; i <= n; ++i) {
        G[i].clear();
    }

}
int main()
{
    //freopen("in", "r", stdin);
    while(~scanf("%d %d", &n, &m)) {
        init();
        for(int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
        }

        spfa(1);
        build();
        int ans = max_flow(1, n);

        printf("%d %d\n", ans, m-minb[n]);
    }
    return 0;
}
