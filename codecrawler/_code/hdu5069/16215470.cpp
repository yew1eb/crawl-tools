#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

#define rep( i , a , b ) for ( int i = a ; i < b ; ++ i )
#define For( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define rev( i , a , b ) for ( int i = a ; i >= b ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )

const int MAXN = 100005 ;
const int MAXE = 100005 ;

struct Edge {
    int v , n ;
    Edge () {}
    Edge ( int v , int n ) : v ( v ) , n ( n ) {}
} ;

struct Node {
    int v , d , n ;
    Node () {}
    Node ( int v , int d , int n ) : v ( v ) , d ( d ) , n ( n ) {}
} ;

struct Query {
    int v , idx , n ;
    Query () {}
    Query ( int v , int idx , int n ) : v ( v ) , idx ( idx ) , n ( n ) {}
} ;

Query Q[MAXE] ;
Edge E[MAXE] ;
Node N[MAXE] ;
int query[MAXN] , cntQ ;
int H[MAXN] , cntE ;
int node[MAXN] , cntN ;
int word[MAXN] ;
int ans[MAXN] ;
set < int > S[MAXN] ;
int n , m ;

void clear () {
    cntN = cntE = cntQ = 0 ;
    clr ( H , -1 ) ;
    clr ( node , -1 ) ;
    clr ( query , -1 ) ;
}

void addedge ( int u , int v ) {
    E[cntE] = Edge ( v , H[u] ) ;
    H[u] = cntE ++ ;
}

void naddedge ( int u , int v , int d ) {
    N[cntN] = Node ( v , d , node[u] ) ;
    node[u] = cntN ++ ;
}

void qaddedge ( int u , int v , int idx ) {
    Q[cntQ] = Query ( v , idx , query[u] ) ;
    query[u] = cntQ ++ ;
}

struct AC_automation {
    int next[MAXN][4] ;
    int fail[MAXN] ;
    int P ;
    int root ;
    int head , tail ;
    int Q[MAXN] ;
    
    int newnode () {
        rep ( i , 0 , 4 ) next[P][i] = -1 ;
        return P ++ ;
    }
    
    void init () {
        P = 0 ;
        root = newnode () ;
    }
    
    int get ( char c ) {
        if ( c == 'A' ) return 0 ;
        if ( c == 'C' ) return 1 ;
        if ( c == 'G' ) return 2 ;
        if ( c == 'T' ) return 3 ;
    }
    
    void insert ( char buf[] , int idx ) {
        int now = root , d = 0 ;
        for ( int i = 0 ; buf[i] ; ++ i ) {
            int index = get ( buf[i] ) ;
            if ( next[now][index] == -1 ) next[now][index] = newnode () ;
            now = next[now][index] ;
            ++ d ;
            naddedge ( now , idx , d ) ;
        }
        word[idx] = now ;
    }
    
    void build () {
        head = tail = 0 ;
        fail[root] = root ;
        rep ( i , 0 , 4 ) {
            if ( next[root][i] == -1 ) next[root][i] = root ;
            else {
                fail[next[root][i]] = root ;
                Q[tail ++] = next[root][i] ;
            }
        }
        while ( head != tail ) {
            int now = Q[head ++] ;
            rep ( i , 0 , 4 ) {
                if ( ~next[now][i] ) {
                    fail[next[now][i]] = next[fail[now]][i] ;
                    Q[tail ++] = next[now][i] ;
                } else next[now][i] = next[fail[now]][i] ;
            }
        }
    }
} ac ;

void dfs ( int u ) {
    for ( int i = node[u] ; ~i ; i = N[i].n ) S[N[i].v].insert ( N[i].d ) ;//insert
    for ( int i = query[u] ; ~i ; i = Q[i].n ) {//get ans
        int v = Q[i].v ;
        int idx = Q[i].idx ;
        if ( S[v].empty () ) ans[idx] = 0 ;
        else ans[idx] = *( -- S[v].end () ) ;
    }
    for ( int i = H[u] ; ~i ; i = E[i].n ) dfs ( E[i].v ) ;//dfs
    for ( int i = node[u] ; ~i ; i = N[i].n ) S[N[i].v].erase ( N[i].d ) ;//erase
}

char buf[MAXN] ;

void solve () {
    int u , v ;
    ac.init () ;
    clear () ;
    For ( i , 1 , n ) S[i].clear () ;
    For ( i , 1 , n ) {
        scanf ( "%s" , buf ) ;
        ac.insert ( buf , i ) ;
    }
    ac.build () ;
    rep ( i , 1 , ac.P ) addedge ( ac.fail[i] , i ) ;
    rep ( i , 0 , m ) {
        scanf ( "%d%d" , &u , &v ) ;
        qaddedge ( word[u] , v , i ) ;
    }
    dfs ( ac.root ) ;
    rep ( i , 0 , m ) printf ( "%d\n" , ans[i] ) ;
}

int main () {
    while ( ~scanf ( "%d%d" , &n , &m ) ) solve () ;
    return 0 ;
}