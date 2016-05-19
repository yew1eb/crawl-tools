#pragma comment(linker,"/STACk:10240000,10240000")
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cassert>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define N 100010
#define L(x) (x<<1)
#define R(x) ((x<<1)|1)
#define MI(x,y) ((x+y)>>1)

int n, m, tot, idx;
int head[N], pre[N], size[N], dep[N], hson[N], top[N], tid[N], ftid[N], ans[N];
struct Edge {
    int u, v, next;
} ed[N * 2];
struct Add {
    int c, v, next;
} ad[N * 40];
struct Tree {
    int l, r, v;
} d[N * 4];

void addedge(int u, int v) {
    ed[tot].u = u;
    ed[tot].v = v;
    ed[tot].next = head[u];
    head[u] = tot++;
}

void add(int u, int c, int v) {
    ad[tot].c = c;
    ad[tot].v = v;
    ad[tot].next = head[u];
    head[u] = tot++;
}

void dfs1(int u, int fa) {
    pre[u] = fa;
    size[u] = 1;
    dep[u] = dep[fa] + 1;
    hson[u] = 0;
    for (int i = head[u]; ~i; i = ed[i].next) {
        int v = ed[i].v;
        if (v != fa) {
            dfs1(v, u);
            if (size[v] > size[hson[u]])
                hson[u] = v;
            size[u] += size[v];
        }
    }
}

void dfs2(int u, int tp) {
    tid[u] = idx;
    ftid[idx] = u;
    idx++;
    top[u] = tp;
    if (hson[u])
        dfs2(hson[u], tp);
    for (int i = head[u]; ~i; i = ed[i].next) {
        int v = ed[i].v;
        if (v != pre[u] && v != hson[u])
            dfs2(v, v);
    }
}

void Update(int u, int v, int c) {
    int fu = top[u], fv = top[v];
    while (fu != fv) {
        if (dep[fu] >= dep[fv]) {
            add(tid[fu], c, 1);
            add(tid[u] + 1, c, -1);
            u = pre[fu];
            fu = top[u];
        } else {
            add(tid[fv], c, 1);
            add(tid[v] + 1, c, -1);
            v = pre[fv];
            fv = top[v];
        }
    }
    if (dep[u] > dep[v])
        swap(u, v);
    add(tid[u], c, 1);
    add(tid[v] + 1, c, -1);
}

void build(int l, int r, int i) {
    d[i].l = l;
    d[i].r = r;
    d[i].v = 0;
    if (l == r)
        return;
    int mid = MI(l,r);
    build(l, mid, L(i));
    build(mid + 1, r, R(i));
}

void up(int i) {
    d[i].v = max(d[L(i)].v, d[R(i)].v);
}

void update(int p, int i, int v) {
    if (d[i].l == d[i].r) {
        d[i].v += v;
        return;
    }
    int mid = MI(d[i].l,d[i].r);
    if (p <= mid)
        update(p, L(i), v);
    else
        update(p, R(i), v);
    up(i);
}

int query(int i) {
    if (d[i].l == d[i].r)
        return d[i].l;
    if (d[i].v == d[L(i)].v)
        return query(L(i));
    else
        return query(R(i));
}

int main() {
    int i, u, v, c;
    while (~scanf("%d%d", &n, &m)) {
        if (!n && !m)
            break;
        tot = 0;
        memset(head, -1, sizeof(head));
        for (i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        dfs1(1, 0);
        idx = 1;
        dfs2(1, 1);
        tot = 0;
        memset(head, -1, sizeof(head));
        for (i = 1; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &c);
            Update(u, v, c);
        }
        build(0, 100001, 1);
        for (u = 1; u <= n; u++) {
            for (i = head[u]; ~i; i = ad[i].next)
                update(ad[i].c, 1, ad[i].v);
            ans[ftid[u]] = query(1);
        }
        for (i = 1; i <= n; i++) {
            printf("%d\n", ans[i]);
            assert(ans[i] >= 0 && ans[i] <= 100000);
        }
    }
    return 0;
}
