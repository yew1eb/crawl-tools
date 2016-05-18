/*
*  题意：判断点在多边形内
*  判点在任意多边形内,顶点按顺时针或逆时针给出
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 100;
const int offset = 1000;   //offset为多边形坐标上限
const double eps = 1e-8;

struct point {
    double x;
    double y;
}p[N], p1, p2;

bool isZero(double x) {//判断x是否接近0 
    return (x > 0 ? x : -x) < eps; 
}

double crossProd(point A, point B, point C) {
    return (B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x);
}

int inPolygon(int n) {
    int count, i = 0;
    p[n] = p[0];
    while (i < n) {
        p2.x = rand() + offset;  //随机取一个足够远的点p2 
        p2.y = rand() + offset;  //以p1为起点p2为终点做射线L 
        for (i=count=0; i<n; ++i) {//依次对多边形的每条边进行考察 
            if (isZero(crossProd(p1,p[i],p[i+1]))&&
            (p[i].x-p1.x)*(p[i+1].x-p1.x)<eps&&(p[i].y-p1.y)*(p[i+1].y-p1.y)<eps)
                return true;//点p1在边上,返回点p1在边上的信息 
            else if (isZero(crossProd(p1, p2, p[i]))) break;//点p[i]在射线p1p2上，停止本循环，另取p2 
            else if (crossProd(p[i], p[i+1], p1)*crossProd(p[i], p2, p[i+1])>eps &&//射线与边相交，统计交点数 
                     crossProd(p1, p2, p[i])*crossProd(p1, p[i+1], p2)>eps)  ++count;
        }
    }
    return count & 1;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i=0; i<n; ++i) scanf ("%lf%lf", &p[i].x, &p[i].y);
        int m;
        scanf ("%d", &m);
        while (m--) {
            scanf ("%lf%lf", &p1.x, &p1.y);
            if (inPolygon(n)) printf ("Yes\n");
            else printf ("No\n");
        }
    }
    return 0;
}