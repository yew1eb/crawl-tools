/*
 * hdu2576/win.cpp
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
const int MOD = 20090524 * 6;

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
    int T, n;
    long long ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ans = n;
        ans *= n + 1;
        ans %= MOD;
        ans *= n + 2;
        ans %= MOD;
        ans /= 6;
        printf("%d\n", (int) ans);
    }
    return 0;
}