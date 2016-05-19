#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std ;

#define clr( a , x ) memset ( a , x , sizeof a )

typedef long long LL ;

const int MAXN = 40 ;

LL a[MAXN] ;
int n ;

int gauss ( int equ , int var ) {
    int r , c , tmp_r ;
    for ( r = 0 , c = 0 ; r < equ && c < var ; ++ r , ++ c ) {
        for ( tmp_r = r ; tmp_r < equ ; ++ tmp_r ) if ( a[tmp_r] & ( 1LL << c ) ) break ;
        if ( tmp_r == equ ) {
            -- r ;
            continue ;
        }
        swap ( a[tmp_r] , a[r] ) ;
        for ( int i = r + 1 ; i < equ ; ++ i ) if ( a[i] & ( 1LL << c ) ) a[i] ^= a[r] ;
    }
    return r < equ ;
}

int solve () {
    scanf ( "%d" , &n ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( i > 40 ) scanf ( "%*I64d" ) ;
        else scanf ( "%I64d" , &a[i] ) ;
    }
    if ( n > 40 ) return 1 ;
    if ( gauss ( n , 40 ) ) return 1 ;
    return 0 ;
}

int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    while ( T -- ) printf ( solve () ? "Yes\n" : "No\n" ) ;
    return 0 ;
}