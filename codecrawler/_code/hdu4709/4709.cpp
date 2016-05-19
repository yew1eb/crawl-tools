#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct point {
    double x, y;
    point(double x=0, double y=0):x(x),y(y) {}
};
point operator - (point A, point B) {
    return point(A.x-B.x, A.y-B.y);
}
double Cross(point A, point B) {
    return A.x*B.y - A.y*B.x;
}
int n;
vector<point> v;
double area(point a, point b, point c) {
    double mid = Cross(b-a, c-a);
    mid = mid/2.0;
    return fabs(mid);
}
double work() {
    int len = v.size();
    double ans = 999999999;
    double tmp = ans;
    for(int i = 0; i < len; i++) {
        for(int j = i+1; j < len; j++) {
            for(int k = j+1; k < len; k++) {
                if(i!=j && i!=k && j!=k) {
                    double mid = area(v[i], v[j], v[k]);
                    if(mid > 0) {   // WA.
                        ans = min(ans, mid);
                    }
                }
            }
        }
    }
    if(ans==tmp) return 0;
    else return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    point t;
    while(T--) {
        scanf("%d", &n);
        v.clear();
        for(int i = 0; i < n; i++) {
            scanf("%lf%lf", &t.x, &t.y);
            v.push_back(t);
        }
        double res = work();
        if(res+0.005<0.01) printf("Impossible\n");
        else printf("%.2lf\n", res);
    }
    return 0;
}