#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

#define REP( i , n ) for ( int i = 0 ; i < n ; ++ i )
#define REPF( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define REPV( i , a , b ) for ( int i = a ; i >= b ; -- i )
#define clear( a , x ) memset ( a , x , sizeof a )


typedef long long LL ;

const int MAXN = 30005 ;
const int MAXH = 30005 ;
const int MAXE = 100005 ;

struct Edge {
    int v , n ;
    Edge () {}
    Edge ( int var , int next ) :
        v ( var ) , n ( next ) {}
} ;

struct priority_queue {
    int heap[MAXH] ;
    int point ;
    
    void init () {
        point = 1 ;
    }
    
    void push ( int idx ) {
        heap[point] = idx ;
        int o = point ++ ;
        while ( o > 1 && heap[o] > heap[o >> 1] ) {
            swap ( heap[o] , heap[o >> 1] ) ;
            o >>= 1 ;
        }
    }
    
    int empty () {
        return point == 1 ;
    }
    
    void pop () {
        heap[1] = heap[-- point] ;
        int o = 1 , p = o , l = o << 1 , r = o << 1 | 1 ;
        while ( o < point ) {
            if ( l < point && heap[l] > heap[p] )
                p = l ;
            if ( r < point && heap[r] > heap[p] )
                p = r ;
            if ( p == o )
                break ;
            swap ( heap[o] , heap[p] ) ;
            o = p , l = o << 1 , r = o << 1 | 1 ;
        }
    }

    int front () {
        return heap[1] ;
    }
} ;



priority_queue q ;
Edge E[MAXE] ;
int hd[MAXN] , cntE ;
int in[MAXN] ;
int n , m ;
int ans[MAXN] ;

void solve () {
    int cnt = 0 ;
    q.init () ;
    REPF ( i , 1 , n )
        if ( !in[i] )
            q.push ( i ) ;
    while ( !q.empty () ) {
        int u = q.front () ;
        q.pop () ;
        ans[++ cnt] = u ;
        for ( int i = hd[u] ; ~i ; i = E[i].n ) {
            int v = E[i].v ;
            if ( 0 == ( -- in[v] ) )
                q.push ( v ) ;
        }
    }
    REPV ( i , cnt , 1 )
        printf ( "%d%c" , ans[i] , i > 1 ? ' ' : '\n' ) ;
}



void addedge ( int u , int v ) {
    E[cntE] = Edge ( v , hd[u] ) ;
    hd[u] = cntE ++ ;
}

void read ( int &x ) {
    x = 0 ;
    char c = ' ' ;
    while ( c < '0' || c > '9' )
        c = getchar () ;
    while ( c >= '0' && c <= '9' )
        x = x * 10 + c - '0' , c = getchar () ;
}

void work () {
    int u , v ;
    clear ( in , 0 ) ;
    clear ( hd , -1 ) ;
    cntE = 0 ;
    read ( n ) , read ( m ) ;
    REP ( i , m ) {
        read ( u ) , read ( v ) ;
        addedge ( v , u ) ;
        ++ in[u] ;
    }
    solve () ;
}

int main () {
    int T ;
    read ( T ) ;
    while (  T -- )
        work () ;
    return 0 ;
}