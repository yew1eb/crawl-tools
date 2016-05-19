#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 111111
const double eps=1e-8;
const double PI=acos(-1.0);
struct Point
{
    double x,y;
    double k;
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
int sgn(double x)
{
    if(fabs(x)<eps) return 0;
    if(x<0) return -1;
    else return 1;
}
double x_multi(Point a,Point b)//åä¹ 
{
    return a.x*b.y-a.y*b.x;
}
double p_multi(Point a,Point b)//ç¹ä¹ 
{
    return a.x*b.x+a.y*b.y;
}
double get_s(Point a,Point b,Point c)
{
    Point d,e;
    d.x=b.x-a.x,d.y=b.y-a.y;
    e.x=c.x-a.x,e.y=c.y-a.y;
    return x_multi(d,e)/2;
}
double dis(Point a,Point b)//ä¸¤ç¹é´è·ç¦» 
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int cmp1(Point a,Point b)
{
    if(b.y!=a.y) return a.y<b.y;
    return a.x<b.x;
}
int cmp2(Point a,Point b)
{
    if(a.k!=b.k) return a.k<b.k;
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}
void Graham(Point pre[],int n,Point tu[],int &res)//preæ°ç»å­çæ¯åå¤è¾¹å½¢çé¡¶ç¹,nä¸ºé¡¶ç¹ä¸ªæ°,tuå­çæ¯å¸åä¸çç¹,resä¸ºå¸åé¡¶ç¹ä¸ªæ° 
{
    sort(pre,pre+n,cmp1);
    for(int i=1;i<n;i++)
    {
        pre[i].k=atan((double)((pre[i].y-pre[0].y)/(pre[i].x-pre[0].x)));
        if(pre[i].k<(double(0))) pre[i].k+=PI;
    }
    sort(pre+1,pre+n,cmp2);
    tu[0]=pre[0];
    tu[1]=pre[1];
    tu[2]=pre[2];
    res=3;
    for(int i=3;i<n;i++)
    {
        while(res>2&&x_multi(tu[res-1]-tu[res-2],pre[i]-tu[res-1])<=0)
            res--;
        tu[res++]=pre[i];
    }
}
int n,res;
Point pre[maxn],tu[maxn];
int main()
{
    while(~scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&pre[i].x,&pre[i].y);
        if(n==1)printf("0.50\n");
        else if(n==2)
        {
            printf("%.2lf\n",dis(pre[0],pre[1])/2+0.5);
        }
        else
        {
            Graham(pre,n,tu,res);
            double ans=0;
            for(int i=0;i<res;i++)
                for(int j=i+1;j<res;j++)
                    for(int k=j+1;k<res;k++)
                    {
                        double a=dis(tu[i],tu[j]),b=dis(tu[i],tu[k]),c=dis(tu[j],tu[k]),temp;
                        if(a*a+b*b<c*c||a*a+c*c<b*b||b*b+c*c<a*a)
                            temp=max(max(a,b),c)/2;
                        else
                        {
                            double s=fabs(get_s(tu[i],tu[j],tu[k]));
                            temp=a*b*c/(4*s);
                        }
                        ans=max(ans,temp);
                    }
            printf("%.2lf\n",ans+0.5);
        }
    }
    return 0;
}