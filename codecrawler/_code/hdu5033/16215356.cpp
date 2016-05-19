#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
typedef __int64 ll;
using namespace std;

const double PI = acos(-1.0);
const int maxn = 100005;

struct Node {
    int x, h;
    bool operator <(const Node &a)const {
        return x < a.x;
    }
} node[maxn<<2], stk[maxn<<2];
double ans[maxn];
int n, q;

int check(Node &a, Node &b, Node c) {
    if (c.h <= 0)
        c.h = 0;
    return (ll)(a.h - c.h) * (c.x - b.x) >= (ll)(b.h - c.h) * (c.x - a.x);
}

double getAngle(Node a, Node b) {
    return atan((double)(b.x-a.x)/(double)(a.h));
}

void cal() {
    int head = 0;
    for (int i = 0; i < n+q; i++) {
        if (node[i].h <= 0) {
            while (head >= 2 && check(stk[head-2], stk[head-1], node[i]))
                head--;
            ans[-node[i].h] += getAngle(stk[head-1], node[i]);
        }
        else {
            while (head && stk[head-1].h <= node[i].h)
                head--;
            while (head >= 2 && check(stk[head-2], stk[head-1], node[i]))
                head--;
            stk[head++] = node[i];
        }
    }
}

int main() {
    int t, cas = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &node[i].x, &node[i].h);
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf("%d", &node[i+n].x);
            node[i+n].h = -i;
        }

        memset(ans, 0, sizeof(ans));
        sort(node, node+n+q);

        cal();

        reverse(node, node+n+q);
        for (int i = 0; i < n+q; i++)
            node[i].x = 10000000 - node[i].x;

        cal();

        printf("Case #%d:\n", cas++);
        for (int i = 0; i < q; i++)
            printf("%.10lf\n", ans[i] * 180.0 / PI);
    }
    return 0;
}