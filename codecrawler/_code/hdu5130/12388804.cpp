#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

const double eps = 1e-8;
const double pi = acos(-1.0);

int dcmp(double x)
{
    if(x > eps) return 1;
    return x < -eps ? -1 : 0;
}

struct Point
{
    double x, y;
    Point(){x = y = 0;}
    Point(double a, double b)
    {x = a, y = b;}
    inline void read() 
    {scanf("%lf%lf", &x, &y);}
    inline Point operator-(const Point &b)const
    {return Point(x - b.x, y - b.y);}
    inline Point operator+(const Point &b)const
    {return Point(x + b.x, y + b.y);}
    inline Point operator*(const double &b)const
    {return Point(x * b, y * b);}
    inline double dot(const Point &b)const
    {return x * b.x + y * b.y;}
    inline double cross(const Point &b, const Point &c)const
    {return (b.x - x) * (c.y - y) - (c.x - x) * (b.y - y);}
    inline double Dis(const Point &b)const
    {return sqrt((*this - b).dot(*this - b));}
    inline bool InLine(const Point &b, const Point &c)const//Èýµã¹²Ïß
    {return !dcmp(cross(b, c));}
    inline bool OnSeg(const Point &b, const Point &c)const//µãÔÚÏß¶ÎÉÏ£¬°üÀ¨¶Ëµã
    {return InLine(b, c) && (*this - c).dot(*this - b) < eps;}
};

inline double min(double a, double b)
{return a < b ? a : b;}
inline double max(double a, double b)
{return a > b ? a : b;}
inline double Sqr(double x)
{return x * x;}
inline double Sqr(const Point &p)
{return p.dot(p);}

Point LineCross(const Point &a, const Point &b, const Point &c, const Point &d)
{
    double u = a.cross(b, c), v = b.cross(a, d);
    return Point((c.x * v + d.x * u) / (u + v), (c.y * v + d.y * u) / (u + v));
}

double LineCrossCircle(const Point &a, const Point &b, const Point &r, 
            double R, Point &p1, Point &p2)
{
    Point fp = LineCross(r, Point(r.x + a.y - b.y, r.y + b.x - a.x), a, b);
    double rtol = r.Dis(fp);
    double rtos = fp.OnSeg(a, b) ? rtol : min(r.Dis(a), r.Dis(b));
    double atob = a.Dis(b);
    double fptoe = sqrt(R * R - rtol * rtol) / atob;
    if(rtos > R - eps) return rtos;
    p1 = fp + (a - b) * fptoe;
    p2 = fp + (b - a) * fptoe;
    return rtos;
}

double SectorArea(const Point &r, const Point &a, const Point &b, double R)
//²»´óÓÚ180¶ÈÉÈÐÎÃæ»ý£¬r->a->bÄæÊ±Õë
{
    double A2 = Sqr(r - a), B2 = Sqr(r - b), C2 = Sqr(a - b);
    return R * R * acos((A2 + B2 - C2) * 0.5 / sqrt(A2) / sqrt(B2)) * 0.5;
}

double TACIA(const Point &r, const Point &a, const Point &b, double R)
//TriangleAndCircleIntersectArea£¬ÄæÊ±Õë£¬rÎªÔ²ÐÄ
{
    double adis = r.Dis(a), bdis = r.Dis(b);
    if(adis < R + eps && bdis < R + eps) return r.cross(a, b) * 0.5;
    Point ta, tb;
    if(r.InLine(a, b)) return 0.0;
    double rtos = LineCrossCircle(a, b, r, R, ta, tb);
    if(rtos > R - eps) return SectorArea(r, a, b, R);
    if(adis < R + eps) return r.cross(a, tb) * 0.5 + SectorArea(r, tb, b, R);
    if(bdis < R + eps) return r.cross(ta, b) * 0.5 + SectorArea(r, a, ta, R);
    return r.cross(ta, tb) * 0.5 + 
        SectorArea(r, a, ta, R) + SectorArea(r, tb, b, R);
}

const int N = 505;

Point p[N];

double SPICA(int n, Point r, double R)//SimplePolygonIntersectCircleArea
{
    int i;
    double res = 0, if_clock_t;
    for(i = 0; i < n; ++ i)
    {
        if_clock_t = dcmp(r.cross(p[i], p[(i + 1) % n]));
        if(if_clock_t < 0) res -= TACIA(r, p[(i + 1) % n], p[i], R);
        else res += TACIA(r, p[i], p[(i + 1) % n], R);
    }
    return fabs(res);
}

int n;
double xa, ya, xb, yb, k;

int main() {
    int cas = 0;
    while (~scanf("%d%lf", &n, &k)) {
        for (int i = 0; i < n; i++) p[i].read();
        scanf("%lf%lf%lf%lf", &xa, &ya, &xb, &yb);
        Point o = Point(-(xb - k * k * xa) / (k * k - 1), -(yb - k * k * ya) / (k * k - 1));
        double r = (xb * xb + yb * yb - k * k * xa * xa - k * k * ya * ya) / (k * k - 1);
        r += (o.x * o.x + o.y * o.y);
        r = sqrt(r);
        printf("Case %d: %.10lf\n", ++cas, SPICA(n, o, r));
    }
    return 0;
}