#include <stdio.h>
#include <string.h>

struct Point
{
    double x, y;
    Point(double x=0, double y=0):x(x), y(y) {}
};
typedef Point Vector;
Point xy[110];
//²æ»ýµÈÓÚÏòÁ¿AºÍB×é³ÉµÄÈý½ÇÐÎµÄÓÐÏòÃæ»ýµÄÁ½±¶¡£
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x; }
//µã - µã = ÏòÁ¿
Vector operator - (Point A, Point B) {return Vector(A.x-B.x, A.y-B.y); }
//¶à±ßÐÎµÄÓÐÏòÃæ»ý
double PloygonArea(Point* p, int n)
{
    double  area = 0;
    for(int i=1; i<n-1; i++)
        area  += Cross(p[i]-p[0], p[i+1] - p[0]);
    return area / 2;
}

int main()
{
    int n, i;
    while(scanf("%d",&n),n)
    {
        for(i=0; i<n; i++)
            scanf("%lf%lf",&xy[i].x,&xy[i].y);
        double sum = PloygonArea(xy,n);
        printf("%.1lf\n",sum);
    }
    return 0;
}






