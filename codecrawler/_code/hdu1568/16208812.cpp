/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1568.cpp
*  Create Date: 2014-08-04 10:09:58
*  Descripton:  fib
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

int n;
ll tab[22];
double ans;

double fib(int x) {
    return -0.5 * log(5.0) / log(10.0) + ( (double)n) * log((sqrt(5.0) + 1) / 2) / log(10.0);
}

int main() {
    // table
    tab[0] = 0;
    tab[1] = 1;
    repf (i, 2, 20)
        tab[i] = tab[i - 1] + tab[i - 2];

    while (~scanf("%d", &n)) {
        if (n < 21) {
            printf("%lld\n", tab[n]);
            continue;
        }
        ans = fib(n);
        ans -= floor(ans);
        ans = pow(10.0, ans);
        while (ans < 1000)
            ans *= 10;
        printf("%d\n", (int)ans);
    }
    return 0;
}