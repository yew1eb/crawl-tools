#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int N, Q, E, V[maxn], first[maxn], jump[maxn * 2], link[maxn * 2];
int id, idx[maxn], top[maxn], far[maxn], son[maxn], dep[maxn], cnt[maxn];

inline void add_Edge (int u, int v) {
    link[E] = v;
    jump[E] = first[u];
    first[u] = E++;
}

inline void dfs (int u, int pre, int d) {
    far[u] = pre;
    son[u] = 0;
    dep[u] = d;
    cnt[u] = 1;

    for (int i = first[u]; i + 1; i = jump[i]) {
        int v = link[i];
        if (v == pre) 
            continue;
        dfs(v, u, d + 1);
        cnt[u] += cnt[v];
        if (cnt[son[u]] < cnt[v])
            son[u] = v;
    }
}

inline void dfs (int u, int rot) {
    idx[u] = ++id;
    top[u] = rot;

    if(son[u])
        dfs(son[u], rot);

    for (int i = first[u]; i + 1; i = jump[i]) {
        int v = link[i];
        if (v == far[u] || v == son[u]) 
            continue;
        dfs(v, v);
    }
}

inline int LCA (int u, int v) {
    int p = top[u], q = top[v];
    while (p != q) {
        if (dep[p] < dep[q]) {
            swap(p, q);
            swap(u, v);
        }

        u = far[p];
        p = top[u];
    }
    return dep[u] > dep[v] ? v : u;
}

void init() {
    E = id = 0;
    memset(first, -1, sizeof(first));
    for (int i = 1; i <= N; i++)
        scanf("%d", &V[i]);

    int u, v;
    for (int i = 1; i < N; i++) {
        scanf("%d%d", &u, &v);
        add_Edge(u, v);
        add_Edge(v, u);
    }
    dfs(1, 0, 0);
    dfs(1, 1);
}

struct node {
    int g[2], c;
}nd[maxn * 20];
int sz, root[maxn];

int insert (int r, int w) {
    int ret, x;
    ret = x = sz++;
    nd[x] = nd[r];

    for (int i = 15; i >= 0; i--) {
        int v = (w>>i)&1;
        int t = sz++;
        nd[t] = nd[nd[x].g[v]];
        nd[t].c++;
        nd[x].g[v] = t;
        x = t;
    }
    return ret;
}

void dfs(int u) {
    root[u] = insert(root[far[u]], V[u]);

    for (int i = first[u]; i + 1; i = jump[i]) {
        int v = link[i];
        if (v == far[u]) 
            continue;
        dfs(v);
    }
}

void Tire_init() {
    sz = 1;
    root[0] = nd[0].c = 0;
    memset(nd[0].g, 0, sizeof(nd[0].g));
    dfs(1);
}

int query(int x, int y, int z, int w) {
    int ans = V[z] ^ w, ret = 0;
    z = root[z];
    for (int i = 15; i >= 0; i--) {
        int v = ((w>>i)&1) ^ 1;
        int cnt = nd[nd[x].g[v]].c + nd[nd[y].g[v]].c - 2 * nd[nd[z].g[v]].c;

        if (cnt)
            ret |= (1<<i);
        else
            v = v^1;

        x = nd[x].g[v], y = nd[y].g[v], z = nd[z].g[v];
    }
    return max(ans, ret);
}

int main () {
    while (scanf("%d%d", &N, &Q) == 2) {
        init();
        Tire_init();

        int u, v, w;
        while (Q--) {
            scanf("%d%d%d", &u, &v, &w);
            printf("%d\n", query(root[u], root[v], LCA(u, v), w));
        }
    }
    return 0;
}