#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define N 310
#define INF 0x3f3f3f3f

struct People {
    int len, id, start, speed;
    double time;
}P[N];

int dis[N][N], d[N];
int n, m, k, zz;
bool vis[N];

int cmp(People a, People b) {
    if (fabs(a.time - b.time) < 1e-7) {
        if (a.len == b.len) {
            return a.id > b.id;
        }
        else 
            return a.len > b.len;
    }
    else
        return a.time < b.time;

}

void init() {

    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;

    int x, y, z;
    for (int i = 0; i < k; i++) {
        scanf("%d%d%d", &x, &y, &z);
        dis[y][x] = min(dis[y][x], z);
    }
    scanf("%d", &zz);

    for (int i = 1; i <= m; i++) {
        scanf("%d", &P[i].start);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &P[i].speed);
    }
}

void Dijkstra() {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        d[i] = dis[zz][i];
    vis[zz] = 1;
    d[zz] = 0;

    for (int i = 2; i <= n; i++) {
        int x, t = INF;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && d[j] < t) {
                t = d[j];
                x = j;
            }
        if (t == INF)
            break;
        vis[x] = 1;
        for (int j = 1; j <= n; j++) {
            if (d[j] > d[x] + dis[x][j]) {
                d[j] = d[x] + dis[x][j];
            }
        }
    }
}

void solve() {
    Dijkstra();

    for (int i = 1; i <= m; i++) {
        if (d[P[i].start] == INF) {
            P[i].time = INF;
            P[i].len = INF;
            P[i].id = i;
        }
        else {
            P[i].time = d[P[i].start] * 1.0 / P[i].speed;
            P[i].len = d[P[i].start];
            P[i].id = i;
        }
    }
    sort(P + 1, P + m + 1, cmp);
    if (P[1].time == INF)
        printf("No one\n");
    else
        printf("%d\n", P[1].id);

}

int main() {
    while (scanf("%d%d%d", &n, &m, &k) != EOF) {
        init();
        solve();
    }
    return 0;
}