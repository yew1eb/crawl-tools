#include <stdio.h>

int main()
{
    double sum=0.0, n, v;
    while(~scanf("%*s"))
    {
        scanf("%lf%lf",&n,&v);
        sum += n*v;
    }
    printf("%.1lf\n",sum);
    return 0;
}
