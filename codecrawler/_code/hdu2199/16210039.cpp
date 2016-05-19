/*
 * hdu-2199 can you solve the equatino
 * mike-w
 * 2012-4-17
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define EPS (1e-6)
#define nDISP_X1_X2

const int co[10]={8,7,2,3,6};

double foo(double x)
{
    double x0=co[0];
    int i;
    for(i=0;i<4;i++)
        x0=x*x0+co[i+1];
    return x0;
}

double solve(double Y)
{
    double x1=0.0, x2=100.0, mid;
    double y1=foo(x1), y2=foo(x2);
    while(fabs(y1-y2)>EPS)
    {
#ifdef DISP_X1_X2
        printf("x1,x2 = %lf,%lf\n",x1,x2);
        printf("y1,y2 = %lf,%lf\n",y1,y2);
#endif
        mid=(x1+x2)/2;
        if(foo(mid)>Y)
            y2=foo(x2=mid);
        else
            y1=foo(x1=mid);
    }
    return x1;
}

int main(void)
{
    int T;
    double min_v=(double)foo(0);
    double max_v=(double)foo(100);
    double Y;
    scanf("%d",&T);
    while(T-->0)
    {
        scanf("%lf",&Y);
        if(Y>max_v || Y<min_v)
            printf("No solution!\n");
        else
            printf("%.4lf\n",solve(Y));
    }
    return 0;
}

        

