#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<numeric>
#include<sstream>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>

using namespace std ;
const int maxn = 10005 ;
int n , num[ maxn ] , value[ maxn ] , sum , a[ maxn ] , b[ maxn ] ;

int main()
{
    while( scanf( "%d" , &n ) != EOF && n )
    {
        sum = 0 ;
        for( int i = 1 ; i <= n ; ++i )
        {
            scanf( "%d%d" , &value[ i ] , &num[ i ] ) ;
            sum += value[ i ] * num[ i ] ; 
        }
        if( sum % 3 != 0 )
        {
            printf( "sorry\n" ) ;
            continue ;
        }
        memset( a , 0 , sizeof( a ) ) ;
        memset( b , 0 , sizeof( b ) ) ;
        a[ 0 ] = 1 ; 
        for( int i = 1 ; i <= n ; ++i )
        {
            for( int j = 0 ; j <= sum ; ++j )
            {
                for( int k = 0 ; k <= num[ i ] && k * value[ i ] + j <= sum ; ++k )
                {
                    b[ k * value[ i ] + j ] +=  a[ j ] ;
                    b[ k * value[ i ] + j ] %= 10000 ;
                }
            }
            for( int j = 0 ; j < sum ; ++j )
            {
                a[ j ] = b[ j ] ; 
                b[ j ] = 0 ; 
            }
        }        
        if( a[ sum / 3 ] == 0 )
            printf( "sorry\n" ) ;
        else
            printf( "%d\n" , a[ sum / 3 ] ) ;
    }
    return 0;
}
