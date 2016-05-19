//   è¿å°±æ¯ä¸ä¸ªç©çé¢ç®ï¼å¨æ­¤ä¹åï¼æä»¬å¿é¡»å¾æç©çå¬å¼åç®
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