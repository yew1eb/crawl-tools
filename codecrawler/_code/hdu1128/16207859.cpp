#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

char hash[1000005];

void deal( int x )
{
    int rec = x;
    while( x > 0 )
    {
        int c = x % 10;
        x /= 10;
        rec += c;
    }
    hash[rec] = 1;
}

int main()
{
    for( int i = 1; i <= 1000000; ++i )
    {
        deal( i );
        if( !hash[i] )
            printf( "%d\n", i );
    }
    return 0;
}