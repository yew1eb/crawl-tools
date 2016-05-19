#include<stdio.h>
#include<math.h>
const double PI=acos(-1.0);
int main()
{
    double d;
    int r;
    double t;
    int iCase=0;
    while(scanf("%lf%d%lf",&d,&r,&t),r)
    {
        iCase++;
        double res1=PI*d*r/(12*5280);
        double res2=res1/t*3600;
        printf("Trip #%d: %.2lf %.2lf\n",iCase,res1,res2);
    }    
    return 0;
}