#include <stdio.h>
#include <math.h>

const double pi = acos(-1);

int main()
{
    int t, n, m, i, c;
    double angle, r, arclength[1024], circle, totalength;

    scanf("%d",&t);
    while (t--)
    {
        scanf("%d %d", &n, &m);

        angle = 2*pi/n;
        c = m / n;
        m = m % n;
        totalength = 0, circle = 0;

        for (i = 1; i <= n / 2; i++)
        {
            r = sqrt(2 - 2 * cos(i*angle) );
            arclength[i] = arclength[n-i] = angle * r;
        }
        arclength[n] = 0;
        
        for (i = 1; i <= n; i++)
            circle += arclength[i];
        for (i = 1; i <= m; i++)
            totalength += arclength[i];

        totalength += c*circle;
        printf("%.2lf\n", totalength);
    }

    return 0;
}