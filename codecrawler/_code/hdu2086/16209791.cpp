#include <stdio.h>

int main()
{
    int n,i;
    double a0,an,c[3005];
    while(~scanf("%d",&n))
    {
        scanf("%lf%lf",&a0,&an);
        for(i = 1;i<=n;i++)
        scanf("%lf",&c[i]);
        double ans,t = 0;
        for(i = 1;i<=n;i++)
        {
            t = t+(n-i+1)*c[i];
        }
        ans = a0*(0.5*n)+an/2.0-t;
        ans/=(0.5*(n+1));
        printf("%.2lf\n",ans);
    }

    return 0;
}
