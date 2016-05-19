#include <stdio.h>
#include <math.h>
int main()
{
    double initial, rate, target;
    int i;
    while(scanf("%lf %lf %lf", &initial, &rate, &target)!=EOF)
    {
        i = 1;
        while(initial * pow(1+rate/100, i) < target)
        {
            i++;
        }
        printf("%d\n",i);
    }
    return 0;
}
