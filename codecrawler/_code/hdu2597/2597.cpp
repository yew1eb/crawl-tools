#include <stdio.h>
#include <math.h>

int main()
{
    double base, rate, target;
    int year;
    while (scanf("%lf %lf %lf", &base, &rate, &target) != EOF)
    {
        year=ceil(log(target / base) / log(1 + 0.01 * rate));
        printf("%d\n",year);
    }

    return 0;
}