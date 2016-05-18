#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define min(a,b) ((a)<=(b)?(a):(b))

const int maxn = 1000;
const double pi = acos(-1.0);

struct point
{
    double x, y;
    double l, r;
}pt[maxn*2+1];

bool cmp(const point &a, const point &b)
{
    return a.l<b.l;
}

void set(point &p, double d, double dis)
{
    double a, b;
    if (p.x==0)
    {
        if (p.y>0) a = 0.5*pi;
        else a = 1.5*pi;
    }
    else if (p.y==0)
    {
        if (p.x>0) a = 0;
        else a = pi;
    }
    else
    {
        a = asin(fabs(p.y*1.0)/dis);
        if (p.x<0 && p.y>=0) a = pi - a;
        else if (p.x<=0 && p.y<0) a += pi;
        else if (p.x>0 && p.y<=0) a = 2*pi-a;
    }
    b = asin(1.0*d/dis);
    p.l = a-b;
    p.r = a+b;
}

double dist(double x, double y)
{
	return sqrt(x*x+y*y);
}

int main()
{
    int t;
    int n;
    double d;
    int i, j;
    int ct;
	double d1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %lf", &n, &d);
        for (i=0; i<n; i++)
        {
            scanf("%lf %lf", &pt[i].x, &pt[i].y);
			d1 = dist(pt[i].x, pt[i].y);
			if (d1<=d)
			{
				i--;
				n--;
			}
			else set(pt[i], d, d1);
        }
        sort(pt, pt+n, cmp);
		for (i=n; i<2*n; i++)
		{
			pt[i].l = pt[i-n].l+2*pi;
			pt[i].r = pt[i-n].r+2*pi;
		}
		int ans = 1000000;
		for (j=0; j<n; j++)
		{
			ct = 1;
			double s = pt[j].r;
			for (i=1+j; i<n+j; i++)
			{
				if (s<pt[i].l)
				{
					ct++;
					s = pt[i].r;
				}
				else
				{
					s = min(s, pt[i].r);
				}
			}
			ans = min(ans, ct);
		}
		if (ans==1000000) ans = 0;
		printf("%d\n", ans);
    }
    return 0;
}