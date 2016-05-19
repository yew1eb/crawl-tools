#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "algorithm"
#include "iostream"

using namespace std;

#define INT __int64
int Pow( INT n )
{
    int temp = n % 10 ;
    int ans = 1 ;
    while( n )
    {
        if( n % 2 == 1 )
        {
            n-- ;
            ans *= temp;
            ans %= 10 ;
        }
        else
        {
            n /= 2 ;
            temp *= temp ;
            temp %= 10 ;
        }
        ans %= 10 ;
    }
    return ans ;
} 
    
int main()
{
    INT n ;
    int Case ;
    cin >> Case ;
    while( Case-- )
    {
        cin >> n ; 
        cout << Pow( n ) << endl ;
    }
    return 0;
}
