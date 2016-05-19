/*************************************************************************
    > File Name: hdu5245.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015å¹´05æ28æ¥ ææå 13æ¶33å13ç§
 ************************************************************************/

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        double ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                LL ways = (LL)(i - 1) * (i - 1) * m * m;
                ways += (LL)(j - 1) * (j - 1) * n * n;
                ways += (LL)(n - i) * (n - i) * m * m;
                ways += (LL)(m - j) * (m - j) * n * n;
                ways -= (LL)(i - 1) * (i - 1) * (j - 1) * (j - 1);
                ways -= (LL)(i - 1) * (i - 1) * (m - j) * (m - j);
                ways -= (LL)(j - 1) * (j - 1) * (n - i) * (n - i);
                ways -= (LL)(n - i) * (n - i) * (m - j) * (m - j);
                LL sum = (LL)m * m * n * n;
                double p = ways * 1.0 / sum;
                double tmp = 1;
                for (int l = 1; l <= k; ++l) {
                    tmp *= p;
                }
                ans += (1 - tmp);
            }
        }
        printf("Case #%d: %.0f\n", icase++, ans);
    }
    return 0;
}