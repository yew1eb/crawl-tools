#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const double pi=acos(-1);

inline double ballv(double r)
{
    return 4./3.0*pi*r*r*r;
}

inline double cov(double hr,double hz)
{
    return pi*hr*hr*hz;
}

const int esp=1e-7;
int dcmp(double x)
{
    if(fabs(x)<=esp)return 0;
    return x<0?-1:1;
}

int main()
{
//freopen("data.txt","r",stdin);
    double r,hr,hz;
    while(scanf("%lf%lf%lf",&r,&hr,&hz)!=EOF)
    {
        double ans;
        if(hr>=r&&hz>=r)
        {
            double b=ballv(r);
            double c=cov(hr,hz*2);
            ans=b/c;
        }
        else if(dcmp(hr*hr+hz*hz-r*r)<0)
        {
            double b=ballv(r);
            double c=cov(hr,hz*2);
            ans=c/b;
        }
        else if(hz>=r&&hr<=r)
        {
            double b=ballv(r);
            double c=cov(hr,hz*2);
            double tmp=r*r-hr*hr;
            double inter=4./3*pi*(r*r*r-sqrt(tmp*tmp*tmp));
            ans=inter/(b+c-inter);
        }
        else if(hz<=r&&hr>=r)
        {
            double inter=2*pi*(r*r*hz-1./3*hz*hz*hz);
            double b=ballv(r);
            double c=cov(hr,hz*2);
            ans=inter/(b+c-inter);
        }
        else
        {
            double b=ballv(r);
            double c=cov(hr,hz*2);
            double r0=sqrt(r*r-hz*hz);
            double c1=cov(r0,hz*2);
            double tmp1=r*r-r0*r0;
            double tmp2=r*r-hr*hr;
            double inter=4./3*pi*(sqrt(tmp1*tmp1*tmp1)-sqrt(tmp2*tmp2*tmp2))+c1;
            ans=inter/(b+c-inter);
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}
