#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

const int PO = 55;
const int N = 1005;
typedef long long ll;
int n, m, ans, cr, cc;
char map[PO][PO];
int row[PO][PO], col[PO][PO];
int G[N][N], vis[N], rec[N];
void init() {
    ans = 0;
    cr = cc = 0;
    memset(map, 0, sizeof(map));
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(G, 0, sizeof(G));
    memset(rec, 0, sizeof(rec));
}
int find(int x) {
    for (int i = 1; i < cc; i++) {
        if (G[x][i] && !vis[i]) {
            vis[i] = 1;    
            if (!rec[i] || find(rec[i])) {
                rec[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
void hungary() {
    for (int i = 1; i < cr; i++) {
        memset(vis, 0, sizeof(vis));    
        if (find(i)) ans++;
    }
}
void input() {
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);    
    }
    cr = 1;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < m; j++)    {
            if (map[i][j] == '*') row[i][j] = cr, flag = 1;
            if (map[i][j] == '#') cr++, flag = 0;
        }
        if (flag) cr++;
    }
    cc = 1;
    for (int i = 0; i < m; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++)    {
            if (map[j][i] == '*') col[j][i] = cc, flag = 1;
            if (map[j][i] == '#') cc++, flag = 0;
        }
        if (flag) cc++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '*') G[row[i][j]][col[i][j]] = 1;
        }    
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        input();    
        hungary();
        printf("%d\n", ans);
    }
    return 0;
}