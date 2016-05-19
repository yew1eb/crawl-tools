/*************************************************************************
    > File Name: hdu5248.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015å¹´05æ31æ¥ æææ¥ 10æ¶46å06ç§
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

static const int N = 100110;
int arr[N];

int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        int l = 0, r = 1000000000;
        int mid;
        int ans = -1;
        while (l <= r) {
            mid = (l + r) >> 1;
            bool flag = 1;
            int last = arr[n] + mid;
            for (int i = n - 1; i >= 1; --i) {
                if (arr[i] + mid < last) {
                    last = arr[i] + mid;
                }
                else if (arr[i] - mid >= last) {
                    flag = 0;
                    break;
                }
                else {
                    --last;
                }
            }
            if (flag) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        printf("Case #%d:\n", icase++);
        printf("%d\n", ans);
    }
    return 0;
}