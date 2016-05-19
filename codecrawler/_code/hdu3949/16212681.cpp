#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
#define M 10010
#define inf 1LL<<60
#define ll long long
#define eps 1e-7
#define bas 9
#define mod 1000000000LL

ll a[M];
ll bit[61];
int n;
void gauss()
{
    int row = 0, col = 60, k;
    while( col >= 0 && row < n ){
        k = row;
        while( k < n && (a[k]&bit[col]) == 0 ) ++k;
        if( k == n ){
            --col;
        }
        else{
            swap( a[row], a[k] );
            for( int i = 0; i < n; ++i ) if( i-row ){
                if( a[i]&bit[col] ) a[i] ^= a[row];
            }
            --col, ++row;
        }
    }
    sort( a, a+n );
    n = unique( a, a+n ) - a;
}

ll cal( int x )
{
    int i = 0;
    if( a[0] == 0 ){
        if( x == 1 ) return 0;
        ++i;
        --x;
    }
    ll ans = 0;
    while( x && i < n ){
        if(x&1) ans ^= a[i];
        x >>= 1;
        ++i;
    }
    if( x ) return -1;
    return ans;
}
int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    bit[0] = 1;
    for( int i = 1; i < 61; ++i ) bit[i] = bit[i-1]<<1;
    int T, q, t = 0, x;
    scanf( "%d", &T );
    while( T-- ){
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) scanf( "%I64d", a+i );
        gauss();
        printf( "Case #%d:\n", ++t );
        scanf( "%d", &q );
        while( q-- ){
            scanf( "%d", &x );
            cout<<cal(x)<<endl;
        }
    }
}
