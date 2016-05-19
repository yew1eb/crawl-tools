#include "cstdio"
#include "cstring"

int main()
{
 int x , y ;
 bool flag[5005];
 for ( int i = 1 ; i <= 5000 ; i ++ )
 {
 flag[i] = false ;
 for ( int a = 1 ; a <= 1000 ; a ++ )
 {
 for ( int b = 1 ; b <= 1000 ; b ++ )
 {
 x = a * a * b + 1 ;
 y = a * a + b ;
 if ( x % i == 0 )
 {
 if ( y % i )
 {
 flag[i] = true ;
 break ;
 }
 }
 }
 if ( flag[i] ) break ;
 }
 }
 int T , n ;
 scanf ( "%d" , &T ) ;
 while ( T -- )
 {
 scanf ( "%d" , &n ) ;
 if ( !flag[n] ) puts("YES") ;
 else puts("NO");
 }
 return 0 ;
}