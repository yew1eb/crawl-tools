/*
 * hdu1077/win.cpp
 * Created on: 2012-10-25
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
const int MAXN = 310;
const double eps = 1e-4;
typedef struct MyPoint {
    double x, y;
    MyPoint() {        x = y = 0;    }
    MyPoint(double xx, double yy) {        x = xx;        y = yy;    }
    MyPoint(const MyPoint &p1, const MyPoint &p2) {
        x = (p1.x + p2.x) / 2;
        y = (p1.y + p2.y) / 2;
    }
}MyPoint;
inline double mydistance(const MyPoint &p1, const MyPoint &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
inline MyPoint operator-(const MyPoint &p1, const MyPoint &p2) {
    return MyPoint(p1.x - p2.x, p1.y - p2.y);
}
MyPoint points[MAXN];
int N, ans;

inline void getcenter(const MyPoint &p1, const MyPoint &p2, MyPoint &c) {
    MyPoint diff = p1 - p2;
    MyPoint mid(p1, p2);
    double angle;
    double high = mydistance(p1, p2) / 2;
    high = sqrt(1 - high * high);
    if (fabs(diff.x) < eps) {
        c.x = mid.x + high;
        c.y = mid.y;
    } else {
        angle = atan(diff.y / diff.x);
        c.x = mid.x - high * sin(angle);
        c.y = mid.y + high * cos(angle);
    }
}

inline bool myjudge(const MyPoint &p1, const MyPoint &p2) {
    double dis = mydistance(p1, p2);
    return dis <= 1 + eps;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in" , "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for(int i = 0; i < N; i++) {
            scanf("%lf%lf", &points[i].x, &points[i].y);
        }
        ans = 1;
        MyPoint p;
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(mydistance(points[i], points[j]) > 2 + eps + eps) {
                    continue;
                }
                getcenter(points[i], points[j], p);
                int t = 0;
                for(int k = 0; k < N; k++) {
                    if(myjudge(p, points[k])) {
                        t++;
                    }
                }
                if(t > ans) {
                    ans = t;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}