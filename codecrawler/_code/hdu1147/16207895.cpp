#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-8;
#define maxn 111111
int sgn(double x)
{
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x=_x;y=_y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator ^(const Point &b)const
    {
        return x*b.y-y*b.x;
    }
    double operator *(const Point &b)const
    {
        return x*b.x+y*b.y;
    }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s=_s;e=_e;
    }
};
//å¤æ­çº¿æ®µç¸äº¤
bool inter(Line l1,Line l2)
{
    return 
        max(l1.s.x,l1.e.x)>=min(l2.s.x,l2.e.x)&&
        max(l2.s.x,l2.e.x)>=min(l1.s.x,l1.e.x)&&
        max(l1.s.y,l1.e.y)>=min(l2.s.y,l2.e.y)&&
        max(l2.s.y,l2.e.y)>=min(l1.s.y,l1.e.y)&&
        sgn((l2.s-l1.s)^(l1.e-l1.s))*sgn((l2.e-l1.s)^(l1.e-l1.s))<=0&&
        sgn((l1.s-l2.s)^(l2.e-l2.s))*sgn((l1.e-l2.s)^(l2.e-l2.s))<=0;
}
Line line[maxn];
bool flag[maxn];
int main()
{
    int n;
    double x1,x2,y1,y2;
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            line[i]=Line(Point(x1,y1),Point(x2,y2));
            flag[i]=true;
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(inter(line[i],line[j]))
                {
                    flag[i]=false;
                    break;
                }
        printf("Top sticks: ");
        bool res=true;
        for(int i=1;i<=n;i++)
            if(flag[i])
            {
                if(res)
                    res=false;
                else
                    printf(", ");
                printf("%d",i);
            }
        printf(".\n");
    }
    return 0;
}