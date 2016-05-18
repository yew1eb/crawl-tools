#include <iostream>
#include <algorithm>
#include <string>
//#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define M 105

struct point{
	point (double a=0, double b=0) {x=a; y=b;}
	double x, y;
}s[M], p[M];

struct line{
	line (point a, point b) {s=a; e=b;}
	line (){}
	point s, e;
};

inline double dist (point a, point b)
{
	return sqrt ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double dot (point a, point b, point c)		//����ca���cb
{
	return (a.x-c.x)*(b.x-c.x) + (a.y-c.y)*(b.y-c.y);
}

double relation (point p, line l)
{
	return dot(p,l.e,l.s) / (dist(l.s,l.e)*dist(l.s,l.e));
}

point perpendicular (point p, line l)		//���C���߶�AB����ֱ�ߵĴ���P
{
	double r = relation (p, l);
	point tp;
	tp.x = l.s.x + r*(l.e.x-l.s.x);
	tp.y = l.s.y + r*(l.e.y-l.s.y);
	return tp;
}
//���p���߶�l����̾���,�������߶��Ͼ�õ����ĵ�np
double ptolinedist (point p,line l, point &np)
{	//ע�⣺np���߶�l�ϵ���p���ĵ㣬��һ���Ǵ���
	double r = relation (p, l);
	if(r < 0) return dist (p, np=l.s);
	if(r > 1) return dist (p, np=l.e);
	np = perpendicular (p, l);
	return dist (p, np);
}

int main()
{
	double ans;
	int i, j, t, n, m;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d", &n);
		for (i = 0; i < n; i++)
			scanf ("%lf%lf", &s[i].x, &s[i].y);
		scanf ("%d", &m);
		for (i = 0; i < m; i++)
			scanf ("%lf%lf", &p[i].x, &p[i].y);
		p[m] = p[0];
		ans = 1e10;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				line l(p[j], p[j+1]);
				point pp;
				double tp = ptolinedist (s[i], l, pp);
				if (tp < ans) ans = tp;
			}
		}
		printf ("%.8f\n", ans/2);
	}
 return 0;
}