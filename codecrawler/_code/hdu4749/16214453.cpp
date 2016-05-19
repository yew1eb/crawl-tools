#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

const int maxn = 111111 ;
int g1[26][maxn] , g2[26][maxn] ;
int p[maxn] , a[maxn] , b[maxn] ;
int vis[maxn] ;

int n , m , t ;

int ok ( int x , int y ) {
    int c1 = 0 , i , c2 = 0 , c3 = 0 ;
    if ( g1[a[x]][x-1] != g1[a[y]][y-1] - g1[a[y]][y-x] ) return 0 ;
    for ( i = 1 ; i < a[x] ; i ++ ) c1 += g1[i][x-1] ;
    for ( i = 1 ; i < a[y] ; i ++ ) c2 += g1[i][y-1] ;
    for ( i = 1 ; i < a[y] ; i ++ ) c3 += g1[i][y-x] ;
    if ( c1 != c2 - c3 ) return 0 ;
    return 1 ;
}

void get_p () {
    int i , j = 0 ;
    p[1] = 0 ;
    for ( i = 2 ; i <= n ; i ++ ) {
        while ( j && !ok ( j + 1 , i ) ) j = p[j] ;
        if ( ok ( j + 1 , i ) ) j ++ ;
        p[i] = j ;
    }
}

int judge ( int x , int y ) {
    int c1 = 0 , i , c2 = 0 , c3 = 0 ;
    if ( g1[a[x]][x-1] != g2[b[y]][y-1] - g2[b[y]][y-x] ) return 0 ;
    for ( i = 1 ; i < a[x] ; i ++ ) c1 += g1[i][x-1] ;
    for ( i = 1 ; i < b[y] ; i ++ ) c2 += g2[i][y-1] ;
    for ( i = 1 ; i < b[y] ; i ++ ) c3 += g2[i][y-x] ;
    if ( c1 != c2 - c3 ) return 0 ;
    return 1 ;
}

void kmp () {
    int i , j = 0 ;
    for ( i = 1 ; i <= m ; i ++ ) {
        while ( j && !judge ( j + 1 , i ) ) j = p[j] ;
        if ( judge ( j + 1 , i ) ) j ++ ;
        if ( j == n ) {
            vis[i] = 1 ;
            j = p[j] ;
        }
    }
   // for ( i = 1 ; i <= m ; i ++ ) printf ( "%d " , vis[i] ) ; puts ( "" ) ;
}

int main () {
    int i , j , k ;
    while ( scanf ( "%d%d%d" , &m , &n , &t ) != EOF ) {
        memset ( g1 , 0 , sizeof ( g1 ) ) ;
        memset ( g2 , 0 , sizeof ( g2 ) ) ;
        memset ( vis , 0 , sizeof ( vis ) ) ;
        for ( i = 1 ; i <= m ; i ++ ) {
            scanf ( "%d" , &b[i] ) ;
            for ( j = 1 ; j <= t ; j ++ ) g2[j][i] = g2[j][i-1] ;
            g2[b[i]][i] ++ ;
        }
        for ( i = 1 ; i <= n ; i ++ ) {
            scanf ( "%d" , &a[i] ) ;
            for ( j = 1 ; j <= t ; j ++ ) g1[j][i] = g1[j][i-1] ;
            g1[a[i]][i] ++ ;
        }
        get_p () ;
        kmp () ;
        int ans = 0 ;
        i = 1 ;
        while ( i <= m ) {
        //    printf ( "i = %d , ans = %d\n" , i , ans ) ;
            if ( vis[i] )
                ans ++ , i += n ;
            else i ++ ;
        }
        printf ( "%d\n" , ans ) ;
    }
}
