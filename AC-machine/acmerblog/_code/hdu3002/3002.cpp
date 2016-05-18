#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
const int INF = 0x3fffffff;
int n, m;
int g[N][N], v[N], d[N];

int Stoer_wagner() 
{
    bool vis[N];
    int i, j, res = INF;
    for ( i = 0; i < n; ++i ) v[i] = i;
    while ( n > 1 ) {
        int maxp = 1, prev = 0;
        for ( i = 1; i < n; ++i ) {
            d[v[i]] = g[v[0]][v[i]];
            if ( d[v[i]] > d[v[maxp]] ) maxp = i;
        }
        memset( vis, 0, sizeof(vis) );
        vis[v[0]] = true;
        for ( i = 1; i < n; i++ ) {
            if ( i == n-1 ) {
                res = min( res, d[v[maxp]] );
                for ( j = 0; j < n; ++j ) {
                    g[v[prev]][v[j]] += g[v[j]][v[maxp]];
                    g[v[j]][v[prev]] = g[v[prev]][v[j]];
                }
                v[maxp] = v[--n];
            }
            vis[v[maxp]] = true;
            prev = maxp;
            maxp = -1;
            for ( j = 1; j < n; ++j ) 
                if ( !vis[v[j]] ) {
                    d[v[j]] += g[v[prev]][v[j]];
                    if ( maxp == -1 || d[v[maxp]] < d[v[j]] ) maxp = j;
                }
        }
    }
    return res;
}
            
int main()
{
    while ( scanf("%d%d", &n, &m ) == 2 ) {
        memset( g, 0, sizeof(g) );
        int x, y, z;
        while ( m-- ) {
            scanf("%d%d%d", &x, &y, &z);
            g[x][y] += z;
            g[y][x] += z;
        }
        printf("%d\n", Stoer_wagner());
    }
}