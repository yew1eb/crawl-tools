#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std ;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define maxn 200050
struct E{
    int v , next ;
}edge[maxn] ;
int head[maxn] , cnt ;
struct node{
    int u , v , w ;
    int lca ;
}p[maxn] ;
int dep[maxn] , rmq[maxn][20] ;
int l[100010] , r[maxn] , cid ;
vector <int> vec[maxn] ;
int dp[maxn] , sum[maxn] ;
int c1[maxn] , c2[maxn] ;
void add_E(int u,int v) {
    edge[cnt].v = v ;
    edge[cnt].next = head[u] ; head[u] = cnt++ ;
    edge[cnt].v = u ;
    edge[cnt].next = head[v] ; head[v] = cnt++ ;
}
void dfs(int fa,int u) {
    l[u] = ++cid ;
    int i , j , v ;
    for(i = head[u] ; i != -1 ; i = edge[i].next) {
        v = edge[i].v ;
        if( v == fa ) continue ;
        dep[v] = dep[u] + 1 ;
        rmq[v][0] = u ;
        for(j = 1 ; j < 20 ; j++)
            rmq[v][j] = rmq[ rmq[v][j-1] ][j-1] ;
        dfs(u,v) ;
    }
    r[u] = ++cid ;
}
int lca(int u,int v) {
    if( dep[u] < dep[v] )
        swap(u,v) ;
    int i , j ;
    for(i = 19 ; i >= 0 ; i--) {
        if( dep[ rmq[u][i] ] >= dep[v] )
            u = rmq[u][i] ;
        if( u == v ) return u ;
    }
    for(i = 19 ; i >= 0 ; i--) {
        if( rmq[u][i] != rmq[v][i] ){
            u = rmq[u][i] ;
            v = rmq[v][i] ;
        }
    }
    return rmq[u][0] ;
}
int lowbit(int x) {
    return  x & -x ;
}
void add(int i,int k,int *c,int n) {
    while( i <= n ) {
        c[i] += k ;
        i += lowbit(i) ;
    }
}
int getsum(int i,int *c) {
    int ans = 0 ;
    while( i ) {
        ans += c[i] ;
        i -= lowbit(i) ;
    }
    return ans ;
}
void solve(int fa,int s,int n) {
    dp[s] = sum[s] = 0 ;
    int i , j , u , v , temp ;
    for(i = head[s] ; i != -1 ;i = edge[i].next) {
        v = edge[i].v ;
        if( v == fa ) continue ;
        solve(s,v,n) ;
        sum[s] += dp[v] ;
    }
    dp[s] = sum[s] ;
    for(i = 0 ; i < vec[s].size() ; i++) {
        u = p[ vec[s][i] ].u ;
        v = p[ vec[s][i] ].v ;
        temp = getsum(l[u],c1) + getsum(l[v],c1) - getsum(l[u],c2) - getsum(l[v],c2) + sum[s] ;
        dp[s] = max(dp[s],temp+p[vec[s][i]].w) ;
    }
    add(l[s],sum[s],c1,n*2) ;
    add(r[s],-sum[s],c1,n*2) ;
    add(l[s],dp[s],c2,n*2) ;
    add(r[s],-dp[s],c2,n*2) ;
}
void init(int n) {
    memset(head,-1,sizeof(head)) ;
    memset(rmq,0,sizeof(rmq)) ;
    memset(c1,0,sizeof(c1)) ;
    memset(c2,0,sizeof(c2)) ;
    cnt = cid = 0 ;
    dep[1] = 1 ;
    rmq[1][0] = 1  ;
    for(int i = 1 ; i <= n ; i++)
        vec[i].clear() ;
    return ;
}
int main() {
    int t , n , m ;
    int i , j , u , v , w ;
    //freopen("1006.in","r",stdin) ;
    //freopen("t.out","w",stdout) ;
    scanf("%d", &t) ;
    while( t-- ) {
        scanf("%d %d", &n, &m) ;
        init(n) ;
        for(i = 1 ; i < n ; i++) {
            scanf("%d %d", &u, &v) ;
            add_E(u,v) ;
        }
        dfs(-1,1) ;
        for(i = 0 ; i < m ; i++) {
            scanf("%d %d %d", &p[i].u, &p[i].v, &p[i].w) ;
            p[i].lca = lca(p[i].u,p[i].v) ;
            vec[ p[i].lca ].push_back(i) ;
        }
        solve(-1,1,n) ;
        printf("%d\n", dp[1]) ;
    }
    return 0 ;
}
