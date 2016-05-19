#include <stdio.h>
#include <algorithm>
using namespace std ;

typedef long long LL ;

const int MAXN = 1 << 20 ;

LL a[MAXN] ;
int n ;

void solve () {
    scanf ( "%d" , &n ) ;
    n = 1 << n ;
    for ( int i = 0 ; i < n ; ++ i ) scanf ( "%lld" , &a[i] ) ;
    if ( n == 1 ) printf ( " %lld\n" , a[0] ) ;
    else {
        LL tmp = a[n - 1] ;
        for ( int s = 2 , ds = 1 ; s <= n ; ds = s , s <<= 1 ) {
            for ( int k = 0 ; k < n ; k += s ) {
                for ( int i = k ; i < k + ds ; ++ i ) {
                    LL t = a[i + ds] ;
                    a[i + ds] -= a[i] ;
                    a[i] += t ;
                }
            }
        }
        a[0] -= n / 2 * tmp ;
        int m = n >> 1 ;
        for ( int i = 0 ; i < n ; ++ i ) printf ( " %lld" , a[i] / m ) ;
        printf ( "\n" ) ;
    }
}

int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    for ( int i = 1 ; i <= T ; ++ i ) {
        printf ( "Case #%d:" , i ) ;
        solve () ;
    }
    return 0 ;
}