#include <iostream>
#include <math.h>
using namespace std;

const double esp = 1e-10;
double a,b;

double f(double x)
{
    return b * sqrt(1.0-(x*x)/(a*a));
}

double simpson(double l,double r)
{
    return (f(l)+4*f((l+r)/2.0)+f(r))/6.0*(r-l);
}

double integral(double l,double r)
{
    double mid = (l+r)/2.0;
    double res = simpson(l,r);
    if (fabs(res-simpson(l,mid)-simpson(mid,r)) < esp)
        return res;
    else
        return integral(l,mid) + integral(mid,r);
}
int main()
{
    int T;
    double l,r;
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> l >> r;
        printf("%.3lf\n",2*integral(l,r));
    }
    return 0;
}