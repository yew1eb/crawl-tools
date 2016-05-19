#include <cstdio>
 #include <cstring>
 #include <cstring>
 #include <cmath>
 using namespace std;
 
 double dp[500][2];
 
 inline double Max( double x, double y )
 {
     if( x - y > 1e-6 )
         return x;
     return y;
 }
 
 inline double to( double m, double xx )
 {
     return floor( m * xx * 0.97 * 100 ) / 100;
 }
 
 int main()
 {
     int N;
     while( scanf( "%d", &N ), N )
     {
         double xx;
         memset( dp, 0, sizeof( dp ) );
         dp[0][1] = 1000.0;  // 0号存储美元值，1号存储加元值
         for( int i = 1; i <= N; ++i )
         {
             scanf( "%lf", &xx );
             dp[i][0] = Max( dp[i-1][0], to( dp[i-1][1], 1.0 / xx ) );
             dp[i][1] = Max( dp[i-1][1], to( dp[i-1][0], xx ) );
         }
         printf( "%.2lf\n", dp[N][1] );
     }
     return 0;
 }