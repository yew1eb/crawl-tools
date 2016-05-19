1 #include <stdio.h>
 2 #include <string.h>
 3 
 4 #define M 1000005
 5 #define MAX(x, y) ((x) > (y) ? (x) : (y))
 6 
 7 int dp[2][M];
 8 int num[M];
 9 
10 int main(void)
11 {
12     int t, i, j;
13     int n, m;
14     int max;
15 
16     while(~scanf("%d%d", &m, &n))
17     {
18     for(i = 1; i <= n; i++)
19     {
20         dp[0][i] = 0;
21         dp[1][i] = 0;
22         scanf("%d", num + i);
23     }
24     for(i = 1, t = 1; i <= m; i++, t = !t)
25     {
26         dp[t][i] = dp[!t][i-1] + num[i];
27         dp[!t][i] = MAX(dp[!t][i], dp[!t][i-1]);
28         for(j = i+1; j <= n - m + i; j++)
29         {
30         dp[t][j] = MAX(dp[!t][j-1], dp[t][j-1]) + num[j];
31         dp[!t][j] = MAX(dp[!t][j], dp[!t][j-1]);
32         }
33     }
34     max = -(1 << 30);
35     for(i = m; i <= n; i++)
36         max = MAX(max, dp[m&1][i]);
37     printf("%d\n", max);
38     }
39     return 0;
40 }