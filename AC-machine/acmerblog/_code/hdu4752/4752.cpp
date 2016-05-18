#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 20005;

typedef struct POINT
{
    int x;
    int y;
}Point;

int n;
Point point[maxn];
long double a, b, c, L, R;

inline long double sqr(long double x)
{
    return x * x;
}

//用于计算定积分
long double f(long double x)
{
    long double temp = sqrt( sqr(b + 2*a*x) + 1 );
    return ( (b + 2*a*x)*temp + log(b + 2*a*x + temp) ) / (a*4);
}

//计算两点之间的抛物线的长度
long double calc( long double x0, long double y0, long double x1, long double y1 )
{    
    //如果抛物线位于这条线段上方，易知不用计算
    double xx = (x0 + x1) / 2;
    if ( a * xx * xx + b * xx + c > (y0 + y1) / 2 )
        return 0;

    //更新左右端点
    //如果只有一个交点，这边显然算出来是0。
    long double l = max( L, x0 );
    long double r = min( R, x1 );

    return l < r ? f(r) - f(l) : 0;
}

int main()
{
    //固定的浮点数显示
    cout << fixed;
    //设置精度为小数点后两位
    cout.precision(2);

    while (cin >> n)
    {
        cin >> a >> b >> c >> L >> R;
        for (int i = 1; i <= n; i++ ) 
            scanf( "%d%d", &point[i].x, &point[i].y );
        point[0].x = point[n].x;
        point[0].y = point[n].y;
        long double ans = 0;
        for ( int i = 1; i <= n; i++ )
            //要计算抛物线在多边形里面的长度，线段肯定不能是垂直于x轴，
            //就算是与抛物线有交点，也只是辅助将抛物线包围进去
            if ( point[i].x != point[i-1].x )
            {
                long double x0 = point[i-1].x, y0 = point[i-1].y;
                long double x1 = point[i].x, y1 = point[i].y;
                long double k = ( y1 - y0) / ( x1 - x0 );
                long double d = y0 - k * x0;
                long double dat = sqr(b - k) - 4 * a * (c - d);
                long double length = 0;

                //确保 x0 在 x1 左边
                if ( x0 > x1 )        
                {
                    swap( x0, x1 );
                    swap( y0, y1 );
                }

                if ( dat >= 0 )
                {
                    long double x2 = ( -(b - k) + sqrt(dat) ) / (2 * a);
                    long double x3 = ( -(b - k) - sqrt(dat) ) / (2 * a);

                    //确保 x2，x3 落在 x0 与 x1 之间，并且 x2 在 x3 左边
                    if ( x2 < x0 )
                        x2 = x0;
                    if ( x2 > x1 )
                        x2 = x1;
                    if ( x3 < x0 )
                        x3 = x0;
                    if ( x3 > x1 )
                        x3 = x1;
                    if ( x2 > x3 )
                        swap(x2, x3);

                    long double y2 = k * x2 + d, y3 = k * x3 + d;
                    length += calc( x0, y0, x2, y2 );
                    length += calc( x2, y2, x3, y3 );
                    length += calc( x3, y3, x1, y1 );
                }
                //如果没有交点的话，只需要考虑抛物线是否在这个线段的上方即可
                //如果线段在上方的话，因为抛物线本来的定义域的限制，
                //或者前一条线段是垂直于x轴的，所以还是要计算的
                else
                    length += calc( x0, y0, x1, y1 );

                //因为这种求法是一段一段考虑的，然后肯定会多加了，或者多减了，
                //所以得考虑好方向，然后相应地减掉或者是加上原来多了或者是少了的抛
                //物线的长度，最后从最后一个点连到第一个点才能正好算出抛物线的长度
                if ( point[i-1].x < point[i].x )
                    ans -= length;
                else
                    ans += length;
            }
        //这种思路，如果把点给的顺序颠倒过来的话，求出来的ans是
        //原来求的ans的相反数，所以得取个绝对值。
        cout << abs(ans) << endl;
    }
    return 0;
}