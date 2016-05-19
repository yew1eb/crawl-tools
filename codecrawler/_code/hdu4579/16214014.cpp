#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 50005;
double p[N][11];
int n , m , c[11];
int l[N] , r[N];
double a[N][11];
double constant[N];
bool zero (double d) {
    const double eps = 1e-6;
    return fabs(d) < eps;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    while (scanf ("%d %d" , &n, &m) != EOF) {
        if (!n & !m) break;
        for (int i = 1 ; i <= n ; i ++) {
            int tot = 0;
            for (int j = 1 ; j <= m ; j ++) {
                scanf ("%d" , &c[j]);
                tot += c[j];
            }
            double other = 1.0;
            for (int j = -m ; j < 0 ; j ++) {
                p[i][j + m] = 0.3 * c[-j] / (1 + tot);
                if (i + j >= 1) other -= p[i][j + m];
            }
            for (int j = 1 ; j <= m ; j ++) {
                p[i][j + m] = 0.7 * c[j] / (1 + tot);
                if(i + j <= n) other -= p[i][j + m];
            }
            p[i][m] = other;
        }
        memset (a , 0 , sizeof(a));
        for (int i = n - 1 ; i > 0 ; i --) {
            l[i] = max(i - m , 1);
            r[i] = min(n , i + m);
            for (int j = 0 ; j < r[i] - l[i] + 1 ; j ++) {
                a[i][j] = p[i][(l[i] + j) - i + m];
            }
            constant[i] = 1.0;
            for (int j = r[i] ; j > i ; j --) {
                if (j == n) a[i][j - l[i]] = 0;
                else {
                    double q = a[i][j - l[i]];
                    if (zero(q)) continue;
                    for (int k = 0 ; k < j - l[j] ; k ++) {
                        a[i][k + l[j] - l[i]] += a[j][k] * q;
                    }
                    a[i][j - l[i]] = 0;
                    constant[i] += constant[j] * q;
                }
            } 
            double q = 1 - a[i][i - l[i]];
            for (int j = 0 ; j < r[i] - l[i] + 1 ; j ++) {
                a[i][j] = a[i][j] / q;
            }
            a[i][i - l[i]] = 0;
            constant[i] = constant[i] / q;
        }
        printf ("%.2f\n" , constant[1]);
    }
    return 0;
}