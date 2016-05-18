#include<stdio.h>
int main()
{
    double a,b,c,t,k,x1,x2,x3,y1,y2,y3,s1,s2;
    int te;
    scanf("%d",&te);
    while(te--)
    {
       scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
       k=(y3-y2)/(x3-x2);
       t=y3-k*x3;
       a=(y2-y1)/((x1-x2)*(x1-x2));
       b=-x1*2*a;
       c=y1-a*x1*x1-b*x1;
       s1=1.0/3*a*x2*x2*x2+1.0/2*(b-k)*x2*x2+x2*(c-t);
       s2=1.0/3*a*x3*x3*x3+1.0/2*(b-k)*x3*x3+x3*(c-t);
       printf("%.2lf\n",s2-s1);
    }
    return 0;
}