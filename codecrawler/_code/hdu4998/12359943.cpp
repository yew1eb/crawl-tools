#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define eps 1.0e-9
using namespace std;
const double pi=acos(-1.0);
int n;
struct point
{
    double x,y,r;
    point(double _x=0,double _y=0) {x=_x;y=_y;}
}p[15];
int sgn(double f)
{
    if(fabs(f)<eps) return 0;
    return f>0?1:-1;
}
typedef point Vector;
Vector operator + (Vector a, Vector b) {return Vector(a.x+b.x, a.y+b.y);}
Vector operator - (Vector a, Vector b) {return Vector(a.x-b.x, a.y-b.y);}
Vector operator * (Vector a, double p) {return Vector(a.x*p, a.y*p);}
Vector operator / (Vector a, double p) {return Vector(a.x/p, a.y/p);}
bool operator == (point a,point b) {return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
double dmult(Vector a,Vector b) {return a.x*b.x+a.y*b.y;}
double xmult(Vector a,Vector b) {return a.x*b.y-a.y*b.x;}
double xmult(point a,point b,point o) {return xmult(o-a,o-b);}
Vector xmult(Vector a) {return Vector(a.y,-a.x);}
double dis(Vector a) {return sqrt(dmult(a,a));}
double dis(point a,point b) {return dis(b-a);}
double angle(Vector v) {return atan2(v.y,v.x);}//ÏòÁ¿¼«½Ç
double intersection_angle(Vector a,Vector b) {return acos(dmult(a,b)/dis(a)/dis(b));}
double DistanceToLine(point p,point a,point b) {return fabs(xmult(b-a,p-a))/dis(b-a);}
Vector Rotate(Vector a,double rad) {return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));}
point solve(point t)
{
    Vector v;
    for(int i=0;i<n;i++)
    {
        v=t-p[i];
        v=Rotate(v,p[i].r);
        t=v+p[i];
    }
    return t;
}
int GetLineIntersection(point p,Vector v,point q,Vector w,point &ans)//1-Î¨Ò»£¬0-ÎÞ½»µã£¬2-ÎÞÇî
{
    if(sgn(xmult(v,w))==0)
    {
        if(sgn(xmult(p-q,w))==0) return 2;
        else return 0;
    }
    else ans=p+v*xmult(w,p-q)/xmult(v,w);
    return 1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].r);
        point a,b;
        a=point(101,0);
        b=point(0,101);
        point ra,rb;
        ra=solve(a);
        rb=solve(b);
        point ma=(ra+a)/2;
        point mb=(rb+b)/2;
        Vector va,vb;
        va=xmult(ra-a);
        vb=xmult(rb-b);
        point ans;
        GetLineIntersection(ma,va,mb,vb,ans);
        ans.r=acos(dmult(a-ans,ra-ans)/dis(a-ans)/dis(ra-ans));
        if(sgn(xmult(a-ans,ra-ans))<0) ans.r=2*pi-ans.r;
        printf("%.10f %.10f %.10f\n",ans.x,ans.y,ans.r);
    }
    return 0;
}