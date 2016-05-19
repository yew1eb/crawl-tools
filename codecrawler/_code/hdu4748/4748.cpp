#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 105;
struct point{
    int x, y;
};
point p[maxn];
int n;
int x_multi(const point p1, const point p2)
{
    return (p1.x * p2.y - p2.x * p1.y);
}
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int t;
    scanf("%d", &t);
    int kase = 0;
    while (t--)
    {
        scanf("%d", &n);
        p[0].x = p[0].y = 0;
        int t1, t2;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &t1, &t2);
            p[i].x = p[i - 1].x + t1;
            p[i].y = p[i - 1].y + t2;
        }
        int area = 0;
        int outside = 0;
        for (int i = 1; i < n; i++)
        {
            area += x_multi(p[i], p[i + 1]);
            outside += gcd(abs(p[i].x - p[i + 1].x), abs(p[i].y - p[i + 1].y));
        }
        area += x_multi(p[n], p[1]);
        outside += gcd(abs(p[n].x - p[1].x), abs(p[n].y - p[1].y));
        if (area < 0)
            area = -area;
        int inside = area + 2 - outside;
        inside /= 2;
        printf("Scenario #%d:\n", ++kase);
        if (area % 2 == 0)//如果在边界上的定点个数为偶数，面积就是整数
        {
            printf("%d %d %d.0\n\n", inside, outside, area / 2);
        }
        else//反之就是小数
            printf("%d %d %d.5\n\n", inside, outside, area / 2);
    }

    return 0;
}