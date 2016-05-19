#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 20;
const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
typedef pair<int, int> pii;
#define MP(a,b) make_pair(a,b)

int g[N][N], vis[N][N], n, m, dp[(1<<15)][20];
char G[N][N];

struct Pipe {
    int x1, y1, x2, y2;
    void read() {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    }
} p[N];

int bfs(Pipe a, Pipe b) {
    queue<pii> Q;
    memset(vis, -1, sizeof(vis));
    Q.push(MP(a.x2, a.y2));
    vis[a.x2][a.y2] = 0;
    while (!Q.empty()) {
    pii now = Q.front();
    if (now.first == b.x1 && now.second == b.y1) return vis[now.first][now.second];
    Q.pop();
    for (int i = 0; i < 4; i++) {
        int xx = now.first + d[i][0];
        int yy = now.second + d[i][1];
        if (xx <= 0 || xx > n || yy <= 0 || yy > n || vis[xx][yy] != -1 || G[xx][yy] != '.') continue;
        vis[xx][yy] = vis[now.first][now.second] + 1;
        Q.push(MP(xx,yy));
    }
    }
    return -1;
}

void build() {
    for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
        if (i == j) g[i][j] = 0;
        else g[i][j] = bfs(p[i], p[j]);
    }
    }
}

int solve() {
    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= m; i++)
    dp[1<<(i - 1)][i] = 0;
    int ans = INF;
    for (int i = 0; i < (1<<m); i++) {
    for (int j = 1; j <= m; j++) {
        if (i&(1<<(j - 1))) {
        for (int k = 1; k <= m; k++) {
            if (i&(1<<(k - 1)) == 0 || g[k][j] == -1) continue;
            dp[i][j] = min(dp[i^(1<<(j - 1))][k] + g[k][j], dp[i][j]);
        }
        }
        if (i == (1<<m) - 1)
        ans = min(ans, dp[i][j]);
    }
    }
    if (ans == INF) return -1;
    return ans;
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; i++)
        scanf("%s", G[i] + 1);
    for (int i = 1; i <= m; i++)
        p[i].read();
    build();
    printf("%d\n", solve());
    }
    return 0;
}