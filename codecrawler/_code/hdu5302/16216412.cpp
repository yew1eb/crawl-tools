#include <bits/stdc++.h>
using namespace std ;

typedef long long LL ;
typedef unsigned long long ULL ;

const int MAXN = 10005 ;

int y[MAXN][2] ;

void solve () {
    int w[3] , b[3] ;
    for ( int i = 0 ; i < 3 ; ++ i ) scanf ( "%d" , &w[i] ) ;
    for ( int i = 0 ; i < 3 ; ++ i ) scanf ( "%d" , &b[i] ) ;
    if ( w[1] % 2 || b[1] % 2 ) {
        printf ( "-1\n" ) ;
        return ;
    }
    int n = w[0] + w[1] + w[2] ;
    int m1 = ( w[1] - 2 ) / 2 + w[2] + 1 ;
    int m2 = ( b[1] - 2 ) / 2 + b[2] + 1 ;
    int m = m1 + m2 ;
    int c2 = 0 , p2 = 2 ;
    for ( int i = 1 ; i <= b[2] + 1 ; ++ i , ++ c2 ) {
        y[c2][0] = p2 ;
        p2 += 2 ;
        if ( p2 > n ) p2 = 1 ;
        y[c2][1] = p2 ;
    }
    for ( int i = 1 ; i <= ( b[1] - 2 ) / 2 ; ++ i , ++ c2 ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            p2 += 2 ;
            if ( p2 > n ) p2 = 1 ;
            y[c2][j] = p2 ;
        }
    }
    for ( int i = 0 ; i < c2 ; ++ i ) {
        if ( y[i][0] == y[i][1] + 1 || y[i][0] + 1 == y[i][1] ) {
            printf ( "-1\n" ) ;
            return ;
        }
    }
    int c1 = 0 , p1 = 1 ;
    printf ( "%d\n" , m ) ;
    for ( int i = 1 ; i <= w[2] + 1 ; ++ i , ++ c1 , ++ p1 ) printf ( "%d %d 0\n" , p1 , p1 + 1 ) ;
    ++ p1 ;
    for ( int i = 1 ; i <= ( w[1] - 2 ) / 2 ; ++ i , ++ c1 , p1 += 2 ) printf ( "%d %d 0\n" , p1 , p1 + 1 ) ;
    for ( int i = 0 ; i < c2 ; ++ i ) printf ( "%d %d 1\n" , y[i][0] , y[i][1] ) ;
}

int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    for ( int i = 1 ; i <= T ; ++ i ) {
        solve () ;
    }
    return 0 ;
}