#pragma comment(linker, "/STACK:16777216")
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std ;

typedef long long LL ;

#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )
#define ls ( o << 1 )
#define rs ( o << 1 | 1 )
#define lson ls , l , m
#define rson rs , m + 1 , r
#define root 1 , 1 , n
#define mid ( ( l + r ) >> 1 )

const int MAXN = 100005 ;
const int MAXE = 200005 ;
const int L = ( 1 << 25 ) - 1 ;

int c[MAXN * 100][2] ;
int cnt[MAXN * 100] ;
int cur ;

struct Trie {
    int Root ;

    int newnode () {
        ++ cur ;
        c[cur][0] = c[cur][1] = cnt[cur] = 0 ;
        return cur ;
    }

    void init () {
        cur = 0 ;
        Root = newnode () ;
    }

    void insert ( int v , int val ) {
        int now = Root ;
        for ( int i = 30 ; i >= 0 ; -- i ) {
            int x = ( v >> i ) & 1 ;
            int& l = c[now][0] ;
            int& r = c[now][1] ;
            if ( x == 0 ) {
                if ( l == 0 ) l = newnode () ;
                now = l ;
            } else if ( x == 1 ) {
                if ( r == 0 ) r = newnode () ;
                now = r ;
            }
            cnt[now] += val ;
        }
    }

    int query ( int v ) {
        int now = Root ;
        int res = 0 ;
        for ( int i = 30 ; i >= 0 ; -- i ) {
            int x = ( v >> i ) & 1 ;
            int l = c[now][0] ;
            int r = c[now][1] ;
            if ( ( !l || l && !cnt[l] ) && ( !r || r && !cnt[r] ) ) return 0 ;
            if ( x == 1 ) {
                if ( l && cnt[l] ) {
                    res += 1 << i ;
                    now = l ;
                } else now = r ;
            } else if ( x == 0 ) {
                if ( r && cnt[r] ) {
                    res += 1 << i ;
                    now = r ;
                } else now = l ;
            }
        }
        return res ;
    }
} ;

struct Edge {
    int v , n ;
    Edge () {}
    Edge ( int v , int n ) : v ( v ) , n ( n ) {}
} ;

struct Node {
    int v , x , f ;
    Node () {}
    Node ( int v , int x , int f ) : v ( v ) , x ( x ) , f ( f ) {}
} ;

Trie T ;
Edge E[MAXE] ;
int H[MAXN] , cntE ;
int in[MAXN] , ou[MAXN] , dfs_clock ;
int val[MAXN] ;
int ans[MAXN] ;
vector < Node > G[MAXN << 2] ;
int n , m ;

void init () {
    dfs_clock = 0 ;

    cntE = 0 ;
    clr ( H , -1 ) ;
}

void addedge ( int u , int v ) {
    E[cntE] = Edge ( v , H[u] ) ;
    H[u] = cntE ++ ;
}

void dfs ( int u ) {
    in[u] = ++ dfs_clock ;
    for ( int i = H[u] ; ~i ; i = E[i].n ) {
        int v = E[i].v ;
        dfs ( v ) ;
    }
    ou[u] = dfs_clock ;
}

void build ( int o , int l , int r ) {
    G[o].clear () ;
    //T[o].insert ( 0 , 1 ) ;
    if ( l == r ) return ;
    int m = mid ;
    build ( lson ) ;
    build ( rson ) ;
}

void update ( int L , int R , int v , int val , int o , int l , int r ) {
    if ( L <= l && r <= R ) {
        G[o].push_back ( Node ( v , val , 0 ) ) ;
        return ;
    }
    int m = mid ;
    if ( L <= m ) update ( L , R , v , val , lson ) ;
    if ( m <  R ) update ( L , R , v , val , rson ) ;
}

void query ( int x , int v , int idx , int o , int l , int r ) {
    G[o].push_back ( Node ( v , idx , 1 ) ) ;
    if ( l == r ) return ;
    int m = mid ;
    if ( x <= m ) query ( x , v , idx , lson ) ;
    else query ( x , v , idx , rson ) ;
}

void deal ( int o , int l , int r ) {
    T.init () ;
    for ( int i = 0 ; i < G[o].size () ; ++ i ) {
        int v = G[o][i].v , x = G[o][i].x ;
        if ( G[o][i].f == 0 ) {
            T.insert ( v , x ) ;
        } else {
            ans[x] = max ( ans[x] , T.query ( v ) ) ;
        }
    }
    if ( l == r ) return ;
    int m = mid ;
    deal ( lson ) ;
    deal ( rson ) ;
}

void solve () {
    int x , y , op ;
    init () ;
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        scanf ( "%d" , &x ) ;
        addedge ( x , i ) ;
    }
    dfs ( 1 ) ;
    build ( root ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &val[i] ) ;
        update ( in[i] , ou[i] , val[i] , 1 , root ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        ans[i] = -1 ;
        scanf ( "%d" , &op ) ;
        if ( op == 0 ) {
            scanf ( "%d%d" , &x , &y ) ;
            update ( in[x] , ou[x] , val[x] , -1 , root ) ;
            val[x] = y ;
            update ( in[x] , ou[x] , val[x] , 1 , root ) ;
        } else {
            scanf ( "%d" , &x ) ;
            query ( in[x] , val[x] , i , root ) ;
        }
    }
    deal ( root ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( ans[i] != -1 ) printf ( "%d\n" , ans[i] ) ;
    }
}

int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    for ( int i = 1 ; i <= T ; ++ i ) {
        solve () ;
    }
    return 0 ;
}