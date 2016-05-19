#include <cstdio>  
#include <cstring>  
#include <algorithm>  
  
using namespace std;  
  
const int MAX_N = 807;  
  
int n;  
int a[MAX_N][MAX_N], b[MAX_N][MAX_N];  
int c[MAX_N][MAX_N];  
  
int main() {  
    while (1 == scanf("%d", &n)) {  
        for (int i = 0; i < n; ++i) {  
            for (int j = 0; j < n; ++j) {  
                int x;  
                scanf("%d", &x);  
                a[i][j] = x % 3;  
            }  
        }  
        for (int i = 0; i < n; ++i) {  
            for (int j = 0; j < n; ++j) {  
                int x;  
                scanf("%d", &x);  
                b[i][j] = x % 3;  
            }  
        }  
        memset(c, 0, sizeof(c));  
        for (int i = 0; i < n; ++i) {  
            for (int k = 0; k < n; ++k) {  
                if (a[i][k] == 0) continue;  
                for (int j = 0; j < n; ++j) {  
                    c[i][j] += a[i][k] * b[k][j];  
                    c[i][j] %= 3;  
                }  
            }  
        }  
        for (int i = 0; i < n; ++i) {  
            for (int j = 0; j < n; ++j) {  
                if (j == 0) printf("%d", c[i][j]);  
                else printf(" %d", c[i][j]);  
            }  
            puts("");  
        }  
    }  
    return 0;  
}  