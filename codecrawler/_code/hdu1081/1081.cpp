#include <stdio.h>
 #include <string.h>
 #define MAX(x, y) ((x) > (y) ? (x) : (y))
 int main(void)
 {
     int map[101][101];
     int dp[101], tmp[101];
     int max;
     int i, j, t;
     int n;
 
     while(scanf("%d", &n) != EOF)
     {
     for(i = 0; i < n; i++)
         for(j = 0; j < n; j++)
         scanf("%d", &map[i][j]);
     max = -10000000;
     for(i = 0; i < n; i++)
     {
         memset(tmp, 0, sizeof(tmp));
         for(t = i; t < n; t++)
         {
         for(j = 0; j < n; j++)
             tmp[j] += map[t][j];
 
         dp[0] = tmp[0];
         for(j = 1; j < n; j++)
         {
             /*dp[j] = MAX(dp[j-1] + tmp[j], tmp[j]);
             max = MAX(dp[j], max);*/
             if(dp[j-1] > 0)
             dp[j] = dp[j-1] + tmp[j];
             else
             dp[j] = tmp[j];
             if(dp[j] > max)
             max = dp[j];
         }
         }
     }
     printf("%d\n", max);
     }
     return 0;
 }