#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const static double PI = acos(-1.0);

void solve(double r,double &r1,double &r2)
{
    r1 =r/sqrt(3.0);
    r2 = r/sqrt(1.5);
}
int main()
{
    double radius;
    while(scanf("%lf",&radius)&&radius!=0)
    {
        double r1, r2;
        solve(radius,r1,r2);
        printf("%.3lf %.3lf\n",r1,r2);
    }

return 0;
}