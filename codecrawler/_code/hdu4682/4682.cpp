#include <cstdio>
#include <cmath>
const int maxn = 1010;
const double PI = acos(-1.0);
const double eps = 1e-9;

int T, cas = 1, n;
double r, a[maxn], b[maxn], c[maxn];
double area[maxn], height[maxn];

double f(double h)
{
    double ret = 0;
    for (int i=1;i<=n;i++)
        if (h < height[i]) ret += a[i] * (1.0 - h / height[i]);
    return ret;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%lf", &n, &r);
        for (int i=1;i<=n;i++) scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
        for (int i=1;i<=n;i++)
        {
            double p = (a[i] + b[i] + c[i]) / 2;
            area[i] = sqrt(p * (p-a[i]) * (p-b[i]) * (p-c[i]));
            height[i] = area[i] * 2 / a[i];
        }
        double low = 0, high = 100000, mid;
        int tt = 60;
        while (tt--)
        {
            mid = (low + high) / 2;
            if (f(mid) <= r) high = mid;
            else low = mid;
        }
        double ans = 0, h = mid;
        for (int i=1;i<=n;i++)
            if (h < height[i]) ans += area[i] - h*a[i]*(h/height[i])/2;
        printf("Case #%d: %.3lf\n", cas++, ans);
    }
	return 0;
}
