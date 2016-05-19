#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const double eps = 1e-4;

struct Point {
    double x, y;
    Point (double x = 0, double y = 0):x(x), y(y) {}
    void read () { scanf("%lf%lf", &x, &y); }
    bool operator < (const Point& u) const { return x < u.x || (x == u.x && y < u.y); }
    Point operator - (const Point& u) { return Point(x - u.x, y - u.y); }
}P[5];

typedef Point Vector;

double getDot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double getPowLength(Vector a) { return getDot(a, a); }

bool judge () {
    sort(P, P + 5);
    do {
        bool flag = true;

        for (int i = 0; i < 5; i++) {
            int p = (i + 4) % 5, q = (i + 1) % 5;
            int a = (i + 2) % 5, b = (i + 3) % 5;
            if (fabs(getPowLength(P[i]-P[p]) - getPowLength(P[i]-P[q])) > eps) flag = false;
            if (fabs(getPowLength(P[i]-P[a]) - getPowLength(P[i]-P[b])) > eps) flag = false;
        }

        if (flag) return true;
    } while (next_permutation(P, P + 5));
    return false;
}

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        for (int i = 0; i < 5; i++) P[i].read();
        printf("%s\n", judge() ? "Yes" : "No");
    }
    return 0;
}