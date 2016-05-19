#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <math.h>

using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);

struct Point
{
    double x,y;
};

struct Line
{
    Point a,b;
};

double dist(Point A,Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

double cross(Point A,Point B,Point C)
{
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}

double distToLine(Point p,Line s)
{
    Point t = p;
    t.x += s.a.y - s.b.y;
    t.y += s.b.x - s.a.x;
    if(cross(s.a,t,p)*cross(s.b,t,p) > eps)
        return dist(p,s.a) < dist(p,s.b) ? dist(p,s.a) : dist(p,s.b);
    return fabs(cross(p,s.a,s.b))/dist(s.a,s.b);
}

Point O,cir,A,B;
Line s[4];
Point p[4];
double r;

void Import()
{
    cin>>cir.x>>cir.y>>r;
    cin>>A.x>>A.y>>B.x>>B.y;
    if(A.y < B.y) swap(A,B);
    p[0].x = A.x;
    p[0].y = B.y;
    p[1].x = B.x;
    p[1].y = B.y;
    p[2].x = B.x;
    p[2].y = A.y;
    p[3].x = A.x;
    p[3].y = A.y;
    s[0].a = p[0];
    s[0].b = p[1];
    s[1].a = p[1];
    s[1].b = p[2];
    s[2].a = p[2];
    s[2].b = p[3];
    s[3].a = p[3];
    s[3].b = p[0];
}

double equ(double alpha)
{
    Point tmp;
    tmp.x = cir.x + r*cos(alpha);
    tmp.y = cir.y + r*sin(alpha);
    double d1 = dist(O,tmp);
    double ans = 99999999;
    for(int i=0;i<4;i++)
       ans = min(ans,distToLine(tmp,s[i]));
    return d1+ans;
}

double ternarySearch(double l,double r)
{
    while(r-l>eps)
    {
        double ll=(2*l+r)/3;
        double rr=(l+2*r)/3;
        double ans1=equ(ll);
        double ans2=equ(rr);
        if(ans1 > ans2)
            l=ll;
        else
            r=rr;
    }
    return l;
}

void Work()
{
    Import();
    cout<<fixed<<setprecision(2)<<equ(ternarySearch(0,2*PI))<<endl;
}

int main()
{
    while(true)
    {
        cin>>O.x>>O.y;
        if(fabs(O.x)<eps && fabs(O.y)<eps) break;
        Work();
    }
    return 0;
}