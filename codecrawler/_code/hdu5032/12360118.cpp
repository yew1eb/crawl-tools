#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define M 1010
#define LL long long

LL sum[M];
void add( int i, LL v )
{
    for( ; i <= 1000; i += i & -i )
        sum[i] += v;
}
LL query( int i )
{
    LL ans = 0;
    for( ; i > 0; i -= i & -i )
        ans += sum[i];
    return ans;
}
struct Node
{
    int x, a, b, id;
    void scan( int i )
    {
        id = i;
        scanf( "%d%d%d", &a, &b, &x );
    }
    bool operator < ( const Node &g ) const{
        return 1LL * b * g.a <= 1LL * a * g.b;
    }
}q[M*100], p[M*M];
LL A, B, ans[M*100];
int top[M];
int main()
{
    int n, T;
    scanf( "%d", &T );
    int cas = 0;
    int all = 0;
    for( int i = 1; i <= 1000; ++i ){
        for( int j = 1; j <= 1000; ++j ){
            p[all].a = i, p[all++].b = j;
        }
    }
    sort( p, p + all );
    while( T-- ){
        cin >> A >> B;
        scanf( "%d", &n );
        memset( sum, 0, sizeof(sum) );
        memset( top, 0, sizeof(top) );
        for( int i = 0; i < n; ++i ) q[i].scan( i );
        sort( q, q + n );
        int j = 0;
        for( int i = 0; i < n; ++i ){
            while( j < all && p[j] < q[i] ){
                add( p[j].a, ( p[j].a + A ) * ( p[j].b + B ) );
                ++j;
            }
            ans[q[i].id] = query( q[i].x );
        }
        printf( "Case #%d:\n", ++cas );
        for( int i = 0; i < n; ++i )
            printf( "%I64d\n", ans[i] );
    }
}