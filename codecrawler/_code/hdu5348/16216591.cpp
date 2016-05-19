#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <algorithm>
using namespace std ;
#pragma comment(linker, "/STACK:102400000,102400000")
#define LL __int64
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
const int mod = 1e9+7 ;
const double eqs = 1e-9 ;
struct node{
    int u , v , id ;
    int next ;
}edge[700000];
int head[100010] , cnt , vis[700000] ;
int in[100010] , out[100010] , num[100010] ;
int ans[700000] , n ;
void add(int u,int v,int id) {
    edge[cnt].u = u ; edge[cnt].v = v ;
    edge[cnt].id = id ;
    edge[cnt].next = head[u] ; head[u] = cnt++ ;
}
void dfs1(int u) {
    int i , v ;
    for(i = head[u] ; i != -1 ; i = edge[i].next ) {
        if( vis[i] ) {
            head[u] = edge[i].next ;
            continue ;
        }
        v = edge[i].v ;
        if( u != v && in[v] > out[v] ) continue ;
        vis[i] = vis[i^1] = 1 ;
        if( i%2 ) ans[i/2] = 0 ;
        else ans[i/2] = 1 ;
        out[u]++ ;
        in[v]++ ;
        head[u] = edge[i].next ;
        dfs1(v) ;
        break ;
    }
}
void dfs2(int u) {
    int i , v ;
    for(i = head[u] ; i != -1 ; i = edge[i].next) {
        if( vis[i] ) {
            head[u] = edge[i].next ;
            continue ;
        }
        v = edge[i].v ;
        if( u != v && out[v] > in[v] ) continue ;
        vis[i] = vis[i^1] = 1 ;
        if( i%2 ) ans[i/2] = 1 ;
        else ans[i/2] = 0 ;
        out[v]++ ;
        in[u]++ ;
        head[u] = edge[i].next ;
        dfs2(v) ;
        break ;
    }

}
int main() {
    int t , m ;
    int i , j , u , v ;
    scanf("%d", &t) ;
    while( t-- ) {
        scanf("%d %d", &n, &m) ;
        cnt = 0 ;
        for(i = 1 ; i <= n ; i++) {
            head[i] = -1 ;
            in[i] = out[i] = num[i] = 0 ;
        }
        for(i = 0 ; i <= 2*m ; i++)
            vis[i] = 0 ;
        for(i = 0 ; i < m ; i++) {
            scanf("%d %d", &u, &v) ;
            add(u,v,i) ;
            add(v,u,i) ;
            num[u]++ ;
            num[v]++ ;
        }
        for(i = 1 ; i <= n ; i++) {
            while( in[i] + out[i] < num[i] ) {
                if( in[i] >= out[i] )
                    dfs1(i) ;
                else
                    dfs2(i) ;
            }
        }
        for(i = 0 ; i < m ; i++) {
            printf("%d\n", ans[i]) ;
        }

    }
    return 0 ;
}