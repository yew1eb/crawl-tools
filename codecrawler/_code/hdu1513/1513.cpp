#include <iostream>
 using namespace std;
 
 char a[5010], b[5010];
 int dp[2][5010];
 int main()
 {
     int n;
     while(scanf("%d", &n) != EOF)
     {
         getchar();
         for(int i = 0; i < n; ++i)
         {
             scanf("%c", a + i);
             b[n - i - 1] = a[i];
         }
         memset(dp, 0, sizeof(dp));
         for(int i = 1; i <= n; ++i)
             for(int j = 1; j <= n; ++j)
                 if(a[i-1] == b[j-1])
                     dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
                 else
                     dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
         printf("%d\n", n - dp[n%2][n]);
     }
     return 0;
 }