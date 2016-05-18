dp[i][j][k]+=dp[i-1][j-1][k-p[i]];
 dp[i][j][k]+=dp[i-1][j][k];