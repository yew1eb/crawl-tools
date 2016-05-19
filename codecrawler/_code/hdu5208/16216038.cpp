#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

typedef long long LL ;

#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )

const int MAXN = 31 ;

int dp[MAXN][2][2][2][2] ;
int vis[MAXN][2][2][2][2] ;
int L1 , R1 , L2 , R2 ;

int dfs ( int cur , int l1 , int r1 , int l2 , int r2 ) {
    if ( cur == -1 ) return 0 ;
    if ( vis[cur][l1][r1][l2][r2] ) return dp[cur][l1][r1][l2][r2] ;
    vis[cur][l1][r1][l2][r2] = 1 ;
    int ans = 0 , t = 1 << cur ;
    int a = L1 >> cur & 1 ;
    int b = R1 >> cur & 1 ;
    int c = L2 >> cur & 1 ;
    int d = R2 >> cur & 1 ;
    if ( !l1 && !r1 ) {
        if ( !l2 && !r2 ) {
            if ( a == b ) {
                if ( c == d ) {
                    if ( a == c ) ans = dfs ( cur - 1 , 0 , 0 , 0 , 0 ) ;//ok
                    else ans = t + dfs ( cur - 1 , 0 , 0 , 0 , 0 ) ;//ok
                } else {//c = 0 , d = 1
                    if ( a == 0 ) ans = dfs ( cur - 1 , 0 , 0 , 0 , 1 ) ;//ok
                    else ans = dfs ( cur - 1 , 0 , 0 , 1 , 0 ) ;//ok
                }
            } else {//a = 0 , b = 1
                if ( c == d ) {
                    if ( c == 0 ) ans = t + dfs ( cur - 1 , 1 , 0 , 0 , 0 ) ;//ok
                    else ans = t + dfs ( cur - 1 , 0 , 1 , 0 , 0 ) ;//ok
                } else {
                    ans = max ( dfs ( cur - 1 , 0 , 1 , 0 , 1 ) , dfs ( cur - 1 , 1 , 0 , 1 , 0 ) ) ;//ok
                }
            }
        } else if ( l2 && !r2 ) {
            if ( a == b ) {
                if ( a == 1 ) {
                    if ( d == 1 ) ans = dfs ( cur - 1 , 0 , 0 , 1 , 0 ) ;//ok
                    else ans = t + dfs ( cur - 1 , 0 , 0 , 1 , 0 ) ;//ok
                } else {
                    if ( d == 1 ) ans = dfs ( cur - 1 , 0 , 0 , 1 , 1 ) ;//ok
                    else ans = dfs ( cur - 1 , 0 , 0 , 1 , 0 ) ;//ok
                }
            } else {//a = 0 , b = 1
                if ( d == 1 ) ans = max ( dfs ( cur - 1 , 0 , 1 , 1 , 1 ) , dfs ( cur - 1 , 1 , 0 , 1 , 0 ) ) ;//ok
                else ans = t + dfs ( cur - 1 , 1 , 0 , 1 , 0 ) ;//ok
            }
        } else if ( !l2 && r2 ) {
            if ( a == b ) {
                if ( a == 0 ) {
                    if ( c == 0 ) ans = dfs ( cur - 1 , 0 , 0 , 0 , 1 ) ;//ok
                    else ans = t + dfs ( cur - 1 , 0 , 0 , 0 , 1 ) ;//ok
                } else {//a = 1
                    if ( c == 0 ) ans = dfs ( cur - 1 , 0 , 0 , 1 , 1 ) ;//ok
                    else ans = dfs ( cur - 1 , 0 , 0 , 0 , 1 ) ;//ok
                }
            } else {//a = 0 , b = 1
                if ( c == 0 ) ans = max ( dfs ( cur - 1 , 0 , 1 , 0 , 1 ) , dfs ( cur - 1 , 1 , 0 , 1 , 1 ) ) ;//ok
                else ans = t + dfs ( cur - 1 , 0 , 1 , 0 , 1 ) ;//ok
            }
        } else if ( l2 && r2 ) {
            if ( a == b ) ans = dfs ( cur - 1 , 0 , 0 , 1 , 1 ) ;//ok
            else ans = max ( dfs ( cur - 1 , 1 , 0 , 1 , 1 ) , dfs ( cur - 1 , 0 , 1 , 1 , 1 ) ) ;//ok
        }
    } else if ( l1 && !r1 ) {
        if ( !l2 && !r2 ) {
            if ( c == d ) {
                if ( c == 1 ) {
                    if ( b == 1 ) ans = t + dfs ( cur - 1 , 1 , 1 , 0 , 0 ) ;//ok
                    else ans = t + dfs ( cur - 1 , 1 , 0 , 0 , 0 ) ;//ok
                } else {//c = 0
                    if ( b == 1 ) ans = t + dfs ( cur - 1 , 1 , 0 , 0 , 0 ) ;//ok
                    else ans = dfs ( cur - 1 , 1 , 0 , 0 , 0 ) ;//ok
                }
            } else {
                if ( b == 1 ) ans = max ( dfs ( cur - 1 , 1 , 1 , 0 , 1 ) , dfs ( cur - 1 , 1 , 0 , 1 , 0 ) ) ;//ok
                else ans = dfs ( cur - 1 , 1 , 0 , 0 , 1 ) ;//ok
            }
        } else if ( l2 && !r2 ) {
            if ( d == 1 ) {
                if ( b == 1 ) ans = max ( dfs ( cur - 1 , 1 , 1 , 1 , 1 ) , dfs ( cur - 1 , 1 , 0 , 1 , 0 ) ) ;//ok
                else ans = dfs ( cur - 1 , 1 , 0 , 1 , 1 ) ;//here!!!!!!!!!!!!!!!!!! before ac , final one is zero
            } else {
                if ( b == 1 ) ans = max ( dfs ( cur - 1 , 1 , 1 , 1 , 0 ) , t + dfs ( cur - 1 , 1 , 0 , 1 , 0 ) ) ;
                else ans = dfs ( cur - 1 , 1 , 0 , 1 , 0 ) ;
            }
        } else if ( !l2 && r2 ) {
            if ( c == 0 ) {
                if ( b == 1 ) ans = max ( dfs ( cur - 1 , 1 , 1 , 0 , 1 ) , dfs ( cur - 1 , 1 , 0 , 1 , 1 ) ) ;
                else ans = dfs ( cur - 1 , 1 , 0 , 0 , 1 ) ;
            } else {
                if ( b == 1 ) ans = max ( t + dfs ( cur - 1 , 1 , 1 , 0 , 1 ) , dfs ( cur - 1 , 1 , 0 , 0 , 1 ) ) ;
                else ans = t + dfs ( cur - 1 , 1 , 0 , 0 , 1 ) ;
            }
        } else if ( l2 && r2 ) {
            if ( b == 1 ) ans = max ( dfs ( cur - 1 , 1 , 1 , 1 , 1 ) , dfs ( cur - 1 , 1 , 0 , 1 , 1 ) ) ;//ok
            else ans = dfs ( cur - 1 , 1 , 0 , 1 , 1 ) ;//ok
        }
    } else if ( !l1 && r1 ) {
        if ( !l2 && !r2 ) {
            if ( c == d ) {
                if ( c == 1 ) {
                    if ( a == 0 ) ans = t + dfs ( cur - 1 , 0 , 1 , 0 , 0 ) ;
                    else ans = dfs ( cur - 1 , 0 , 1 , 0 , 0 ) ;
                } else {
                    if ( a == 0 ) ans = t + dfs ( cur - 1 , 1 , 1 , 0 , 0 ) ;
                    else ans = t + dfs ( cur - 1 , 0 , 1 , 0 , 0 ) ;
                }
            } else {
                if ( a == 0 ) ans = max ( dfs ( cur - 1 , 0 , 1 , 0 , 1 ) , dfs ( cur - 1 , 1 , 1 , 1 , 0 ) ) ;
                else ans = dfs ( cur - 1 , 0 , 1 , 1 , 0 ) ;
            }
        } else if ( l2 && !r2 ) {
            if ( d == 1 ) {
                if ( a == 0 ) ans = max ( dfs ( cur - 1 , 0 , 1 , 1 , 1 ) , dfs ( cur - 1 , 1 , 1 , 1 , 0 ) ) ;
                else ans = dfs ( cur - 1 , 0 , 1 , 1 , 0 ) ;
            } else {
                if ( a == 0 ) ans = t + dfs ( cur - 1 , 0 , 1 , 1 , 0 ) ;
                else ans = t + dfs ( cur - 1 , 0 , 1 , 1 , 0 ) ;
            }
        } else if ( !l2 && r2 ) {
            if ( c == 0 ) {
                if ( a == 0 ) ans = max ( dfs ( cur - 1 , 1 , 1 , 1 , 1 ) , dfs ( cur - 1 , 0 , 1 , 0 , 1 ) ) ;
                else ans = dfs ( cur - 1 , 0 , 1 , 1 , 1 ) ;
            } else {
                if ( a == 0 ) ans = t + dfs ( cur - 1 , 0 , 1 , 0 , 1 ) ;
                else ans = dfs ( cur - 1 , 0 , 1 , 0 , 1 ) ;
            }
        } else if ( l2 && r2 ) {
            if ( a == 0 ) ans = max ( dfs ( cur - 1 , 0 , 1 , 1 , 1 ) , dfs ( cur - 1 , 1 , 1 , 1 , 1 ) ) ;//ok
            else ans = dfs ( cur - 1 , 0 , 1 , 1 , 1 ) ;//ok
        }
    } else if ( l1 && r1 ) {
        if ( !l2 && !r2 ) {
            if ( c == d ) ans = t + dfs ( cur - 1 , 1 , 1 , 0 , 0 ) ;
            else ans = max ( dfs ( cur - 1 , 1 , 1 , 0 , 1 ) , dfs ( cur - 1 , 1 , 1 , 1 , 0 ) ) ;
        } else if ( l2 && !r2 ) {
            if ( d == 1 ) ans = max ( dfs ( cur - 1 , 1 , 1 , 1 , 0 ) , dfs ( cur - 1 , 1 , 1 , 1 , 1 ) ) ;
            else ans = t + dfs ( cur - 1 , 1 , 1 , 1 , 0 ) ;
        } else if ( !l2 && r2 ) {
            if ( c == 0 ) ans = max ( dfs ( cur - 1 , 1 , 1 , 0 , 1 ) , dfs ( cur - 1 , 1 , 1 , 1 , 1 ) ) ;
            else ans = t + dfs ( cur - 1 , 1 , 1 , 0 , 1 ) ;
        } else if ( l2 && r2 ) {
            ans = dfs ( cur - 1 , 1 , 1 , 1 , 1 ) ;//ok , ans = 0
        }
    }
    //printf ( "dp[%d][%d][%d][%d][%d] = %d\n" , cur , l1 , r1 , l2 , r2 , ans ) ;
    return dp[cur][l1][r1][l2][r2] = ans ;
}

void solve ( int T ) {
    scanf ( "%d%d%d%d" , &L1 , &R1 , &L2 , &R2 ) ;
    clr ( vis , 0 ) ;
    int ans = dfs ( 30 , 0 , 0 , 0 , 0 ) ;
    printf ( "Case #%d: %d\n" , T , ans ) ;
}

int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    For ( i , 1 , T ) solve ( i ) ;
    return 0 ;
}