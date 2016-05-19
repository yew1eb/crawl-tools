#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int jz( int num , int j )
{
    int sum = 0 ;
    while( num )
    {
        sum += num % j ;
        num /= j ;
    }
    return sum ;
}
int main()
{
    for( int i = 2992 ; i <= 9999 ; ++i )
    {
        int a = jz( i , 10 ) ;
        int b = jz( i , 12 ) ;
        int c = jz( i , 16 ) ;
        if( a == b && a == c )
            cout << i << endl ;
    }
    return 0 ;
} 