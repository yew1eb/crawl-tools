#include <bits/stdc++.h>
using namespace std ;

typedef long long LL ;

const int MAXN = 500005 ;

int a[MAXN] ;
int R[MAXN] ;
int d[MAXN] ;
int nxt[MAXN] ;
int S[MAXN] , top ;
int n , m , k ;

bool check ( int l ) {
    d[n] = 0 ;
    for ( int i = n - 1 ; i >= 1 ; -- i ) {
        if ( R[i] >= n ) d[i] = d[i + 1] + 1 ;
        else if ( R[i] - i < l ) d[i] = d[i + 1] ;
        else d[i] = d[i + 1] + ( d[i + l] > d[R[i] + 1] ) ;
    }
    return d[1] > d[R[0] + 1] ;
}

void get ( int l ) {
    check ( l ) ;
    nxt[n] = 0 ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        nxt[i] = d[i] > d[i + 1] ? i : nxt[i + 1] ;
    }
    top = 0 ;
    int x = nxt[1] ;
    while ( x ) {
        S[top ++] = x ;
        if ( R[x] >= n ) break ;
        x = nxt[x + l] ;
    }
}

void solve () {
    a[0] = m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , a + i ) ;
        a[i] = -a[i] + a[i - 1] ;
    }
    for ( int i = 0 , j = 1 , tmp = 0 ; i < n ; ++ i , tmp += k ) {
        while ( j <= n && tmp + a[j] > 0 ) ++ j ;
        R[i] = j > n ? 1e9 : j - 1 ;
        if ( R[i] <= i ) {
            printf ( "Poor Hero!\n" ) ;
            return ;
        }
    }
    if ( R[0] >= n || R[R[0]] >= n ) printf ( "Poor JRY!\n" ) ;
    else {
        int l = 1 , r = n ;
        while ( l < r ) {
            int mid = ( l + r + 1 ) >> 1 ;
            if ( check ( mid ) ) l = mid ;
            else r = mid - 1 ;
        }
        get ( l ) ;
        printf ( "%d\n" , l ) ;
        printf ( "%d\n" , top ) ;
        for ( int i = 0 ; i < top ; ++ i ) {
            printf ( "%d%c" , S[i] , i < top - 1 ? ' ' : '\n' ) ;
        }
    }
}

int main () {
    while ( ~scanf ( "%d%d%d" , &n , &m , &k ) ) solve () ;
    return 0 ;
}