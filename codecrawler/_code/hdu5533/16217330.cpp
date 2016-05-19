#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 105;

struct Point {
    int x, y;
    Point (int x = 0, int y = 0): x(x), y(y) {}

    void read() { scanf("%d%d", &x, &y); }
    bool operator == (const Point& u) const { return x == u.x && y == u.y; }
    bool operator < (const Point& u) const { return x < u.x || (x == u.x && y < u.y); }

    Point operator + (const Point& u) const { return Point(x + u.x, y + u.y); }
    int operator * (const Point& u) const { return x * u.x + y * u.y; }
    int operator ^ (const Point& u) const { return x * u.y - y * u.x; }
};

int N;
Point P[maxn];

bool judge () {
    if (N != 4) return false;
    vector<int> g;
    g.clear();

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int x = P[i].x - P[j].x;
            int y = P[i].y - P[j].y;
            g.push_back(x * x + y * y);
        }
    }
    sort(g.begin(), g.end());
    for (int i = 1; i < 4; i++)
        if (g[i] != g[0]) return false;
    return g[4] == g[5];
}

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) P[i].read();
        printf("%s\n", judge() ? "YES" : "NO");
    }
    return 0;
}