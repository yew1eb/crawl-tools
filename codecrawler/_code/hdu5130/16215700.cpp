#include<iostream>
#include<algorithm>
#include<cassert>
#include<string>
#include<sstream>
#include<set>
#include<bitset>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<list>
#include<complex>
#include<functional>
#define INF 0x3f3f3f3f
using namespace std;

#define me(s) memset(s,0,sizeof(s))
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
typedef long long ll;
typedef pair <int,int> P;

const int N=2000+10;
const double eps=1e-10;
const double PI=acos(-1.0);
int rnd;

int dcmp(double x)
{
    if(fabs(x)<eps)return 0;
    return x<0?-1:1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    void read()
    {
        scanf("%lf%lf",&x,&y);
    }
    friend ostream&operator<< (ostream&out,Point&p)
    {
        out<<"("<<p.x<<","<<p.y<<")";
        return out;
    }
}tp[N];

typedef Point Vector;
Vector operator+(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator-(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
Vector operator*(Vector a,double p){return Vector(a.x*p,a.y*p);}
Vector operator/(Vector a,double p){return Vector(a.x/p,a.y/p);}

double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double Length(Vector a){return sqrt(Dot(a,a));}
double Area(Point a,Point b,Point c){return 0.5*Cross(b-a,c-a);}
double Angle(Vector a,Vector b){return acos(Dot(a,b)/Length(a)/Length(b));}

struct Circle
{
    Point c;
    double r;
    Circle(){}
    Circle(Point c,double r):c(c),r(r){}
    Point point(double a)
    {
        return Point(c.x+cos(a)*r,c.y+sin(a)*r);
    }
};

struct Line
{
    Point p;
    Vector v;
    double ang;
    Line(){}
    Line(Point p,Vector v):p(p),v(v){ang=atan2(v.y,v.x);}
    bool operator<(const Line&L)const
    {
        return ang<L.ang;
    }
    Point point(double t){return p+v*t;}
};

int getLineCircleIntersection(Line L,Circle C,double&t1,double&t2,vector<Point>&sol)
{
    double a=L.v.x,b=L.p.x-C.c.x,c=L.v.y,d=L.p.y-C.c.y;
    double e=a*a+c*c,f=2*(a*b+c*d),g=b*b+d*d-C.r*C.r;
    double delta=f*f-4*e*g;
    if(dcmp(delta)<0)return 0;
    if(dcmp(delta)==0)
    {
        t1=t2=-f/(2*e);
        if(dcmp(t1)>0&&dcmp(t1-1)<0)
            sol.push_back(L.point(t1));
        return 1;
    }
    t1=(-f-sqrt(delta))/(2*e);
    t2=(-f+sqrt(delta))/(2*e);
    if(t1>t2)swap(t1,t2);
    if(dcmp(t1)>0&&dcmp(t1-1)<0)sol.push_back(L.point(t1));
    if(dcmp(t2)>0&&dcmp(t2-1)<0)sol.push_back(L.point(t2));
    return (int)sol.size();
}




struct GetCirclePolyIntersection //æ±è§£ååå¤è¾¹å½¢çå¬å±åºåçé¢ç§¯
{
    Circle cir;
    double Scir;

    Point p[N];
    int tail;
    GetCirclePolyIntersection(){tail=0;}
    GetCirclePolyIntersection(Circle C):cir(C)
    {
        Scir=PI*cir.r*cir.r;
        tail=0;
    }

    void solve(Point*tp,int n)
    {
        for(int i=0;i<n;i++)
        {
            p[tail++]=tp[i];
            Line line=Line(tp[i],tp[(i+1)%n]-tp[i]);
            double t1,t2;
            vector<Point>sol;
            getLineCircleIntersection(line,cir,t1,t2,sol);
            for(int j=0;j<sol.size();j++)
                p[tail++]=sol[j];
        }
        double res=0;
        for(int i=0;i<tail;i++)
        {
            Point O=cir.c;
            double ang=Angle(p[(i+1)%tail]-O,p[i]-O);
            if(dcmp(Cross(p[i]-O,p[(i+1)%tail]-O))>0)ang*=1;
            else ang*=-1;
            double Sshan=ang/(2*PI)*Scir;
            double Strian=Area(O,p[i],p[(i+1)%tail]);
            if(dcmp(fabs(Sshan)-fabs(Strian))<=0)  //åä¸è§å½¢åæå½¢é¢ç§¯çè¾å¤§è
                res+=Sshan;
            else res+=Strian;
        }
        printf("Case %d: %.10lf\n",++rnd,fabs(res));
    }

};

Point p[2*N];
int tail;
double square(double x){return x*x;}

int main()
{
    rnd=0;
    int n;
    double K;

    while(~scanf("%d%lf",&n,&K))
    {
        tail=0;
        for(int i=0;i<n;i++)
            tp[i].read();
        double ax,ay,bx,by;
        scanf("%lf%lf%lf%lf",&ax,&ay,&bx,&by);
        double mu=K*K-1;
        Point O=Point(-(bx-K*K*ax)/mu,-(by-K*K*ay)/mu);
        double L=Length(Point(ax,ay)-Point(bx,by));
        double R=L*K/(1-K*K);
        Circle cir=Circle(O,R);
        GetCirclePolyIntersection gcp=GetCirclePolyIntersection(cir);
        gcp.solve(tp,n);
    }
}
