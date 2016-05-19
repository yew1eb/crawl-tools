#include <stdio.h>
#include <math.h>
const double pi = 3.1415926;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        double x1,x2,y1,y2,t,a,b,c,max;
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        a = sqrt(x1*x1+y1*y1);
        b = sqrt(x2*x2+y2*y2);
        c = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        t = (a*a+b*b-c*c)/(2.0*b*a);
        t = acos(t)*180/pi;
        while(t>180)
        t-=180;
        printf("%.2lf\n",t);
    }

    return 0;
}
