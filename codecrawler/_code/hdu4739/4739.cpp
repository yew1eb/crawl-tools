#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define LL long long
#define PI acos(-1.0)
#define N 5100
#define M 1148576
#define inf 1000000000

struct node {
    int a, b, c, d;
    void set (int _a, int _b, int _c, int _d) {
        a = _a; b = _b; c = _c; d = _d;
    }
}pe[N];
struct point {
    int x, y;
    void set () {
        scanf ("%d%d", &x, &y);
    }
}p[30];
int cnt;
int cmp (point a, point b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
int dp[M];
int dfs (int s) {
    if (dp[s] != -1) return dp[s];
    int Max = 0;
    for (int i = 0; i < cnt; ++i) {
        if ((s&(1<<pe[i].a)) + (s&(1<<pe[i].b))+(s&(1<<pe[i].c)) + (s&(1<<pe[i].d)) == 0) {
            int si = s + (1<<pe[i].a) + (1<<pe[i].b) + (1<<pe[i].c) + (1<<pe[i].d);
            Max = max (Max, dfs (si) + 4);
        }
    }
    return dp[s]= Max;
}
int main () {
    int n;
    while (scanf ("%d", &n), n != -1) {
        for (int i = 0; i < n; ++i) {
            p[i].set();
        }
        cnt = 0;
        sort (p, p + n, cmp);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (p[i].x != p[j].x) break;
                for (int ii = j + 1;  ii < n; ++ii) {
                    for (int jj = ii + 1; jj < n; ++jj) {
                        if (p[ii].x != p[jj].x) continue;
                        if (p[i].y == p[ii].y && p[j].y == p[jj].y && p[j].y - p[i].y == p[ii].x - p[i].x) {
                            pe[cnt].set (i, j, ii, jj);
                        //    cout << i << ' ' << j << ' ' << ii << ' ' << jj << endl;
                            cnt++;
                        }
                    }
                }
            }
        }
        memset (dp, -1, sizeof (dp));
        printf ("%d\n", dfs (0));
    }
}