#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAX 100007

using namespace std;

long long sum[MAX];

int main  ( )
{
    sum[0] = 0;
    for ( int i = 1 ; i <= 100000 ; i++ )
        sum[i] = sum[i-1] + i;
    int t,x,b;
    int c = 1;
    scanf ( "%d" , &t );
    while ( t-- )
    {
        scanf ( "%d%d" , &x , &b );
        double p = 1.0 - pow ( (x-1)*1.0/(x*1.0) , b*1.0 ); 
        printf ( "Case #%d: " , c++ );
        printf ( "%.3f\n" , sum[x]*1.0*p );
    }
}