#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

#define REP( i , a , b ) for ( int i = a ; i < b ; ++ i )
#define FOR( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define REV( i , a , b ) for ( int i = a ; i >= b ; -- i )
#define CLR( a , x ) memset ( a , x , sizeof a )


const int MAXN = 505 ;
const int MAXE = 3005 ;
const int INF = 0x3f3f3f3f ;

struct Edge {
    int u , v , c ;
} ;

struct MST {
    Edge E[MAXE] ;
    int idx[MAXN] ;
    int vis[MAXN] ;
    int in[MAXN] ;
    int p[MAXN] ;
    int NV , NE ;
    int root ;
    
    void init () {
        NV = 0 ;
        NE = 0 ;
    }
    
    void addedge ( int u , int v , int c ) {
        E[NE].u = u ;
        E[NE].v = v ;
        E[NE].c = c ;
        ++ NE ;
    }
    
    bool zhuliu ( int& res ) {
        res = 0 ;
        root = 0 ;
        while ( 1 ) {
            CLR ( in , INF ) ;
            REP ( i , 0 , NE ) {
                if ( E[i].u != E[i].v && in[E[i].v] > E[i].c ) {
                    in[E[i].v] = E[i].c ;
                    p[E[i].v] = E[i].u ;
                }
            }
            REP ( i , 0 , NV ) if ( i != root && in[i] == INF ) return 0 ;
            int cnt = 0 ; 
            in[root] = 0 ;
            CLR ( vis , -1 ) ;
            CLR ( idx , -1 ) ;
            REP ( i , 0 , NV ) {
                res += in[i] ;
                int v = i ;
                while ( vis[v] != i && idx[v] == -1 && v != root ) {
                    vis[v] = i ;
                    v = p[v] ;
                }
                if ( idx[v] == -1 && v != root ) {
                    for ( int u = p[v] ; u != v ; u = p[u] ) idx[u] = cnt ;
                    idx[v] = cnt ++ ;
                }
            }
            if ( !cnt ) break ;
            REP ( i , 0 , NV ) if ( idx[i] == -1 ) idx[i] = cnt ++ ;
            REP ( i , 0 , NE ) {
                int u = E[i].u ;
                int v = E[i].v ;
                E[i].u = idx[u] ;
                E[i].v = idx[v] ;
                if ( idx[u] != idx[v] ) E[i].c -= in[v] ;
            }
            NV = cnt ;
            root = idx[root] ;
        }
        return 1 ;
    }
} T ;

int n , m ;
int num[MAXN] ;

void solve () {
    int u , v , Lu , Lv , c ;
    int res ;
    T.init () ;
    FOR ( i , 1 , n ) {
        scanf ( "%d" , &num[i] ) ;
        T.addedge ( num[i - 1] + 1 , 0 , 0 ) ;
        FOR ( j , 2 , num[i] ) T.addedge ( num[i - 1] + j , num[i - 1] + j - 1 , 0 ) ;
        num[i] += num[i - 1] ;
    }
    while ( m -- ) {
        scanf ( "%d%d%d%d%d" , &u , &Lu , &v , &Lv , &c ) ;
        u = !Lu ? 0 : num[u - 1] + Lu ;
        v = !Lv ? 0 : num[v - 1] + Lv ;
        T.addedge ( u , v , c ) ;
    }
    T.NV = num[n] + 1 ;
    if ( T.zhuliu ( res ) ) printf ( "%d\n" , res ) ;
    else printf ( "-1\n" ) ;
}

int main () {
    while ( ~scanf ( "%d%d" , &n , &m ) && ( n || m ) ) solve () ;
    return 0 ;
}