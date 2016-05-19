#include <cstdio>
#include <cstring>
using namespace std;
#pragma comment(linker,"/STACk:10240000,10240000")
#define N 100010
#define M 400010
#define min(a, b) ((a) < (b) ? (a) : (b))

struct Edge{
    int to, next;
}E[M];

int n, m, tot, dfs_clock, bnum;
int head[N], f[N], low[N], pre[N];
bool isbridge[N], mark[N];

void AddEdge(int u, int v) {
    E[tot].to = v; E[tot].next = head[u]; head[u] = tot++;
    u = u ^ v; v = u ^ v; u = u ^ v;
    E[tot].to = v; E[tot].next = head[u]; head[u] = tot++;
}

void init() {
    memset(head, -1, sizeof(head));
    tot = 0;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
    }
}

void dfs(int u, int fa) {
    low[u] = pre[u] = ++dfs_clock;
    bool flag = false;

    for (int i = head[u]; i != -1; i = E[i].next) {
        int v = E[i].to;
        if (v == fa && !flag) {
            flag = true;
            continue;
        }

        if (!pre[v]) {
            f[v] = u;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > pre[u]) {
                isbridge[v] = 1;
                bnum++;
            }
        }
        else if (pre[v] <  pre[u]) {
            low[u] = min(low[u], pre[v]);
        }
    }
}

void LCA(int u, int v) {
    while (pre[u] > pre[v]) {
        if (isbridge[u]) {
            bnum--;
            isbridge[u] = 0;
        }
        u = f[u];
    }

    while (pre[u] < pre[v]) {
        if (isbridge[v]) {
            bnum--;
            isbridge[v] = 0;
        }
        v = f[v];
    }

    while (u != v) {
        while (pre[u] > pre[v]) {
            if (isbridge[u]) {
                bnum--;
                isbridge[u] = 0;
            }
            u = f[u];
        }
    }
}

int cas = 1;
void solve() {
    memset(pre, 0, sizeof(pre));
    memset(isbridge, 0, sizeof(isbridge));
    dfs_clock = bnum = 0;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    dfs(1, -1);
    int q, u, v;
    scanf("%d", &q);
    printf("Case %d:\n", cas++);
    while (q--) {
        scanf("%d%d", &u, &v);
        LCA(u, v);
        printf("%d\n", bnum);
    }
    printf("\n");
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF && n + m) {
        init();
        solve();
    }
    return 0;
}
