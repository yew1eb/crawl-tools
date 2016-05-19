/*
 * hdu1594/win.cpp
 * Created on: 2012-7-23
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
const int MAXN = 100010;
int n[MAXN], d[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
    int T;
    while(scanf("%d", &T) == 1) {
        for(int i = 0; i < T; i++) {
            scanf("%d", &n[i]);
        }
        for(int i = 1; i < T; i++) {
            d[i] = abs(n[i] - n[i - 1]);
        }
        int ans = -1, ansj;
        for(int i = T - 1; i > 0; i--) {
            if(d[i] >= ans) {
                ans = d[i];
                ansj = i;
            }
        }
        printf("%d %d\n", ansj, ansj + 1);
    }
    return 0;
}