#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define N 1005
#define PR 1e-8
struct TPoint
{
    double x,y;
    TPoint(){};
    TPoint(double _x,double _y):x(_x),y(_y){}
    TPoint operator-(const TPoint p){return TPoint(x-p.x,y-p.y);}
}s;
struct TPolygon
{
    int n;
    TPoint p[N];
}ply1,ply2;
int dblcmp(double a) {return fabs(a)<PR?0:a>0?1:-1;}
double MIN(double a,double b) {return a<b?a:b;}
double dist(TPoint a,TPoint b)//两点距
{
    TPoint c(a-b);
    return sqrt(c.x*c.x+c.y*c.y);
}
double cross(TPoint a,TPoint b,TPoint c)//叉积
{
    TPoint s(b-a),t(c-a);
    return s.x*t.y-s.y*t.x;
}
double dot(TPoint a,TPoint b,TPoint c)//点积
{
    TPoint s(b-a),t(c-a);
    return s.x*t.x+s.y*t.y;
}
bool cmop(TPoint a,TPoint b)//x、y排序
{
    if(fabs(a.x-b.x)<PR) return a.y<b.y;
    else return a.x<b.y;
}
bool cmp(TPoint a,TPoint b)//叉积内排序
{
    int d1=dblcmp(cross(s,a,b));
    return d1>0||(d1==0&&dist(s,a)<dist(s,b));
}
TPolygon graham(TPolygon ply)//凸包
{
    int i,k;
    if(ply.n<3) return ply;
    sort(ply.p,ply.p+ply.n,cmop);
    s=ply.p[0];
    sort(ply.p+1,ply.p+ply.n,cmp);
    for(i=2,k=2;i<ply.n;i++)
    {
        while(k>1&&(dblcmp(cross(ply.p[k-2],ply.p[i],ply.p[k-1])))>=0) k--;
        ply.p[k++]=ply.p[i];
    }
    ply.n=k;
    return ply;
}
double disps(TPoint a,TPoint b,TPoint c)//点到线段的最近距离
{
    TPoint s(a-b),t(c-b);
    if(s.x*t.x+s.y*t.y<0) return dist(a,b);
    s=(a-c); t=(b-c);
    if(s.x*t.x+s.y*t.y<0) return dist(a,c);
    return fabs(cross(a,b,c))/(dist(b,c));
}
double disss(TPoint a,TPoint b,TPoint c,TPoint d)//两条线段最近距离
{
    return MIN(MIN(disps(a,c,d),disps(b,c,d)),MIN(disps(c,a,b),disps(d,a,b)));
}
double solve(TPolygon pl,TPolygon pr,int p,int q)//旋转卡壳，求凸边形最近距离
{
    int i;
    double tmp,min=1e90;
    pl.p[pl.n]=pl.p[0]; pr.p[pr.n]=pr.p[0];
    for(i=0;i<pl.n;i++)
    {
        while((tmp=cross(pl.p[p+1],pr.p[q+1],pl.p[p])-cross(pl.p[p+1],pr.p[q],pl.p[p]))>PR)
            q=(q+1)%pr.n;
        if(tmp<-PR) min=MIN(min,disps(pr.p[q],pl.p[p],pl.p[p+1]));
        else min=MIN(min,disss(pl.p[p],pl.p[p+1],pr.p[q],pr.p[q+1]));
        p=(p+1)%pl.n;
    }
    return min;
}
void gettop(TPolygon pl,TPolygon pr,int &l,int &r)//得到最下和最上点
{
    int i;
    l=r=0;
    for(i=0;i<pl.n;i++)
    {
        if((dblcmp(pl.p[i].y-pl.p[l].y))<0) l=i;
    }
    for(i=0;i<pr.n;i++)
    {
        if((dblcmp(pr.p[i].y-pr.p[r].y))>0) r=i;
    }
}
bool segcross(TPoint a,TPoint b,TPoint c,TPoint d)//ab交线段cd
{
    int d1=dblcmp(cross(a,c,d));
    int d2=dblcmp(cross(b,c,d));
    int d3=dblcmp(cross(c,a,b));
    int d4=dblcmp(cross(d,a,b));
    if(d1*d2<0&&d3*d4<0) return true;//严格交
    else return false;
}
bool pintoply(TPoint a,TPolygon res)//点在多边形内、环顾法
{
    int i;
    for(i=0;i<res.n;i++)//a点在多边形外
        if((dblcmp(cross(a,res.p[i],res.p[i+1])))<=0) return false;
    return true;
}
bool plyintoply(TPolygon res1,TPolygon res2)//包含
{
    int i,j;
    for(i=0;i<res1.n;i++)
        if(pintoply(res1.p[i],res2)) return true;
    return false;
}
bool plycrossply(TPolygon res1,TPolygon res2)//相交
{
    int i,j;
    for(i=0;i<res1.n;i++)
        for(j=0;j<res2.n;j++)
            if(segcross(res1.p[i],res1.p[i+1],res2.p[j],res2.p[j+1])) return true;
    return false;
}
int main()
{
    while(~scanf("%d%d",&ply1.n,&ply2.n))
    {
        int i,l,r,j;
        bool tmp=false;
        double mindis;
        TPolygon temp;
        for(i=0;i<ply1.n;i++) scanf("%lf%lf",&ply1.p[i].x,&ply1.p[i].y);
        for(i=0;i<ply2.n;i++) scanf("%lf%lf",&ply2.p[i].x,&ply2.p[i].y);
        ply1=graham(ply1); ply2=graham(ply2);
        ply1.p[ply1.n]=ply1.p[0]; ply2.p[ply2.n]=ply2.p[0];
        mindis=1e120;
        if(ply1.n>ply2.n) {temp=ply1;ply1=ply2;ply2=temp;}//多边形1拥有最少点
        if(ply1.n==1)
        {
            if(ply2.n==1) mindis=dist(ply1.p[0],ply2.p[0]);//两点
            else if(ply2.n==2) mindis=disps(ply1.p[0],ply2.p[0],ply2.p[1]);//一对二
            else//一对多
            {
                if(pintoply(ply1.p[0],ply2)) mindis=0;//包含
                else
                    for(i=0;i<ply2.n;i++)
                        mindis=MIN(mindis,disps(ply1.p[0],ply2.p[i],ply2.p[i+1]));
            }
        }
        else if(ply1.n==2)//二对多
        {
            if(ply2.n==2)
            {
                if(segcross(ply1.p[0],ply1.p[1],ply2.p[0],ply2.p[1])) mindis=0;
                else mindis=disss(ply1.p[0],ply1.p[1],ply2.p[0],ply2.p[1]);
            }
            else
            {
                if((pintoply(ply1.p[0],ply2))||(pintoply(ply1.p[1],ply2))) mindis=0.0;//包含
                else
                {
                    for(i=0;i<ply2.n;i++)//相交
                        if(segcross(ply1.p[0],ply1.p[1],ply2.p[i],ply2.p[i+1])) {tmp=true;break;}
                    if(tmp) mindis=0;
                    else
                        for(i=0;i<ply2.n;i++)
                            mindis=MIN(mindis,disss(ply1.p[0],ply1.p[1],ply2.p[i],ply2.p[i+1]));
                }
            }
        }
        else
        {
            if((plyintoply(ply1,ply2))||(plyintoply(ply2,ply1))) mindis=0.0;
            else
            {
                if(plycrossply(ply1,ply2)) mindis=0;
                else
                {
                    gettop(ply1,ply2,l,r);
                    mindis=MIN(solve(ply1,ply2,l,r),solve(ply2,ply1,r,l));//最近距离
                }
            }
        }
        printf("%.4lf\n",mindis);
    }
    return 0;
}