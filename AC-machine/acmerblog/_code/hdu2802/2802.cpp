/*
 * hdu2802/win.cpp
 * Created on: 2011-10-28
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
const int MOD = 2009 * 4;

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
    int n;
    long long ans;
    while (scanf("%d", &n) == 1 && n > 0) {
        ans = (n + 1);
        ans *= (n + 1);
        ans %= MOD;
        ans *= (2 * n - 1);
        ans %= MOD;
        if (n % 2 == 0) {
            ans++;
        }
        ans %= MOD;
        ans /= 4;
        printf("%d\n", (int) ans);
    }
    return 0;
}