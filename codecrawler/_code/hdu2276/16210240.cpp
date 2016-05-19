/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2276.cpp
*  Create Date: 2014-08-03 22:47:12
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

const int SIZE = 101;    // max size of the matrix

int n;
string s;

struct Mat{
    int n;
    int v[SIZE][SIZE];    // value of matrix

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
                printf("%d ", v[i][j]);
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
                c.v[i][j] ^= (a.v[i][k] & b.v[k][j]);
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
    cin >> s;
    int len = s.length();
    a.n = b.n = c.n = len;
    a.init(0);
    b.init(0);
    c.init(0);

    repf (i, 0, len - 1) {
        b.v[i][0] = s[i] - '0';
    }
    a.v[0][0] = a.v[0][a.n - 1] = 1;
    repf (i, 1, a.n - 1) {
        a.v[i][i] = a.v[i][i - 1] = 1;
    }
}

void solve(int n) {
    c = a ^ (n);
    c = c * b;
    repf (i, 0, c.n - 1) {
        printf("%d", c.v[i][0]);
    }
    puts("");
}

int main() {
    while (~scanf("%d", &n)) {
        init();
        solve(n);
    }
    return 0;
}
