#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iomanip>

using namespace std;

__int64 gcd( __int64 a , __int64 b )
{
    return b == 0 ? a : gcd( b , a % b ) ;
}
int main()
{
    __int64 n , m ;
    while( scanf( "%I64d%I64d" ,&n ,&m ) , n | m )
    {
        if( gcd( n , m ) == 1 )
            printf( "%I64d\n" , n * m - n - m ) ;
        else
            printf( "Inf\n" ) ;
    }
    return 0 ;
}

