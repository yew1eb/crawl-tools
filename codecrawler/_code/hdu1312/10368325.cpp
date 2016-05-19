#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 21;
int n, m;
char xx[maxn][maxn];
int ans;
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

void dfs(int x, int y)
{
    int i;
    for(i=0; i<4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx >=0 && tx <n && ty >= 0 && ty <m && xx[tx][ty]=='.') {
            xx[tx][ty] = '#';
            ans++;
            dfs(tx, ty);
        }
    }
}
int main()
{
    int i, j;
    int x, y;
    while(scanf("%d%d",&m,&n)) {
        if(n==0 && m==0) break;
        getchar();
        for(i=0; i<n; ++i) {
            for(j=0; j<m; ++j) {
                scanf("%c",&xx[i][j]);
                if(xx[i][j] == '@') {
                    x = i;
                    y = j;
                    xx[i][j] = '#';
                }
            }
            getchar();
        }
        ans = 1;
        dfs(x, y);
        printf("%d\n", ans);
    }
    return 0;
}
