#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define N 55
#define S (1<<11)
#define INF 0x3f3f3f3f

struct Node {
    int x, y, state, step;
}start;

map<int, int> M;
int n, m, stone_num;
int dp[N][N][S], g[N][N];
int dir[4][2] = {{-1,0}, {1,0}, {0, -1}, {0,1}};

void init() {

    M.clear();
    stone_num = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &g[i][j]);
            if (g[i][j])    
                M[i * m + j] = stone_num++;
        }
    memset(dp, 0, sizeof(dp));
}

int bfs() {
    queue<Node> q;
    start.x = 0;
    start.y = 0;
    if (g[0][0])
        start.state = (1 << M[0]);
    else
        start.state = 0;
    start.step = 0;
    q.push(start);

    while (!q.empty()) {
        Node t = q.front();
        q.pop();
        int x = t.x, y = t.y;

        if (x == 0 && y == 0 && t.state == (1 << stone_num) - 1) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            int state = t.state;
            int step = t.step;

            if (xx < 0 || yy < 0 || xx >= n || yy >= m )
                continue;

            if (g[xx][yy])
                state |= (1 << M[xx * m + yy]);

            if (dp[xx][yy][state])
                continue;

            dp[xx][yy][state] = step + 1;

            Node tt;
            tt.x = xx;
            tt.y = yy;
            tt.state = state;
            tt.step = t.step + 1;
            q.push(tt);
        }
    }
    return dp[0][0][(1 << stone_num) - 1];
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        if(stone_num == 0)
            printf("0\n");
        else
            printf("%d\n", bfs());
    }
    return 0;
}
