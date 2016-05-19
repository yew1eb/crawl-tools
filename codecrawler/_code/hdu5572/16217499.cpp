#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const double eps = 1e-8;
const double inf = 1e20;

inline int dcmp(double x) { if (fabs(x) < eps) return 0; return x < 0 ? -1 : 1; }

struct Point {
    double x, y;
    Point (double x = 0, double y = 0): x(x), y(y) {}

    void read() { scanf("%lf%lf", &x, &y); }
    Point operator + (const Point& u) const { return Point(x + u.x, y + u.y); }
    Point operator - (const Point& u) const { return Point(x - u.x, y - u.y); }
    Point operator * (const double& k) const { return Point(x * k, y * k); }
};

typedef Point Vector;

double getCross (Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
double getDot (Vector a, Vector b) { return a.x * b.x + a.y + b.y; }
double getLength(Vector a) { return sqrt(getDot(a, a)); }
Vector getNormal (Vector a) { return Vector(-a.y, a.x); }

struct Circle {
    Point o;
    double r;
    void read() { scanf("%lf%lf%lf", &o.x, &o.y, &r); }
};

int getLineCircleIntersection (Point p, Vector v, Circle O, double& t1, double& t2) {
    double a = v.x, b = p.x - O.o.x, c = v.y, d = p.y - O.o.y;
    double e = a*a+c*c, f = 2*(a*b+c*d), g = b*b+d*d-O.r*O.r;
    double delta = f*f - 4*e*g;
    if (dcmp(delta) < 0) return 0;
    if (dcmp(delta) == 0) {
        t1 = t2 = -f / (2 * e);
        return 1;
    }

    t1 = (-f - sqrt(delta)) / (2 * e);
    t2 = (-f + sqrt(delta)) / (2 * e);
    return 2;
}

bool getIntersection (Point p, Vector v, Point q, Vector w, Point& o) {
    if (dcmp(getCross(v, w)) == 0) return false;
    Vector u = p - q;
    double k = getCross(w, u) / getCross(v, w);
    o = p + v * k;
    return true;
}

Point A, B;
Vector V;
Circle C;

bool onLine (Point a, Vector v, Point b) { return dcmp(getCross(v, b - a)) == 0; }
double getPos(Vector v, Vector t) {
    if (dcmp(v.x) == 0) return t.y / v.y;
    return t.x / v.x;
}

bool judge () {
    double t1, t2, hint = inf;
    int k = getLineCircleIntersection(A, V, C, t1, t2);
    if (k > 1 && dcmp(t1) >= 0) hint = t1;
    else if (k > 1 && dcmp(t2) >= 0) hint = t2;

    if (onLine(A, V, B)) {
        double t = getPos(V, B - A);
        if (dcmp(t) >= 0 && t < hint) return true;
    }

    if (dcmp(hint - inf) < 0) {
        Point I = A + V * hint, T;
        Vector H = getNormal(C.o - I);
        getIntersection(I, H, B, C.o - I, T);
        B = T * 2 - B;

        if (onLine(A, V, B)) {
            double t = getPos(V, B - A);
            if (dcmp(t) >= 0) return true;
        }
    }
    return false;
}

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        C.read(), A.read(), V.read(), B.read();
        printf("Case #%d: %s\n", kcas, judge() ? "Yes" : "No");
    }
    return 0;
}