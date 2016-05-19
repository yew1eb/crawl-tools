#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAX 100007

using namespace std;

long long  sum[MAX],ans;

int main ( )
{
    int t,n,m,start,end,begin;
    scanf ( "%d" , &t );
    while ( t-- )
    {
        scanf ( "%d%d" , &n , &m );
        sum[1] = 0;
        for ( int i = 2 ; i <= n ; i++ )
            scanf ( "%lld" , &sum[i] );
        for ( int i = 2 ; i <= n; i++ )
            sum[i] = sum[i]+sum[i-1];
        for ( int i = 1 ; i <= m ; i++ )
        {
            scanf ( "%d%d" , &start , &end );
            begin = (i-1)%n+1;
            if ( begin <=start && start <= end )
                    ans = sum[end] - sum[begin];
            if ( begin > start && start <= end )
                    ans = 2*sum[n]-sum[begin]+sum[end];
            if (  end < start )
                    ans = 2*sum[n]-sum[begin]-sum[end];
            printf ( "%lld\n" , ans );
        }
    }
}