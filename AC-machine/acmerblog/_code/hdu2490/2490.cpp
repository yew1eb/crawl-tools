#include <cstdio>
 #include <cstring>
 #include <iostream>
 #include <algorithm>
 using namespace std;
 
 const int MAXN = 110;
 const int MAXM = 10010;
 
 int wel[MAXN][MAXM], len[MAXN][MAXM];
 int sum_w[MAXM], sum_l[MAXM];
 int a[MAXM], b[MAXM], head, tail;
 int dp[2][MAXM];
 int n, m, k, cur;
 
 inline void insert(int x, int y) {
     while(head != tail && a[tail - 1] < x) --tail;
     a[tail] = x; b[tail] = y; ++tail;
 }
 
 void solve() {
     memset(dp, 0, sizeof(dp));
     cur = 0;
     for(int i = 0; i < n; ++i) {
         cur ^= 1;
         memset(dp[cur], 0, sizeof(dp[cur]));
 
         sum_w[0] = sum_l[0] = 0;
         for(int j = 1; j <= m; ++j) sum_w[j] = sum_w[j - 1] + wel[i][j];
         for(int j = 1; j <= m; ++j) sum_l[j] = sum_l[j - 1] + len[i][j];
         head = tail = 0;
         for(int j = 0; j <= m; ++j) {
             insert(dp[cur ^ 1][j] - sum_w[j], sum_l[j]);
             while(k < sum_l[j] - b[head]) ++head;
             dp[cur][j] = max(dp[cur][j], a[head] + sum_w[j]);
         }
 
         sum_w[m] = sum_l[m] = 0;
         for(int j = m; j > 0; --j) sum_w[j - 1] = sum_w[j] + wel[i][j];
         for(int j = m; j > 0; --j) sum_l[j - 1] = sum_l[j] + len[i][j];
         head = tail = 0;
         for(int j = m; j >= 0; --j) {
             insert(dp[cur ^ 1][j] - sum_w[j], sum_l[j]);
             while(k < sum_l[j] - b[head]) ++head;
             dp[cur][j] = max(dp[cur][j], a[head] + sum_w[j]);
         }
     }
 }
 
 int main() {
     while(scanf("%d%d%d", &n, &m, &k) != EOF) {
         if(n == 0 && m == 0 && k == 0) break;
         ++n;
         for(int i = 0; i < n; ++i)
             for(int j = 1; j <= m; ++j) scanf("%d", &wel[i][j]);
         for(int i = 0; i < n; ++i)
             for(int j = 1; j <= m; ++j) scanf("%d", &len[i][j]);
         solve();
         int ans = 0;
         for(int i = 0; i <= m; ++i) ans = max(ans, dp[cur][i]);
         printf("%d\n", ans);
     }
 }