#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char map[105][105];
int n, m, ans;
int dx[]={1, 1,-1,-1,0, 0,1,-1};
int dy[]={1,-1, 0, 1,1,-1,0,-1};
void dfs(int x, int y) {
    map[x][y] ='*';
    for(int i=0; i<8; i++)
        if(map[x+dx[i]][y+dy[i]]=='@')
            dfs(x+dx[i],y+dy[i]);
}
int main() {
    int i, j, cnt;
    while(~scanf("%d %d",&n,&m),n+m) {
        memset(map,'*',sizeof(map));
        for(i=1; i<=n; i++) {
            for(j=1; j<=m; j++)
                cin>>map[i][j];
        }
        cnt = 0;
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                if(map[i][j]=='@') {
                    cnt++;
                    dfs(i,j);
//                    for(i=0; i<=n+1; i++)
//                    {
//                        for(j=0; j<=m+1; j++) printf("%c",map[i][j]);
//                        printf("\n");
//                    }
                }
        printf("%d\n",cnt);
    }
    return 0;
}
