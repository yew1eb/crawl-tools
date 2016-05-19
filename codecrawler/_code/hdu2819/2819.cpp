#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
int n, g[N][N], cx[N], cy[N], ans1[N*2], ans2[N*2];
bool used[N];

bool dfs( int u ) 
{
    for ( int i = 1; i <= n; ++i ) if ( g[u][i] && !used[i] ) {
        used[i] = true;
        if ( cy[i] == -1 || dfs( cy[i] ) ) {
            cy[i] = u;
            cx[u] = i;
            return true;
        }
    }
    return false;
}
int match()
{
    int res = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for ( int i = 1; i <= n; ++i ){
        memset( used, 0, sizeof(used));
        if ( dfs(i) ) res++;
        else break;
    }
    return res;
}
int main()
{
    while ( scanf("%d", &n) != EOF ) {
        for ( int i = 1; i <= n; ++i )
            for ( int j = 1; j <= n; ++j ) scanf("%d", &g[i][j]);
        if ( match() != n ) {
            printf("-1\n");
            continue;
        }
        int len = 0;
        for ( int i = 1; i <= n; ++i ) {
            int mark = i, tmp;
            for ( int j = i; j <= n; ++j ) 
                if ( cy[mark] > cy[j] ) mark = j;
            if ( mark == i ) continue;
            ans1[++len] = i, ans2[len] = mark;
            tmp = cy[mark];
            cy[mark] = cy[i];
            cy[i] = tmp;
        }
        printf("%d\n", len);
        for ( int i = 1; i <= len; ++i ) printf("C %d %d\n", ans1[i], ans2[i]);
    }
}