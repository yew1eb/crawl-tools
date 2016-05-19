#include <cmath>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 
 const double PI = acos(-1.0);
 int n;
 
 int main() {
     while (scanf("%d", &n) != EOF) {
         if (n == 0) break;
         printf("%.2lf\n", (n / PI) * (n / PI) * PI * 0.5);
     }
     return 0;
 }