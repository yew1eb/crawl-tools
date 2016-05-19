#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;
const double eps = 1e-8;

//ä¸ç»´ç©ºé´ç¹
struct Point
{
    double x, y, z;
    Point(double x=0,double y=0,double z=0): x(x),y(y),z(z){}
    Point(const Point& a)
    {
        x = a.x;
        y = a.y;
        z = a.z;
        return;
    }
    void Print()
    {
        printf("%lf %lf %lf\n", x, y, z);
    }

    Point operator + (Point &t)
    {
        return Point(x+t.x, y+t.y, z+t.z);
    }
};

//ç©ºé´ç´çº¿
struct Line
{
    Point a,b;
};

//ç©ºé´å¹³é¢
struct Plane
{
    Point a,b,c;

    Plane(){}
    Plane(Point a, Point b, Point c):a(a),b(b),c(c){}

    void showPlane()
    {
        a.Print();
        b.Print();
        c.Print();
        return;
    }
};

double dcmp(double t)
{
    if(fabs(t) < eps) return 0;
    return t < 0 ? -1 : 1;
}

//ä¸ç»´åç§¯
Point cross(Point u,Point v)
{
    Point ret;
    ret.x = u.y * v.z - v.y * u.z;
    ret.y = u.z * v.x - u.x * v.z;
    ret.z = u.x * v.y - u.y * v.x;
    return ret;
}

//ä¸ç»´ç¹ç§¯
double multi(Point u,Point v)
{
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

//ç¢éå·®
Point sub(Point u,Point v)
{
    Point ret;
    ret.x = u.x - v.x;
    ret.y = u.y - v.y;
    ret.z = u.z - v.z;
    return ret;
}

//ä¸¤ç¹è·ç¦»
double dist(Point p1, Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) + (p1.z-p2.z)*(p1.z-p2.z));
}

//åéçæ¨¡
double VectorLength(Point p)
{
    return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}

//ç©ºé´ç´çº¿è·ç¦»
double LineToLine(Line u,Line v,Point &tmp )
{
    tmp = cross(sub(u.a,u.b),sub(v.a,v.b));
    return fabs(multi(sub(u.a,v.a),tmp))/VectorLength(tmp);
}

//åå¹³é¢æ³åé
Point normalVector(Plane s)
{
    return cross(sub(s.a,s.b),sub(s.b,s.c));
}

//ç©ºé´å¹³é¢ä¸ç´çº¿çäº¤ç¹
Point Intersection(Line l,Plane s)
{
    Point ret = normalVector(s);
    double t = (ret.x*(s.a.x-l.a.x)+ret.y*(s.a.y-l.a.y)+ret.z*(s.a.z-l.a.z))/(ret.x*(l.b.x-l.a.x)+ret.y*(l.b.y-l.a.y)+ret.z*(l.b.z-l.a.z));
    ret.x = l.a.x + ( l.b.x - l.a.x ) * t;
    ret.y = l.a.y + ( l.b.y - l.a.y ) * t;
    ret.z = l.a.z + ( l.b.z - l.a.z ) * t;
    return ret;
}

/************ä»¥ä¸ä¸ºæ¨¡æ¿*************/

void work(Line A, Line B)
{
    Point normal;
    double d = LineToLine( A, B, normal );
    printf("%.6lf\n",d);
    Plane alpha = Plane(A.a, A.b, A.a + normal);
    Plane beta  = Plane(B.a, B.b, B.a + normal);
    Point u = Intersection(B,alpha);
    Point v = Intersection(A,beta);
    printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", v.x, v.y, v.z, u.x, u.y, u.z );
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Line A,B;
        scanf("%lf%lf%lf", &A.a.x, &A.a.y, &A.a.z);
        scanf("%lf%lf%lf", &A.b.x, &A.b.y, &A.b.z);
        scanf("%lf%lf%lf", &B.a.x, &B.a.y, &B.a.z);
        scanf("%lf%lf%lf", &B.b.x, &B.b.y, &B.b.z);
        work(A,B);
    }
    return 0;
}