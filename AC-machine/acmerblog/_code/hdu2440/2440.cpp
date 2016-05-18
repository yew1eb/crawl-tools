#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define FF(i, a, b) for(int i=a; i<b; i++)
#define FD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0; i<n; i++)
#define CLR(a, b) memset(a, b, sizeof(a))
#define debug puts("**debug**")
#define LL long long
#define PB push_back
#define eps 1e-10
using namespace std;

//hdu 2440
const int maxn = 111;
int n, T;
struct Point
{
    double x, y;
    Point (double x=0, double y=0):x(x), y(y) {}
}p[maxn], pt[maxn], ft;
typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (Vector A, double p) { return Vector(A.x/p, A.y/p); }

bool operator < (const Point& a, const Point& b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int dcmp(double x)
{
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

bool operator == (const Point& a, const Point& b)
{
    return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angel(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }

int ConvexHull(Point *p, int n, Point* ch)//凸包
{
    sort(p, p+n);
    int m = 0;
    REP(i, n)
    {
        while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    FD(i, n-2, 0)
    {
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    return m;
}

inline double dist(Point a, Point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double fermat_point(Point *pt, int n, Point& ptres)
{
	Point u, v;
	double step = 0.0, curlen, explen, minlen;
	int i, j, k, idx;
	bool flag;
	u.x = u.y = v.x = v.y = 0.0;
	REP(i, n)
	{
		step += fabs(pt[i].x) + fabs(pt[i].y);
		u.x += pt[i].x;
		u.y += pt[i].y;
	}
	u.x /= n;
	u.y /= n;
	flag = 0;
	while(step > eps)
	{
		for(k = 0; k < 10; step /= 2, ++k)
			for(i = -1; i <= 1; ++i)
				for(j = -1; j <= 1; ++j)
				{
					v.x = u.x + step*i;
					v.y = u.y + step*j;
					curlen = explen = 0.0;
				        REP(idx, n)
					{
						curlen += dist(u, pt[idx]);
						explen += dist(v, pt[idx]);
					}
					if(curlen > explen)
					{
						u = v;
						minlen = explen;
						flag = 1;
					}
				}
	}
	ptres = u;
	return flag ? minlen : curlen;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
	    scanf("%d", &n);
	    REP(i, n) scanf("%lf%lf", &p[i].x, &p[i].y);
	    int m = ConvexHull(p, n, pt);
	    double ans = fermat_point(pt, m, ft);
	    printf("%.0f\n", ans);
	    if(T > 0) puts("");
	}
	return 0;
}