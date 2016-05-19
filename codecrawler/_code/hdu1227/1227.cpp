#include <iostream>
 using namespace std;
 
 int fab(int a)
 {
     return a > 0 ? a : -a;
 }
 
 int cost[210][210];
 int dp[32][210];
 int a[210];
 
 int k, n;
 int main()
 {
     int cas = 0;
     while(scanf("%d%d", &n, &k) && (n || k))
     {
         for(int i = 1; i <= n; ++i)
             scanf("%d", a + i);
         for(int i = 1; i <= n; ++i)
             for(int j = i; j <= n; ++j)
             {
                 cost[i][j] = 0;
                 for(int k = i; k <= j; ++k)
                     cost[i][j] += fab(a[k] - a[(i+j)/2]);
             }
         for(int i = 1; i <= k; ++i)
             for(int j = 1; j <= n; ++j)
                 dp[i][j] = 0;
         for(int i = 1; i <= n; ++i)
             dp[1][i] = cost[1][i];
             
         for(int i = 2; i <= k; ++i)
             for(int j = i + 1; j <= n; ++j)
             {
                 int mmin = 1 << 30;
                 for(int k = i -1; k < j; ++k)
                     if(dp[i-1][k] + cost[k+1][j] < mmin)
                         mmin = dp[i-1][k] + cost[k+1][j];
                 dp[i][j] = mmin;
             }
         printf("Chain %d\n", ++cas);
         printf("Total distance sum = %d\n\n", dp[k][n]);
     }
     return 0;
 }