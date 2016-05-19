#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double a,b,x,y;
bool judge()
{
    if(a*b<=x*y)return false;
    if(a>x&&b>y)return true;
    if(b<=y)return false;
    double angle1,angle2,angle3,length,djx;
    djx=sqrt(x*x+y*y);
    angle1=acos(y/djx);
    angle2=acos(b/djx);
    angle3=angle1-angle2;
    length=djx*sin(angle2)+2*y*sin(angle3);
    if(length<a)return true;
    else return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
        if(b>a)
        {
            int t=a;
            a=b;
            b=t;
        }
        if(y>x)
        {
            int t=x;
            x=y;
            y=t;
        }
        if(judge())printf("Escape is possible.\n");
        else printf("Box cannot be dropped.\n");
    }
    return 0;
}
