#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
#define eps 1e-6
#define maxn 2010
#define pi acos(-1.0)
#define ull unsigned long long

inline double Sqr(double x){ return x*x; }
struct Point {
    double x,y,r;
    Point(double _x,double _y, double _r):x(_x),y(_y),r(_r) {}
    Point() {}
};
double dis( Point& p1, Point& p2 )
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}
int n;
Point tmp[maxn],p[maxn];

struct node
{
    double k;
    int st;
} ang[maxn];

inline int dblcmp( double x )
{
    if( fabs(x) < eps )    return 0;
    return x > 0 ? 1 : -1;
}

void get( Point c, double a, Point& p )
{
    p.x = c.x + c.r*cos(a);
    p.y = c.y + c.r*sin(a);
}

void adjust( double& x )
{
    while( dblcmp(x) < 0 )    x += 2*pi;
    while( dblcmp(x-2*pi) >= 0 )    x -= 2*pi;
}

bool inter_cir( Point& o1, Point& o2, double& p1, double& p2 )
{
	double d = dis(o1, o2);
	if( dblcmp(d-fabs(o1.r-o2.r)) <= 0 || dblcmp(d-o1.r-o2.r) >= 0 )
		return 0;

	double cosa = (o1.r*o1.r + d*d - o2.r*o2.r) / (2*o1.r*d);
	double ang = acos(cosa);

	p1 = p2 = atan2( o2.y-o1.y, o2.x-o1.x );
	p1 -= ang;	adjust(p1);
	p2 += ang;	adjust(p2);

	return 1;
}

int cmp( node a, node b )
{
    if( dblcmp(a.k - b.k) )
        return a.k < b.k;
    return a.st > b.st;
}

double cross( Point& a, Point& b )
{
    return a.x*b.y - a.y*b.x;
}
double ans[20];
double solve()
{
    int i, j, e, cnt, t;
    Point p1, p2;
    double pre, a, b;

    for( i = 0; i < n; ++i )
    {
        t = 0;
        for( j = 0; j < n; ++j )    if( j != i )
        {
            if( dblcmp(p[j].r - p[i].r - dis(p[i], p[j])) >= 0 )
                t++;
        }

        e = 0;
        for( j = 0; j < n; ++j )    if( j != i )
        {
            if( inter_cir(p[i], p[j], a, b) )
            {
                ang[e].k = a;    ang[e++].st = 1;
                ang[e].k = b;    ang[e++].st = -1;

                if( dblcmp(a-b) > 0 )
                {
                    ang[e].k = 0;    ang[e++].st = 1;
                    ang[e].k = 2*pi;    ang[e++].st = -1;
                }
            }
        }

        if( !e )
        {
            ans[t] += pi*p[i].r*p[i].r;
            continue;
        }

        sort(ang, ang+e, cmp);
        cnt = 0;
        pre = ang[e-1].k - 2*pi;
        get(p[i], ang[e-1].k, p1);
        for( j = 0; j < e; ++j )
        {
            ans[t+cnt] += 0.5*p[i].r*p[i].r*(ang[j].k-pre - sin(ang[j].k-pre));
            get(p[i], ang[j].k, p2);
            ans[t+cnt] += cross(p1, p2)*0.5;
            p1 = p2;

            cnt += ang[j].st;
            pre = ang[j].k;
        }
    }
    return ans[0]-ans[n-1];
}

Point get_cir(Point a,Point b)
{
    Point t;
    t.x=(a.x+b.x)*0.5;
    t.y=(a.y+b.y)*0.5;
    t.r=dis(a,b)*0.5;
    return t;
}

int main()
{
    Point a,b,c,d; int i,j,v,u,ok,k,tt=0;
    double x,y,dd;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y)!=EOF)
    {
        if(a.x==0&&a.y==0&&b.x==0&b.y==0&&c.x==0&&c.y==0&&d.x==0&&d.y==0) break;
        tmp[0]=get_cir(a,d);
        tmp[1]=get_cir(a,c);
        tmp[2]=get_cir(b,c);
        tmp[3]=get_cir(b,d);
        n=4;k=0;
        for( i = 0; i < n; ++i )
		{
			ok = 1;
			if( !dblcmp(tmp[i].r) )
				ok = 0;
			for( j = 0; ok && j < i; ++j )
			{
				if( !dblcmp(tmp[j].x-tmp[i].x) &&
					!dblcmp(tmp[j].y-tmp[i].y) &&
					!dblcmp(tmp[j].r-tmp[i].r) )
					ok = 0;
			}
			if( ok )
				p[k++] = tmp[i];
		}
		n = k;
        memset(ans,0,sizeof(ans));
        printf("Case %d: %.3lf\n\n",++tt,solve()+eps);
    }
    return 0;
}