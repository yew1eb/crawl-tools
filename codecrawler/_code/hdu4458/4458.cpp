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
#include<functional>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

#define me(s)  memset(s,0,sizeof(s))
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
//typedef pair <int, int> P;


const double PI=acos(-1.0);
const double eps=1e-10;

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
    Point operator+(const Point&p){return Point(x+p.x,y+p.y);}
    Point operator-(const Point&p){return Point(x-p.x,y-p.y);}
    Point operator*(double p){return Point(x*p,y*p);}
    Point operator/(double p){return Point(x/p,y/p);}

};

typedef Point Vector;

double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double Length(Vector a){return sqrt(Dot(a,a));}
double Angle(Vector a,Vector b){return acos(Dot(a,b)/Length(a)/Length(b));}

bool OnSegment(Point p,Point a,Point b)
{
    if(dcmp(Cross(p-a,p-b)))return 0;
    return dcmp(a.x-p.x)*dcmp(b.x-p.x)<=0&&dcmp(a.y-p.y)*dcmp(b.y-p.y)<=0; //利用dcmp判断，避免使用Dot
}

typedef vector<Point> Polygon;

int isPointInPolygon(Point p,Polygon poly)
{
    int wn=0;
    int n=poly.size();
    for(int i=0;i<n;i++)
    {
        if(OnSegment(p,poly[i],poly[(i+1)%n]))return 0;
        int k=dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i]));
        int d1=dcmp(poly[i].y-p.y);
        int d2=dcmp(poly[(i+1)%n].y-p.y);
        if(k>0&&d1<=0&&d2>0)wn++;
        if(k<0&&d2<=0&&d1>0)wn--;
    }
    return wn;
}

double v,b,g;
int n;


int main()
{
    while(~scanf("%lf%lf%lf",&v,&b,&g))
    {
        if(v==0&&b==0&&g==0)break;
        scanf("%d",&n);
        Polygon p;
        double my=0.0,x,y;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&x,&y);
            my=max(my,y);
            p.push_back(Point(x,y));
        }
        int ok=0;
        double T=dcmp(g)?2.0*b/g:my/b; //分2种情况
        for(double t=0.0;t<=T;t+=0.001)
        {
            Point tmp(-v*t,b*t-0.5*g*t*t); 
            if(isPointInPolygon(tmp,p))
            {
                printf("%.2lf\n",t);
                ok=1;
                break;
            }
        }
        if(!ok)puts("Miss!");
    }
}

