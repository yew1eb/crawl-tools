#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define N 55
using namespace std;

struct node {
    int x, y, z;
    int step;
};
int dx[]= {1,-1,0,0,0,0};
int dy[]= {0,0,1,-1,0,0};
int dz[]= {0,0,0,0,1,-1};

int A, B, C, T;
int map[N][N][N];

void init() {
    int i, j, k;
    scanf("%d%d%d%d",&A, &B, &C, &T);
    for(i=0; i<A; i++)
    for(j=0; j<B; j++)
    for(k=0; k<C; k++)
        scanf("%d",&map[i][j][k]);
}

int bfs() {
    int i;
    node e, tmp;
    queue<node> q;
    e.x = e.y =e.z = e.step  = 0;
    q.push(e);
    map[e.x][e.y][e.z] = 1;
    while(!q.empty()) {
        e = q.front();
        q.pop();
        if(e.step>T) return -1;
        if(e.x==A-1&&e.y==B-1&&e.z==C-1) {
            if(e.step<=T)
            return  e.step;
        }
        for(i=0; i<6; i++) {
            int x = e.x + dx[i];
            int y = e.y + dy[i];
            int z = e.z + dz[i];
            if(x<0||x>=A||y<0||y>=B||z<0||z>=C||map[x][y][z]) continue;
            tmp.x = x, tmp.y = y, tmp.z = z, tmp.step = e.step+1;
            map[x][y][z] = 1;
            q.push(tmp);
        }
    }
    return -1;
}

int main() {
    int k;
    scanf("%d",&k);
    while(k--) {
        init();
        if(T<(A+B+C-3) ) {
            printf("-1\n");
            continue;
        }
        int ans = bfs();
        printf("%d\n",ans);
    }
    return 0;
}
