/**************************************************
 *        Problem:  HDU 4773
 *         Author:  clavichord93
 *          State:  Accepted
 **************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#define sqr(a) ((a) * (a))
using namespace std;
const double EPS = 1e-8;
const double PI = acos(-1.0);

const double INVERSION_CONST = 10000.0;

inline int sgn(double a) {
    return a > EPS ? 1 : (a < -EPS ? -1 : 0);
}

struct Point {
    double x, y;
    Point() { x = y = 0; }
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point operator + (const Point &a) const {
        return Point(x + a.x, y + a.y);
    }
    Point operator - (const Point &a) const {
        return Point(x - a.x, y - a.y);
    }
    Point operator * (const double &k) const {
        return Point(x * k, y * k);
    }
    Point operator / (const double &k) const {
        return Point(x / k, y / k);
    }
    Point& operator = (const Point &a) {
        x = a.x, y = a.y;
        return *this;
    }
    bool operator < (const Point &a) const {
        return sgn(x - a.x) < 0 || (!sgn(x - a.x) && sgn(y - a.y) < 0);
    }
    bool operator == (const Point &a) const{
        return !sgn(x - a.x) && !sgn(y - a.y);
    }
    bool operator != (const Point &a) const {
        return sgn(x - a.x) || sgn(y - a.y);
    }
    //æ³åéï¼å·¦ææ¹å
    Point normal() const {
        return Point(-y, x);
    }
    void read() {
        scanf("%lf %lf", &x, &y);
    }
    void print() {
        printf("%.6f %.6f\n", x, y);
    }
};
typedef Point Vector;

struct Line {
    Point p; Vector v;
    Line() {}
    Line(Point _p, Vector _v) : p(_p), v(_v) {}
    //normalæ³åéï¼è¿åæåæ¹ååéå·¦æä¾§
    Vector normal() const {
        return Vector(-v.y, v.x);
    }
    void print() {
        printf("(%.10f, %.10f) + t * (%.10f, %.10f)\n", p.x, p.y, v.x, v.y);
    }
};

inline double dot(const Vector &a, const Vector &b) {
    return a.x * b.x + a.y * b.y;
}
inline double det(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
}

inline double dist(const Point &a, const Point &b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

inline double length(const Vector &v) {
    return sqrt(dot(v, v));
}

inline bool sameSidePL(const Point &a, const Point &b, const Line &l) {
    return sgn(det(l.p - a, l.v) * det(l.p - b, l.v)) > 0;
}

inline bool pointOnLine(const Point &a, const Line &l) {
    return !sgn(det(a - l.p, l.v));
}

inline Point intersectLL(const Line &la, const Line &lb) {
    double t = det(lb.v, la.p - lb.p) / det(la.v, lb.v);
    return la.p + la.v * t;
}

inline Point outerCenter(const Point &a, const Point &b, const Point &c) {
    Line la = Line((a + b) / 2.0, (b - a).normal());
    Line lb = Line((a + c) / 2.0, (c - a).normal());
    return intersectLL(la, lb);
}

struct Circle {
    double x, y, r;
    Circle() {
        x = y = r = 0;
    }
    Circle(double _x, double _y, double _r) : x(_x), y(_y), r(_r) {}
    bool operator == (const Circle &c) {
        return !sgn(x - c.x) && !sgn(y - c.y) && !sgn(r - c.r);
    }
    bool operator != (const Circle &c) {
        return sgn(x - c.x) || sgn(y - c.y) || sgn(r - c.r);
    }
    Point getPoint(double ang) const {
        return Point(x + r * cos(ang), y + r * sin(ang));
    }
    // ä»aå°bç»éæ¶éæ¹åçå¼§é¿
    //double arcLength(const Point &a, const Point &b) const {
        //Point c = Point(x, y);
        //Vector v1 = a - c, v2 = b - c;
        //double ang = angle(v1, v2);
        //if (sgn(det(v1, v2)) < 0) ang = TAU - ang;
        //return ang * r;
    //}
    Point center() const {
        return Point(x, y);
    }
    void read() {
        scanf("%lf %lf %lf", &x, &y, &r);
    }
    void print() {
        printf("%.10f %.10f %.10f\n", x, y, r);
    }
    bool operator < (const Circle &a) const {
        return sgn(y - a.y) < 0;
    }
};

// ç¹å°åçåç¹
inline pair<Point, Point> tangentPointCP(const Circle &c, const Point &p) {
    double ang = atan2(p.y - c.y, p.x - c.x);
    double alpha = acos(c.r / dist(Point(c.x, c.y), p));
    return make_pair(c.getPoint(ang + alpha), c.getPoint(ang - alpha));
}

// æ±ä¸¤åçå¤å¬åç¹ï¼ret[0],ret[1]å±äºåaï¼ret[2],ret[3]å±äºåb
inline vector<Point> outerTangentPoint(const Circle &a, const Circle &b) {
    vector<Point> ret;
    Vector v = Vector(b.x - a.x, b.y - a.y);
    double ang = atan2(v.y, v.x);
    double alpha = acos((a.r - b.r) / length(v));
    ret.push_back(a.getPoint(ang + alpha));
    ret.push_back(a.getPoint(ang - alpha));
    ret.push_back(b.getPoint(ang + alpha));
    ret.push_back(b.getPoint(ang - alpha));
    return ret;
}

// æ±ä¸¤åçå¤å¬åçº¿
inline pair<Line, Line> outerTangentLine(Circle a, Circle b) {
    vector<Point> t = outerTangentPoint(a, b);
    return make_pair(Line(t[0], t[2] - t[0]), Line(t[1], t[3] - t[1]));
}

inline Point inversionPP(const Point &p1, const Point &p) {
    Vector v = p1 - p;
    double len = length(v);
    double k = INVERSION_CONST / len;
    v = v / len * k;
    return v + p;
}

inline Circle inversionCC(const Circle &c, const Point &p) {
    Point p0 = c.getPoint(0);
    Point p1 = c.getPoint(0.5 * PI);
    Point p2 = c.getPoint(PI);
    p0 = inversionPP(p0, p);
    p1 = inversionPP(p1, p);
    p2 = inversionPP(p2, p);
    Point ct = outerCenter(p0, p1, p2);
    double radius = dist(ct, p0);
    return Circle(ct.x, ct.y, radius);
}

inline Circle inversionLC(const Line &l, const Point &p) {
    Point p1 = l.p;
    Point p2 = l.p + l.v;
    p1 = inversionPP(p1, p);
    p2 = inversionPP(p2, p);
    Point ct = outerCenter(p, p1, p2);
    double radius = dist(ct, p);
    return Circle(ct.x, ct.y, radius);
}

int main() {
    #ifdef LOCAL_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        Circle c1, c2;
        Point p;
        c1.read();
        c2.read();
        p.read();
        Circle c3 = inversionCC(c1, p);
        Circle c4 = inversionCC(c2, p);
        pair<Line, Line> t = outerTangentLine(c3, c4);
        vector<Circle> ans;
        if (!pointOnLine(p, t.first) && sameSidePL(p, c3.center(), t.first)) {
            ans.push_back(inversionLC(t.first, p));
        }
        if (!pointOnLine(p, t.second) && sameSidePL(p, c3.center(), t.second)) {
            ans.push_back(inversionLC(t.second, p));
        }
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < (int)ans.size(); i++) {
            ans[i].print();
        }
    }

    return 0;
}
