#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100005
#define lc (tr[d].ls)
#define rc (tr[d].rs)

struct Tr{
    int sum, ls, rs, l, r;
    bool lz;
}tr[N<<4];

int ca = 0, weight[N], light[N], tid[N], dep[N], fa[N];
int sun[N], pathf[N], flag[N] = {0}, tot;
bool col[N];
int isbuild[N] = {0};
vector<int>V[N];

inline void Push(int d) {
    tr[d].sum = tr[lc].sum+tr[rc].sum;
}

inline void resum(int d) {
    tr[d].sum = tr[d].r-tr[d].l-tr[d].sum;
}

inline void lazy(int d) {
    if (tr[d].lz) {
        resum(lc), resum(rc);
        tr[lc].lz ^= 1, tr[rc].lz ^= 1;
        tr[d].lz = false;
    }
}

int build(int l, int r) {
    int root = tot++;
    tr[root].l = l, tr[root].r = r;
    tr[root].lz = tr[root].sum = 0;
    if (l == r-1) {
        tr[root].ls = tr[root].rs = -1;
        return root;
    }
    int mid = l+r>>1;
    tr[root].ls = build(l, mid);
    tr[root].rs = build(mid, r);
    return root;
}

void update(int d, int l, int r) {
    if (r <= l) return;
    if (l >= tr[d].r || r <= tr[d].l) return;
    if (tr[d].l == l && r == tr[d].r) {
        tr[d].lz ^= 1;
        tr[d].sum = tr[d].r-tr[d].l-tr[d].sum;
        return;
    }
    lazy(d);
    int mid = tr[d].l+tr[d].r>>1;
    if (r <= mid) update(lc, l, r);
    else if (l >= mid) update(rc, l, r);
    else update(lc, l, mid), update(rc, mid, r);
    Push(d);
}

int query(int d, int l, int r) {
    if (r <= l) return 0;
    if (l >= tr[d].r || r <= tr[d].l) return 0;
    if (tr[d].l == l && tr[d].r == r) return tr[d].sum;
    lazy(d);
    int mid = tr[d].l+tr[d].r>>1;
    if (r <= mid) return query(lc, l, r);
    else if (l >= mid) return query(rc, l, r);
    else return query(lc, l, mid)+query(rc, mid, r);
}

inline void init() {
    ca++;
    tot = 0;
    memset(tid, -1, sizeof(tid));
    memset(dep, -1, sizeof(dep));
    memset(sun, -1, sizeof(sun));
    memset(col, false, sizeof(col));;
    memset(pathf, -1, sizeof(pathf));
}

int dfs(int u) {
    int i, v, re = 1, tm = 0, sid = u;
    for (i = 0;i < V[u].size();i++) {
        v = V[u][i];
        if (flag[v] == ca) continue;
        flag[v] = ca;
        int t = dfs(v);
        if (t > tm) tm = t, sid = v;
        re += t;
    }
    sun[u] = sid;
    return re;
}

void dfs1(int u, int f, int top, int d, int id) {
    dep[u] = d, tid[u] = id, pathf[u] = top, fa[u] = f;
    if (tid[sun[u]] == -1) dfs1(sun[u], u, top, d+1, id+1);
    if (isbuild[top] != ca) {
        weight[top] = build(0, id+1);
        light[top] = build(0, id+1);
        isbuild[top] = ca;
    }
    for (int i = 0;i < V[u].size();i++) {
        int v = V[u][i];
        if (tid[v] != -1) continue;
        dfs1(v, u, v, d+1, 0);
    }
}

int cal(int u) {
    int f = fa[u];
    return col[u]^query(light[pathf[f]], tid[f], tid[f]+1);
}

void reverse1(int u, int v) {
    while (pathf[u] != pathf[v]) {
        if (dep[pathf[u]] < dep[pathf[v]]) swap(u, v);
        update(weight[pathf[u]], 1, tid[u]+1);
        u = pathf[u];
        col[u] ^= 1;
        u = fa[u];
    }
    if (tid[u] > tid[v]) swap(u, v);
    update(weight[pathf[u]], tid[u]+1, tid[v]+1);
}

void reverse2(int u, int v) {
    while (pathf[u] != pathf[v]) {
        if (dep[pathf[u]] < dep[pathf[v]]) swap(u, v);
        update(light[pathf[u]], 0, tid[u]+1);
        update(weight[pathf[u]], tid[u]+1, tid[u]+2);
        u = pathf[u];
        col[u] ^= 1;
        u = fa[u];
    }
    if (tid[u] > tid[v]) swap(u, v);
    update(light[pathf[u]], tid[u], tid[v]+1);
    if (u == pathf[u]) {
        col[u] ^= 1;
    }else {
        update(weight[pathf[u]], tid[u], tid[u]+1);
    }
    update(weight[pathf[u]], tid[v]+1, tid[v]+2);
}

int sum(int u, int v) {
    int re = 0;
    while (pathf[u] != pathf[v]) {
        if (dep[pathf[u]] < dep[pathf[v]]) swap(u, v);
        re += query(weight[pathf[u]], 1, tid[u]+1);
        u = pathf[u];
        re += cal(u);
        u = fa[u];
    }
    if (tid[u] > tid[v]) swap(u, v);
    re += query(weight[pathf[u]], tid[u]+1, tid[v]+1);
    return re;
}

inline int in() {
    int tm = 0;
    char c;
    c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        tm = tm*10+c-'0';
        c = getchar();
    }
    return tm;
}

int main() {
    int T, n, m, u, v, i, q;
    T = in();
    while (T--) {
        n = in();
        init();
        for (i = 0;i < n;i++) V[i].clear();
        for (i = 0;i < n-1;i++) {
            u = in(), v = in();
            u--, v--;
            V[u].push_back(v), V[v].push_back(u);
        }
        flag[0] = ca;
        dfs(0);
        dfs1(0, -1, 0, 0, 0);//å»ºæ å®æ¯
        m = in();
        while (m--) {
           q = in(), u = in(), v = in();// scanf("%d%d%d", &q, &u, &v);
            v--, u--;
            if (q == 1) {
                reverse1(u, v);
            }else if (q == 2) {
                reverse2(u, v);
            }else {
                printf("%d\n", sum(u, v));
            }
        }
    }
}
