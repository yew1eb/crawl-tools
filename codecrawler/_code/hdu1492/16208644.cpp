#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;

#define LL long long 
int main()
{
    LL n ;
    int a , b , c , d ;

    while( cin >> n  , n )
    {    
        a = b = c = d = 1 ; 
        while( n != 1 )
        {
            while( n % 2 == 0 )
            {
                n /= 2 ;
                a++ ; 
            }
                
            while( n % 3 == 0 )
            {
                n /= 3 ;
                b++ ;
            }
            while(n % 5 == 0 )
            {
                n /= 5 ; 
                c++ ; 
            }
            while( n % 7 == 0 )
            {
                n /= 7 ;
                d++ ;
            }        
        }
        cout << ( a * b * c * d ) << endl ;
    }
    return 0 ;
}
