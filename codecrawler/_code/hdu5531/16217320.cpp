#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

const int MAX = 1e4 + 5;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, x[MAX], y[MAX];
double d[MAX], r[MAX];

int sgn(double t)
{
    return (t > eps) - (t < -eps);
}

double f(double a, double b, double c, double t)
{
    return a*t*t + b*t + c;
}

void input()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d", &x[i], &y[i]);
}

void solve()
{
    x[n] = x[0];
    y[n] = y[0];
    for(int i = 0; i < n; i++)
        d[i] = sqrt((x[i + 1] - x[i])*(x[i + 1] - x[i]) + (y[i + 1] - y[i])*(y[i + 1] - y[i]));
    if(n&1)
    {
        double all = 0, other = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            all += d[i];
            if(i&1)
                other += d[i];
        }
        r[0] = all/2 - other;
        if(sgn(r[0]) < 0)
        {
            printf("IMPOSSIBLE\n");
            return;
        }
        ans += r[0]*r[0];
        for(int i = 1; i < n; i++)
        {
            r[i] = d[i - 1] - r[i - 1];
            if(sgn(r[i]) < 0)
            {
                printf("IMPOSSIBLE\n");
                return;
            }
            ans += r[i]*r[i];
        }
        printf("%.2lf\n", pi*ans);
        for(int i = 0; i < n; i++)
            printf("%.2lf\n", r[i]);
    }
    else
    {
        double temp = 0;
        for(int i = 0; i < n; i += 2)
            temp += d[i] - d[i + 1];
        if(sgn(temp) != 0)
        {
            printf("IMPOSSIBLE\n");
            return;
        }
        int k = 1;
        double b = 0, L = 0, R = d[0];
        double A = 1, B = 0, C = 0;
        for(int i = 1; i < n; i++)
        {
            k = -k;
            b = -b + d[i - 1];
            if(k == 1)
                L = max(L, -b);
            else
                R = min(R, b);
            A++;
            B += 2*k*b;
            C += b*b;
        }
        if(sgn(L - R) > 0)
        {
            printf("IMPOSSIBLE\n");
            return;
        }
        double mid = -B/(2*A), ans;
        if(sgn(L - mid) >= 0)
        {
            ans = f(A, B, C, L);
            r[0] = L;
        }
        if(sgn(R - mid) <= 0)
        {
            ans = f(A, B, C, R);
            r[0] = R;
        }
        if(sgn(mid - L) >= 0 && sgn(mid - R) <= 0)
        {
            ans = f(A, B, C, mid);
            r[0] = mid;
        }
        printf("%.2lf\n", pi*ans);
        for(int i = 0; i < n; i++)
        {
            if(i)
                r[i] = d[i - 1] - r[i - 1];
            printf("%.2lf\n", r[i]);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        input();
        solve();
    }
}
