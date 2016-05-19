#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 45
typedef long long LL;

const int mod = (int) 1e9 + 7;
int dp[2][N], f[N][N], in[N], out[N], fa[N], vis[N], qu[N], g[1 << 21];
vector<int> ed[N];
int n, m, ans, top;
struct node {
    int id, fa;
    bool operator<(const node ff) const {
        return fa < ff.fa;
    }
} nd[N];

void init() {
    for (int i = 1; i <= n; i++) {
        in[i] = out[i] = 0;
        fa[i] = i;
        vis[i] = 0;
        ed[i].clear();
    }
    ans = 1;
    top = 0;
}

int getf(int x) {
    if (x != fa[x])
        fa[x] = getf(fa[x]);
    return fa[x];
}

LL topo(int sta) {
    if (g[sta] != -1)
        return g[sta];
    LL res = 0;
    int i, u, j, ss;
    for (i = 0; i < top; i++) {
        u = qu[i];
        if (!vis[u] && !in[u]) {
            vis[u] = 1;
            ss = ed[u].size();
            for (j = 0; j < ss; j++)
                in[ed[u][j]]--;
            res += topo(sta | (1 << i));
            vis[u] = 0;
            for (j = 0; j < ss; j++)
                in[ed[u][j]]++;
        }
    } 
    return g[sta] = res % mod;
}

void maketable() {
    int i, j, u, v, from, to;
    for (i = 1; i < N; i++) {
        f[0][i] = 1;
        for (j = i; j < N; j++) {
            for (v = 1; v <= i + 1; v++)
                dp[1][v] = 1;
            to = 1;
            for (u = 2; u <= j; u++) {
                from = (u & 1) ^ 1;
                to = u & 1;
                for (v = 1; v <= i + 1; v++)
                    dp[from][v] = (dp[from][v] + dp[from][v - 1]) % mod;
                for (v = 1; v <= i + 1; v++)
                    dp[to][v] = dp[from][v];
            }
            for (v = 1; v <= i + 1; v++)
                dp[to][v] = (dp[to][v] + dp[to][v - 1]) % mod;
            f[j][i] = f[i][j] = dp[to][i + 1];
        }
    }
}

int main() {
    int i, j, u, v;
    maketable();
    while (~scanf("%d%d", &n, &m)) {
        init();
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            if (u == v)
                continue;
            ed[u].push_back(v);
            in[v]++;
            out[u]++;
            u = getf(u);
            v = getf(v);
            if (u != v)
                fa[v] = u;
        }
        for (i = 1; i <= n; i++) {
            nd[i].id = i;
            nd[i].fa = getf(i);
        }
        sort(nd + 1, nd + n + 1);
        nd[n + 1].fa = -1;
        for (i = 1; i <= n; i = j) {
            top = 1;
            qu[0] = nd[i].id;
            for (j = i + 1; j <= n + 1; j++) {
                if (nd[j].fa == nd[i].fa) {
                    qu[top++] = nd[j].id;
                } else {
                    for (u = 0; u < (1 << top); u++)
                        g[u] = -1;
                    g[(1 << top) - 1] = 1;
                    ans = (LL) ans * (topo(0) * f[i - 1][j - i] % mod) % mod;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
