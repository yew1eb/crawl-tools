#pragma comment( linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<math.h>
#define ll __int64
using namespace std ;

const int maxn = 511111 ;

struct AC_auto {
    int tot , c[2][maxn] , fail[maxn] , val[maxn] ;
    int cnt[maxn] , tri[2][maxn] ;
    queue<int> q ;
    inline int new_node () {
        int i ;
        for ( i = 0 ; i < 2 ; i ++ )
            c[i][tot] = tri[i][tot] = 0 ;
        val[tot] = cnt[tot] = 0 ;
        return tot ++ ;
    }
    void init () {
        tot = 0 ;
        new_node () ;
    }
    int search ( char *s ) {
        int i , now = 0 ;
        for ( i = 0 ; s[i] ; i ++ ) {
            int k = s[i] - '0' ;
            now = tri[k][now] ;
            if ( !now ) return 0 ;
        }
        if ( cnt[now] ) return 1 ;
        return 0 ;
    }
    void insert ( char *s ) {
        int now = 0 , i , j ;
        for ( ; *s ; s ++ ) {
            int k = *s - '0' ;
            if ( !tri[k][now] ) tri[k][now] = new_node () ;
            now = tri[k][now] ;
        }
        cnt[now] = 1 ;
    }
    void get_fail () {
        int u = 0 , e , i , j ;
        for ( i = 0 ; i < tot ; i ++ ) fail[i] = 0 ;
        for ( i = 0 ; i < 2 ; i ++ )
            if ( tri[i][u] ) {
                q.push ( tri[i][u] ) ;
                c[i][u] = tri[i][u] ;
                val[c[i][u]] = cnt[c[i][u]] ;
            }
        while ( !q.empty () ) {
            int u = q.front () ;
            q.pop () ;
            for ( i = 0 ; i < 2 ; i ++ ) {
                if ( tri[i][u] ) {
                    c[i][u] = tri[i][u] ;
                    e = c[i][u] ;
                    j = fail[u] ;
                    fail[e] = c[i][j] ;
                    q.push ( e ) ;
                    val[e] = val[fail[e]] + cnt[e] ;
                }
                else c[i][u] = c[i][fail[u]] ;
            }

        }
    }
    ll find ( char *s , int len ) {
        int now = 0 ;
        ll ans = 0 ;
        int i ;
        for ( i = 1 ; i <= len ; i ++ ) {
            int k = s[i] - '0' ;
            now = c[k][now] ;
            ans += val[now] ;
        }
        return ans ;
    }
} heap , buf ;

void init () {
    heap.init () ;
    buf.init () ;
}
void dfs ( int u1 , int u2 ) {
    int i ;
    for ( i = 0 ; i < 2 ; i ++ ) {
        if ( buf.tri[i][u2] ) {
            int e2 = buf.tri[i][u2] ;
            if ( !heap.tri[i][u1] ) heap.tri[i][u1] = heap.new_node () ;
            int e1 = heap.tri[i][u1] ;
            heap.cnt[e1] |= buf.cnt[e2] ;
            dfs ( e1 , e2 ) ;
        }
    }
}

void join () {
    dfs ( 0 , 0 ) ;
    buf.init () ;
    heap.get_fail () ;
}

char s[7654321] ;
char s1[7654321] ;
int main () {
    int cas , ca = 0 , i , j ;
    scanf ( "%d" , &cas ) ;
    while ( cas -- ) {
        printf ( "Case #%d:\n" , ++ ca ) ;
        int n ; ll last = 0 ;
        init () ;
        scanf ( "%d" , &n ) ;
        while ( n -- ) {
            scanf ( "%s" , s1 ) ;
            int len = strlen ( s1 + 1 ) ;
            s[0] = s1[0] ;
            for ( i = 0 ; i < len ; i ++ ){
                s[i+1] = s1[1+(i+last%len+len)%len] ;
            }
            s[len+1] = 0 ;
            if ( s[0] == '+' ) {
                i = buf.search ( s + 1 ) ;
                j = heap.search ( s + 1 ) ;
                if ( i || j ) continue ;
                buf.insert ( s + 1 ) ;
                buf.get_fail () ;
                if ( buf.tot > 2000 ) join () ;
            }
            else {
                last = buf.find ( s , len ) + heap.find ( s , len ) ;
                printf ( "%I64d\n" , last ) ;
            }
        }
    }
    return 0 ;
}
/*
2
10
+01
+110
?010
+110
+00
+0
?001001
?001001
+110110
?1101001101

2
10
+01
+110
+110
+00
+0
?001001

1
20
+101001011
?110100
+11010100
?0011001101
+111011
?00010011
+0111010110
+0000101
+0
+11000
?1
+1010101
+0001
+0110
+0111101111
?1100
+0111
+1001
?0110111011
?1010010100

1
10
+00
?010110100
+0100000100
+111
+000000
?0000110
+110
+00
+0011
?101001

1
20
+0
+1000100
+01
+0
?1110010011

*/