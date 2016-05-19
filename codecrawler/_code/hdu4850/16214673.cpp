#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std ;

#define REP( i , a , b ) for ( int i = a ; i < b ; ++ i )
#define clear( a , x ) memset ( a , x , sizeof a )

typedef long long LL ;

const int MAXN = 26 ;
const int MAXS = 500005 ;

bool vis[MAXN][MAXN][MAXN][MAXN] ;
int s[MAXS] ;

int main () {
    int n , l = 0 , flag = 1 ;
    clear ( vis , 0 ) ;
    REP ( i , 0 , MAXN )
        s[l + 3] = s[l + 2] = s[l + 1] = s[l] = i , l += 4 ;
    REP ( i , 3 , l )
        vis[s[i]][s[i - 1]][s[i - 2]][s[i - 3]] = 1 ;
    while ( flag ) {
        flag = 0 ;
        REP ( i , 0 , MAXN )
            if ( !vis[i][s[l - 1]][s[l - 2]][s[l - 3]] ) {
                s[l] = i ;
                vis[s[l]][s[l - 1]][s[l - 2]][s[l - 3]] = 1 ;
                l ++ ;
                flag = 1 ;
            }
    }
    while ( ~scanf ( "%d" , &n ) ) {
        if( n > l )
            puts ( "Impossible" ) ;
        else {
            REP ( i , 0 , n )
                putchar ( s[i] + 97 ) ;
            putchar ( '\n' ) ;
        }
    }
    return 0 ;
}