#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define exp 1e-8

int n,k;
double a[10005],sum;

int judge(double s)
{
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        cnt+=(int)(a[i]/s);
    }
    if(cnt>=k) return 1;
    return 0;
}

int main()
{
    int i;
    while(~scanf("%d%d",&n,&k),n+k)
    {
        sum = 0;
        for(i = 0; i<n; i++)
        {
            scanf("%lf",&a[i]);
            sum+=a[i];
        }
        sum = sum/k;
        double l = 0,r = sum;
        while(fabs(l-r)>exp)
        {
            double mid = (l+r)/2;
            if(judge(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%.2f\n",l);
    }

    return 0;
}
