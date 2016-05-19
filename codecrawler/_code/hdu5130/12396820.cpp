#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 600;
inline double sqr(double x)
{
    return x*x;
}
const double eps = 1e-8;
int sgn(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y):x(_x),y(_y) {}
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
    Point  operator -(const Point &b)const
    {
        return Point(x-b.x, y-b.y);
    }
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    double len()
    {
        return hypot(x, y);
    }
    double len2()
    {
        return x*x + y*y;
    }
    double distance(Point p)
    {
        return hypot(x-p.x, y-p.y);
    }
    Point operator +(const Point &b)const
    {
        return Point(x+b.x, y+b.y);
    }
    Point operator *(const double &k)const
    {
        return Point(x*k, y*k);
    }
    Point operator /(const double &k)const
    {
        return Point(x/k, y/k);
    }
    double rad(Point a, Point b)
    {
        Point p = *this;
        return fabs(atan2( fabs((a-p)^(b-p)), (a-p)*(b-p) ));
    }
    Point trunc(double r)
    {
        double l = len();
        if(!sgn(l)) return *this;
        r /= l;
        return Point(x*r, y*r);
    }
};
struct Line {
    Point s, e;
    Line() {}
    Line(Point _s, Point _e):s(_s),e(_e) {}
    double length()
    {
        return s.distance(e);
    }
    double dispointtoline(Point p)
    {
        return fabs((p-s)^(e-s))/length();
    }
    Point lineprog(Point p)
    {
        return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
    }
};

struct Circle {
    Point p;
    double r;
    Circle() {}
    void output()
    {
        printf("(%.4f,%.4f), r= %.4f\n", p.x, p.y, r);
    }
    int relation(Point b)
    {
        double dst = b.distance(p);
        if(sgn(dst-r)<0) return 2;
        else if(sgn(dst-r)==0) return 1;
        return 0;
    }
    int relationline(Line v)
    {
        double dst = v.dispointtoline(p);
        if(sgn(dst-r) < 0) return 2;
        else if(sgn(dst-r)==0) return 1;
        return 0;
    }
    int pointcrossline(Line v, Point &p1, Point &p2)
    {
        if(!(*this).relationline(v)) return 0;
        Point a = v.lineprog(p);
        double d = v.dispointtoline(p);
        d = sqrt(r*r-d*d);
        if(sgn(d)==0) {
            p1 = a;
            p2 = a;
            return 1;
        }
        p1 = a + (v.e-v.s).trunc(d);
        p2 = a - (v.e-v.s).trunc(d);
        return 2;
    }
    double areatriangle(Point a, Point b)
    {
        if(sgn((p-a)^(p-b)) == 0) return 0.0;
        Point q[5];
        int len = 0;
        q[len++] = a;
        Line l(a,b);
        Point p1, p2;
        if(pointcrossline(l, q[1], q[2])==2) {
            if(sgn((a-q[1])*(b-q[1]))<0) q[len++] = q[1];
            if(sgn((a-q[2])*(b-q[2]))<0) q[len++] = q[2];
        }
        q[len++] = b;
        if(len == 4 && sgn((q[0]-q[1])*(q[2]-q[1]))>0) swap(q[1], q[2]);
        double res = 0;
        for(int i=0; i<len-1; i++) {
            if(relation(q[i])==0 || relation(q[i+1])==0) {
                double arg = p.rad(q[i], q[i+1]);
                res += r*r*arg/2.0;
            } else {
                res += fabs((q[i]-p)^(q[i+1]-p))/2.0;
            }
        }
        return res;
    }

};

Circle cao;
Point pt[maxn];
int n;
Point A, B;
double K;
double areacircle(Circle c)
{
    double ans = 0;
    for(int i=0; i<n; ++i) {
        int j = (i+1) % n;
        if(sgn( (pt[j]-c.p)^(pt[i] - c.p) ) >= 0)
            ans += c.areatriangle(pt[i], pt[j]);
        else ans -= c.areatriangle(pt[i], pt[j]);
    }
    return fabs(ans);
}

void getcircle(double xa, double ya, double xb, double yb, double k)
{
        Point o = Point(-(xb - k * k * xa) / (k * k - 1), -(yb - k * k * ya) / (k * k - 1));
        double r = (xb * xb + yb * yb - k * k * xa * xa - k * k * ya * ya) / (k * k - 1);
        r += (o.x * o.x + o.y * o.y);
        r = sqrt(r);
        cao.p = o;
        cao.r = r;
    //cao.output();
}
int main()
{
    int ca = 1;
    while(~scanf("%d%lf", &n, &K)) {
        for(int i=0; i<n; ++i) pt[i].input();
        A.input();
        B.input();
        getcircle(A.x, A.y, B.x, B.y, K);
        double ans = areacircle(cao);
        printf("Case %d: %.12f\n", ca++, ans);
    }
    return 0;
}
