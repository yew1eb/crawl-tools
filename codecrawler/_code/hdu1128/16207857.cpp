#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
bool a[1000005];

void solve( )
{
     for( int i=1 ; i<=1000000 ; i++ )
     {
         int t1 , t2;
         t1 = t2 = i;
         while( t1 )
         {
                t2 += t1 % 10;
                t1 /= 10;       
         }
         a[t2] = true;
     }
     for( int i=1 ; i<=1000000 ; i++ )
          if( !a[i] )
     printf("%d\n",i);
}

int main( )
{
    memset( a , false , sizeof(a) ); 
    solve( );
    return 0;
} 
