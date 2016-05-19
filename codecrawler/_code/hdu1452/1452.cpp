#include <iostream>
 #include <cstdio>
 #include <cmath>
 
 using namespace std;
 
 int _pow( int a, int n )
 {
     int b = 1;
     while( n > 1 )
         if( n % 2 == 0 )
         {
             a = ( a * a ) % 29;
             n /= 2;
         }
         else
         {
             b = b * a % 29;
             n--;
         }
         return a * b % 29;
 }
 int main()
 {
     int X;
     int a, b, c;
     while( cin >> X, X )
     {
         a = _pow( 2, 2 * X + 1 );
         b = _pow( 3, ( X + 1 ) );
         c = _pow( 22, ( X + 1 ) );
 
         cout << ( a - 1 ) * ( b - 1 ) * 15 * ( c - 1 ) * 18 % 29 << endl;
     }
     return 0;
 }