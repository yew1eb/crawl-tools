#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 55;
const int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int N, M, G[maxn][maxn];

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        memset(G, 0, sizeof(G));
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++) scanf("%d", &G[i][j]);

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (G[i][j]) ans++;
                for (int d = 0; d < 4; d++) {
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];
                    //if (x <= 0 || x > N || y <= 0 || y > M) continue;
                    ans += max(G[i][j] - G[x][y], 0);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}