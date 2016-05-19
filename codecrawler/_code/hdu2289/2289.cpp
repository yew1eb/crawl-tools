#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define PI acos(-1.0)
#define exp 1e-9
double solve(double r,double R,double h,double H)
{
    double u = h/H*(R-r) + r;
    return PI/3*(r*r+r*u+u*u)*h;
}
int main()
{
    int t;
    double r,R,H,V,mid,vv,f,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&r,&R,&H,&V);
        f=0;
        l=100;
        while(l-f>exp)
        {
            mid=(l+f)/2;
            vv=solve(r,R,mid,H);
            if(fabs(vv-V)<=exp)
                break;
            else if(vv>V)
                l=mid-exp;
            else
                f=mid+exp;
        }
        printf("%.6lf\n",mid);
    }
    return 0;
}