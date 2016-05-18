#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
double PI = acos(-1);
double Min(double a, double b)
{
    return a < b ? a : b;
}
double Max(double a, double b)
{
    return a > b ? a : b;
}
int main()
{
    double w, h, r, ans1, ans2, ans;
    while (scanf("%lf%lf", &w, &h) != EOF && w &&h)
    {
        r = Min(w / 2.0, h /(2.0 * PI + 2.0));//以w为圆柱的高
        ans1 = PI * r * r * w;
        r = Min(w / (2.0 * PI), h / 3.0);
        ans2 = PI * r * r * (h - 2.0 * r);//以h-2r为圆柱的高
        ans = Max(ans1, ans2);
        printf("%.3lf\n", ans);
    }
    return 0;
}