#include <bits/stdc++.h>
using namespace std ;

typedef long long LL ;

#define clr(a,x) memset ( a , x , sizeof a )

const int MAXN = 131072 ;
const int MAXM = 2000005 ;
const LL mod = ( 1LL << 47 ) * 7 * 4451 + 1 ;
const LL g = 3 ;

struct Node {
    LL x , y ;
} ;

LL x1[MAXN] , x2[MAXN] ;
LL ans[MAXN] ;
Node a[MAXN] ;
int n ;

LL mul ( LL x , LL y ) {
    return ( x * y - ( long long ) ( x / ( long double ) mod * y + 1e-3 ) * mod + mod ) % mod ;
}

LL power ( LL a , LL b ) {
    LL res = 1 , tmp = a ;
    while ( b ) {
        if ( b & 1 ) res = mul ( res , tmp ) ;
        tmp = mul ( tmp , tmp ) ;
        b >>= 1 ;
    }
    return res ;
}

void DFT ( LL y[] , int n , bool rev ) {
    for ( int i = 1 , j , t , k ; i < n ; ++ i ) {
        for ( k = n >> 1 , t = i , j = 0 ; k ; k >>= 1 , t >>= 1 ) {
            j = j << 1 | t & 1 ;
        }
        if ( i < j ) swap ( y[i] , y[j] ) ;
    }
    for ( int s = 2 , ds = 1 ; s <= n ; ds = s , s <<= 1 ) {
        LL wn = power ( g , ( mod - 1 ) / s ) ;
        if ( !rev ) wn = power ( wn , mod - 2 ) ;
        for ( int k = 0 ; k < n ; k += s ) {
            LL w = 1 , t ;
            for ( int i = k ; i < k + ds ; ++ i , w = mul ( w , wn ) ) {
                y[i + ds] = ( y[i] - ( t = mul ( y[i + ds] , w ) ) + mod ) % mod ;
                y[i] = ( y[i] + t ) % mod ;
            }
        }
    }
}

void FFT ( LL x1[] , LL x2[] , int n ) {
    DFT ( x1 , n , 1 ) ;
    DFT ( x2 , n , 1 ) ;
    for ( int i = 0 ; i < n ; ++ i ) x1[i] = mul ( x1[i] , x2[i] ) ;
    DFT ( x1 , n , 0 ) ;
    LL vn = power ( n , mod - 2 ) ;
    for ( int i = 0 ; i < n ; ++ i ) x1[i] = mul ( x1[i] , vn ) ;
}

void solve () {
    int x , L = 0 , s = 0 ;
    scanf ( "%d" , &n ) ;
    clr ( a , 0 ) ;
    ans[0] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &x ) ;
        if ( x ) L = i ;
        ans[0] += ( LL ) ( i - L ) * ( i - L + 1 ) / 2 ;
        s += x ;
        a[s].x += i ;
        a[s].y ++ ;
    }
    a[0].y ++ ;
    int n1 = 1 ;
    while ( n1 <= 2 * s ) n1 <<= 1 ;
    for ( int i = 0 ; i <= s ; ++ i ) {
        x1[i] = a[i].x ;
        x2[i] = a[s - i].y ;
    }
    for ( int i = s + 1 ; i < n1 ; ++ i ) x1[i] = x2[i] = 0 ;
    FFT ( x1 , x2 , n1 ) ;
    for ( int i = 1 ; i <= s ; ++ i ) {
        ans[i] = x1[i + s] ;
    }
    for ( int i = 0 ; i <= s ; ++ i ) {
        x1[i] = a[i].y ;
        x2[i] = a[s - i].x ;
    }
    for ( int i = s + 1 ; i < n1 ; ++ i ) x1[i] = x2[i] = 0 ;
    FFT ( x1 , x2 , n1 ) ;
    for ( int i = 1 ; i <= s ; ++ i ) {
        ans[i] -= x1[i + s] ;
    }
    for ( int i = 0 ; i <= s ; ++ i ) {
        printf ( "%I64d\n" , ans[i] ) ;
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