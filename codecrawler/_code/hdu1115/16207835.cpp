#include<stdio.h>
#include<math.h>
#define eps 1e-8

struct point
{
    double x;
    double y;
};
struct line
{
    point a;
    point b;
};
point p[1000005];

double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

point intersection(line u,line v)
{
    point ret=u.a;
    double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x=ret.x+(u.b.x-u.a.x)*t;
    ret.y=ret.y+(u.b.y-u.a.y)*t;
    return ret;
}

point barycenter(point a,point b,point c)
{
    line u,v;
    u.a.x=(a.x+b.x)/2;
    u.a.y=(a.y+b.y)/2;
    u.b=c;
    v.a.x=(a.x+c.x)/2;
    v.a.y=(a.y+c.y)/2;
    v.b=b;
    return intersection(u,v);
}

point barycenter(int n)
{
    point ret,t;
    double t1=0,t2;
    int i;
    ret.x=ret.y=0;
    for(i=1;i<n-1;i++)
    {
        if(fabs(t2=xmult(p[0],p[i],p[i+1]))>eps)
        {
            t=barycenter(p[0],p[i],p[i+1]);
            ret.x=ret.x+t.x*t2;
            ret.y=ret.y+t.y*t2;
            t1=t1+t2;
        }
    }
    if(fabs(t1)>eps)
    {
        ret.x=ret.x/t1;
        ret.y=ret.y/t1;
    }
    return ret;
}

int main()
{
    int t,n,i;
    point center;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        center=barycenter(n);
        printf("%.2lf %.2lf\n",(center.x+0.001),(center.y+0.001));
    }
    return 0;
}