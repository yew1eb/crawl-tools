#include <stdio.h>
  #include <math.h>
  const double eps=1.0e-6;
  int dp[10010][10];
  void Init( )
  {
      int y;
      double s=log10(2), t, x;
      dp[0][1]=1;
      for( int i=1; i<=10000; ++ i ){
          for( int j=1; j<10; ++ j ){
              dp[i][j]=dp[i-1][j];
          }
          t=s*i;
          x=t-(int)t;
          y=( int )(pow( 10, x )+eps);// 注意有精度损失 
          dp[i][y]++;
      }
  }
  int main( )
  {
      Init( );
      int N;
      while( ~scanf( "%d", &N ) ){
          if( N==-1 )break;
          for( int i=1; i<10; ++i ){
              printf( i==9?"%d\n":"%d ", dp[N][i] );
          }
      }
      return 0;
  }