#include <stdio.h>
#include <math.h>
#include <string.h>
char map[10][10];
int dis[10][10];
int n, m, s;
int sx, sy, ex, ey;
int flag;
int dx[]= {0,1,-1,0};
int dy[]= {1,0,0,-1};
void dfs(int x, int y, int k) {
    int i, xx , yy;
    if(flag) return;
    if(k>s) return;
    if(k==s)
    {
        if(x==ex && y==ey) flag = 1;
        return;
    }
    int t = s-k-dis[x][y];
    if( t<0 | t&1 ) return;
    for(i=0; i<4; ++i) {
        xx= x + dx[i];
        yy= y + dy[i];
        if(xx<0 || xx >= n || yy <0 || yy >=m || map[xx][yy] =='X') continue;
        if(map[xx][yy] != 'X') {
            map[xx][yy] ='X';
            dfs(xx, yy, k+1);
            map[xx][yy] = '.';
        }
    }
}
int main() {
    int i, j, count;
    int ch;
    while(scanf("%d%d%d",&n,&m,&s)) {
        if(n==0 && m==0 && s==0) break;
        flag = 0;
        count = 0;
        for(i=0; i<n; i++) scanf("%s",map[i]);
        for(i=0; i<n; ++i)
            for(j=0; j<m; ++j) {
                if(map[i][j] == 'S') {
                    sx = i;
                    sy = j;
                    map[i][j]='X';
                }
                if(map[i][j] == 'D') {
                    ex = i;
                    ey = j;
                }
                if(map[i][j]=='.')  count++;
            }
            
            if(count+1< s) {printf("NO\n");continue;}
            
            for(i=0; i<n; ++i)
                for(j=0; j<m; ++j)
                    dis[i][j] = abs(ex-i) + abs(ey-j);
                dfs(sx, sy, 0);
                if(flag) printf("YES\n");
                else printf("NO\n");
    }
    return 0;
}
