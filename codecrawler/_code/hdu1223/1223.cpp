#include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <cassert>
 #include <cmath>
 #include <algorithm>
 
 using namespace std;
 
 const int maxSize = 150;
 
 struct bigNum {
     char num[maxSize];
 };
 
 bigNum operator * (bigNum a, bigNum b) {
     int la = strlen(a.num);
     int lb = strlen(b.num);
     bigNum ret;
     int tmp[maxSize];
 
     for (int i = 0; i < la; i++) a.num[i] -= '0';
     for (int i = 0; i < lb; i++) b.num[i] -= '0';
     for (int i = 0, endi = la + lb; i <= endi; i++) tmp[i] = ret.num[i] = 0;
     for (int i = 0; i < la; i++) {
         int ti = la - 1 - i;
 
         for (int j = 0; j < lb; j++) {
             int tj = lb - 1 - j;
 
             tmp[i + j] += a.num[ti] * b.num[tj];
         }
     }
     for (int i = 0, endi = la + lb - 1; i < endi; i++) {
         tmp[i + 1] += tmp[i] / 10;
         ret.num[endi - i] = tmp[i] % 10 + '0';
     }
     ret.num[0] = tmp[la + lb - 2] / 10 + '0';
 
     if (ret.num[0] == '0') {
         for (int i = 1, endi = la + lb + 2; i < endi; i++) {
             ret.num[i - 1] = ret.num[i];
         }
     }
 
     return ret;
 }
 
 bigNum operator + (bigNum a, bigNum b) {
     int la = strlen(a.num);
     int lb = strlen(b.num);
     bigNum ret;
     int maxLen = max(la, lb);
     int minLen = min(la, lb);
 
     for (int i = 0; i <= maxLen + 1; i++) ret.num[i] = 0;
     for (int i = 0; i < minLen; i++) {
         ret.num[maxLen - i] += a.num[la - i - 1] + b.num[lb - i - 1] - '0';
         if (ret.num[maxLen - i] > '9') ret.num[maxLen - i - 1]++, ret.num[maxLen - i] -= 10;
     }
     if (maxLen == la) {
         for (int i = minLen; i < maxLen; i++) {
             ret.num[maxLen - i] += a.num[la - i - 1];
             if (ret.num[maxLen - i] > '9') ret.num[maxLen - i - 1]++, ret.num[maxLen - i] -= 10;
         }
     } else {
         for (int i = minLen; i < maxLen; i++) {
             ret.num[maxLen - i] += b.num[lb - i - 1];
             if (ret.num[maxLen - i] > '9') ret.num[maxLen - i - 1]++, ret.num[maxLen - i] -= 10;
         }
     }
     ret.num[0] += '0';
 
     if (ret.num[0] == '0') {
         for (int i = 1, endi = la + lb + 2; i < endi; i++) {
             ret.num[i - 1] = ret.num[i];
         }
     }
 
     return ret;
 
 }
 
 const int maxn = 52;
 bigNum dp[maxn][maxn];
 bigNum fac[maxn];
 
 char *con(int x) {
     int len = (int)log10((double)x) + 1;
     char *ret = new char[len + 1];
 
     for (int i = len - 1; i >= 0; i--) {
         ret[i] = x % 10 + '0';
         x /= 10;
     }
     ret[len] = 0;
 
     return ret;
 }
 
 void pre() {
     strcpy(fac[0].num, "1");
     for (int i = 1; i < maxn; i++){
         bigNum tmp;
         char *temp = con(i);
 
         strcpy(tmp.num, temp);
         delete temp;
         fac[i] = fac[i - 1] * tmp;
     }
     for (int i = 1; i < maxn; i++) {
         strcpy(dp[i][1].num, "1");
         strcpy(dp[i][i].num, "1");
         for (int j = 2; j < i; j++) {
             bigNum tmp;
             char *temp = con(j);
 
             strcpy(tmp.num, temp);
             delete temp;
             dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * tmp;
         }
         strcpy(dp[i][0].num, "0");
         for (int j = 1; j <= i; j++){
             dp[i][0] = dp[i][0] + dp[i][j] * fac[j];
         }
 //printf("%s\n", dp[i][0].num);
     }
 }
 
 int main() {
     pre();
     int n, T;
 
     scanf("%d", &T);
     while (T-- && ~scanf("%d", &n)){
         printf("%s\n", dp[n][0].num);
     }
 
     return 0;
 }