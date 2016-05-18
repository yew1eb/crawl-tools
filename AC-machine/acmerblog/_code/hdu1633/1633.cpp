#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
struct point
{
    double x;
    double y;
};
const int INF=1e9;
const double eps = 1e-9;
double area2(point p1, point p2, point p3);

int main()
{
 
    point p1,p2,p3;
    point p;
    int i,i2;
    int sum;
    while (scanf ("%lf%lf%lf%lf%lf%lf", &p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y)!=EOF)
    {
        sum=0;
 
        if (p1.x == 0.0 && p1.y == 0.0 && p2.x == 0.0 && p2.y == 0.0 &&
                     p3.x==0.0 && p3.y == 0.0)
            break;
	/*本来这里想做些许优化,从构成三角形的三个点中计算出包含此三角形的最小矩阵,然后再从该小矩阵中枚举所有点,但不知道为何就wa了
	  于是只能枚举所有的点了[0-100][0-100]
        int mix=(int)min(min(p1.x,p2.x),p3.x)-1;
        if(mix<0) mix=0;
        int mx =(int)max(max(p1.x,p2.x),p3.x)+1;
        if(mx>99) mx=99;
        int miy=(int)min(min(p1.y,p2.y),p3.y)-1;
        if(miy<0) miy=0;
        int my =(int)max(max(p1.y,p2.y),p3.y)+1;
        if(my>99) my=99;*/
 
        for (i=1; i<=mx; i++)
            for (i2=1; i2<=my; i2++)
            {
                p.x=i;p.y=i2;
                if ( fabs(area2 (p1,p2,p3) - area2 (p,p1,p2) - area2 (p,p1,p3) - area2 (p,p2,p3))<eps)
                    sum++;
            }
 
        printf ("%4d\n",sum);
 
    }
    return 0;
}
 
 
double area2(point p1, point p2, point p3)
{
    return fabs(p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p3.x*p2.y - p1.x*p3.y - p2.x*p1.y);
}