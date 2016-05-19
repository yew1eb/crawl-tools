#include<cstdio>
#include<cstring>
#include<cmath>

const double pi=acos(-1.0);
const double eps=1e-12;

double a,b,c;
double x,y,v,vx,vy;

double cal(double p)
{
    double tmp=a/(cos(p)*cos(p))+b*tan(p)+c;
    return tmp;
}

double trisection(double &down,double &up)
{
    double left,right,xl,xr;
    while ((up-down)>eps)
    {
        left=(up+down+down)/3.0;
        right=(up+up+down)/3.0;
        xl=cal(left),xr=cal(right);
        if (xl<0) return left;
        if (xr<0) return right;
        if (xl<xr) up=right;
        else down=left;
    }
    return -1.0;
}

double dbs(double tmp)
{
    return tmp>0?tmp:-tmp;
}

double binary(double down,double up)
{
    double t,mid;
    while ((up-down)>eps)
    {
        mid=(down+up)/2.0;
        t=cal(mid);
        if (t>0) down=mid;
        else up=mid;
    }
    return mid;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lf%lf%lf",&x,&y,&v);
        a=4.9*x*x/v/v,b=-x,c=y;
        double m1=0.0,m3=pi/2.0-eps;
        double m2=trisection(m1,m3);
        if (m2>0)
        {
            x=binary(m1,m2);
            printf("%lf\n",x);
        }
        else printf("%.0lf\n",m2);
    }
    return 0;
}