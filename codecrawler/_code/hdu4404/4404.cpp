#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
#define FF(i, a, b) for(int i=a; i<b; i++)
#define FD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0; i<n; i++)
#define CLR(a, b) memset(a, b, sizeof(a))
#define LL long long
#define PB push_back
#define eps 1e-10
#define debug puts("**debug**")
using namespace std;


const int maxn = 110;
const double PI = acos(-1);
const double TWO_PI = PI * 2;


double NormalizeAngle(double rad, double center = PI)
{
  return rad - TWO_PI * floor((rad + PI - center) / TWO_PI);
}


struct Point
{
    double x, y;
    Point (double x=0, double y=0):x(x), y(y) {}
};
typedef Point Vector;
struct Circle
{
   Point c;
   double r;
   Circle() {}
   Circle(Point c, double r) : c(c), r(r) {}
   Point point(double a) { return Point(c.x+cos(a)*r, c.y+sin(a)*r); }
};
struct Line
{
    Point p;
    Vector v;
    double ang;
    Line(){}
    Line(Point p, Vector v) : p(p), v(v) {ang = atan2(v.y, v.x); }
    Point point(double t)
    {
        return Point(p.x + t*v.x, p.y + t*v.y);
    }
    bool operator < (const Line& L) const
    {
        return ang < L.ang;
    }
};


template <class T> T sqr(T x) { return x * x;}
Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (Vector A, double p) { return Vector(A.x/p, A.y/p); }
bool operator < (const Point& a, const Point& b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
int dcmp(double x)
{
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}
bool operator == (const Point& a, const Point& b){ return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;}


double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angel(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }
double torad(double d) { return (d/180)*PI; }
Vector vecunit(Vector x){ return x / Length(x);} //单位向量
Vector normal(Vector x) { return Point(-x.y, x.x) / Length(x);} //垂直法向量
Point GetIntersection(Line a, Line b) //线段交点
{
    Vector u = a.p-b.p;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.p + a.v*t;
}
bool OnSegment(Point p, Point a1, Point a2)
{
    return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}


bool InCircle(Point x, Circle c) { return dcmp(sqr(c.r) - sqr(Length(c.c - x))) >= 0;}
bool OnCircle(Point x, Circle c) { return dcmp(sqr(c.r) - sqr(Length(c.c - x))) == 0;}
double angle(Vector x) { return atan2(x.y, x.x);}


//直线与圆交点
int getLineCircleIntersection(Line L, Circle C, double& t1, double& t2, vector<Point>& sol)
{
    double a=L.v.x, b=L.p.x-C.c.x, c=L.v.y, d=L.p.y-C.c.y;
    double e=a*a+c*c, f=2*(a*b+c*d), g=b*b+d*d-C.r*C.r;
    double delta=f*f-4*e*g;
    if(dcmp(delta) < 0) return 0;
    if(dcmp(delta) == 0)
    {
        t1 = t2 = -f/(2*e); sol.PB(L.point(t1));
        return 1;
    }
    t1 = (-f-sqrt(delta))/(2*e); sol.PB(L.point(t1));
    t2 = (-f+sqrt(delta))/(2*e); sol.PB(L.point(t2));
    return 2;
}


//线段与圆的焦点
int getSegCircleIntersection(Line L, Circle C, Point* sol)
{
    Vector nor = normal(L.v);
    Line pl = Line(C.c, nor);
    Point ip = GetIntersection(pl, L);
    double dis = Length(ip - C.c);
    if (dcmp(dis - C.r) > 0) return 0;
    Point dxy = vecunit(L.v) * sqrt(sqr(C.r) - sqr(dis));
    int ret = 0;
    sol[ret] = ip + dxy;
    if (OnSegment(sol[ret], L.p, L.point(1))) ret++;
    sol[ret] = ip - dxy;
    if (OnSegment(sol[ret], L.p, L.point(1))) ret++;
    return ret;
}


double SegCircleArea(Circle C, Point a, Point b) //线段切割圆
{
    double a1 = angle(a - C.c);
    double a2 = angle(b - C.c);
    double da = fabs(a1 - a2);
    if (da > PI) da = PI * 2.0 - da;
    return dcmp(Cross(b - C.c, a - C.c)) * da * sqr(C.r) / 2.0;
}


double PolyCiclrArea(Circle C, Point *p, int n)//多边形与圆相交面积
{
    double ret = 0.0;
    Point sol[2];
    p[n] = p[0];
    REP(i, n)
    {
        double t1, t2;
        int cnt = getSegCircleIntersection(Line(p[i], p[i+1]-p[i]), C, sol);
        if (cnt == 0)
        {
            if (!InCircle(p[i], C) || !InCircle(p[i+1], C)) ret += SegCircleArea(C, p[i], p[i+1]);
            else ret += Cross(p[i+1] - C.c, p[i] - C.c) / 2.0;
        }
        if (cnt == 1)
        {
            if (InCircle(p[i], C) && !InCircle(p[i+1], C)) ret += Cross(sol[0] - C.c, p[i] - C.c) / 2.0, ret += SegCircleArea(C, sol[0], p[i+1]);
            else ret += SegCircleArea(C, p[i], sol[0]), ret += Cross(p[i+1] - C.c, sol[0] - C.c) / 2.0;
        }
        if (cnt == 2)
        {
            if ((p[i] < p[i + 1]) ^ (sol[0] < sol[1])) swap(sol[0], sol[1]);
            ret += SegCircleArea(C, p[i], sol[0]);
            ret += Cross(sol[1] - C.c, sol[0] - C.c) / 2.0;
            ret += SegCircleArea(C, sol[1], p[i+1]);
        }
    }
    return fabs(ret);
}


int n;
double x, y, v, ang, t, g, r;
Circle C;
Point p[maxn];


int main()
{
    while (scanf("%lf%lf%lf%lf%lf%lf%lf", &x, &y, &v, &ang, &t, &g, &r))
    {
      if(x == 0 && y == 0 && v == 0 && ang == 0 && t == 0 &&  g == 0 && r == 0) break;
      ang = torad(ang);
      C = Circle(Point(x + v*cos(ang)*t, y + v*sin(ang)*t - 0.5*g*t*t), r);


      scanf("%d", &n);
      REP(i, n) scanf("%lf%lf", &p[i].x, &p[i].y);
      printf("%.2f\n", PolyCiclrArea(C, p, n));
    }
    return 0;
}
