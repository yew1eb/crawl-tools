#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 10007

using namespace std;

struct record
{
    int t,x;
    bool operator < ( const record& a ) const 
    {
        return t < a.t;
    }
}r[MAX];

double get ( int i )
{
    int x1 = r[i].x;
    int x2 = r[i-1].x;
    int t1 = r[i].t;
    int t2 = r[i-1].t;
    return  abs ( x1 - x2 )*1.0 / ( abs ( t1-t2)*1.0); 
}

int main ( )
{
    int t,n;
    scanf ( "%d" , &t );
    int c = 1;
    while ( t-- )
    {
        scanf ( "%d" , &n );
        for ( int i = 1 ; i <= n ; i++ )
            scanf ( "%d%d" , &r[i].t , &r[i].x );
        sort ( r+1 , r+n+1 );
        double maxn = get ( 2 );
        for ( int i = 3 ; i <= n ; i++ )
            maxn = max ( maxn , get ( i ) );
        printf ( "Case #%d: ", c++ );
        printf ( "%.2lf\n" , maxn );
    }
}