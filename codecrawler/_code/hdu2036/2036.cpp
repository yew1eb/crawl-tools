#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 110;

struct Point{
    double x, y;
    Point(double x = 0, double y = 0):x(x), y(y) { }
};

typedef Point Vector;
Vector v[maxn];

double Cross(Vector A, Vector B) {
    return A.x * B.y - A.y * B.x;
}

Vector operator - (Point A, Point B) {
    return Vector(A.x-B.x, A.y-B.y);
}

double getArea(Point* p, int n) {
    double area = 0;
    for(int i = 1; i < n-1; i++) {
        area += Cross(p[i]-p[0], p[i+1]-p[0]);
    }
    return area/2;
}

int main()
{
    int n;
    int x, y;
    while(scanf("%d", &n)!=EOF) {
        if(n==0) break;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &x, &y);
            v[i] = Point(x, y);
        }
        double res = getArea(v, n);
        printf("%.1lf\n", res);
    }
    return 0;
}