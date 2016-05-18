#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int T;
    long long N;
    scanf( "%d", &T );
    while( T-- )
    {
        scanf( "%I64d", &N );
        long long lim = ( long long )sqrt( double ( N + 1 ) ) - 1, cnt = 0;
        for( long long i = 1; i <= lim; ++i )
        {
            if( ( N - i ) % ( i + 1 ) == 0  ) 
            {
                cnt++;
            }
        }    
        printf( "%I64d\n", cnt );
    }
    return 0;
}