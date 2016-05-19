#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long ll;

int t;
double v1, v2, r, d;

int main() {
    scanf("%d", &t);
    while (t--) {
    scanf("%lf%lf%lf%lf", &v1, &v2, &r, &d);
    double ti = asin(r * v1 / r / v2) * r / v1 - asin(0.0) * r / v1;
    if (ti * v2 > d) printf("Why give up treatment\n");
    else printf("Wake up to code\n");
    }
    return 0;
}