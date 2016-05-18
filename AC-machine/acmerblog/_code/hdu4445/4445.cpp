#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
using namespace std;
const int maxn = 202;
const double g = 9.80;
const double eps = 1e-8;
const double PI = acos(-1.0);
double pos[10],v[maxn];
double h,farest;
int n;

void read()
{
    scanf("%lf %lf %lf %lf %lf",&h,&pos[0],&pos[1],&pos[2],&pos[3]);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&v[i]);
    }
    return;
}

double dis(double ang,double vv)
{
    double s = sin(ang);
    double c = cos(ang);
    return vv * s * (vv * c + sqrt(vv * vv * c * c + 2.0 * g * h)) / g;
}

void tris(double vv)
{
    double l = 0,r = PI / 2.0;
    int t = 30;
    while(t--)
    {
        double mid = (l + r) / 2.0;
        double midd = (l + mid) / 2.0;
        if(dis(midd , vv) > dis(mid , vv)) r = mid;
        else l = midd;
    }
    farest = l;
    return;
}

double bis_left(double l,double r,double d,double vv)
{
    int t = 30;
    while(t--)
    {
        double mid = (l + r) / 2.0;
        if(dis(mid , vv) <= d) l = mid;
        else r = mid;
    }
    return l;
}

double bis_right(double l,double r,double d,double vv)
{
    int t = 30;
    while(t--)
    {
        double mid = (l + r) / 2.0;
        if(dis(mid , vv) < d) r = mid;
        else l = mid;
    }
    return l;
}

void solve()
{
    int res = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            tris(v[i]);
            if(dis(farest , v[i]) < pos[j]) continue;
            double wei = pos[j];
            if(j == 0) wei += eps;
            if(j == 1) wei -= eps;
            if(j == 2) wei -= eps;
            if(j == 3) wei += eps;
            double ang = bis_left(0.0 , farest , wei , v[i]);
            bool flag = true;
            int c = 0;
            for(int k=0;k<n;k++)
            {
                double here = dis(ang , v[k]);
                if(here >= pos[2] && here <= pos[3])
                {
                    flag = false;
                    break;
                }
                else if(here >= pos[0] && here <= pos[1]) c++;
            }
            if(flag) res = MAX(res , c);
            if(res == n) break;

            ang = bis_right(farest , PI , wei , v[i]);
            flag = true;
            c = 0;
            for(int k=0;k<n;k++)
            {
                double here = dis(ang , v[k]);
                if(here >= pos[2] && here <= pos[3])
                {
                    flag = false;
                    break;
                }
                else if(here >= pos[0] && here <= pos[1]) c++;
            }
            if(flag) res = MAX(res , c);
            if(res == n) break;
        }
    }
    printf("%d\n",res);
    return;
}

int main()
{
    while(scanf("%d",&n) && n)
    {
        read();
        solve();
    }
    return 0;
}
