#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
int map[10][10];
int sx,sy,ex,ey, n, m;
struct node {
    int x, y,step,time;
};
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

int bfs() {
    int i;
    node first, next;
    queue<node> q;
    first.x =sx;
    first.y = sy;
    first.time = 6;
    first.step = 0;
    q.push(first);
    while(!q.empty()) {
        first = q.front();
        q.pop();
        for(i=0; i<4; i++) {
            next.x = first.x + dx[i];
            next.y = first.y + dy[i];
            next.step = first.step + 1;
            next.time = first.time - 1;
            if(next.x<0||next.x>=n||next.y<0||next.y>=m||map[next.x][next.y]==0||next.time==0) continue;
            if(map[next.x][next.y]==3) return next.step;
            if(map[next.x][next.y]==4) {
                next.time = 6;
                map[next.x][next.y] = 0;
            }
            q.push(next);
        }
    }
    return -1;
}


int main() {
    int T, i, j;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)
            for(j=0; j<m; j++) {
                scanf("%d",&map[i][j]);
                if(map[i][j]==2)
                    sx=i,sy = j;
                else if(map[i][j]==3)
                    ex=i,ey = j;
            }
        printf("%d\n", bfs());
    }
    return 0;
}









