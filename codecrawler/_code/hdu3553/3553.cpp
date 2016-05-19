#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll __int64
using namespace std ;
const int maxn = 111111 ;

int min ( int a , int b ) { return a < b ? a : b ; }
int f[maxn] ;
int dp[22][maxn] ;
ll sum[maxn] ;

char s1[maxn] ;
int s[maxn] ;

struct Suf{
    int wa[maxn] , wb[maxn] , ws[maxn] , wv[maxn] ;
    int rank[maxn] , hei[maxn] , sa[maxn] ;

    int cmp ( int *r , int i , int j , int l ){ return r[i] == r[j] && r[i+l] == r[j+l] ; }

    void da ( int *r , int n , int m ){
            int *x = wa , *y = wb , *t ;
        int i , j , k , p ;
        for ( i = 0 ; i < m ; i ++ ) ws[i] = 0 ;
        for ( i = 0 ; i < n ; i ++ ) ws[x[i]=r[i]] ++ ;
        for ( i = 1 ; i < m ; i ++ ) ws[i] += ws[i-1] ;
        for ( i = n - 1 ; i >= 0 ; i -- ) sa[--ws[x[i]]] = i ;
        for ( j = 1 , p = 1 ; p < n ; j *= 2 , m = p ) {
            for ( p = 0 , i = n - j ; i < n ; i ++ ) y[p++] = i ;
            for ( i = 0 ; i < n ; i ++ ) if ( sa[i] >= j ) y[p++] = sa[i] - j ;
            for ( i = 0 ; i < m ; i ++ ) ws[i] = 0 ;
            for ( i = 0 ; i < n ; i ++ ) ws[x[i]] ++ ;
            for ( i = 1 ; i < m ; i ++ ) ws[i] += ws[i-1] ;
            for ( i = n - 1 ; i >= 0 ; i -- ) sa[--ws[x[y[i]]]] = y[i] ;
            for ( t = x , x = y , y = t ,x[sa[0]] = 0 , p = 1 , i = 1 ; i < n ; i ++ )
                x[sa[i]] = cmp ( y , sa[i-1] , sa[i] , j ) ? p - 1 : p ++ ;
        }
        k = 0 ;
        for ( i = 1 ; i < n ; i ++ ) rank[sa[i]] = i ;
        for ( i = 0 ; i < n - 1 ; hei[rank[i++]] = k )
            for ( k ? k -- : 0 , j = sa[rank[i]-1] ; r[i+k] == r[j+k] ; k ++ ) ;
    }

	int min_hei ( int x , int y ) {
		return ( hei[x] < hei[y] ? x : y ) ;
	}

    void rmq ( int n ) {
        int i , j ;
        for ( i = 1 ; i <= n ; i ++ ) dp[0][i] = i ;
        for ( i = 1 ; i <= 20 ; i ++ )
            for ( j = 1 ; j + ( 1 << i ) - 1 <= n ; j ++ )
                dp[i][j] = min_hei ( dp[i-1][j] , dp[i-1][j+(1<<(i-1))] ) ;
    }

    int query ( int l , int r ) {
        if ( l > r ) swap ( l , r ) ;
        l ++ ;//要从height[l+1]到height[r]之间求最小值
        if ( l == r ) return dp[0][l] ;
        int k = r - l + 1 ;
        return min_hei ( dp[f[k]][l] , dp[f[k]][r-(1<<f[k])+1] ) ;
    }

    void solve ( int n , ll k ) {
		rmq ( n ) ;
		int l = 1 , r = n  , i;
		sum[0] = 0 ;
		for ( i = 1 ; i <= n ; i ++ )
			sum[i] = sum[i-1] + n - sa[i] ;
		int h = 0 ;
		int pos = 0 , len ;
		while ( l < r ) {
			int mid = query ( l , r ) - 1 ;
//			printf ( "l = %d , r = %d mid = %d , k = %I64d , fuck = %d\n" , l , r , mid , k , ( hei[mid] - h ) * ( r - l + 1 ) ) ;
			if ( k <= (ll) ( hei[mid+1] - h ) * ( r - l + 1 ) ) {
				pos = l ;
				len = h + k / ( r - l + 1 ) + ( k % ( r - l + 1 ) != 0 ) ;
//				printf ( "pos = %d , l = %d\n" , pos , len ) ;
				break ;
			}
			k -= (ll) (hei[mid+1] - h ) * ( r - l + 1 ) ;
			if ( k <= sum[mid] - sum[l-1] - (ll) hei[mid+1] * ( mid - l + 1 ) ) {
				r = mid ;
			}
			else {
				k -= sum[mid] - sum[l-1] - (ll) hei[mid+1] * ( mid - l + 1 ) ;
				l = mid + 1 ;
			}
			h = hei[mid+1] ;
		}
		if ( !pos ) pos = l , len = h + k ;
		for ( i = 0 ; i < len ; i ++ )
			printf ( "%c" , s[sa[pos]+i] ) ;
		puts ( "" ) ;
    }

} arr ;

int main () {
    int cas , i , j , ca = 0 ;
    ll m ;
    j = 0 ;
    for ( i = 1 ; i < maxn - 1111 ; i ++ ) {
        if ( i > 1 << j + 1 ) j ++ ;
        f[i] = j ;
    }
    scanf ( "%d" , &cas ) ;
    while ( cas -- ) {
        scanf ( "%s" , s1 ) ;
        scanf ( "%I64d" , &m ) ;
        int len = strlen ( s1 ) ;
        for ( i = 0 ; i < len ; i++ ) s[i] = s1[i] ;
        s[len] = 0 ;
        arr.da ( s , len + 1 , 411 ) ;
        printf ( "Case %d: " , ++ ca ) ;
        arr.solve ( len , m ) ;
    }
}
/*
10000
ddff 9
*/