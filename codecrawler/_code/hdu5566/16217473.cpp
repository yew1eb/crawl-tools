#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define N 100020
#define M 200020

#define fi first
#define sd second
#define MP make_pair

// ok
struct graph {
    int fst[N], nxt[M], vv[M], e;
    void init() {
        memset(fst, -1, sizeof fst);
        e = 0;
    }
    void add(int u, int v) {
        vv[e] = v, nxt[e] = fst[u], fst[u] = e++;
    }
}g1, g2;
// ok
int ch[N][26], f[N];
vector<pair<int, int> > g[N];
int tot;

// ok
void build_ac() {
    queue<int> q;
    f[0] = 0;
    for(int i = 0; i < 26; ++i) {
        int &v = ch[0][i];
        if(v == -1) v = 0;
        else {
            f[v] = 0;
            q.push(v);
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < 26; ++i) {
            int &v = ch[u][i];
            if(v == -1) v = ch[f[u]][i];
            else {
                f[v] = ch[f[u]][i];
                q.push(v);
            }
        }
    }
}

int n, m;
char s[N];

// tree-cut
int sz[N], fa[N], tp[N], dep[N], son[N];
int c[N], d[N], lab[N], dc;

int rt[N];
// segment - tree
struct seg_t {
    int ch[N*20][2], mx[N*20];
    int tot;
    void init() {
        tot = 0;
        ch[0][0] = ch[0][1] = 0;
        mx[0] = 0;
    }
#define md (ll + rr >> 1)

    int insert(int i, int x, int v, int ll, int rr) {
        int k = ++tot;
        ch[k][0] = ch[i][0];
        ch[k][1] = ch[i][1];
        mx[k] = max(mx[i], v);
        if(ll == rr) return k;
        if(x <= md) ch[k][0] = insert(ch[i][0], x, v, ll, md);
        else ch[k][1] = insert(ch[i][1], x, v, md + 1, rr);
        return k;
    }
    int query(int i, int l, int r, int ll, int rr) {
        if(ll == l && rr == r) return mx[i];
        if(r <= md) return query(ch[i][0], l, r, ll, md);
        if(l > md) return query(ch[i][1], l, r, md + 1, rr);
        return max(query(ch[i][0], l, md, ll, md), query(ch[i][1], md + 1, r, md + 1, rr));
    }
}T;


void insert(char *s, int id, int len) {
    int t = 0;
    for(int i = 0; s[i]; ++i) {
        int c = s[i] - 'a';
        if(ch[t][c] == -1) {
            int k = ++tot;
            memset(ch[k], -1, sizeof ch[k]);
            g[k].clear();
            ch[t][c] = k;
        }
        t = ch[t][c];
    }
    g[t].push_back(MP(id, len));
}

void dfs(int u, int p, int d) {
    dep[u] = d;
    fa[u] = p;
    sz[u] = 1;
    son[u] = 0;
    int mx = 0;
    for(int i = g1.fst[u]; ~i; i = g1.nxt[i]) {
        int v = g1.vv[i];
        if(v == p) continue;
        dfs(v, u, d + 1);
        sz[u] += sz[v];
        if(sz[v] > mx) mx = sz[v], son[u] = v;
    }
}
void dfs1(int u, int anc) {
    c[u] = ++dc;
    tp[u] = anc;
    lab[dc] = u;
    if(son[u]) dfs1(son[u], anc);
    for(int i = g1.fst[u]; ~i; i = g1.nxt[i]) {
        int v = g1.vv[i];
        if(v != fa[u] && v != son[u])
            dfs1(v, v);
    }
    d[u] = dc;
}
void dfs2(int u, int pre) {
    rt[u] = pre;
    for(int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i].fi, len = g[u][i].sd;
        rt[u] = T.insert(rt[u], c[v], len, 1, n);
    }
    for(int i = g2.fst[u]; ~i; i = g2.nxt[i]) {
        int v = g2.vv[i];
        dfs2(v, rt[u]);
    }
}

int calc(int t, int x, int y) {
    int ret = 0;
    while(tp[x] != tp[y]) {
        if(dep[tp[x]] > dep[tp[y]]) swap(x, y);
        ret = max(ret, T.query(rt[t], c[tp[y]], c[y], 1, n));
        y = fa[tp[y]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    ret = max(ret, T.query(rt[t], c[x], c[y], 1, n));
    return ret;
}
int main() {
    int cas;
    scanf("%d", &cas);
    while(cas--) {
        memset(ch[0], -1, sizeof ch[0]);
        g[0].clear();
        tot = 0;

        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s);
            insert(s, i, strlen(s));
        }
        build_ac();
        g1.init();
        for(int i = 2; i <= n; ++i) {
            int p; scanf("%d", &p);
            g1.add(p, i);
            g1.add(i, p);
        }

        dc = 0;
        dfs(1, -1, 0);
        dfs1(1, 1);
        g2.init();
        for(int i = 1; i <= tot; ++i) {
            g2.add(f[i], i);
        }
        T.init();
        
        dfs2(0, 0);
        
        scanf("%d", &m);
        while(m--) {
            int x, y;
            scanf("%d%d%s", &x, &y, s);
            int t = 0;
            int ans = 0;
            for(int i = 0; s[i]; ++i) {
                int c = s[i] - 'a';
                t = ch[t][c];
                if(t != 0) {
                    ans = max(ans, calc(t, x, y));
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}