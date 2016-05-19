/**************************************************
 *        Problem:  HDU 4855 (Xi'an Invitation 2014 Problem I)
 *         Author:  clavichord93
 *          State:  Accepted
 **************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define sqr(a) ((a) * (a))
using namespace std;
const double DINF = 1e30;
const double PI = acos(-1.0);
const double EPS = 1e-13;

inline int sgn(double a) {
    return a > EPS ? 1 : (a < -EPS ? -1 : 0);
}

const int MAX_N = 205;

struct Circle {
    double x, y, r;
    void read() {
        scanf("%lf %lf %lf", &x, &y, &r);
    }
};

int n;
Circle c[MAX_N];

int cntAng;
double ang[MAX_N * 3];

double calc(double ang) {
    double A = sin(ang);
    double B = -cos(ang);
    double _A = cos(ang);
    double _B = sin(ang);
    double ret = 0;
    for (int i = 0; i < n; i++) {
        double dist = fabs(A * c[i].x + B * c[i].y);
        double tag = _A * c[i].x + _B * c[i].y;
        if (sgn(dist - c[i].r) < 0 && sgn(tag) > 0) {
            double length = 2.0 * sqrt(sqr(c[i].r) - sqr(dist));
            ret += length;
        }
    }
    return ret;
}

int main() {
    #ifdef LOCAL_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    while (scanf("%d", &n) != EOF) {
        cntAng = 0;
        ang[cntAng++] = -PI;
        ang[cntAng++] = PI;
        for (int i = 0; i < n; i++) {
            c[i].read();
            double angCenter = atan2(c[i].y, c[i].x);
            double dist = sqrt(sqr(c[i].x) + sqr(c[i].y));
            double alpha = asin(c[i].r / dist);
            double angLeft = angCenter - alpha;
            double angRight = angCenter + alpha;
            if (sgn(angLeft + PI) < 0) {
                angLeft += 2.0 * PI;
            }
            if (sgn(angRight - PI) > 0) {
                angRight -= 2.0 * PI;
            }
            ang[cntAng++] = angLeft;
            ang[cntAng++] = angCenter;
            ang[cntAng++] = angRight;
        }
        sort(ang, ang + cntAng);
        cntAng = unique(ang, ang + cntAng) - ang;
        double ans = 0;
        for (int i = 0; i < cntAng - 1; i++) {
            double l = ang[i], r = ang[i + 1];
            double res = 0;
            while (l <= r) {
                double length = (r - l) / 3;
                double x1 = l + length;
                double x2 = l + length * 2;
                double f1 = calc(x1);
                double f2 = calc(x2);
                if (sgn(f1 - f2) >= 0) {
                    res = f1;
                    r = x2 - EPS;
                }
                else {
                    res = f2;
                    l = x1 + EPS;
                }
            }
            if (sgn(ans - res) < 0) {
                ans = res;
            }
        }
        printf("%.10f\n", ans);
    }

    return 0;
}
