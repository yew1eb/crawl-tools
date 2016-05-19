#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100010
#define inf 0x7fffffff

bool y[N];
int n, s, t, ds[N], dt[N], ms[N], mt[N], len, id, ans;
struct node {
    int v, w, id;
    node() {}
    node(int _v, int _w, int _id) : v(_v), w(_w), id(_id) {}
};
vector<node> g[N];
void dfs(int now, int fa) {
    int u;
    for (int i=0; i<g[now].size(); i++)
        if ((u = g[now][i].v) != fa) {
            ds[u] = ds[now] + 1;
            dfs(u, now);
        }
}
void dfs2(int now, int fa) {
    int u;
    for (int i=0; i<g[now].size(); i++)
        if ((u = g[now][i].v) != fa) {
            dt[u] = dt[now] + 1;
            dfs2(u, now);
        }
}
void d1(int now, int fa) {
    int u;
    mt[now] = dt[now];
    for (int i=0; i<g[now].size(); i++)
        if ((u = g[now][i].v) != fa) {
            d1(u, now);
            mt[now] = max(mt[now], mt[u]);
        }
}
void d2(int now, int fa) {
    int u;
    ms[now] = ds[now];
    for (int i=0; i<g[now].size(); i++)
        if ((u = g[now][i].v) != fa) {
            d2(u, now);
            ms[now] = max(ms[now], ms[u]);
        }
}
void work(int now, int fa) {
    int u, w;
    for (int i=0; i<g[now].size(); i++)
        if ((u = g[now][i].v) != fa) {
            if (ds[now] + 1 + dt[u] == len)
                w = g[now][i].w * max(ms[now], mt[u]);
            else w = g[now][i].w * len;

            if (w < ans) { ans = w, id = g[now][i].id; }
            else if (w == ans && g[now][i].id < id)
                id = g[now][i].id;
            work(u, now);
        }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int size = 20 << 20; // 20MB
    char *p = (char*)malloc(size) + size;
    __asm__("movl %0, %%esp\n" :: "r"(p));

    int T;
    scanf("%d", &T);
    for (int cas=1; cas<=T; cas++) {
        scanf("%d", &n);
        for (int i=0; i<=n; i++) {
            g[i].clear();
            y[i] = false;
        }
        for (int i=1, a, b, c; i<n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            g[a].push_back(node(b, c, i));
            g[b].push_back(node(a, c, i));
        }
        ds[1] = 0;
        dfs(1, 0);
        ds[s=0] = 0; for (int i=1; i<=n; i++) if (ds[i] > ds[s]) s = i;

        ds[s] = 0; dfs(s, 0);
        t = 0; for (int i=1; i<=n; i++) if (ds[i] > ds[t]) t = i;
        len = ds[t];

        dt[t] = 0;
        dfs2(t, 0);

        d1(s, 0); d2(t, 0);

        id = ans = inf;
        work(s, 0);
        printf("Case #%d: %d\n", cas, id);
    }
    return 0;
}
