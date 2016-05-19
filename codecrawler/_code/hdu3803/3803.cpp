#include <iostream>
using namespace std;
typedef __int64 Lint;
struct Point
{
    Lint x, y;
};
struct Fract
{
    Lint z, m;
    Lint gcd(Lint a, Lint b)
    {
        while (b)
        {
            Lint r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    void Create(Lint a, Lint b = 1)
    {
        Lint t = gcd(a, b);
        a = a / t;
        b = b / t;
        z = a; m = b;
        if (m < 0)
        { m = -m; z = -z; }
    }
    void print()
    {
        if (m == 1)
        {
            printf("%I64d", z);
        }
        else
        {
            printf("%I64d/%I64d", z, m);
        }
    }
};
int Cmp(const Lint &v)
{
    if (v > 0) return 1;
    else if (v == 0) return 0;
    else return -1;
}
Lint Det(const Point &a, const Point &b, const Point &c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool Between(const Point &a, const Point &b, const Point &c)
{
    if (a.x - b.x != 0)
    {
        Lint mi = min(a.x, b.x);
        Lint mx = max(a.x, b.x);
        return mi <= c.x && c.x <= mx;
    }
    else
    {
        Lint mi = min(a.y, b.y);
        Lint mx = max(a.y, b.y);
        return mi <= c.y && c.y <= mx;
    }
}
// 0无交点，1有一个交点，2有无数交点
// 如果有一个交点，则p为交点位置
int Cross(const Point &a, const Point &b, const Point &c, const Point &d, Fract &x, Fract &y)
{
    int k1, k2, k3, k4;
    Lint s1, s2, s3, s4;
    k1 = Cmp(s1 = Det(a, b, c));
    k2 = Cmp(s2 = Det(a, b, d));
    k3 = Cmp(s3 = Det(c, d, a));
    k4 = Cmp(s4 = Det(c, d, b));
    // 规范相交
    if ((k1 ^ k2) == -2 && (k3 ^ k4) == -2)
    {
        x.Create(c.x * s2 - d.x * s1, s2 - s1);
        y.Create(c.y * s2 - d.y * s1, s2 - s1);
        return 1;
    }
    Lint mi1, mx1, mi2, mx2;
    if (a.x - b.x != 0)
    {
        mi1 = min(a.x, b.x);
        mx1 = max(a.x, b.x);
        mi2 = min(c.x, d.x);
        mx2 = max(c.x, d.x);
    }
    else
    {
        mi1 = min(a.y, b.y);
        mx1 = max(a.y, b.y);
        mi2 = min(c.y, d.y);
        mx2 = max(c.y, d.y);
    }
    // 不规范相交
    if (k1 == 0 && k2 == 0 && k3 == 0 && k4 == 0)
    {
        // 有无数交点
        if (mi2 < mi1 && mi1 < mx2 ||
            mi2 < mx1 && mx1 < mx2 ||
            mi1 < mi2 && mi2 < mx1 ||
            mi1 < mx2 && mx2 < mx1 ||
            mi1 <= mi2 && mx2 <= mx1 ||
            mi2 <= mi1 && mx1 <= mx2)
        {
            return 2;
        }
    }
    if (k1 == 0 && Between(a, b, c))
    {
        x.Create(c.x);
        y.Create(c.y);
        return 1;
    }
    if (k2 == 0 && Between(a, b, d))
    {
        x.Create(d.x);
        y.Create(d.y);
        return 1;
    }
    if (k3 == 0 && Between(c, d, a))
    {
        x.Create(a.x);
        y.Create(a.y);
        return 1;
    }
    if (k4 == 0 && Between(c, d, b))
    {
        x.Create(b.x);
        y.Create(b.y);
        return 1;
    }
    return 0;
}
bool IsPoint(const Point &a, const Point &b)
{
    if (a.x == b.x && a.y == b.y) return true;
    else return false;
}
int main()
{
    int test, cas;
    Point a, b, c, d;
    Fract x, y;
    int res;
    scanf("%d", &test);
    for (cas = 1; cas <= test; cas++)
    {
        scanf("%I64d %I64d %I64d %I64d", &a.x, &a.y, &b.x, &b.y);
        scanf("%I64d %I64d %I64d %I64d", &c.x, &c.y, &d.x, &d.y);
        if (IsPoint(a, b) && IsPoint(c, d))
        {
            if (IsPoint(a, c))
            {
                printf("1/n");
                printf("%I64d %I64d/n", a.x, a.y);
            }
            else
            {
                printf("0/n");
            }
            continue;
        }
        if (IsPoint(a, b))
        {
            if (Cmp(Det(c, d, a)) == 0 && Between(c, d, a))
            {
                printf("1/n");
                printf("%I64d %I64d/n", a.x, a.y);
            }
            else
            {
                printf("0/n");
            }
            continue;
        }
        if (IsPoint(c, d))
        {
            if (Cmp(Det(a, b, c)) == 0 && Between(a, b, c))
            {
                printf("1/n");
                printf("%I64d %I64d/n", c.x, c.y);
            }
            else
            {
                printf("0/n");
            }
            continue;
        }
        res = Cross(a, b, c, d, x, y);
        if (res == 1)
        {
            printf("1/n");
            x.print();
            printf(" ");
            y.print();
            printf("/n");
        }
        else if (res == 0)
        {
            printf("0/n");
        }
        else
        {
            printf("INF/n");
        }
    }
    return 0;
}
 

版权声明：本文为博主原创文章，未经博主允许不得转载。

参考：http://blog.csdn.net/racebug2010/article/details/6427653
						                        





(adsbygoogle = window.adsbygoogle || []).push({});

 


window._bd_share_config={"common":{"bdSnsKey":{},"bdText":"","bdMini":"2","bdMiniList":false,"bdPic":"","bdStyle":"0","bdSize":"24"},"share":{}};with(document)0[(getElementsByTagName('head')[0]||body).appendChild(createElement('script')).src='http://bdimg.share.baidu.com/static/api/js/share.js?v=89860593.js?cdnversion='+~(-new Date()/36e5)];

					