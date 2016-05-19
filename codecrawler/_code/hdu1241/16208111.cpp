#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char map[105][105];
int n, m;
int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1} } ;

bool inmap(int x,int y) {
    if(x<0 || y<0 || x>=m || y>=n) return false;
    return true;
}

void dfs(int x, int y) {
    int xx, yy, i;
    for(i=0; i<8; i++) {
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        if(inmap(xx, yy) && map[xx][yy] == '@') {
            map[xx][yy] = '*';
            dfs(xx, yy);
        }
    }
}

int main() {
    int i, j, cnt;
    while(scanf("%d%d",&m,&n)!=EOF) {
        if(!m) break;
        getchar();
        for(i=0; i<m; i++)
            scanf("%s",map[i]);
        cnt = 0;
        for(i=0; i<m; i++) {
            for(j=0; j<n; j++) {
                if(map[i][j] == '@') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
