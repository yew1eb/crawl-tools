#include <stdio.h>
#include <string.h>
#define N 110
#define eps 1e-8

char map[N][N];
double visit[N][N]; //到该点的概率

double deal ( int c, int n, int m ) {
 int i, j;
 double ans = 0;
 memset ( visit, 0, sizeof ( visit ) );
 visit[ 0 ][ c ] = 1;
 for ( i = 0 ; i < n - 1 ; ++i ) { //这里用的是向下扩展
  for ( j = 0 ; j < m ; ++j ) {
   if ( visit[ i ][ j ] > eps ) {
    if ( map[ i ][ j ] != '.' ) { //有概率就一定不是'*' 并且又不是'.'的情况下就是数字了
     ans += visit[ i ][ j ] * ( map[ i ][ j ] - '0' );
    }
    else {
     if ( map[ i + 1 ][ j ] != '*' ) { //不是'*'的地方直接继承
      visit[ i + 1 ][ j ] += visit[ i ][ j ];
     }
     else {
      if ( j > 0 ) { //向左下右下扩展
       visit[ i + 1 ][ j - 1 ] += visit[ i ][ j ] / 2;
      }
      if ( j < m - 1 ) {
       visit[ i + 1 ][ j + 1 ] += visit[ i ][ j ] / 2;
      }
     }
    }
   }
  }
 }
 for ( i = 0 ; i < m ; ++i ) { //最后一行特别处理下
  if ( map[ n - 1 ][ i ] != '*' && map[ n - 1 ][ i ] != '.' ) {
   ans += visit[ n - 1 ][ i ] * ( map[ n - 1 ][ i ] - '0' );
  }
 }
 return ans;
}

int main () {
 int i, n, m, t;
 double ans, temp;
 scanf ( "%d", &t );
 while ( t-- ) {
  scanf ( "%d%d", &n, &m );
  getchar();
  for ( i = 0 ; i < n ; ++i ) {
   gets( map[ i ] );
   if ( map[ i ][ 0 ] == '\0' ) --i;
  }
  ans = 0;
  for ( i = 0 ; i < m ; ++i ) {
   if ( map[ 0 ][ i ] != '.' ) { //特判下第一行
    if ( map[ 0 ][ i ] == '*' ) temp = 0;
    else temp = map[ 0 ][ i ] - '0';
   }
   else temp = deal( i, n, m ); //向下搜索
   if ( temp - ans > eps ) ans = temp;
  }
  printf ( "%.6lf\n", ans );
 }
 return 0;
}