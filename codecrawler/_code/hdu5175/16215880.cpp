#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAX 100009

using namespace std;

typedef long long LL;

LL ans[MAX];
LL n;
int cnt = 1;

LL gcd ( LL a , LL b )
{
    return b==0?a:gcd(b,a%b);
}

void solve ( )
{
    cnt = 1;
    for ( LL i = 1 ; i*i<= n ; i++ )
    {
        if ( n%i ) continue;
        LL x = n^i;
        if ( x > 0 && x <= n && gcd ( n, x ) == i ) 
            ans[cnt++] = x;
        if ( n/i == i ) continue;
        if ( i == 1 ) continue;
        x = n^(n/i);
        if ( x > 0 && x <= n && gcd ( n , x ) == n/i )
            ans[cnt++] = x;
    }
}

int main ( )
{
    int c = 1;
    while ( ~scanf ( "%lld" , &n ) )
    {
        solve ( );
        printf ( "Case #%d:\n" , c++ );
        sort ( ans+1 , ans + cnt );
        cnt--;
        printf ( "%d\n" , cnt );
        for ( int i = 1 ; i < cnt ; i++ )
            printf ( "%lld " , ans[i] );
        if ( cnt == 0 ) puts ( "" );
        else printf ( "%lld\n" ,ans[cnt] );
    }
}