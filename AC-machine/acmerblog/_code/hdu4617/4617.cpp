#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#pragma comment (linker, "/STACK:1024000000,1024000000")

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define eps 1e-8
#define sign(x) ((x) > eps ? 1 : ((x) < -eps ? (-1) : (0)))

using namespace std;

typedef long long ll;

int n;

struct point
{
    double x, y, z;
    point() {}
    point(double _x, double _y, double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    void input()
    {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
    point operator + (const point &b) const
    {
        return point(x + b.x, y + b.y, z + b.z);
    }
};

struct line
{
    point a, b;
};

struct circle
{
    point o, p1, p2;

    void input()
    {
        o.input();
        p1.input();
        p2.input();
    }
} c[100];

point xmult(point u, point v)
{
    point ret;
    ret.x = u.y * v.z - v.y * u.z;
    ret.y = u.z * v.x - u.x * v.z;
    ret.z = u.x * v.y - u.y * v.x;
    return ret;
}

double dis(point u, point v)
{
    return sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y) + (u.z - v.z) * (u.z - v.z));
}

double dmult(point u, point v)
{
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

point sub(point u, point v)
{
    point ret;
    ret.x = u.x - v.x;
    ret.y = u.y - v.y;
    ret.z = u.z - v.z;
    return ret;
}

double vlen(point p)
{
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

point pvec(circle s)
{
    return xmult(sub(s.o, s.p1), sub(s.p1, s.p2));
}

double linedis(line u, line v)
{
    point n = xmult(sub(u.a, u.b), sub(v.a, v.b));
    return fabs(dmult(sub(u.a, v.a), n)) / vlen(n);
}

void solve()
{
    double ans = 1e9;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            circle c1 = c[i], c2 = c[j];
            double r1 = dis(c[i].o, c[i].p1);
            double r2 = dis(c[j].o, c[j].p1);

            point k1 = pvec(c1);
            point k2 = pvec(c2);

            line l1, l2;
            l1.a = c1.o, l1.b = k1 + c1.o;
            l2.a = c2.o, l2.b = k2 + c2.o;

            double d = linedis(l1, l2);
            if(sign(d - r1 - r2) <= 0)
            {
                puts("Lucky");
                return ;
            }
            ans = min(ans, d - r1 - r2);
        }
    }
    printf("%.2f\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            c[i].input();
        solve();
    }
    return 0;
}
