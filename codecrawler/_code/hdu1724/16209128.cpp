#include<stdio.h>
#include<math.h>
#define EPS 1e-6
double a,b;
double f(double x)
{
    return b*sqrt(1.0-x*x/(a*a));
}
double simpson(double l,double r)
{
    double mid=l+(r-l)/2.0;
    return (r-l)*(f(l)+4.0*f(mid)+f(r))/6.0;
}
double solve(double l,double r,double eps)
{
    double mid=l+(r-l)/2.0;
    if(fabs(simpson(l,r)-simpson(l,mid)-simpson(mid,r))<eps) return simpson(l,r);
    else return solve(l,mid,eps/2)+solve(mid,r,eps/2);
}
int main()
{
    int t;
    double l,r;

    //freopen("t.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&l,&r);
        printf("%.3lf\n",2*solve(l,r,EPS));
    }

    return 0;
}
