#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

double cal(double x)
{
    return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double n;
        scanf("%lf",&n);
        if(cal(0)>n || cal(100)<n)
        {
            printf("No solution!\n");
            continue;
        }
        double l = 0.0,r = 100.0;
        double mid = (l+r)/2;
        while(fabs(cal(mid)-n)>1e-5)
        {
            if(cal(mid)>n)
                r = mid-1;
            else
                l = mid+1;
            mid = (l+r)/2;
        }
        printf("%.4f\n",mid);
    }

    return 0;
}
