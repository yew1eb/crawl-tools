#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

double a[65];
double f[65];

int main() {
    int n;
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    a[1] = 2;
    f[1] = 1;
    for(int i = 2; i < 65; i++) {
        a[i] = a[i-1] * 2;
    }
    for(int i = 2; i < 65; i++) {
        double tmp;
        double mmin = a[i] - 1;
        for(int j = 1; j < i; j++) {
            tmp = a[i-j] - 1 + 2 * f[j];
            if(tmp < mmin) {
                mmin = tmp;
            }
        }
        f[i] = mmin;
    }
    while(scanf("%d", &n) != EOF) {
        printf("%.0lf\n", f[n]);
    }
    return 0;
}
