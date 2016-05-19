#include <bits/stdc++.h>
using namespace std;
#define maxn 111
#define INF 1e16
#define eps 1e-10
#define find Find

struct node {
    double x, y;
}p[maxn];
int n;
int u, v;
double edge, ang; //è¾¹é¿ è§åº¦

double dis (const node &a, const node &b) {
    double xx = a.x-b.x, yy = a.y-b.y;
    return sqrt (xx*xx + yy*yy);
}

double find (int pos) { //æ¾å°æè¿çä¸¤ä¸ªç¹
    double Min = INF;
    for (int i = 1; i <= n; i++) {
        if (i == pos)
            continue;
        double d = dis (p[pos], p[i]);
        if (fabs (d-Min) <= eps) {
            v = i;
        }
        else if ((Min-d) > eps) {
            Min = d;
            u = i;
        }
    }
    return Min;
}

int main () {
    //freopen ("in", "r", stdin);
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf ("%lf%lf", &p[i].x, &p[i].y);
        }
        edge = find (1);
        double d = dis (p[u], p[v]);
        ang = acos (1.0 - d*d/(2.0*edge*edge));
        bool ok = 1;
        for (int i = 2; i <= n; i++) {
            double cur_edge = find (i);
            double d = dis (p[u], p[v]);
            double cur_ang = acos (1.0 - d*d/(2.0*cur_edge*cur_edge));
            if (fabs (cur_edge-edge) <= eps && fabs (cur_ang-ang) <= eps) {}
            else {
                ok = 0;
                break;
            }
        }
        if (!ok) {
            printf ("NO\n");
        }
        else printf ("YES\n");
    }
    return 0;
}
