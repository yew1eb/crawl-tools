#define PI 3.1415927
#include<stdio.h>
int main()
{
    double r;
    while(scanf("%lf",&r)!=EOF)
       printf("%.3lf\n",4.0/3*PI*r*r*r);
    return 0;
}