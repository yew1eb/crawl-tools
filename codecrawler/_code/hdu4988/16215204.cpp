#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

#define inf 0x3f3f3f3f
#define LL long long
#define mxn 100020
#define ls ( p[i].ch[0] )
#define rs ( p[i].ch[1] )


struct node {
    int ch[2];
    int r, v, s;
    node() {}
    node( int v ): v( v ) {
        ch[0] = ch[1] = 0;
        r = rand();
        s = 1;
    }
}p[mxn*80];
int sz;
int creat( int v ) {
    ++ sz;
    p[sz] = node( v );
    return sz;
}
int cmp( int i, int v ) {
    if( p[i].v == v )
        return -1;
    return v < p[i].v ? 0: 1;
}
void mt( int i ) {
    p[i].s = 1;
    if( ls )
        p[i].s += p[ls].s;
    if( rs )
        p[i].s += p[rs].s;
}
void rt( int &i, int d ) {
    int k = p[i].ch[d^1];
    p[i].ch[d^1] = p[k].ch[d];
    p[k].ch[d] = i;
    mt( i ), mt( k );
    i = k;
}
void insert( int &i, int v ) {
    if( !i ) {
        i = creat( v );
        return ;
    }
    int d = cmp( i, v );
    insert( p[i].ch[d], v );
    if( p[p[i].ch[d]].r > p[i].r )
        rt( i, d ^ 1 );
    mt( i );
}
void Remove( int &i, int v ) {
    int d = cmp( i, v );
    if( !~d ) {
        if( !ls )
            i = rs;
        else if( !rs )
            i = ls;
        else {
            int d2 = p[ls].r > p[rs].r ? 1: 0;
            rt( i, d2 );
            Remove( p[i].ch[d2], v );
        }
    }
    else
        Remove( p[i].ch[d], v );
    if( i )
        mt( i );
}
// å°äºvçæ°çä¸ªæ°
int Low( int i, int v ) {
    if( !i )
        return 0;
    int d = cmp( i, v );
    int ret = 0;
    if( ls )
        ret += p[ls].s;
    if( !~d ) {
        return ret + 1;
    }
    if( d == 0 )
        return Low( ls, v );
    return ret + 1 + Low( rs, v );
}
// å¤§äºvçæ°çä¸ªæ°
int Up( int i, int v ) {
    if( !i )
        return 0;
    int d = cmp( i, v );
    int ret = 0;
    if( rs )
        ret += p[rs].s;
    if( !~d )
        return ret + 1;
    if( d == 1 )
        return Up( rs, v );
    return ret + 1 + Up( ls, v );
}
int a[mxn], b[mxn], on[mxn];
int r[mxn], n;
int root[mxn];
int lb( int x ) {
    return x & -x;
}
void read() {
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d", &a[i] );
        ++ a[i];
    }
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d", &b[i] );
        ++ b[i];
    }
    for( int i = 1; i <= n; ++i )
        r[a[i]] = i;
    for( int i = 1; i <= n; ++i ) {
        b[i] = r[b[i]];  // ç½®æ¢bæ°ç»
        on[b[i]] = i; // on[i] è¡¨ç¤º æ°içä¸æ 
    }
}
// æ´æ°ãã
void update( int x, int v, int d ) {
    while( x <= n ) {
        if( d == -1 )
            Remove( root[x], v );
        else
            insert( root[x], v );
        x += lb( x );
    }
}
int low( int x, int v ) {
    int ret = 0;
    while( x ) {
        ret += Low( root[x], v );
        x -= lb( x );
    }
    return ret;
}
int up( int x, int v ) {
    int ret = 0;
    while( x ) {
        ret += Up( root[x], v );
        x -= lb( x );
    }
    return ret;
}
int main() {
    while( scanf( "%d", &n ) != EOF ) {
        sz = 0;
        read();
        LL ans = 0;
        memset( root, 0, sizeof( root ) );
        //  treap + æ ç¶æ°ç»
        for( int i = 1; i <= n; ++i ) {
            for( int j = i - lb( i ) + 1; j <= i; ++j )
                insert( root[i], b[j] );
        }
        for( int i = 2; i <= n; ++i )
            ans += up( i - 1, b[i] );
        int m;
        scanf( "%d", &m );
        while( m-- ) {
            char s[10];
            scanf( "%s", s );
            if( s[0] == 'Q' ) {
                printf( "%I64d\n", ans );
                continue;
            }
            int p, x, y;
            scanf( "%d%d%d", &p, &x, &y );
            x ++, y++;
            if( x == y )
                continue;
            if( p == 0 ) {
                x = on[x], y = on[y];
            }
            if( x > y )
                swap( x, y );
            if( y - x > 1 ) {
                ans -= low( y - 1, b[x] ) - low( x, b[x] );
                ans += up( y - 1, b[x] ) - up( x, b[x] );
                ans -= up( y - 1, b[y] ) - up( x, b[y] );
                ans += low( y - 1, b[y] ) - low( x, b[y] );
            }
            if( b[x] < b[y] )
                ans ++;
            else
                ans --;
            update( x, b[x], -1 );
            update( y, b[y], -1 );
            update( x, b[y], 1 );
            update( y, b[x], 1 );
            swap( on[b[x]], on[b[y]] ); // è¦åæ´æ°onæ°ç»
            swap( b[x], b[y] );
        }
    }
    return 0;
}
