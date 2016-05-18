//   这就是一个物理题目，在此之前，我们必须得把物理公式化简
#include<stdio.h>
int main()
{
    double h,l,v,g=9.8;
    while(scanf("%lf%lf%lf",&h,&l,&v)!=EOF && h+l+v!=0)
    {
           h+=0.5*v*v/g-0.5*g*l*l/(v*v);
           printf("%.2lf\n",h);
    }
    return 0;
}