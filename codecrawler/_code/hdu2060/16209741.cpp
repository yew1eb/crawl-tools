#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std; 

int main()
{
    int n , m , a , b ;
     cin >> n ;
    {
        while( n-- )
        {
            cin >> m >> a >> b ;
            if( m <= 6 )
                a += ( 15 - m ) * m / 2 ;
            else
                a += 27 + 8 * ( m - 6 ) ;
            if( a >= b )
                cout << "Yes" << endl ;
            else
                cout << "No" << endl ;
        }
    }
    return 0 ;
}