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

struct Point
{
    double x, y;
    Point (double x=0, double y=0):x(x), y(y) {}
};
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
double Area2(Vector A, Vector B, Vector C) { return Cross(B-A, C-A); }


//向量逆时针旋转
Vector Rotate(Vector A, double rad)
{
    return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}

//求直线p+tv和q+tw的交点 Cross(v, w) == 0无交点
Point GetLineIntersection(Point p, Vector v, Point q, Vector w)
{
    Vector u = p-q;
    double t = Cross(w, u) / Cross(v, w);
    return p + v*t;
}


//点p到直线ab的距离
double DistanceToLine(Point p, Point a, Point b)
{
    Vector v1 = b - a, v2 = p - a;
    return fabs(Cross(v1, v2)) / Length(v1);//如果不带fabs 得到的是有向距离
}

//点p到线段ab的距离
double DistanceToSegment(Point p, Point a, Point b)
{
    if(a == b) return Length(p-a);
    Vector v1 = b-a, v2 = p-a, v3 = p-b;
    if(dcmp(Dot(v1, v2) < 0)) return Length(v2);
    else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
    else return fabs(Cross(v1, v2)) / Length(v1);
}

//点p在直线ab上的投影
Point GetLineProjection(Point p, Point a, Point b)
{
    Vector v = b-a;
    return a + v*(Dot(v, p-a) / Dot(v, v));
}

//点段相交判定
bool SegmentItersection(Point a1, Point a2, Point b1, Point b2)
{
    double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1),
    c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}

//点在线段上
bool OnSegment(Point p, Point a1, Point a2)
{
    return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}

//多变形面积
double PolygonArea(Point* p, int n)
{
    double ret = 0;
    FF(i, 1, n) ret += Cross(p[i]-p[0], p[i+1]-p[0]);
    return ret/2;
}

Point read_point()
{
    Point a;
    scanf("%lf%lf", &a.x, &a.y);
    return a;
}

const int maxn = 301;
Point p[maxn], v[maxn*1000];

int main()
{
    int n, kase = 1;
    while(scanf("%d", &n), n)
    {
        REP(i, n)
        {
            scanf("%lf%lf", &p[i].x, &p[i].y);
            v[i] = p[i];
        }
        int cnt = n-1, e_num = n-1;//原有边数

        //枚举所有边，求出相交出来的新的点
        REP(i, n-1) FF(j, i+1, n-1)
        if(SegmentItersection(p[i], p[i+1], p[j], p[j+1]))
        v[cnt++] = GetLineIntersection(p[i], p[i+1]-p[i], p[j], p[j+1]-p[j]);

        sort(v, v+cnt);
        int v_num = unique(v, v+cnt) - v;//去重点

        REP(i, v_num) REP(j, n-1)
        if(OnSegment(v[i], p[j], p[j+1])) e_num++;//线段被切割
        printf("Case %d: There are %d pieces.\n", kase++, e_num + 2 - v_num);
    }
    return 0;
}