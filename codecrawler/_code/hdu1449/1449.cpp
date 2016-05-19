#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 2000005
#define SIZE 5005
int n;
int x[SIZE], y[SIZE];
int dp[MAX], dist[SIZE];
inline int min(int a, int b)
{
 return a < b ? a : b;
}
int DP()
{
 dp[x[1]] = 0;
 for(int i = 2; i <= n; ++i)
 {
  for(int j = x[i]-1; j >= x[1]; --j)
  {
   if(dp[j] == -1) continue;
   if( (x[i]-j)*(x[i]-j) > dist[i] ) break;
   if( dp[ 2*x[i]-j ] == -1 || dp[ 2*x[i]-j ] > dp[j]+1)
    dp[ 2*x[i]-j ] = dp[j]+1;
   if( 2*x[i]-j >= x[n] &&  (dp[ x[n] ] == -1 || dp[ x[n] ] > dp[ 2*x[i]-j ]) )
    dp[ x[n] ] = dp[ 2*x[i]-j ];
  }
 }
 return dp[ x[n] ];
}
int main()
{
// freopen("input.txt", "r", stdin);
 int caseNum, i;
 scanf("%d",&caseNum);
 while(caseNum--)
 {
  scanf("%d",&n);
  for(i = 1; i <= n; ++i)
  {
   scanf("%d %d",&x[i], &y[i]);
   dist[i] = y[i]*y[i]-(y[i]-y[1])*(y[i]-y[1]);
  }
  memset(dp, -1, sizeof(dp));
  printf("%d\n",DP());
 }
 return 0;
}