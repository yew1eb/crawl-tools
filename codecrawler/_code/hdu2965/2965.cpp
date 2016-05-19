/*
 * hdu2965/win.cpp
 * Created on: 2012-11-4
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
typedef long long LL;
int gcd(int a, int b) {
    int r;
    while(b) {
        r = a % b;
        a = b, b = r;
    }
    return a;
}
inline bool judge2(int a, int b, int z) {
    int x = 1;
    while(a * x < z) {
        if((z - a * x) % b == 0) {
            return true;
        }
        x++;
    }
    return false;
}

inline bool judge(int x, int y, int n, int m) {
    int t = gcd(x, y);
    if(n % t != 0 || m % t != 0) {
        return false;
    }
    x /= t, y /= t, m /= t, n /= t;
    if(n % x == 0 && m % y == 0) {
        return true;
    }
    if(n % y == 0 && m % x == 0) {
        return true;
    }
    if(n % x == 0 && n % y == 0 && judge2(x, y, m)) {
        return true;
    }
    if(m % x == 0 && m % y == 0 && judge2(x, y, n)) {
        return true;
    }
    return false;
}
int get_int() {
    int res = 0, ch;
    while (!((ch = getchar()) >= '0' && ch <= '9')) {
        if (ch == EOF)
            return 1 << 30;
    }
    res = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + (ch - '0');
    return res;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
    int T, x, y, n, m;
    T = get_int();
    while(T--) {
        x = get_int();
        y = get_int();
        n = get_int();
        m = get_int();
        bool ret = judge(x, y, n, m);
        puts(ret ? "YES" : "NO");
    }
    return 0;
}