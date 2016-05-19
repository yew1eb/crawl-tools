#include <stdio.h>
#include <math.h>

double min(double a, double b);

int main()
{
    const double pi = acos(-1);
    double h, w, r1, v1, v2;

    while (scanf("%lf %lf", &w, &h) != EOF)
    {
        if ( (h == 0) && (w == 0) )
            break;

        r1 = min(0.5 * h / (pi + 1), w / 2);
        v1 = r1 * r1 * w * pi;

        v2 = w * w * (h - (w / pi) ) / (4 * pi);

        if (v1 <= v2)
            printf("%.3lf\n",v2);
        else
            printf("%.3lf\n",v1);
    }

    return 0;
}

double min(double a, double b)
{
    if(a <= b)
        return a;
    else
        return b;
}