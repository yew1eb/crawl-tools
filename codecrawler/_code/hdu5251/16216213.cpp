#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps=1e-8;
const double PI=acos(-1.0);
#define maxn 11111
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
int res;
Point pre[4*maxn],tu[4*maxn];
int sgn(double x)
{
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
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
double dis(Point a,Point b)//ä¸¤ç¹é´è·ç¦» 
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int cmp1(Point a,Point b)
{
    if(b.y!=a.y)
        return a.y<b.y;
    return a.x<b.x;
}
int cmp2(Point a,Point b)
{
    if(a.k!=b.k)
        return a.k<b.k;
    if(a.y!=b.y)
        return a.y<b.y;
    return a.x<b.x;
}
double get_dis(Point a,Point b)//å¾å°å¸åä¸æ²¿a->bæ¹åæå¤§æå½±å¼ 
{
    double ans=-(1<<29),temp;
    for(int i=0;i<res;i++)
    {
        temp=p_multi(b-a,tu[i]-b)/dis(a,b);
        if(sgn(temp-ans)>0)
            ans=temp;
    }
    return ans+eps;
}
double get_h(Point a,Point b)//å¾å°å¸åä¸ä¸line(a,b)è·ç¦»æè¿çç¹ 
{
    double ans=-(1<<29),temp;
    for(int i=0;i<res;i++)
    {
        temp=x_multi(tu[i]-a,tu[i]-b)/dis(a,b);
        if(sgn(temp-ans)>0)
            ans=temp;
    }
    return ans+eps;
}
int main()
{
    int t;
    scanf("%d",&t);
    int ret=1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        n*=4;
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&pre[i].x,&pre[i].y);
        //Grahamæ«ææ³æ±å¸å 
        sort(pre,pre+n,cmp1);
        for(int i=1;i<n;i++)
        {
            pre[i].k=atan((double)((pre[i].y-pre[0].y)/(pre[i].x-pre[0].x)));
            if(pre[i].k<(double(0)))
                pre[i].k+=PI;
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
        //for(int i=0;i<res;i++)
        //  printf("%lf %lf\n",tu[i].x,tu[i].y);
        double ans=1<<29;
        for(int i=0;i<res;i++)
        {
            int j=(i+1)%res;
            double dis1=get_dis(tu[i],tu[j]);
            //printf("dis1=%lf\n",dis1);
            double dis2=get_dis(tu[j],tu[i]);
            //printf("dis2=%lf\n",dis2);
            double d=dis(tu[i],tu[j])+dis1+dis2+eps;//ä»¥line(tu[i],tu[j])ä¸ºåºè¾¹çç©å½¢åº 
            //printf("d=%lf\n",d);
            double h=get_h(tu[i],tu[j]);//ä»¥line(tu[i],tu[j])ä¸ºåºè¾¹çç©å½¢é«
            //printf("h=%lf\n",h);
            double temp=d*h+eps;////ä»¥line(tu[i],tu[j])ä¸ºåºè¾¹çç©å½¢é¢ç§¯ 
            if(sgn(temp-ans)<0)//æ´æ°æå°ç©å½¢é¢ç§¯ 
                ans=temp;
        }
        printf("Case #%d:\n",ret++);
        printf("%.0lf\n",ans);
    }
    return 0;
}