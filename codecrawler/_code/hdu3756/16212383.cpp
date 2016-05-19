#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define MAXN 200005
#define MAXM 1000005
#define INF 1000000001
#define lch(x) x<<1
#define rch(x) x<<1|1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define eps 1e-7
using namespace std;
int n;
struct P
{
    double x, y, z;
}p[11111];
double calc(double r)
{
    double h = 0;
    for(int i = 1; i <= n; i++)
    {
        double tmp = r * p[i].z / (r - sqrt(p[i].x * p[i].x + p[i].y * p[i].y));
        if(tmp > h) h = tmp;
    }
    return h * r * r;
}
void solve()
{
    double r = 1000000.0, l = 0;
    while(r - l >= eps)
    {
        double mid = (l + r) / 2;
        double midmid = (mid + r) / 2;
        double s1 = calc(mid);
        double s2 = calc(midmid);
        if(s1 < s2)
        r = midmid;
        else l = mid;
    }
    double h = 0;
    for(int i = 1; i <= n; i++)
    {
        double tmp = r * p[i].z / (r - sqrt(p[i].x * p[i].x + p[i].y * p[i].y));
        if(tmp > h) h = tmp;
    }
    printf("%.3f %.3f\n",h, r);
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
        solve();
    }
    return 0;
}
