#include <stdio.h>
#include <string.h>
#include <vector>
#pragma comment(linker, "/STACK:16777216")
#include <algorithm>
using namespace std ;

typedef long long LL ;

#define clr( a , x ) memset ( a , x , sizeof a )

const int MAXM = 105 ;
const int MAXN = 100005 ;
const int INF = 0x3f3f3f3f ;

vector < int > G[MAXN] ;
int dp[MAXM][MAXN] ;
int qp[MAXM][MAXN] ;
int U[MAXM][MAXN] ;
int w[MAXN] ;
int n , m ;

void dfs ( int u , int f ) {
    int n = G[u].size () , wu = w[u] ;
    if ( n == 1 ) {
        dp[w[u]][u] = 1 ;
        qp[1][u] = 0 ;
        qp[0][u] = dp[1][u] ;
        return ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        int v = G[u][i] ;
        if ( v != f ) dfs ( v , u ) ;
    }
    for ( int o = 1 ; o <= m ; ++ o ) {
        LL sum = 0 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            int v = G[u][i] ;
            if ( v == f ) continue ;
            U[o][v] = min ( U[o - 1][v] , min ( dp[o + 1][v] , qp[o - 1][v] ) ) ;
            sum += U[o][v] ;
        }
        for ( int i = 0 ; i < n ; ++ i ) {
            int v = G[u][i] ;
            if ( v == f ) continue ;
            dp[o][u] = min ( ( LL ) dp[o][u] , sum - U[o][v] + dp[o + 1][v] ) ;
            qp[o][u] = min ( ( LL ) qp[o][u] , sum - U[o][v] + qp[o - 1][v] ) ;
        }
    }
    for ( int i = 1 ; i <= wu ; ++ i ) {
        dp[wu][u] = min ( dp[wu][u] , min ( dp[i][u] , qp[i][u] ) + 1 ) ;
    }
    qp[0][u] = dp[1][u] ;
}

void solve () {
    int u , v ;
        m = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &w[i] ) ;
        w[i] ++ ;
        G[i].clear () ;
        m = max ( m , w[i] ) ;
    }
    for ( int o = 0 ; o <= m + 1 ; ++ o ) {
        clr ( U[o] , INF ) ;
        clr ( dp[o] , INF ) ;
        clr ( qp[o] , INF ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        scanf ( "%d%d" , &u , &v ) ;
        G[u].push_back ( v ) ;
        G[v].push_back ( u ) ;
    }
    G[1].push_back ( 0 ) ;
    dfs ( 1 , 0 ) ;
    int ans = INF ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        ans = min ( ans , dp[i][1] ) ;
    }
    printf ( "%d\n" , ans ) ;
}

int main () {
    while ( ~scanf ( "%d" , &n ) ) solve () ;
}