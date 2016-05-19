#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

const int kMaxN = 200;
int n, r;
vector<int> org[kMaxN];
int val[kMaxN][2];
int type[kMaxN];
int f[kMaxN][2];
int g[kMaxN][2];
int q[kMaxN];
int ind[kMaxN];

#define AMB 0
#define XQ 1
#define END 2

bool check(int lim) {
    for (int i = 0; i < n; ++ i)
        if (type[i] == END)
            for (int v = 0; v < 2; ++ v)
                g[i][v] = val[i][v];
    for (int i = r - 1; i >= 0; -- i) {
        int u = q[i];
        if (type[u] != END) {
            g[u][0] = g[u][1] = -1;
            int min_op = 10000 + 1;
            bool exist = false;
            for (vector<int>::iterator it = org[u].begin(); it != org[u].end(); ++ it) {
                int v = *it;
                if (type[u] == AMB) {
                    if (g[v][type[u]] > g[u][type[u]]) {
                        g[u][type[u]] = g[v][type[u]];
                        g[u][type[u] ^ 1] = g[v][type[u] ^ 1];
                    }
                } else {
                    min_op = min(min_op, g[v][type[u] ^ 1]);
                    if (g[v][type[u]] >= lim) {
                        exist = true;
                        if (g[v][type[u] ^ 1] > g[u][type[u] ^ 1]) {
                            g[u][type[u]] = g[v][type[u]];
                            g[u][type[u] ^ 1] = g[v][type[u] ^ 1];
                        }
                    }
                }
            }
            if (type[u] == XQ && !exist) {
                g[u][type[u]] = lim - 1;
                g[u][type[u] ^ 1] = min_op;
            }
        }
    }
    return (g[0][XQ] >= lim);
}

int main() {
    //freopen("t.in", "r", stdin);
    int T;
    for (scanf("%d", &T); T --; ) {
        scanf("%d", &n);
        memset(ind, 0, sizeof(ind));
        for (int i = 0, m; i < n; ++ i) {
            scanf("%d", &m);
            if (m == 0) {
                scanf("%d%d", &val[i][AMB], &val[i][XQ]);
                type[i] = END;
            } else {
                for (int j = 0, x; j < m; ++ j) {
                    scanf("%d", &x);
                    -- x;
                    org[i].push_back(x);
                    ++ ind[x];
                }
                static char buf[2];
                scanf("%s", buf);
                if (buf[0] == 'A') type[i] = AMB;
                else type[i] = XQ;
            }
        } 
        int qh = 0, qt = 0;
        for (int i = 0; i < n; ++ i)
            if (ind[i] == 0) q[qt ++] = i;
        while (qh != qt) {
            int u = q[qh ++];
            for (vector<int>::iterator it = org[u].begin(); it != org[u].end(); ++ it) {
                int v = *it;
                -- ind[v];
                if (ind[v] == 0) {
                    q[qt ++] = v;
                }
            }
        }
        r = qt;
        for (int i = 0; i < n; ++ i)
            if (type[i] == END) {
                for (int v = 0; v < 2; ++ v)
                    f[i][v] = val[i][v];
            }
        for (int i = r - 1; i >= 0; -- i) {
            int u = q[i];
            if (type[u] != END) {
                f[u][0] = f[u][1] = -1;
                for (vector<int>::iterator it = org[u].begin(); it != org[u].end(); ++ it) {
                    int v = *it;
                    if (f[v][type[u]] > f[u][type[u]]) {
                        f[u][type[u]] = f[v][type[u]];
                        f[u][type[u] ^ 1] = f[v][type[u] ^ 1];
                    }
                }
            }
        }
        printf("%d ", f[0][XQ]);
        int lb = 0, rb = 10000 + 1;
        while (lb + 1 < rb) {
            int mid = (lb + rb) >> 1;
            if (check(mid)) {
                lb = mid;
            }
            else {
                rb = mid;
            }
        }
        printf("%d\n", lb);
        for (int i = 0; i < n; ++ i) org[i].clear();
    }
    return 0;
}