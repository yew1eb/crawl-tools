#include <stdio.h>

int main()
{
    double r,a,b;
    int cas = 1;
    while(~scanf("%lf",&r),r)
    {
        scanf("%lf%lf",&a,&b);
        a = a/2;
        b = b/2;
        if(a*a + b*b > r*r)
        printf("Pizza %d does not fit on the table.\n",cas++);
        else
        printf("Pizza %d fits on the table.\n",cas++);
    }

    return 0;
}
