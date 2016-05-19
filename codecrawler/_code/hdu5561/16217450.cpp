#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long double LD;
typedef long long LL;

const int maxn = 40;

const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const LD eps = 1e-15;

int n, rt;

int tot, st[maxn];
int lk[maxn << 1], b[maxn << 1], c[maxn << 1];
bool fg[maxn << 1];
void addedge(int u, int v, int w) {
    lk[++ tot] = st[u]; b[tot] = v; c[tot] = w; fg[tot] = 0; st[u] = tot;
}

struct Node {
    int u, S;
    LD f; LL g, w;
    bool operator <(const Node& B) const {
        return g < B.g;
    }
} A[maxn * (1<<16)]; int AN;

int e[maxn], eN;

void dfsA1(int u, int fa) {
    for (int i = st[u]; i; i = lk[i]) {
        int v = b[i];
        if (v == fa) continue;
        e[eN ++] = i;
        dfsA1(v, u);
    }
}

LL f[maxn][2];
void dfsA2(int u, int fa) {
    f[u][0] = 0, f[u][1] = -INF;
    for (int i = st[u]; i; i = lk[i]) {
        int v = b[i];
        if (v == fa) continue;
        dfsA2(v, u);

        LL f0 = -INF, f1 = -INF;
        f0 = f[u][0] + max(f[v][0], f[v][1]);
        f1 = f[u][1] + max(f[v][0], f[v][1]);
        if (fg[i]) f1 = max(f1, f[u][0] + c[i] + f[v][0]);
        f[u][0] = max(f[u][0], f0), f[u][1] = max(f[u][1], f1);
    }
}

LD mu[maxn];

bool calc(LD lam) {
    AN = 0;

    for (int i = 1; i <= n; ++ i) mu[i] = 0;
    for (int i = st[rt]; i; i = lk[i]) {
        int u = b[i], w = c[i];

        eN = 0;
        dfsA1(u, rt);
        for (int S = 0; S < (1<<eN); ++ S) {
            LL sEw = 0;
            for (int i = 0; i < eN; ++ i) if (S&(1<<i)) { fg[e[i]] = fg[e[i]^1] = 1; sEw += c[e[i]]; }
            dfsA2(u, rt);
            for (int i = 0; i < eN; ++ i) if (S&(1<<i)) fg[e[i]] = fg[e[i]^1] = 0;

            LL hu = max(f[u][0], f[u][1]);
            LD fu = hu - lam * sEw;
            LL gu = max(f[u][0] + w, f[u][1]) - hu;
            A[AN ++] = (Node){u, S, fu, gu, w};

            if (S > 0 && fu < eps)
                return 1;
        }
    }

    sort(A, A+AN);

    for (int i = 0; i < AN; ++ i) {
        int u = A[i].u; LD fu = A[i].f; LL gu = A[i].g;

        if (A[i].S == 19) {
            int pp = 0;
        }

        LD s = 0;
        for (int j = 1; j <= n; ++ j) if (j != u) s += mu[j];

        if (fu + gu - A[i].w * lam + s < eps) return 1;

        mu[u] = min(mu[u], fu - A[i].w * lam);
    }

    return 0;
}

int cen, vcen;
int sz[maxn], mxChSz[maxn];
void dfsC(int u, int fa, int n) {
    sz[u] = 1; mxChSz[u] = 0;
    for (int i = st[u]; i; i = lk[i]) {
        int v = b[i];
        if (v == fa) continue;
        dfsC(v, u, n);
        sz[u] += sz[v];
        mxChSz[u] = max(mxChSz[u], sz[v]);
    }
    mxChSz[u] = max(n - sz[u], mxChSz[u]);
    if (mxChSz[u] < vcen) {
        cen = u; vcen = mxChSz[u];
    }
}
int getCen() {
    vcen = n+1;
    dfsC(1, 0, n);
    return cen;
}

void solve() {
    scanf("%d", &n);

    tot = 1; memset(st, 0, sizeof st);
    for (int i = 1; i < n; ++ i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w); addedge(v, u, w);
//      printf("%d %d %d\n", u, v, w);
    }

    rt = getCen();

    LD L = 0, R = 1 + eps;
    for (int z = 20; z --; ) {
        LD M = (L + R) / 2;
        if (calc(M)) R = M; else L = M;
    }
    printf("%.8lf\n", (double)R);
}

int main() {
//  freopen("J.in", "r", stdin);
//  freopen("J.out", "w", stdout);

    int kase, i = 0; scanf("%d", &kase);
    for (int i = 1; i <= kase; ++ i) {
        printf("Case #%d: ", i);
        solve();
    }
//  for(;;);
    return 0;
}
