#include<stdio.h>
int main()
{
    double h,l,v,g=9.8;
    while(scanf("%lf%lf%lf",&h,&l,&v)!=EOF)
    {
        if(h==0&&l==0&&v==0)return 0;
        printf("%.2lf\n",(0.5*v*v/g-0.5*g*l*l/(v*v)+h));
    }
    return 0;
}