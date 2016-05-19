#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    double a,b,c,d,q,p,x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        x=(a+c)/2.0;
        y=(b+d)/2.0;
        q=sqrt(x*x+y*y+a*a+b*b-2*a*x-2*b*y);
        p=sqrt(x*x+y*y+c*c+d*d-2*c*x-2*d*y);
        printf("%.1lf\n",q+p);
    }
    return 0;
}