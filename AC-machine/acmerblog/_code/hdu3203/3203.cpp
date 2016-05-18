#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 
 const int MAX_N = 100000;
 int n, d, a, b;
 double p, f[MAX_N + 1][2];
 
 int main() {
     while (scanf("%d%d%d%d", &n, &d, &a, &b) != EOF) {
         if (!n && !d && !a && !b) break;
         p = d / 100.0;
         if (n <= 1) printf("%.4lf\n", 0.0);
         else {
             f[n][0] = min(a, b), f[n][1] = 0;
             for (int i = n - 1; i >= 1; i --) {
                 f[i][0] = min(f[i + 1][0] + b, a + p * f[i + 1][0] + (1.0 - p) * f[i + 1][1]);
                 f[i][1] = min(f[i + 1][1] + a, p * f[i + 1][0] + (1.0 - p) * f[i + 1][1]);
             }
             printf("%.4lf\n", f[1][1]);
         }
     }
     return 0;
 }