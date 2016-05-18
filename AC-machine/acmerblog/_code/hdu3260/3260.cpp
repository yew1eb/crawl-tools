#include <cstdio>
 #include <algorithm>
 #include <cstring>
 #include <iostream>
 using namespace std;
 typedef long long LL;
 
 const int MAXN = 110;
 const int MAXM = 1010;
 const int INF = 0x3fff3fff;
 
 int dp[MAXM];
 int mat[MAXN][MAXM];
 bool money[MAXN][MAXM];
 int n, m, k;
 
 void dfs(int from, int ti, int tj, int spd, int sum) {
     if(ti < 1) ti = 1;
     if(ti > n) ti = n;
     if(ti == 1 && from != tj) {
         if(dp[tj] < sum) dp[tj] = sum;
         return ;
     }
     if(tj - from == k || tj == m) return ;
     if(money[ti][tj]) sum += mat[ti][tj];
     else if(ti != 1) spd += mat[ti][tj];
     dfs(from, ti + spd - 1, tj + 1, spd - 1, sum);
     dfs(from, ti + spd    , tj + 1, spd    , sum);
     dfs(from, ti + spd + 1, tj + 1, spd + 1, sum);
 }
 
 void solve() {
     dp[1] = 0;
     for(int i = 2; i <= m; ++i) dp[i] = -INF;
     for(int i = 1; i < m; ++i) {
         if(dp[i] == -INF) continue;
         dfs(i, 1, i, 0, dp[i]);
     }
     //for(int i = 1; i <= m; ++i) printf("%d\n", dp[i] + money[1][i] * mat[1][i]);
     if(money[1][m]) dp[m] += mat[1][m];
     printf("%d\n", dp[m]);
 }
 
 char lastch = ' ';
 
 inline char readchar() {
     while(lastch != 'v' && lastch != '$')
         lastch = getchar();
     return lastch;
 }
 
 inline int readint() {
     int g = 0, l;
     while(!isdigit(lastch) && lastch != '-') lastch = getchar();
     if(lastch == '-') {
         l = -1;
         lastch = getchar();
     }
     else l = 1;
     while(isdigit(lastch)) {
         g = g * 10 + lastch - '0';
         lastch = getchar();
     }
     return g * l;
 }
 
 int main() {
     while(true) {
         n = readint(); m = readint(); k = readint();
         if(n + m + k == 0) break;
         char c;
         for(int i = 1; i <= n; ++i) {
             for(int j = 1; j <= m; ++j) {
                 //scanf(" %c%d", &c, &mat[i][j]);
                 c = readchar();
                 mat[i][j] = readint();
                 money[i][j] = (c == '$');
             }
         }
         solve();
     }
 }