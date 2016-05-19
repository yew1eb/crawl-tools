#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>

using namespace std;
#define MAX 105 
int  num[ MAX ] ;

int judge( int n )
{
    int sum = 0 ;
    for( int i = 2 ; i < sqrt( n ) ; ++i )
    {
        if( n % i == 0 )
        {
            if( i != ( n / i ) ) 
            {
                sum += i + n / i ;
            }
            else
                sum += i ;
        }
    }
    if( n != 1 )
        sum += 1;
    if( sum > n )
        return 1 ;
    else if( sum == n  )
        return 0 ;
    else
        return -1 ;
}
int main()
{
    int flag ;
    while( 1 )
    {
        flag = 0 ;        
        int i = 0 ;    
        int a ;
        while( 1 )
        {
            for( i = 0 ; ; ++i)
            {
                cin >> num[ i ] ;
                if( num[ i ] == 0 )
                {
                    flag = 1 ;
                    break ;
                }
//                cout << num[ i ] << endl ;
            }
            if( flag )
                break ;
        }
        if( flag )
        {            
            printf( "PERFECTION OUTPUT\n" ) ;
            for( int  j = 0 ; j < i ; ++j )
            {
                int temp = judge( num[ j ] ) ;
                if( temp == 0 )
                    printf( "%5d  PERFECT\n" , num[ j ] ) ;
                else if( temp > 0 )
                    printf( "%5d  ABUNDANT\n" , num[ j ] ) ;
                else
                    printf( "%5d  DEFICIENT\n" , num[ j ] ) ;    
                
            }
            printf( "END OF OUTPUT\n" ) ;
            break ;
        }
        if( flag )
            break ;
    }
    return 0 ;
}