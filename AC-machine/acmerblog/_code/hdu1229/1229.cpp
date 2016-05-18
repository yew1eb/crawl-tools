#include <cstdlib>
 #include <cstring>
 #include <cstdio>
 using namespace std;
 
 int main()
 {
     char a[10], b[10], aa[10], bb[10];
     int bit, num1, num2;
     while( 1 )
     {
         memset( a, '0', sizeof( a ) );
         memset( b, '0', sizeof( b ) );
         scanf( "%s %s", a, b );
         if( a[0] == '0' && b[0] == '0' )
             break;
         strcpy( aa, a );
         strcpy( bb, b );
         scanf( "%d", &bit );
         int len1 = strlen( a ), len2 = strlen( b );
         a[len1] = b[len2] = '0';
         for( int i = len1 - 1, j = 8; i >= 0; --i, --j )
         {
             a[j] = a[i];
             a[i] = '0';
         }
         for( int i = len2 - 1, j = 8; i >= 0; --i, --j )
         {
             b[j] = b[i];
             b[i] = '0';
         }
         a[9] = b[9] = '\0';
         if( strcmp( a + 9 - bit, b + 9 - bit ) )
         {
             num1 = atoi( aa );
             num2 = atoi( bb );
             printf( "%d\n", num1 + num2 );
         }
         else
             puts( "-1" );
     }
     return 0;
 }