#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
 
#define REP( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define FOR( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define REV( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define CLR( a , x ) memset ( a , x , sizeof a )
#define CPY( a , x ) memcpy ( a , x , sizeof a )
#define ls ( o << 1 )
#define rs ( o << 1 | 1 )
#define lson ls , l , m
#define rson rs , m + 1 , r
#define root 1 , 1 , n
#define rt o , l , r
#define mid ( ( l + r ) >> 1 )

typedef long long LL ;

const int MAXN = 10005 ;
const int mod = 123456789 ;

struct Node {
    int v , idx ;
    bool operator < ( const Node& a ) const {
        return v != a.v ? v < a.v : idx > a.idx ;
    }
} a[MAXN] ;

int sum[101][MAXN << 2] ;
int n , k ;

void update ( int pos , int v , int x , int o , int l , int r ) {
    if ( l == r ) {
        sum[x][o] = v ;
        return ;
    }
    int m = mid ;
    if ( pos <= m ) update ( pos , v , x , lson ) ;
    else update ( pos , v , x , rson ) ;
    sum[x][o] = sum[x][ls] + sum[x][rs] ;
    if ( sum[x][o] >= mod ) sum[x][o] -= mod ;
}

int query ( int L , int R , int x , int o , int l , int r ) {
    if ( L > R ) return 0 ;
    if ( L <= l && r <= R ) return sum[x][o] ;
    int m = mid ;
    if ( R <= m ) return query ( L , R , x , lson ) ;
    if ( m <  L ) return query ( L , R , x , rson ) ;
    int ans = query ( L , R , x , lson ) + query ( L , R , x , rson ) ;
    if ( ans >= mod ) ans -= mod ;
    return ans ;
}

void scanf ( int& x , char c = 0 ) {
    while ( ( c = getchar () ) < '0' || c > '9' ) ;
    x = c - '0' ;
    while ( ( c = getchar () ) >= '0' && c <= '9' ) x = x * 10 + c - '0' ;
}

void solve () {
    FOR ( i , 1 , k ) CLR ( sum[i] , 0 ) ;
    FOR ( i , 1 , n ) {
        scanf ( a[i].v ) ;
        a[i].idx = i ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    FOR ( i , 1 , n ) {
        update ( a[i].idx , 1 , 1 , root ) ;
        FOR ( j , 1 , k - 1 ) {
            int tmp = query ( 1 , a[i].idx - 1 , j , root ) ;
            if ( !tmp ) break ;
            update ( a[i].idx , tmp , j + 1 , root ) ;
        }
    }
    printf ( "%d\n" , sum[k][1] ) ;
}

int main () {
    while ( ~scanf ( "%d%d" , &n , &k ) ) solve () ;
    return 0 ;
}