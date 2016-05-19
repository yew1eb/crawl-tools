#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iomanip>

using namespace std;


#define MAX_PRIME 31700
#define PRIME_NUM 3500

int Primes[ PRIME_NUM + 10 ] ;

int _Count = 0  ;
int GetPrimes( )
{
    unsigned char  *PrimeBuffer = ( unsigned char * ) malloc( sizeof( unsigned char ) * ( MAX_PRIME + 10 ) ) ;
    int i , j  ;
    
    memset( Primes , 0 , sizeof( int ) *PRIME_NUM ) ;
    memset( PrimeBuffer , 0 , sizeof( unsigned char) * MAX_PRIME ) ;
    
    
    for( i = 2 ; i < MAX_PRIME ; i++ )
    {
        if( PrimeBuffer[ i ] == 0 )
            Primes[ _Count++ ] = i ;
        for( j = 0 ; j < _Count && i * Primes[ j ] <= MAX_PRIME ; j++ )
        {
            PrimeBuffer[ i * Primes[ j ] ] = 1 ;
             if( i % Primes[ j ] == 0 )
                  break ;
        }
    }
    free( PrimeBuffer ) ;
    return _Count ;
}

int main()
{
    GetPrimes();
    int Case , n , num , sum , temp;
    cin >> Case ;
    temp = 0 ;
    while( Case-- )
    { 
        cin >> n ;
        sum = 1 ;
        for( int i = 0 ; i < _Count ; ++i )
        {
            int  flag =  ( int )sqrt( n ) + 1 ;
            if( Primes[ i ] > flag )
                break ;
            num = 0 ;
            while( n % Primes[ i ] == 0 )
            {
                num++ ;
                n /= Primes[ i ] ;
            }
            sum *= ( 1 + 2 * num ) ;
        }
        if( n > 1 )
            sum *= 3 ;
        cout << "Scenario #" << ++temp << ":" << endl ;
        cout << ( sum + 1 ) / 2 << endl << endl ;
    }
    return 0 ;
}
