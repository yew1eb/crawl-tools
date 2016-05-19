#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1005;
const int INF = 1e9;


int g[maxn][maxn], d[maxn], pre[maxn];
bool vis[maxn];
int n, m;

void init()
{
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            g[i][j] = INF;
            if(i==j) g[i][j] = 0;
        }
    }
    int u, v, w;
    for(int i=1; i<=m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        if(w<g[u][v]) {
            g[u][v] = g[v][u] = w;
        }
    }
}

int dijkstra()
{
    for(int i=1; i<=n; ++i) d[i] = INF;
    memset(pre, -1, sizeof pre );
    memset(vis, 0, sizeof vis );
    d[1] = 0;
    for(int i=1; i<=n; ++i) {
        int k = -1;
        for(int j=1; j<=n; ++j)
            if(!vis[j] &&(k==-1||d[j]<d[k])) {
                k = j;
            }
        if(-1==k) break;
        vis[k] = 1;
        for(int j=1; j<=n; ++j) if(!vis[j]&&d[j]>d[k]+g[k][j]){
            d[j] = d[k] + g[k][j];
            pre[j] = k;
        }
    }
    return d[n];
}
void solve()
{
    int ans = dijkstra();
    int u = n, v;
    while(~pre[u]) {
        v = pre[u];
        int tmp = g[u][v];
        g[u][v] = g[v][u] = INF;
        int res = dijkstra();
        ans = max(ans, res);
        g[u][v] = g[v][u] = tmp;
        u = v;
    }
    printf("%d\n", ans);
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.cpp", "r", stdin);
    freopen("out.cpp", "w", stdout);
#endif
    while(~scanf("%d%d", &n, &m)) {
        init();
        solve();
    }
    return 0;
}



















