#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define clr(a, b) memset(a, b, sizeof(a))
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define inf 0x3f3f3f3f
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;



namespace acm {

#ifdef CHEN_PC
    #define P "%lld"
#else
    #define P "%I64d"
#endif


#define sqr(x) ((x)*(x))
const double eps = 1e-8;
const double pi = acos(-1.0);
const int N = 1010;
int n;

int dcmp(double x) {
    if (x < -eps) return -1;
    else return x > eps;
}

struct circle {
    double x, y, r;
    void get() {
        scanf("%lf%lf%lf", &x, &y, &r);
    }
};
circle cir[N];

struct node {
    double angle;
    int flag;
    node(){}
    node(double a, int f): angle(a), flag(f) {}
    bool operator < (const node& u) const {
        if (dcmp(angle - u.angle))
            return angle < u.angle;
        return flag > u.flag;
    }
};
node v[20000];
int cnt;

double dis(circle u, circle v) {
    return sqrt(sqr(u.x - v.x) + sqr(u.y - v.y));
}

void add(double ang1, double ang2) {
//    printf("(%g, %g)\n", ang1, ang2);
    while (ang1 < -pi) ang1 += pi * 2;
    while (ang1 > pi) ang1 -= pi * 2;
    while (ang2 < -pi) ang2 += pi * 2;
    while (ang2 > pi) ang2 -= pi * 2;
    if (dcmp(ang1 - ang2) <= 0) {
        v[cnt++] = node(ang1, 1);
        v[cnt++] = node(ang2, -1);
    } else {
        v[cnt++] = node(ang1, 1);
        v[cnt++] = node(pi, -1);
        v[cnt++] = node(-pi, 1);
        v[cnt++] = node(ang2, -1);
    }
}

void solve() {
    scanf("%d", &n);
//    puts("");
    forn (i, n) cir[i].get();
    int ans = 0;
    forn (i, n) {
        int tmp = 1;
        cnt = 0;
        forn (j, n) {
            if (i == j) continue;
            double d = dis(cir[i], cir[j]);
            if (dcmp(cir[i].r - cir[j].r - d) > 0) continue;
            if (dcmp(cir[j].r - cir[i].r - d) >= 0) {
                tmp++;
                continue;
            }
            double ang = atan2(cir[j].y - cir[i].y, cir[j].x - cir[i].x);
            if (dcmp(cir[i].r + cir[j].r - d) >= 0) {
                double delta = asin((cir[j].r - cir[i].r) / d);
                add(ang - delta, ang + delta + pi);
            } else {
                double ang1, ang2;
//                printf("\n %g %g %g\n", ang, asin((cir[j].r - cir[i].r) / d),
//                        asin((cir[j].r + cir[i].r) / d));
                ang1 = ang - asin((cir[j].r - cir[i].r) / d);
                ang2 = ang + asin((cir[j].r + cir[i].r) / d);
                add(ang1, ang2);
                ang1 = ang - asin((cir[j].r + cir[i].r) / d) + pi;
                ang2 = ang + asin((cir[j].r - cir[i].r) / d) + pi;
                add(ang1, ang2);
            }
        }
        sort(v, v + cnt);
//        puts("");
        ans = max(ans, tmp);
        forn (j, cnt) {
//            printf("%g, %d\n", v[j].angle, v[j].flag);
            tmp += v[j].flag;
            ans = max(ans, tmp);
        }
//        printf("%d %d\n", i, ans);
    }
    printf("%d\n", ans);
}

void icpc() {
    int cas;
    scanf("%d", &cas);
    for (int i = 1; i <= cas; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
}

}

int main() {
#ifdef CHEN_PC
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    acm::icpc();
    return 0;
}