#include <cstdio>
#include <cstring>
#pragma comment(linker, "/STACK:102400000,102400000")
#define N 100010
#define M 600010

struct Edge{
    int to, next;
}E[M];

int head[N], color[N], pre[N], belong[N];
int n, m, tot;

void AddEdge(int u, int v) {
    E[tot].to = v; E[tot].next = head[u]; head[u] = tot++;
    u = u ^ v; v = u ^ v; u = u ^ v;
    E[tot].to = v; E[tot].next = head[u]; head[u] = tot++;
}

void init() {
    memset(head, -1, sizeof(head));
    tot = 0;

    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        AddEdge(u, v);
    }
}

bool odd, even;
int cnt;

void dfs(int u, int fa) {
    for (int i = head[u]; i != -1; i = E[i].next) {
        int v = E[i].to;
        if (v == fa) continue;  
        if (color[v] == color[u]) {
            odd = true;
            ++cnt;
            int t = v;
            while (!even) {
                if (belong[t]) {
                    even = true;
                    break;
                }
                belong[t] = cnt;
                t = pre[t];
                if (t == u || t == -1)
                    break;
            }
        }
        if (color[v] == 3 - color[u]) even = true;
        if (!color[v]) {
            color[v] = 3 - color[u];
            pre[v] = u;
            dfs(v, u);
        }
    }
}

void solve() {
    memset(color, 0, sizeof(color));
    memset(belong, 0, sizeof(belong));
    cnt = 0;
    even = odd = false;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            color[i] = 1;
            pre[i] = -1;
            dfs(i, -1);
        }
    }
    printf("%s\n", odd ? "YES" : "NO");
    printf("%s\n", even ? "YES" : "NO");
}

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        init();
        solve();
    }
    return 0;
}
