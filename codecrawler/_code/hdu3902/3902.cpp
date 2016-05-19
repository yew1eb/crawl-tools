#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>

#define ll __int64

using namespace std;

const double eps = 1e-8;
const int maxn = 40005;

struct Point {
    double x, y;
} p[maxn];

int n;

double dis(int a, int b) {
    double dx = p[a].x - p[b].x;
    double dy = p[a].y - p[b].y;
    return sqrt(dx * dx + dy * dy);
}

bool Check(int a, int b) {
    int x = a - 1, y = a + 1;
    while (y != b) {
        if (x == -1) x = 2 * n - 1;
        if (fabs(dis(x, a) - dis(y, a)) > eps) return false;
        if (fabs(dis(x, b) - dis(y, b)) > eps) return false;
        x--, y++;
    }
    return true;
}

int main() {
    int i;
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%lf %lf", &p[i*2].x, &p[i*2].y);
            if (i > 0) {
                p[i*2-1].x = (p[i*2].x + p[i*2-2].x) / 2.0;
                p[i*2-1].y = (p[i*2].y + p[i*2-2].y) / 2.0;
            }
        }
        p[n*2-1].x = (p[0].x + p[n*2-2].x) / 2.0;
        p[n*2-1].y = (p[0].y + p[n*2-2].y) / 2.0;
        
        for (i = 0; i < n; i++) {
            if (Check(i, i + n))
                break;
        }
        puts(i == n ? "NO" : "YES");
    }
    return 0;
}
