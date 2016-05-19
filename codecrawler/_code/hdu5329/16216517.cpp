#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std ;
#pragma comment(linker,"/STACK:102400000,102400000") ;
#define maxn 100000+10
struct node{
    int v , next ;
}edge[maxn<<1] ;
int head[maxn] , h_cnt ;
int vis[maxn] ;
int a[maxn] , c[maxn] , n ;
int s[maxn] , m ;
int dp[maxn] ;
int cnt[maxn] , sum[maxn] ;
void add(int u,int v) {
    edge[h_cnt].v = v ;
    edge[h_cnt].next = head[u] ; head[u] = h_cnt++ ;
}
int f(int x) {
    return c[x] == x ? x : c[x] = f(c[x]) ;
}
int find1(int x,int y) {
    if( f(x) == f(y) ) return 1 ;
    c[ f(x) ] = f(y) ;
    return 0 ;
}
void dfs(int u) {
    dp[u] = 1 ;
    int i, v ;
    for(i = head[u] ; i != -1 ; i = edge[i].next) {
        v = edge[i].v ;
        if( vis[v] ) continue ;
        dfs(v) ;
        dp[u] += dp[v] ;
    }
    return ;
}
int solve(int k) {
    int i , max1 , temp = 0 ;
    memset(cnt,0,sizeof(cnt)) ;
    for(i = 1 ; i <= n ; i++) {
        if( vis[i] ) continue ;
        if( dp[i]%k == 0 ) temp++ ;
    }
    sum[0] = 0 ;
    for(i = 1 ; i<= m ; i++) {
        sum[i] = (sum[i-1] + dp[ s[i] ])%k ;
        cnt[ sum[i] ]++ ;
    }
    max1 = cnt[ sum[m] ] + temp ;
    for(i = 1 ; i < m ; i++) {
        cnt[ sum[i] ]-- ;
        cnt[ (sum[m]+sum[i])%k ]++ ;
        max1 = max(max1,cnt[ (sum[m]+sum[i])%k ]+temp) ;
    }
    if( max1 == n/k ) return 1 ;
    return 0 ;
}
int main() {
    int i , j , x , k ,ans ;
    //freopen("1003.in","r",stdin) ;
    //freopen("1111.out","w",stdout) ;
    while( scanf("%d", &n) != EOF ) {
        memset(head,-1,sizeof(head)) ;
        h_cnt = 0 ;
        memset(vis,0,sizeof(vis)) ;
        for(i = 1 ; i <= n ; i++) {
            scanf("%d", &a[i]) ;
            add(a[i],i) ;
            c[i] = i ;
        }
        for(i = 1 ; i <= n ; i++) {
            if( find1(i,a[i]) )
                break ;
        }
        m = 0 ;
        s[ ++m ] = i ;
        vis[i] = 1 ;
        x = a[i] ;
        while( x != s[1] ) {
            s[++m] = x ;
            vis[x] = 1 ;
            x = a[x] ;
        }
        for(i = 1 ; i <= m ; i++)
            dfs(s[i]) ;
        ans = 0 ;
        for(k = 1 ; k <= n ; k++) {
            if( n%k ) continue ;
            ans += solve(k) ;
        }
        printf("%d\n", ans) ;
    }
    return 0 ;
}

/*
12
7 9 12 2 3 4 8 6 10 5 8 1
*/
