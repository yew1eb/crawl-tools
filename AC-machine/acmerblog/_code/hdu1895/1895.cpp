/*hdu 1895  A[0][i]+A[1][j]+A[2][k]+A[3][l]+A[4][m]＝0
一共5个数组,合并成2次,变成3个数组,这是空间是90000*90000*3000
对三个数组排序,用300*90000*log(90000),大家应该想到是二分查找吧*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#define MOD 1000000007
#define MAXN 305
using namespace std;
int a[5][MAXN], b[2][MAXN*MAXN];
int cmp( int p1, int p2 )
{
 return p1 < p2;
}
int Find( int x, int c[] )
{
 int l = 1, r = c[0], mid;
 while ( l <= r )
 {
  mid = ( l + r ) >> 1;
  if( x > c[r] || x < c[l] )
  {
   return 0;
  }
  if( c[mid] == x )
  {
   int sum = 1;
   for( l = mid - 1; l >= 0 && c[l] == x; l--, sum++ );
   for( r = mid + 1; r <= c[0] && c[r] == x; r++, sum++ );
   return sum;
  }
  else if( x > c[mid] )
  {
   l = mid + 1;
  }
  else
  {
   r = mid - 1;
  }
 }
 return 0;
}
void Connect( int k1, int k2, int k3 )
{
 int i, j, len = 0;
 for( i = 1; i <= a[k1][0]; i++ )
 {
  for( j = 1; j <= a[k2][0]; j++ )
  {
   b[k3][++len] = a[k1][i] + a[k2][j];
  }
 }
 b[k3][0] = len;
}
void Solve( int c1[], int c2[], int c3[] )
{
 int i, j, num, sum = 0;
 sort( c1+1, c1+c1[0]+1, cmp );
 sort( c2+1, c2+c2[0]+1, cmp );
 sort( c3+1, c3+c3[0]+1, cmp );
 for( i = 1; i <= c1[0]; i++ )
 {
  for( j = 1; j <= c2[0]; j++ )
  {
   num = -( c1[i] + c2[j] );
   if( num < c3[1] || num > c3[c3[0]] )
   {
    continue;
   }
   sum += Find( num, c3 );
  }
 }
 printf("%d\n", sum);
}
int main()
{ 
 int cas;
 scanf("%d", &cas);
 while ( cas-- )
 {
  int i, j;
  for( i = 0; i < 5; i++ )
  {
   scanf("%d", &a[i][0]);
   for( j = 1; j <= a[i][0]; j++ )
   {
    scanf("%d", &a[i][j]);
   }
  }
  Connect( 0, 1, 0 );
  Connect( 2, 3, 1 );
  Solve( a[4], b[0], b[1] );
 }
 return 0;
}