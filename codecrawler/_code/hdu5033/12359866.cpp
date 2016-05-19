#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200000 + 100;
const double pi = acos(-1.0);
struct Point {
    double x, y;
    int f;
    Point(double x=0, double y=0, int f=0):x(x),y(y),f(f){}
    bool operator <(const Point&rhs) const
    {
        return x <rhs.x;
    }
};

typedef Point Vector;
Vector operator - (const Point& a, const Point& b)
{
    return Vector(a.x-b.x, a.y-b.y);
}
double Cross(const Vector& a, const Vector& b)
{
    return a.x*b.y - a.y*b.x;
}

double ans[maxn];

Point P[maxn];

int n, q;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.cpp", "r", stdin);
    freopen("out.cpp", "w", stdout);
#endif // ONLINE_JUDGE

    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas) {
        scanf("%d", &n, &q);
        for(int i=1; i<=n; ++i) {
            scanf("%lf%lf", &P[i].x, &P[i].y);
            P[i].f = 0;
        }
        scanf("%d", &q);
        for(int i=1; i<=q; ++i) {
            double x;
            scanf("%lf", &x);
            P[n+i].x = x;
            P[n+i].y = 0;
            P[n+i].f = i;
        }
        n += q;
        sort(P+1, P+n+1);
        vector<Point> ch(n+1);
        Vector u;
        int m = 0;
        for(int i=1; i<=n; ++i) {
            while(m>1 && Cross(ch[m-1]-ch[m-2],P[i]-ch[m-2])>=0) m--;
            ch[m] = P[i];
            if(ch[m].f) {
                u = ch[m-1] - ch[m];
              //  printf("(%d,%d)\n", ch[m-1].x, ch[m-1].y);
                ans[ ch[m].f ]= atan2(u.y, u.x);
               // printf("%lf\n", ans[ mp[P[i].x] ][0]);
            }
            m++;
        }

        m = 0;
        for(int i=n; i>=1; --i) {
            while(m>1 && Cross(ch[m-1]-ch[m-2],P[i]-ch[m-2])<=0) m--;
            ch[m] = P[i];
            if(ch[m].f) {
                u = ch[m-1] - ch[m];
               // printf("(%d,%d)\n", ch[m-1].x, ch[m-1].y);
                ans[ ch[m].f ] -= atan2(u.y, u.x);
               // printf("%lf\n", ans[ mp[P[i].x] ][1]);
            }
            m++;
        }
        printf("Case #%d:\n", cas);
        for(int i=1; i<=q; ++i){
            printf("%.10lf\n", ans[i]*180/pi);
        }
    }
    return 0;
}