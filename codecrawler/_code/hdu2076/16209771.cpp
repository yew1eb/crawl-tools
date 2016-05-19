#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "algorithm"
#include "iostream"

using namespace std;

int main()
{
    int n , h , m , s ;
    double ans1 , ans2 , temp ;
    scanf( "%d" , &n ) ;
    int t ;
    while( n-- )
    {
         scanf( "%d%d%d" ,&h , &m , &s ) ;
         ans1 = 1.0 * m * 6 + 0.1 * s ;
         ans2 = 1.0 * ( h % 12 ) * 30 + 0.5 * m + 1.0 / 120 * s ;
         temp = fabs( ans1 - ans2 ) ;
         if( temp > 180 ) 
            t = (int )(360 - temp) ;
         else
             t = (int)temp ;
        printf( "%d\n" ,t );
    }
    return 0;
}
