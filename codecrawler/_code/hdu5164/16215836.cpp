#include <cmath>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

typedef long long LL ;

#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )

const int MAXN = 1000005 ;

LL ans ;

int gcd ( int a , int b ) {
    return b ? gcd ( b , a % b ) : a ;
}

struct AC_automation {
    map < int , int > mp[MAXN] ;
    map < int , int > :: iterator it ;
    int fail[MAXN] ;
    int end[MAXN] ;
    int Q[MAXN] , head , tail ;
    int root ;
    int p ;

    int newnode () {
        mp[p].clear () ;
        end[p] = 0 ;
        return p ++ ;
    }

    void init () {
        p = 0 ;
        ans = 0 ;
        root = newnode () ;
    }

    void insert ( int s[] , int n ) {
        int now = root ;
        rep ( i , 1 , n ) {
            int g = gcd ( s[i] , s[i + 1] ) ;
            int t = s[i] / g * 10001 + s[i + 1] / g ;
            if ( !mp[now].count ( t ) ) mp[now][t] = newnode () ;
            now = mp[now][t] ;
        }
        ++ end[now] ;
    }

    void build () {
        head = tail = 0 ;
        fail[root] = root ;
        for ( it = mp[root].begin () ; it != mp[root].end () ; ++ it ) {
            fail[it->second] = root ;
            Q[tail ++] = it->second ;
        }
        while ( head != tail ) {
            int now = Q[head ++] ;
            end[now] += end[fail[now]] ;
            for ( it = mp[now].begin () ; it != mp[now].end () ; ++ it ) {
                int x = fail[now] , flag = 0 ;
                while ( x != root ) {
                    if ( mp[x].count ( it->first ) ) {
                        fail[it->second] = mp[x][it->first] ;
                        flag = 1 ;
                        break ;
                    }
                    x = fail[x] ;
                }
                if ( x == root && mp[x].count ( it->first ) ) {
                    fail[it->second] = mp[x][it->first] ;
                    flag = 1 ;
                }
                if ( !flag ) fail[it->second] = root ;
                Q[tail ++] = it->second ;
            }
        }
    }

    void query ( int s[] , int n ) {
        int now = root ;
        rep ( i , 1 , n ) {
            int g = gcd ( s[i] , s[i + 1] ) ;
            int t = s[i] / g * 10001 + s[i + 1] / g ;
            int x = now , flag = 0 ;
            while ( x != root ) {
                if ( mp[x].count ( t ) ) {
                    now = mp[x][t] ;
                    flag = 1 ;
                    break ;
                }
                x = fail[x] ;
            }
            if ( x == root && mp[x].count ( t ) ) {
                now = mp[x][t] ;
                flag = 1 ;
            }
            if ( !flag ) now = root ;
            ans += end[now] ;
        }
    }
} ;

AC_automation ac ;
int s[100005] , p[300005] ;
int n , m , q ;


void solve () {
    ans = 0 ;
    ac.init () ;
    scanf ( "%d%d" , &n , &q ) ;
    For ( i , 1 , n ) scanf ( "%d" , &s[i] ) ;
    while ( q -- ) {
        scanf ( "%d" , &m ) ;
        For ( i , 1 , m ) scanf ( "%d" , &p[i] ) ;
        if ( m > 1 ) ac.insert ( p , m ) ;
        else ans += n ;
    }
    ac.build () ;
    ac.query ( s , n ) ;
    printf ( "%I64d\n" , ans ) ;
}

int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    while ( T -- ) solve () ;
    return 0 ;
}
