#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define INF 2147483647
#define N 25
#define PI 3.141592653
#define EPS 1e-8
struct point
{
    double x;
    double y;
}p[N];
double r[N];
int n;
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double interarea(point a,double ra,point b,double rb)   //求圆相交面积的模板 重点
{
    double ans=0;
    double d=dis(a,b);
    double temp;
    if(ra<rb)
    {
        temp=ra;
        ra=rb;
        rb=temp;
    }
    if(d>=ra+rb)return 0;        //相离
    if(d<=ra-rb)return PI*rb*rb;         //内含
    double angle1=acos((ra*ra+d*d-rb*rb)/2.0/ra/d);
    double angle2=acos((rb*rb+d*d-ra*ra)/2.0/rb/d);
    ans-=d*ra*sin(angle1);
    ans+=angle1*ra*ra+angle2*rb*rb;
    return ans;
}
bool istrue(int t,double ra)
{
    for(int i=0;i<n;i++)
    {
            double area=interarea(p[t],ra,p[i],r[i]);
            if(area<0.5*PI*r[i]*r[i])return false;
    }
    return true;
}
double getr(int i)
{
    double l,r,mid;
    l=0;r=50000;
    while(l+EPS<=r)
    {
        mid=(l+r)/2;
        if(istrue(i,mid))r=mid-EPS;
        else l=mid+EPS;
    }
    return mid;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&p[i].x,&p[i].y,&r[i]);
        }
        double ans=INF;
        for(int i=0;i<n;i++)
        {
            double radiu=getr(i);
            if(ans>radiu)ans=radiu;
        }
        printf("%.4lf\n",ans);
    }
    return 0;
}