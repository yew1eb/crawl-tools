#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
    int i;
    double a[2], b[2];
    double x[4], y[4];

    while (scanf("%lf%lf", x, y) != EOF)
    {
        for (i = 1; i < 4; i++)
            scanf("%lf%lf", x+i, y+i);
        if (x[0] > x[1]) swap(x[0], x[1]);
        if (y[0] > y[1]) swap(y[0], y[1]);
        if (x[2] > x[3]) swap(x[2], x[3]);
        if (y[2] > y[3]) swap(y[2], y[3]);
        a[0] = x[0] > x[2] ? x[0] : x[2];
        a[1] = x[1] < x[3] ? x[1] : x[3];
        b[0] = y[0] > y[2] ? y[0] : y[2];
        b[1] = y[1] < y[3] ? y[1] : y[3];
        printf("%.2f\n", a[0]<a[1] && b[0]<b[1]? (b[1]-b[0])*(a[1]-a[0]) : 0);
    }

    return 0;
}