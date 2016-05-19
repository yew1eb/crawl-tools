#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAX 107
#define MOD 2147483647

using namespace std;

typedef long long LL;

LL a[MAX];
LL cnt[MAX];
LL b[MAX];
LL n,ans;

int main ( )
{
    LL c = 1;
    while ( ~scanf ( "%lld" , &n ) )
    {
        ans = 0;
        for ( int i = 1 ; i <= n ; i++ ) scanf ( "%lld" , &a[i] );
        sort ( a+1 , a+n+1 );
        LL cc = 0;
        a[0] = -1;
        memset ( cnt , 0 , sizeof ( cnt ) );
        for ( int i = 1 ; i <= n ; i++ )
            if ( a[i] != a[i-1] ) b[++cc] = a[i] ,cnt[cc]++;
            else cnt[cc]++;
        if ( cc == 1 ) ans = -1;
        else for ( int i = 1 ; i <= cc ; i++ )
        {
            LL t1 = b[i-1] , t2 = b[i] , t3 = b[i+1];
            if ( i == 1 ) t1 = b[cc];
            if ( i == cc ) t3 = b[1];
            if ( ( t1 + t2 )%MOD == t3 ) ans += cnt[i];
        }
        printf ( "Case #%I64d: %I64d\n" , c++ , ans ); 
    }
}