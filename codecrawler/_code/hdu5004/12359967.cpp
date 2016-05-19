#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

const int n = 16, m = 10;
int mp[10][18][12], id[18][12], mp2[170][170], co[15], vis[170], px[170], py[170];
int t, ln, mn;
int xx[5] = {0, 1, 0, -1}, yy[5] = {1, 0, -1, 0};
char c;
vector <int> g;

void dfs (int c, int x ,int y) {
    id[x][y] = ln;
    for (int i = 0; i < 4; i++) {
        int dx = x + xx[i], dy = y + yy[i];
        if (dx > n || dx < 1 || dy > m || dy < 1 || id[dx][dy]) continue;
        if (mp[0][dx][dy] != c) continue;
        dfs (c, dx, dy);
    }
}

int d[170];

void bfs (int k) {
    queue <int> q;
    q.push(k);
    memset (d, 0, sizeof d);
    d[k] = 1;
    int m = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= ln; i++) {
            if (!d[i] && mp2[u][i]) {
                d[i] = d[u] + 1;
                q.push(i);
                m = max (d[i], m);
            }
        }
    }
    if (m == mn) {
        g.push_back(k);
    } else if (m < mn) {
        mn = m;
        g.clear();
        g.push_back(k);
    }
}

int jug (int k, int l) {
    int vis2[5], sum = 0;
    memset (vis2, 0, sizeof vis2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int tmp = mp[k][i][j];
//            cout << tmp ;
            if (!vis2[tmp]) {
                vis2[tmp] = 1;
                sum++;
            }
        }
//        cout << endl;
    }
    if (sum > l) return 1;
    return 0;
}

int c1, c2;

void cg (int k, int i, int j) {
    mp[k][i][j] = c2;
    int dx, dy;
    for (int d = 0; d < 4; d++) {
        dx = i + xx[d], dy = j + yy[d];
        if (mp[k][dx][dy] == c1) cg (k, dx, dy);
    }
}

int dfs2 (int k, int x, int y) {
    if (t - k < 4 && jug (k, t - k + 1)) {
//        cout << 'x' <<endl;
        return 0;
    }
    if (k == t) {
        return 1;
    }
    for (int i = 1; i <= 4; i++) {
        if (i == mp[k][x][y]) continue;
        co[k] = i;
        memcpy (mp[k + 1], mp[k], sizeof mp[k]);
        c1 = mp[k][x][y], c2 = i;
//        cout << k << ' ' << c1 << ' ' << c2 << endl;
        cg(k + 1, x, y);
        if (dfs2 (k + 1, x, y)) return 1;
    }
    return 0;
}

int main()
{
//    freopen ("in", "r", stdin);
    srand (time (NULL));
    int T, cas = 1;
    cin >> T;
    while (T--) {
        cin >> t;
        g.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c;
                mp[0][i][j] = c - '0';
            }
        }
        memset (mp2, 0, sizeof mp2);
        memset (id, 0, sizeof id);
        ln = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) if (!id[i][j]){
                ln++;
                px[ln] = i, py[ln] = j;
                dfs (mp[0][i][j], i, j);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < 4; k++) {
                    int dx = i + xx[k], dy = j + yy[k];
                    if (dx > n || dx < 1 || dy > m || dy < 1) continue;
                    int id1 = id[i][j], id2 = id[dx][dy];
                    if (id1 != id2) mp2[id1][id2] = mp2[id2][id1] = 1;
                }
            }
        }
        mn = 1e9;
        for (int i = 1; i <= ln; i++) {
            bfs (i);
        }
        int sz = g.size(), x, y;
        memset (vis, 0, sizeof vis);
        for (int i = 0; i < sz; i++) {
//            cout << g[i] << endl;
            vis[g[i]] = 1;
            int j = px[g[i]], k = py[g[i]];
            if (dfs2 (0, j, k)) {
                x = j, y = k;
                goto x;
            }
        }
        while (1) {
            int tmp = rand() % ln + 1;
            while (vis[tmp]) {
                tmp++;
                if (tmp > ln) tmp = 1;
            }
            vis[tmp] = 1;
            int j = px[tmp], k = py[tmp];
            if (dfs2 (0, j, k)) {
                x = j, y = k;
                break;
            }
        }
        x:;
//        cout << x << ' ' << y << endl;
        printf ("Case #%d:\n", cas++);
        for (int k = 0; k < t; k++) {
            cout << co[k] << ' ' << x << ' ' << y << endl;
        }
    }
    return 0;
}