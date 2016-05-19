#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cmath>
using namespace std;

struct point 
{
    double x,y,z;
};

point rollptoline1(point p,double angle)//顺时针旋转 
{
    point ans=p;
    ans.x=p.x*cos(angle)+p.y*sin(angle);
    ans.y=-p.x*sin(angle)+p.y*cos(angle);
    return ans;
}
point rollptoline2(point p,double angle)//逆时针旋转 
{
    point ans=p;
    ans.x=p.x*cos(angle)+p.z*sin(angle);
    ans.z=-p.x*sin(angle)+p.z*cos(angle);
    return ans;
}
double anle(double x,double y)
{
    return atan(y/x);
}
int main()
{
    point t1,t2;
    double du;
    //double pi=3.1415926;
    double pi=acos(-1.0);
    while(scanf("%lf %lf %lf",&t1.x,&t1.y,&t1.z)!=EOF)
    {
        scanf("%lf %lf %lf",&t2.x,&t2.y,&t2.z);
        scanf("%lf",&du);
        double d1=anle(t2.x,t2.y);
        t2=rollptoline1(t2,d1);
        t1=rollptoline1(t1,d1);
    //    printf("%.3lf %.3lf %.3lf\n",t2.x,t2.y,t2.z);
        double d2=anle(t2.z,t2.x);
        t2=rollptoline2(t2,-d2);
        t1=rollptoline2(t1,-d2);

        //printf("%.3lf %.3lf %.3lf\n\n",t2.x,t2.y,t2.z);
        t1=rollptoline1(t1,-du);
        t1=rollptoline2(t1,d2);
        t1=rollptoline1(t1,-d1);
    //    t2=rollptoline2(t2,d2);
        //printf("%.3lf %.3lf %.3lf\n",t2.x,t2.y,t2.z);
    //    t2=rollptoline1(t2,-d1);
        printf("%.3lf %.3lf %.3lf\n",t1.x,t1.y,t1.z);
    }
    return 0;
}