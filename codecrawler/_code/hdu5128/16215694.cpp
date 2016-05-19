#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 35;
const int MAXM = 210;

struct Node {
    int x, y;
} node[MAXN];

int n, G[MAXM][MAXM], ans;

void init() {
    memset(G, -1, sizeof(G));
    ans = -1;
}

void input() {
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &node[i].x, &node[i].y);
        G[node[i].x][node[i].y] = i;
    }
}

int judge(int a, int b, int c, int d, int e, int f, int g, int h) {
    int minX = node[a].x, maxX = node[c].x, minY = node[a].y, maxY = node[c].y;
    int minX2 = node[e].x, maxX2 = node[g].x, minY2 = node[e].y, maxY2 = node[g].y;
    if (minX2 >= minX && minX2 <= maxX && minY2 >= minY && minY2 <= maxY) {
        if (maxX2 > minX && maxX2 < maxX && maxY2 > minY && maxY2 < maxY) {
            return (maxX - minX) * (maxY - minY);
        } else {
            return -1;
        }
    } else {
        return (maxX - minX) * (maxY - minY) + (maxX2 - minX2) * (maxY2 - minY2);
    }
    return -1;
}

void solve() {
    for (int a = 0; a < n; a++) {
        for (int c = a+1; c < n; c++) {
            int minX = node[a].x, maxX = node[c].x, minY = node[a].y, maxY = node[c].y;
            if (minX > maxX || minY > maxY) continue;
            int b = G[minX][maxY], d = G[maxX][minY];
            if (b != -1 && d != -1 && b != d) {
                if (a != b && a != d && b != c && d != c) {
                    for (int e = a+1; e < n; e++) {
                        if (e == a || e == b || e == c || e == d) continue;
                        for (int g = e+1; g < n; g++) {
                            if (g == a || g == b || g == c || g == d) continue;
                            int minX2 = node[e].x, maxX2 = node[g].x, minY2 = node[e].y, maxY2 = node[g].y;
                            if (minX2 > maxX2 || minY2 > maxY2) continue;
                            int f = G[minX2][maxY2], h = G[maxX2][minY2];
                            if (f != -1 && h != -1 && f != h) {
                                if (e != f && e != h && f != g && h != g) {
                                    ans = max(ans, judge(a, b, c, d, e, f, g, h));
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (ans == -1) {
        printf("imp\n");
    } else {
        printf("%d\n", ans);
    }
}

int main() {
    while (~scanf("%d", &n) && n) {
        init();
        input();
        solve();
    }
    return 0;
}
