#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.0);
const int maxn=1100;

struct point
{
    double x,y;
    point() {}
    point(double xx,double yy):x(xx),y(yy) {}
    friend point operator - (const point &a,const point &b)
    {
        return point(a.x-b.x,a.y-b.y);
    }
    friend point operator * (const point &a,const double &b)
    {
        return point(a.x*b,a.y*b);
    }
    friend point operator / (const point &a,const double &b)
    {
        return point(a.x/b,a.y/b);
    }
} A,B,res[maxn];

double k,r;
int n,cnt;

double sqr(double x)
{
    return x*x;
}

int dcmp(double k)
{
    return k < -eps ? -1 : k > eps ? 1 : 0 ;
}

double dot(const point &a,const point &b)
{
    return a.x*b.x+a.y*b.y;
}

double cross(const point &a,const point &b)
{
    return a.x*b.y-a.y*b.x;
}

double abs(const point &o)
{
    return sqrt(dot(o,o));
}

point crosspt(const point &a,const point &b,const point &p,const point &q)
{
    double a1 = cross(b-a,p-a);
    double a2 = cross(b-a,q-a);
    return (p*a2-q*a1)/(a2-a1);
}

double mysqrt(double n)
{
    return sqrt(max(0.0,n));
}

double sector_area(const point &a,const point &b)
{
    double theta = atan2(a.y,a.x) - atan2(b.y,b.x);
    while(theta<=0)     theta+=2*PI;
    while(theta>2*PI)   theta-=2*PI;
    theta = min(theta,2*PI-theta);
    return r*r*theta/2;
}

void circle_cross_line(const point &a,const point &b,const point &o,double r,point ret[],int &num)
{
    double x0=o.x,y0=o.y;
    double x1=a.x,y1=a.y;
    double x2=b.x,y2=b.y;
    double dx=x2-x1,dy=y2-y1;
    double A=dx*dx+dy*dy;
    double B=2*dx*(x1-x0)+2*dy*(y1-y0);
    double C=sqr(x1-x0)+sqr(y1-y0)-sqr(r);
    double delta=B*B-4*A*C;
    num=0;
    if(dcmp(delta)>=0)
    {
        double t1=(-B-mysqrt(delta))/(2*A);
        double t2=(-B+mysqrt(delta))/(2*A);
        if(dcmp(t1-1)<=0 && dcmp(t1)>=0)   ret[num++]=point(x1+t1*dx,y1+t1*dy);
        if(dcmp(t2-1)<=0 && dcmp(t2)>=0)   ret[num++]=point(x1+t2*dx,y1+t2*dy);
    }
}

double calc(const point &a,const point &b)
{
    point p[2];
    int num=0;
    int ina=dcmp(abs(a)-r)<0;
    int inb=dcmp(abs(b)-r)<0;
    if(ina && inb) return fabs(cross(a,b))/2.0;
    circle_cross_line(a,b,point(0,0),r,p,num);
    if(ina)    return sector_area(b,p[0])+fabs(cross(a,p[0]))/2.0;
    if(inb)    return sector_area(p[0],a)+fabs(cross(p[0],b))/2.0;
    if(num==2) return sector_area(a,p[0])+sector_area(p[1],b)+fabs(cross(p[0],p[1]))/2.0;
    return sector_area(a,b);
}

void input()
{
    for(int i=0; i<n; i++) scanf("%lf %lf",&res[i].x,&res[i].y);
    scanf("%lf %lf",&A.x,&A.y);
    scanf("%lf %lf",&B.x,&B.y);
}

void initial()
{
    double E=(2*B.x-2*sqr(k)*A.x)/(1.0-sqr(k));
    double F=(2*B.y-2*sqr(k)*A.y)/(1.0-sqr(k));
    double G=(sqr(k*A.x)+sqr(k*A.y)-sqr(B.x)-sqr(B.y))/(1.0-sqr(k));
    double x0=E/2.0,y0=F/2.0;
    r=sqrt(G+sqr(E)/4.0+sqr(F)/4.0);
    for(int i=0; i<n; i++)
    {
        res[i].x-=x0;
        res[i].y-=y0;
    }
    res[n]=res[0];
}

double area()
{
    double ret=0;
    for(int i=0; i<n; i++)
    {
        int sgn=dcmp(cross(res[i],res[i+1]));
        if(sgn!=0)  ret+=sgn*calc(res[i],res[i+1]);
    }
    return ret;
}

int main()
{
    while(scanf("%d %lf",&n,&k)!=EOF)
    {
        input();
        initial();
        printf("Case %d: %.10lf\n",++cnt,fabs(area()));
    }
    return 0;
}
