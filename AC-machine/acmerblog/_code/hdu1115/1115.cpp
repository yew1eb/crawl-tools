/*
摘自：KIDxの博客 
求多边形重心的题目大致有这么几种： 
1、质量集中在顶点上 
    n个顶点坐标为(xi,yi)，质量为mi，则重心 
　　X = ∑( xi×mi ) / ∑mi 
　　Y = ∑( yi×mi ) / ∑mi 
　　特殊地，若每个点的质量相同，则 
　　X = ∑xi / n 
　　Y = ∑yi / n 
2、质量分布均匀 
　　特殊地，质量均匀的三角形重心： 
　　X = ( x0 + x1 + x2 ) / 3 
　　Y = ( y0 + y1 + y2 ) / 3 
3、质量分布不均匀 
    只能用函数多重积分来算，不太会 
这题的做法： 
将n边形分成多个三角形，分别求出重心坐标以及质量m【因为质量分布均匀，所以可以设密度为1，则面积就是质量】 
因为质量都集中在重心 
所以把所有求出来的重心按逆时针连接起来又是一个多边形 
但是这个多边形的质量集中在顶点上 
所以可以利用上面公式进行计算 
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 1000000;

struct point {
    double x;
    double y;
}p[N], g;

double crossProd(point A, point B, point C) {
    return (B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x);
}

void compGravity(int n) {//求重心 
    point tmp;
    double sumArea, area;
    sumArea = 0;
    g.x = g.y = 0;
    for (int i=2; i<n; ++i) {
        area = crossProd(p[0], p[i-1], p[i]);
        sumArea += area;
        tmp.x = p[0].x + p[i-1].x + p[i].x;
        tmp.y = p[0].y + p[i-1].y + p[i].y;
        g.x += tmp.x * area;
        g.y += tmp.y * area;
    }
    g.x /= (sumArea * 3.0);
    g.y /= (sumArea * 3.0);
}

int main() {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n;
        scanf ("%d", &n);//顶点以逆时针方向给出 
        for (int i=0; i<n; ++i) scanf ("%lf%lf", &p[i].x, &p[i].y);
        compGravity(n);
        printf ("%.2lf %.2lf\n", g.x, g.y);
    }
    return 0;
}