#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define eps 1e-6
int sgn(double x){
    if(fabs(x) <= eps) return 0;
    return x > 0 ? 1 : -1;
}
struct Point{
    double x,y;
    Point(){}
    Point(const double  &x,const double  &y):x(x),y(y){}
    double sqrlen()
    {
        return x*x+y*y;
    }
    double len()
    {
        return sqrt(sqrlen());
    }
    void print()
    {
        printf("%.6lf %.6lf\n",x,y);
    }
};
Point operator +(Point a,Point b)
{
    return Point(a.x+b.x,a.y+b.y);
}
Point operator -(Point a,Point b)
{
    return Point(a.x-b.x,a.y-b.y);
}
struct Circle{
    Point o;
    double r;
    Circle(){}
    Circle(const Point &o,const double &r):o(o),r(r){}
};
bool zero(double x)
{
    if(fabs(x)<=eps)return true;
    return false;
}
bool operator == (Circle a,Circle b)
{
    Point c=a.o-b.o;
    if(zero(c.x)&&zero(c.y)&&zero(a.r-b.r))return true;
    return false;
}


void c2point(Circle c1,Circle c2,Point &rp1,Point &rp2){
    if(c1 == c2){
        rp1 = c1.o + Point(0,c1.r);
        rp2 = c1.o - Point(0,c1.r);
        return;
    }
    Point p1 = c1.o , p2 = c2.o;
    double r1 = c1.r , r2 = c2.r;
    double a = p2.x - p1.x , b = p2.y - p1.y , r = (a*a + b*b + r1*r1 - r2*r2) / 2;
    double tmp;
    if(a == 0 && b != 0){
        rp1.y = rp2.y = r / b;
        tmp = r1 * r1 - rp1.y * rp1.y;
        if(sgn(tmp)<=0) tmp = 0;
        rp1.x = sqrt(tmp);
        rp2.x = -rp1.x;
    }
    else if(a != 0 && b == 0){
        rp1.x = rp2.x = r / a;
        tmp = r1 * r1 - rp1.x * rp1.x;
        if(sgn(tmp)<=0) tmp = 0;
        rp1.y = sqrt(tmp);
        rp2.y = -rp1.y;
    }
    else if(a != 0 && b != 0){
        double delta = b*b*r*r - (a*a + b*b) * (r*r - r1*r1*a*a);
        if(sgn(delta)<=0) delta = 0;
        rp1.y = (b*r + sqrt(delta)) / (a*a + b*b);
        rp2.y = (b*r - sqrt(delta)) / (a*a + b*b);
        rp1.x = (r - b*rp1.y) / a;
        rp2.x = (r - b*rp2.y) / a;
    }
    rp1.x += p1.x , rp1.y += p1.y;
    rp1.x += p1.x , rp2.y += p1.y;
}
Point A,B,C,D,_A;
double AB , BC , CD , DA , EF;
int main()
{
//    freopen("1008.in","r",stdin);
//    freopen("myout.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        scanf("%lf%lf%lf%lf%lf",&AB,&BC,&CD,&DA,&EF);
        B=Point(BC,0);
        C=Point(0,0);
        Point nouse;
        Circle BO,CO;
        BO=Circle(B,2*EF);
        CO=Circle(C,DA);
        c2point(CO,BO,_A,nouse);
        Point G=_A+(B-C);
        Circle GO;
        CO=Circle(C,CD);
        GO=Circle(G,AB);
        c2point(CO,GO,D,nouse);
        A=D+(C-_A);
        printf("Case #%d:\n",cas);
        A.print();
        B.print();
        C.print();
        D.print();
    }
}
