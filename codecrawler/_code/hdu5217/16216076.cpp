#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std ;

typedef long long LL ;

#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )
#define ls ( o << 1 )
#define rs ( o << 1 | 1 )
#define lson ls , l , m
#define rson rs , m + 1 , r
#define root 1 , 1 , n
#define mid ( ( l + r ) >> 1 )

const int MAXN = 200005 ;

int n , q ;
char s[MAXN] ;
int lnum[MAXN << 2] ;
int rnum[MAXN << 2] ;

void pushup ( int o ) {
    int x = min ( lnum[ls] , rnum[rs] ) ;
    lnum[o] = lnum[ls] + lnum[rs] - x ;
    rnum[o] = rnum[ls] + rnum[rs] - x ;
}

void build ( int o , int l , int r ) {
    if ( l == r ) {
        if ( s[l] == '(' ) lnum[o] = 1 , rnum[o] = 0 ;
        else lnum[o] = 0 , rnum[o] = 1 ;
        return ;
    }
    int m = mid ;
    build ( lson ) ;
    build ( rson ) ;
    pushup ( o ) ;
}

void update ( int x , int o , int l , int r ) {
    if ( l == r ) {
        lnum[o] ^= 1 ;
        rnum[o] ^= 1 ;
        return ;
    }
    int m = mid ;
    if ( x <= m ) update ( x , lson ) ;
    else update ( x , rson ) ;
    pushup ( o ) ;
}

int Lnum , Rnum ;
void query ( int L , int R , int o , int l , int r ) {
    if ( L <= l && r <= R ) {
        int x = min ( Lnum , rnum[o] ) ;
        Lnum = Lnum + lnum[o] - x ;
        Rnum = Rnum + rnum[o] - x ;
        return ;
    }
    int m = mid ;
    if ( L <= m ) query ( L , R , lson ) ;
    if ( m <  R ) query ( L , R , rson ) ;
}

int Lsearch ( int L , int R , int v , int o , int l , int r ) {
    int m = mid ;
    if ( L <= l && r <= R ) {
        int x = min ( Lnum , rnum[o] ) ;
        if ( l == r && Rnum + rnum[o] - x == v ) return l ;
        if ( Rnum + rnum[o] - x < v ) {
            Lnum = Lnum + lnum[o] - x ;
            Rnum = Rnum + rnum[o] - x ;
            return 0 ;
        }
        int y = min ( Lnum , rnum[ls] ) ;
        if ( Rnum + rnum[ls] - y >= v ) {
            return Lsearch ( L , R , v , lson ) ;
        } else {
            Rnum = Rnum + rnum[ls] - y ;
            Lnum = Lnum + lnum[ls] - y ;
            return Lsearch ( L , R , v , rson ) ;
        }
    }
    //printf ( ": %d %d %d %d %d %d %d\n" , Lnum , Rnum , L , R , o , l , r ) ;
    if ( R <= m ) return Lsearch ( L , R , v , lson ) ;
    if ( m <  L ) return Lsearch ( L , R , v , rson ) ;
    int x = Lsearch ( L , R , v , lson ) ;
    if ( !x ) return Lsearch ( L , R , v , rson ) ;
}

int Rsearch ( int L , int R , int v , int o , int l , int r ) {
    int m = mid ;
    if ( L <= l && r <= R ) {
        int x = min ( Rnum , lnum[o] ) ;
        if ( l == r && Lnum + lnum[o] - x == v ) return l ;
        if ( Lnum + lnum[o] - x < v ) {
            Lnum = Lnum + lnum[o] - x ;
            Rnum = Rnum + rnum[o] - x ;
            return 0 ;
        }
        int y = min ( Rnum , lnum[rs] ) ;
        if ( Lnum + lnum[rs] - y >= v ) {
            return Rsearch ( L , R , v , rson ) ;
        } else {
            Lnum = Lnum + lnum[rs] - y ;
            Rnum = Rnum + rnum[rs] - y ;
            return Rsearch ( L , R , v , lson ) ;
        }
    }
    if ( R <= m ) return Rsearch ( L , R , v , lson ) ;
    if ( m <  L ) return Rsearch ( L , R , v , rson ) ;
    int x = Rsearch ( L , R , v , rson ) ;
    if ( !x ) return Rsearch ( L , R , v , lson ) ;
}

void solve () {
    int op , l , r , v ;
    scanf ( "%d%d%s" , &n , &q , s + 1 ) ;
    build ( root ) ;
    while ( q -- ) {
        scanf ( "%d" , &op ) ;
        if ( op == 1 ) {
            scanf ( "%d" , &v ) ;
            update ( v , root ) ;
        } else {
            scanf ( "%d%d%d" , &l , &r , &v ) ;
            Lnum = Rnum = 0 ;
            query ( l , r , root ) ;
            if ( Rnum + Lnum < v ) {
                printf ( "-1\n" ) ;
                continue ;
            }
            int x ;
            if ( v <= Rnum ) {
                Lnum = Rnum = 0 ;
                x = Lsearch ( l , r , v , root ) ;
            } else {
                v = Lnum + Rnum - v + 1 ;
                Lnum = Rnum = 0 ;
                x = Rsearch ( l , r , v , root ) ;
            }
            printf ( "%d\n" , x ) ;
        }
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