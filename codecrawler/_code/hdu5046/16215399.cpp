#include <cstdio>
#include <cstring>
#include <algorithm>
//using namespace std ;

typedef long long LL ;

#pragma comment(linker, "/STACK:16777216")
#define rep( i , a , b ) for ( int i = a ; i < b ; ++ i )
#define For( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define rev( i , a , b ) for ( int i = a ; i >= b ; -- i )
#define rec( i , A , o ) for ( int i = A[o] ; i != o ; i = A[i] )
#define travel( e , H , u ) for ( Edge* e = H[u] ; e ; e = e -> next )
#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )
#define ls ( o << 1 )
#define rs ( o << 1 | 1 )
#define lson ls , l , m
#define rson rs , m + 1 , r
#define mid ( ( l + r ) >> 1 )
#define root 1 , 1 , n

const int MAXNODE = 10000 ;
const int MAXN = 100 ;
const int MAXR = 100 ;
const int MAXC = 100 ;

struct Point {
    int x , y ;
} p[MAXN] ;

int U[MAXNODE] , D[MAXNODE] , L[MAXNODE] , R[MAXNODE] ;
int H[MAXR] , S[MAXC] ;
int col[MAXNODE] ;
int size ;
int n , K ;
LL d[MAXN][MAXN] ;
LL a[3000] ;
bool vis[MAXN] ;
int cnt ;

void clear ( int n ) {
    For ( i , 0 , n ) {
        L[i] = i - 1 ;
        R[i] = i + 1 ;
        U[i] = D[i] = i ;
        S[i] = 0 ;
    }
    clr ( H , -1 ) ;
    L[0] = n ;
    R[n] = 0 ;
    size = n ;
}

void link ( int r , int c ) {
    ++ size ;
    S[c] ++ ;
    col[size] = c ;
    U[size] = U[c] ;
    D[size] = c ;
    D[U[c]] = size ;
    U[c] = size ;
    if ( H[r] != -1 ) {
        L[size] = L[H[r]] ;
        R[size] = H[r] ;
        L[R[size]] = size ;
        R[L[size]] = size ;
    } else H[r] = L[size] = R[size] = size ;
}

void remove ( int c ) {
    rec ( i , D , c ) {
        L[R[i]] = L[i] ;
        R[L[i]] = R[i] ;
    }
}

void resume ( int c ) {
    rec ( i , U , c ) {
        L[R[i]] = R[L[i]] = i ;
    }
}

int h () {
    int cnt = 0 ;
    clr ( vis , 0 ) ;
    rec ( i , R , 0 ) if ( !vis[i] ) {
        ++ cnt ;
        vis[i] = 1 ;
        rec ( j , D , i ) rec ( k , R , j ) vis[col[k]] = 1 ;
    }
    return cnt ;
}

int dance ( int d = 0 ) {
    if ( d + h () > K ) return 0 ;
    if ( !R[0] ) return 1 ;
    int c = R[0] ;
    rec ( i , R , 0 ) if ( S[c] > S[i] ) c = i ;
    rec ( i , D , c ) {
        remove ( i ) ;
        rec ( j , R , i ) remove ( j ) ;
        if ( dance ( d + 1 ) ) return 1 ;
        rec ( j , L , i ) resume ( j ) ;
        resume ( i ) ;
    }
    return 0 ;
}

void make_map ( LL dist ) {
    clear ( n ) ;
    rep ( i , 0 , n ) {
        link ( i + 1 , i + 1 ) ;
        rep ( j , i + 1 , n ) {
            if ( d[i][j] <= dist ) {
                link ( i + 1 , j + 1 ) ;
                link ( j + 1 , i + 1 ) ;
            }
        }
    }
}

int unique ( int n ) {
    int cnt = 1 ;
    std :: sort ( a + 1 , a + n + 1 ) ;
    For ( i , 2 , n ) if ( a[cnt] != a[i] ) a[++ cnt] = a[i] ;
    return cnt ;
}

void solve () {
    scanf ( "%d%d" , &n , &K ) ;
    rep ( i , 0 , n ) scanf ( "%d%d" , &p[i].x , &p[i].y ) ;
    cnt = 0 ;
    rep ( i , 0 , n ) rep ( j , i + 1 , n ) d[j][i] = d[i][j] = ( LL ) abs ( p[i].x - p[j].x ) + ( LL ) abs ( p[i].y - p[j].y ) ;
    rep ( i , 0 , n ) rep ( j , i + 1 , n ) a[++ cnt] = d[i][j] ;
    a[++ cnt] = 0 ;
    cnt = unique ( cnt ) ;
    int l = 1 , r = cnt ;
    LL ans = 0 ;
    while ( l < r ) {
        int m = ( l + r ) >> 1 ;
        make_map ( a[m] ) ;
        if ( dance () ) r = m ;
        else l = m + 1 ;
    }
    printf ( "%I64d\n" , a[l] ) ;
}

int main () {
    int T , cas = 0 ;
    scanf ( "%d", &T ) ;
    while ( T -- ) {
        printf ( "Case #%d: " , ++ cas ) ;
        solve () ;
    }
    return 0 ;
}