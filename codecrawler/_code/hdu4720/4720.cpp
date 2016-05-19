#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const double eps=1e-14;
double x,y,r,rr;
double cross(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void find(double x1,double y1,double x2,double y2,double x3,double y3)
{
    double coss,a,b,c,x4,y4,r4;
    a=cross(x1,y1,x2,y2);b=cross(x1,y1,x3,y3);c=cross(x2,y2,x3,y3);
    coss=(a*a+b*b-c*c)/(2*a*b);
    //cout<<coss<<"***"<<endl;
    //cout<<a<<" "<<b<<" "<<c<<endl;
    x4=(x2+x3)/2;y4=(y2+y3)/2;
    r4=sqrt((x2-x4)*(x2-x4)+(y2-y4)*(y2-y4));
    if(coss<0)
    {
        x=x4;
        y=y4;
        r=r4;
    }
}
int main()
{
    int T,tt=0;
    double x1,y1,x2,y2,x3,y3,xx,yy;
    cin>>T;
    while(T--)
    {
        double a,b,c,d,e,f;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>xx>>yy;
        a=x1*x1-x2*x2+y1*y1-y2*y2;b=x1-x1-x3*x3+y1*y1-y3*y3;
        c=x1-x2;d=x1-x3;e=y1-y2;f=y1-y3;
        y=(c/d* b/2-a/2)/(c/d*f-e);x=(a/2-e*y)/c;//根据垂直向量数量积为0，两一元二次方程求得
        r=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
        find(x1,y1,x2,y2,x3,y3);
        find(x2,y2,x3,y3,x1,y1);
        find(x3,y3,x1,y1,x2,y2);
        //cout<<x<<" "<<y<<endl;
        //cout<<cross(x,y,x1,y1)<<" "<<cross(x,y,x2,y2)<<" "<<cross(x,y,x3,y3)<<endl;
        rr=sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
        if(rr-r<eps)cout<<"Case #"<<++tt<<": Danger"<<endl;
        else cout<<"Case #"<<++tt<<": Safe"<<endl;
    }
    return 0;
}
/*
    三角形外接圆圆心为垂直平分线的交点;
    当三角形是锐角的是否，外接圆最小；当三角形是钝角的时候，圆心在最长边中点上时，圆面积最小。
    三个巫师的位置应该是不同的。。
    
    一开始忘了外接圆的定义了，看别人说是重心，我也就想当然了。。还水过了，汗。。
*/
