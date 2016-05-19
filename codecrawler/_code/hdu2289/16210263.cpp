#include"stdio.h"
#include"math.h"
const double P=3.1415926535898;
double r,R,h,v;


double com(double x)
{
    double r2;
    double temp2;
    temp2=(R-r)/h;
    r2=r+temp2*x;
    return  P*(r*r+r2*r2+r*r2)*x/3;
}
int main()
{
    double INF=pow(10,-8);
    int T;
    double low,up,mid;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf",&r,&R,&h,&v);


        low=0;
        up=h;
        mid=(low+up)/2;
        while(up-low>INF)
        {
            if(com(mid)>v)    up=mid;
            else            low=mid;
            mid=(up+low)/2;
        }


        printf("%0.6lf\n",mid);
    }
    return 0;
}