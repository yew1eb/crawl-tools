#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#define L1 long long
#define L2 __int64
#define inf 0x3f3f3f3f
using namespace std;
//const int m1=1001000;
//const int m2=1010;
//int head[m1],vex[m1],arr[m1];
//bool vis[m2][m2];

//char st2[500000],st1[500000];
const double eps=1e-8;
const double PI=acos(-1.0);
double max(double x,double y)
{
    return x>y?x:y;
}
double min(double x,double y)
{
    return x<y?x:y;
}

int sgn(double x)
{
    if(fabs(x)<eps ) return 0;
    if(x<0) return -1;
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
    Point operator-(const Point &b)const
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
    /*void transXY(double B)
    {
        double tx=x,ty=y;
        x=tx*cos(B)-ty*sin(B);
        y=tx*sin(B)+ty*cos(B);
    }*/
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s=_s;e=_e;
    }
    pair<int,Point> operator &(const Line &b)const
    {
        Point res=s;
        if(sgn((s-e)^(b.s-b.e))==0 )
        {
            if(sgn((s-b.e)^(b.s-b.e))==0 )
                return make_pair(0,res);
            else
                return make_pair(1,res);
        }
        double t=((s-b.s)^(b.s-b.e) )/( (s-e)^(b.s-b.e) ) ;
        res.x+=(e.x-s.x)*t;
        res.y+=(e.y-s.y)*t;
        return make_pair(2,res);
    }
};

bool OnSeg(Point P,Line L)
{
    return
    sgn( (L.s-P)^(L.e-P) )==0&&
    sgn( (P.x-L.s.x)*(P.x-L.e.x))<=0&&
    sgn((P.y-L.s.y)*(P.y-L.e.y))<=0;
}
bool inter(Line l1,Line l2)
{
    return
    max(l1.s.x,l1.e.x)>=min(l2.s.x,l2.e.x)&&
    max(l2.s.x,l2.e.x)>=min(l1.s.x,l1.e.x)&&
    max(l1.s.y,l1.e.y)>=min(l2.s.y,l2.e.y)&&
    max(l2.s.y,l2.e.y)>=min(l1.s.y,l1.e.y)&&
    sgn((l2.s-l1.e)^(l1.s-l1.e) )*sgn((l2.e-l1.e)^(l1.s-l1.e))<=0&&
    sgn((l1.s-l2.e)^(l2.s-l2.e) )*sgn((l1.e-l2.e)^(l2.s-l2.e))<=0;

}
int inPloy(Point p,Point poly[],int n)
{
    int cnt;
    Line ray,side;
    cnt=0;
    ray.s=p;
    ray.e.y=p.y;
    ray.e.x=-inf;
    for(int i=0;i<n;i++)
    {
        side.s=poly[i];
        side.e=poly[ (i+1)%n];
        if(OnSeg(p,side )) return 0;

        if(sgn(side.s.y-side.e.y)==0 )
            continue;

        if(OnSeg(side.s,ray))
        {
            if(sgn(side.s.y-side.e.y)>0)cnt++;
        }
        else if(OnSeg(side.e,ray))
        {
            if(sgn(side.e.y-side.s.y)>0)cnt++;
        }
        else if(inter(ray,side))
            cnt++;
    }
    if(cnt%2==1)
        return 1;
    else return -1;
}

int main()
{
    int zu;
    Point ar[110],tmp;
    while(~scanf("%d",&zu))
    {
        for(int i=0;i<zu;i++)
        scanf("%lf%lf",&ar[i].x,&ar[i].y);
        int m;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%lf%lf",&tmp.x,&tmp.y);
            if(inPloy(tmp,ar,zu)!=-1)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}