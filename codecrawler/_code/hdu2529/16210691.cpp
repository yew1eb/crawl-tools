#include<stdio.h>
#define  g 9.8
int main()
{
    double  h,l,v;
    while(scanf("%lf %lf %lf",&h,&l,&v)!=EOF)
    {
        if(!h&&!l&&!v) break;
        double a,b,c;
        a=c=-9.8*l*l/(2*v*v);
        b=l;
    //    printf("%lf %lf %lf\n",a,b,c);
        double ans=(4*a*c-b*b)/(4*a);
        ans+=h;
        printf("%.2lf\n",ans);
    }
    return 0;
}