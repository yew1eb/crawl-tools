#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>

using namespace std;

const int N = 305;
int map[N][N], out[N][N], vis2[N][N];
int n, m, sx, sy, ans;
bool vis[N][N];
const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
struct node {
    int x, y;
};

inline bool judge(int x, int y) {
    if(x >= 1 && y >= 1 && x <= n && y <= m) return 1;
    else return 0;
}

inline bool judged(int x, int y) {
    if(x == 1 || y == 1 || x == n || y == m) return 1;
    else return 0;
}

void bfs2(int x, int y) {
    if(vis2[x][y]) return;
    vis2[x][y] = 1;
    if(vis[x][y]) {
        out[x][y] = 1;
        return;
    }
    int i, xx, yy;
    node start, tp, p;
    start.x = x; start.y = y;
    queue<node> Q;
    Q.push(start);
    while(!Q.empty()) {
        tp = Q.front(); Q.pop();
        for(i=0; i<4; i++) {
            xx = tp.x + dir[i][0];
            yy = tp.y + dir[i][1];
            if(judge(xx, yy) && !vis2[xx][yy]) {
                vis2[xx][yy] = 1;
                if(!vis[xx][yy]) {
                    p.x = xx; p.y = yy;
                    Q.push(p);
                } else {
                    out[xx][yy] = 1;
                }
            }
        }
    }
}

void bfs() {
    if(judged(sx, sy)) {
        ans = -1;
        return ;
    }

    memset(vis, 0, sizeof(vis));
    queue<node> Q;
    node tp, p, start;
    start.x = sx; start.y = sy;
    Q.push(start);
    vis[sx][sy] = 1;
    int i, j, k, xx, yy;
    ans = 0;
    while(!Q.empty()) {
        tp = Q.front(); Q.pop();
        //printf("tp:%d %d\n", tp.x, tp.y);
        for(i=0; i<4; i++) {
            xx = tp.x + dir[i][0];
            yy = tp.y + dir[i][1];
            //printf("xx=%d, yy=%d\n", xx, yy);
            if(judge(xx, yy) && !vis[xx][yy]) {
                vis[xx][yy] = 1;
                if(map[xx][yy] == 0) {
                    if(judged(xx, yy)) {
                        //printf("%d %d\n", xx, yy);
                        ans = -1;
                        return ;
                    }
                    p.x = xx; p.y = yy;
                    Q.push(p);
                }
            }
        }
    }
    //printf("###\n");
    memset(out, 0, sizeof(out));
    memset(vis2, 0, sizeof(vis2));
    for(i=1; i<=n; i++) {
        bfs2(1, i);
        bfs2(n, i);
        bfs2(i, 1);
        bfs2(i, n);
    }
}

int main()
{
    while(cin >> n >> m)
    {
        int i, j;
        for(i=1; i<=n; i++) {
            for(j=1; j<=m; j++) {
                scanf("%d", &map[i][j]);
                if(map[i][j] == -1) {
                    sx = i; sy = j;
                }
            }
        }

        //printf("%d %d\n", sx, sy);

        bfs();
/*
        printf("\nans=%d\n", ans);
        for(i=1; i<=n; i++) {
            for(j=1; j<=m; j++) {
                printf("%d ", out[i][j]);
            }
            printf("\n");
        }
*/

        if(ans == -1) {
            printf("Ali Win\n");
            continue;
        }

        for(i=1; i<=n; i++) {
            for(j=1; j<=m; j++) {
                if(vis2[i][j] && !out[i][j]) ans += map[i][j];
                if(out[i][j]) ans += map[i][j] - 1;
            }
        }
        //printf("ans = %d\n", ans);
        if(ans % 2 == 0) printf("Baba Win\n");
        else printf("Ali Win\n");
    }
    return 0;
}