#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
#define mid (l+r>>1)
#define lc (o<<1)
#define rc (o<<1|1)
typedef unsigned long long LL;
const int maxn = 30030;

struct Edge
{
    int v, w;
};

int sumv[4*maxn], setv[4*maxn], siz[maxn], dep[maxn], col[maxn];
int L[maxn], R[maxn], U[maxn], V[maxn];
vector<Edge> G[maxn];
map<LL, int> idx;
int n, tot, ql, qr, p, vv;

LL mhash(char *s)
{
    LL h = 0;
    for(int i = 0; s[i]; i++)
        h = h*123 + s[i];
    return h;
}

void dfs(int u, int fa, int d, int c)
{
    dep[u] = d; col[u] = c;
    siz[u] = 1; L[u] = R[u] = ++tot;
    for(int i = 0; i < G[u].size(); i++) {
        Edge &e = G[u][i];
        if(e.v == fa) continue;
        dfs(e.v, u, d+1, c^e.w);
        siz[u] += siz[e.v];
        R[u] = R[e.v];
    }
}

void update(int o, int l, int r)
{
    setv[o] = 0;
    if(l == r) {
        sumv[o] = vv;
        return;
    }
    int m = mid;
    if(p <= m) update(lc, l, m);
    else update(rc, m+1, r);
    sumv[o] = sumv[lc] + sumv[rc];
    //printf("%d %d %d\n", l, r, sumv[o]);
}

void pushdown(int o, int l, int r)
{
    if(r > l) {
        int m = mid;
        setv[lc] ^= 1; sumv[lc] = m-l+1 - sumv[lc];
        setv[rc] ^= 1; sumv[rc] = r-m - sumv[rc];
//        printf("%d %d:  %d %d\n", l, r, sumv[lc], sumv[rc]);
    }
    setv[o] = 0;
}

void maintain(int o, int l, int r)
{
    if(r > l) sumv[o] = sumv[lc] + sumv[rc];
}

void gao(int o, int l, int r)
{
    if(ql <= l && r <= qr) {
        setv[o] ^= 1;
        sumv[o] = r-l+1 - sumv[o];
    } else {
        if(setv[o]) pushdown(o, l, r);
        int m = mid;
        if(ql <= m) gao(lc, l, m);
        if(qr >  m) gao(rc, m+1, r);
        maintain(o, l, r);
    }
//    printf("%d %d %d %d\n", l, r, sumv[o], setv[o]);
}

int main()
{
    //freopen("h.txt", "r", stdin);
    int T, nc = 0, u, v, w;
    char s[20];
    cin >> T;
    while(T--)
    {
        printf("Case #%d:\n", ++nc);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%s", s);
            LL h = mhash(s);
            idx[h] = i;
            G[i].clear();
        }
        for(int i = 1; i < n; i++) {
            scanf("%s", s); u = idx[mhash(s)]; U[i] = u;
            scanf("%s", s); v = idx[mhash(s)]; V[i] = v;
            scanf("%d", &w);
            G[u].push_back((Edge){v, w});
            G[v].push_back((Edge){u, w});
        }
        tot = 0;
        dfs(1, -1, 1, 0);
//        for(int i = 1; i <= n; i++) {
//            printf("%d %d %d %d %d\n", siz[i], dep[i], L[i], R[i], col[i]);
//        }

        for(int i = 1; i <= n; i++) {
            p = L[i]; vv = col[i];
            update(1, 1, n);
        }

        int q;
        scanf("%d", &q);
        while(q--) {
            scanf("%s", s);
            if(s[0] == 'Q') {
                printf("%d\n", 2*(n-sumv[1])*sumv[1]);
            } else {
                scanf("%d", &w);
                u = U[w]; v = V[w];
                if(dep[u] < dep[v]) u = v;
                ql = L[u]; qr = R[u];
                gao(1, 1, n);
            }
        }
    }
    return 0;
}