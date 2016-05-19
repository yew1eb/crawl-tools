/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2294.cpp
*  Create Date: 2014-08-03 16:03:27
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 31;
const int SIZE = 31;    // max size of the matrix
const int MOD = 1234567891;

int ans[N];
int t, n, k;

struct Mat{
    int n;
    ll v[SIZE][SIZE];    // value of matrix

    Mat(int _n = SIZE) {
        n = _n;
        memset(v, 0, sizeof(v));
    }

    void init(ll _v) {
        memset(v, 0, sizeof(v));
        repf (i, 0, n - 1)
            v[i][i] = _v;
    }

    void output() {
        repf (i, 0, n - 1) {
            repf (j, 0, n - 1)
                printf("%lld ", v[i][j]);
            puts("");
        }
        puts("");
    }
} a, b, c;

Mat operator * (Mat a, Mat b) {
    Mat c(a.n);
    repf (i, 0, a.n - 1) {
        repf (j, 0, a.n - 1) {
            c.v[i][j] = 0;
            repf (k, 0, a.n - 1) {
                c.v[i][j] += (a.v[i][k] * b.v[k][j]) % MOD;
                c.v[i][j] %= MOD;
            }
        }
    }
    return c;
}

Mat operator ^ (Mat a, ll k) {
    Mat c(a.n);
    c.init(1);
    while (k) {
        if (k&1) c = c * a;
        a = a * a;
        k >>= 1;
    }
    return c;
}

void init() {
    scanf("%d%d", &n, &k);
    a.n = b.n = c.n = k + 1;
    a.init(0);
    a.v[0][0] = a.v[0][k] = 1;
    repf (i, 1, k) {
        if (i > 1)
            a.v[i][i - 1] = k - i + 1;
        a.v[i][i] = i;
    }
    b.init(0);
    b.v[1][0] = k;
}

void solve() {
    c = a ^ n;
    c = c * b;
    printf("%lld\n", c.v[0][0]);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        init();
        solve();
    }
    return 0;
}
