/*************************************************************************
    > File Name: hdu5225.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015å¹´05æ09æ¥ ææå­ 21æ¶15å54ç§
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

static const int mod = 1e9 + 7;
LL per_inver[110];
int arr[110];
bool vis[110];
LL sum[110];
LL f[110];
int tree[110];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int n) {
    for (int i = x; i <= n; i += lowbit(i)) {
        ++tree[i];
    }
}

int getsum(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) {
        ans += tree[i];
    }
    return ans;
}

int main() {
    per_inver[0] = 0;
    per_inver[1] = 0;
    f[0] = 1;
    for (int i = 1; i <= 100; ++i) {
        f[i] = f[i - 1] * i;
        f[i] %= mod;
    }
    LL jiechen = 1;
    for (int i = 2; i <= 100; ++i) {
        LL last = per_inver[i - 1];
        jiechen *= (i - 1);
        jiechen %= mod;
        per_inver[i] = 0;
        for (int j = 0; j < i; ++j) {
            per_inver[i] += last;
            per_inver[i] %= mod;
            last += jiechen;
            last %= mod;
        }
    }
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1;i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        memset(tree, 0, sizeof(tree));
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            add(arr[i], n);
            LL cur = i - getsum(arr[i]);
            cur %= mod;
            sum[i] = sum[i - 1] + cur;
            sum[i] %= mod;
        }
        LL ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < arr[i]; ++j) { //è¿ä¸ä½å¼å§å°ï¼åé¢çé½ç¸åï¼æä¸¾æ²¡åºç°è¿ç
                LL pre = sum[i - 1]; //åé¢åºå®çéåºå¯¹
                if (!vis[j]) {
                    LL cur = 0, u = 0;
                    for (int k = 1; k < j; ++k) {
                        if (!vis[k]) {
                            ++u;
                        }
                    }
                    for (int k = j + 1; k <= n; ++k) {
                        if (vis[k]) {
                            ++cur;
                        }
                    }
                    int v = 0;
                    for (int k = 1; k < i; ++k) {
                        for (int l = i; l <= n; ++l) {
                            if (!vis[arr[l]] && arr[l] != j) {
                                if (arr[k] > arr[l]) {
                                    ++v;
                                }
                            }
                        }
                    }
                    ans += per_inver[n - i] + (cur + u + v + pre) * f[n - i];
                    ans %= mod;
                }
            }
            vis[arr[i]] = 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}