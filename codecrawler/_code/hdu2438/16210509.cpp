#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define eps 1e-8

struct point
{
    double x;
    double y;
};
double w1,w2,l,d;

double cross(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double cal(double x)
{
    point t1,t2,p0;
    double s,y,h;
    y=sqrt(l*l-x*x);
    t1.x=w1-x,t1.y=-w2;
    t2.x=w1,t2.y=-(w2-y);
    p0.x=0,p0.y=0;
    s=fabs(cross(t1,t2,p0));
    h=s/l;
    return h;
}

void solve()
{
    int i;
    double left,right,mid1,mid2,h1,h2;
    left=0,right=l;
    for(i=0;i<=100;i++)
    {
        mid1=(left*2+right)/3;
        mid2=(left+right*2)/3;
        h1=cal(mid1);
        h2=cal(mid2);
        if(h1>h2)
        {
            left=mid1;
        }
        else
        {
            right=mid2;
        }
    }
    double H=cal(left);
    if(H-d>0)
        printf("yes\n");
    else
        printf("no\n");
}

int main()
{
    while(scanf("%lf%lf%lf%lf",&w1,&w2,&l,&d)!=EOF)
    {
        if(d>=w1||d>=w2)
        {
            printf("no\n");
            continue;
        }
        solve();
    }
    return 0;
}
