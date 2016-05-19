#include <stdio.h>
#include <string.h>
const int N = 505;
int n, m, k, g[N][N], temp[N][N], vis[N][N];

bool judge(int x, int y) {
    if (x - 1 >= 0 && y - 1 >= 0) {
        if (temp[x - 1][y] && temp[x][y - 1])
            return true;
    }
    if (x - 1 >= 0 && y + 1 < m) {
        if (temp[x - 1][y] && temp[x][y + 1])
            return true;
    } 
    if (x + 1 < n && y - 1 >= 0) {
        if (temp[x + 1][y] && temp[x][y - 1])
            return true;
    }
    if (x + 1 < n && y + 1 < m) {
        if (temp[x + 1][y] && temp[x][y + 1])
            return true;
    }
    return false;
}

int main() {
    int t, cas = 1;
    scanf("%d", &t);
    while (t--) {
        memset(g, 0, sizeof(g));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d%d", &n, &m, &k);
        int num = 0, x, y;
        for (int i = 0; i < k; i++) {
            scanf("%d%d", &x, &y);
            if (!g[x - 1][y - 1]) {
                g[x - 1][y - 1] = 1;
                num++;
            }
        }
        int res = 0;
        while (1) {
            int flag = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    temp[i][j] = g[i][j];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    if (temp[i][j] == 0 && judge(i, j)) {
                        g[i][j] = 1;
                        flag++;
                    }
                }
            if (flag)
                res += flag;
            else
                break;
        }
        printf("Case #%d:\n%d\n", cas++, res + num);
    }
    return 0;
}