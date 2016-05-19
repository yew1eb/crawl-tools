#include<stdio.h>
#include<math.h>
#define pi 3.1415927
int main()
{
 double r,v,k;
 while(~scanf("%lf",&r)){
 v=4*pi*r*r*r/3;
 printf("%.3lf\n",v);}
 return 0;
}