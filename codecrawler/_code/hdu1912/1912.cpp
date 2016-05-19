#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 10005
int n;
double d, l;
struct SEG {
    double b, e;
};
SEG S[N];

int cmp(const SEG &p1, const SEG &p2) {
    if(p1.b != p2.b) return p1.b < p2.b;
    else return p1.e < p2.e;
}
int solve() {
    int i, ans = 1;
    double d2 = d * d, r,x,y;
    for (i = 0; i < n; i++) {
        scanf("%lf%lf", &x, &y);
        r = sqrt(d2 - y*y);
        S[i].b = x-r, S[i].e = x+r;

    }
    sort(S, S + n, cmp);
    double cr = S[0].e;
    for(i = 1; i < n; i++)
    {
        if(S[i].b > cr)
            cr = S[i].e, ans++;
        else if(cr > S[i].e)
            cr = S[i].e;
    }
    return ans;

}
int main() {
    while(scanf("%lf%lf%d", &l, &d, &n) != EOF)
        printf("%d\n", solve());
    return 0;
}