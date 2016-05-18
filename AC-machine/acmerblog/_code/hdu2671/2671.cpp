/*
*  题目所求：在直线上找一点P，使其与其它（A,B）两点组成的距离最短 
*  点A跟点B与直线的位置情况四种：
*  1.两点在直线的同侧（两点都不在直线上） 
*  2.两点在直线的异侧（两点都不在直线上） 
*  3.其中一点在直线上
*  4.两点都在直线上
*  auther:Try86 
*/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

struct point {//点结构 
    double x;
    double y;
}A, B, C;

struct segment {//线段结构 
    point s;
    point e;
}seg;

struct line {//直线结构，标准式 
    double a;
    double b;
    double c;
}l;

double k;

double dis(point A, point B) {
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

int segXLine(line l, segment seg) {//判断线段是否跟直线相交 
    if ((l.a*seg.s.x+l.b*seg.s.y+l.c)*(l.a*seg.e.x+l.b*seg.e.y+l.c)<=0) return 1;
    return 0;
}

double solve() {
    point D;
    double ans = 0; 
    l.a = k;     //直线标准式 
    l.b = -1;
    l.c = C.y - k * C.x;
    seg.s = A;  //线段 
    seg.e = B;
    if (segXLine(l, seg)) ans = dis(A, B);//相交，则直接求两点距离即可 
    else {
        D.x = ((l.b*l.b-l.a*l.a)*A.x - 2*l.a*l.b*A.y - 2*l.a*l.c) / (l.a*l.a+l.b*l.b);//求点A关于直线的对称点 
        D.y = ((l.a*l.a-l.b*l.b)*A.y - 2*l.a*l.b*A.x - 2*l.b*l.c) / (l.a*l.a+l.b*l.b);
        ans = dis(B, D);//所求 
    }
    return ans;
}
 
int main() {
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%lf", &k);
        scanf ("%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
        double ans = solve();
        printf ("%.2lf\n", ans);
    }
    return 0;
}