#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

typedef long long LL ;

#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )
#define ls ( o << 1 )
#define rs ( o << 1 | 1 )
#define lson ls , l , m
#define rson rs , m + 1 , r
#define rt o , l , r
#define root 1 , 1 , n
#define mid ( ( l + r ) >> 1 )

const int MAXN = 55 ;
const int mod = 1000000007 ;

int c[MAXN][MAXN] ;
LL sum[MAXN][MAXN] ;
int n , m ;

void preprocess () {
    clr ( c , 0 ) ;
    clr ( sum , 0 ) ;
    c[0][0] = 1 ;
    For ( i , 1 , 50 ) {
        c[i][0] = 1 ;
        For ( j , 1 , i ) {
            c[i][j] = ( c[i - 1][j - 1] + c[i - 1][j] ) % mod ;
            sum[i][1] = ( sum[i][1] + c[i][j] ) % mod ;
        }
        For ( j , 2 , 50 ) sum[i][j] = sum[i][j - 1] * sum[i][1] % mod ;
    }
}

void solve () {
    int ans = 0 ;
    LL sign = 1 ;
    rep ( i , 0 , m ) {
        ans = ( ans + sign * c[m][i] * sum[m - i][n] ) % mod ;
        sign = -sign ;
    }
    printf ( "%d\n" , ( ans % mod + mod ) % mod ) ;
}

int main () {
    preprocess () ;
    while ( ~scanf ( "%d%d" , &n , &m ) ) solve () ;
    return 0 ;
}