#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char map[105][105];
int n, m;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int x, int y) {
    map[x][y]='.';
    for(int i=0; i<4; i++)
        if(map[x+dx[i]][y+dy[i]]=='#')
            dfs(x+dx[i],y+dy[i]);
}
int main() {
    int T, ans,i,j;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        memset(map,'.',sizeof(map));
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                cin>>map[i][j];
        ans = 0;
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                if(map[i][j]=='#') {
                    ans++;
                    dfs(i,j);
                }
        cout<<ans<<endl;
    }
    return 0;
}
