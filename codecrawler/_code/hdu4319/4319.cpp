#include <cstdio>
#include <cassert>
#include <cmath>
#include <algorithm>
using namespace std;

typedef __int64 LL;
const int MAXN = 100010;
int a[MAXN], n;

struct Pt {int x, y;} pt[MAXN], up[2][MAXN], low[2][MAXN];
Pt merged[MAXN*2];
int stk[MAXN];

inline bool check(int x1, int y1, int x2, int y2, bool is_up) {
    if (is_up) {
        return (LL)x1 * y2 - (LL)x2 * y1 > 0;
    } else {
        return (LL)x1 * y2 - (LL)x2 * y1 < 0;
    }
}

inline Pt pt_add(const Pt &a, const Pt &b) {
    Pt tmp;
    tmp.x = a.x + b.x;
    tmp.y = a.y + b.y;
    return tmp;
}

int get_bound(Pt *pt, int len, Pt *out, bool is_up) {
    assert(len > 0);
    if (len == 1) {out[0] = pt[0]; return 1;}
    stk[0] = 0; stk[1] = 1;
    int top = 2;
    for (int i = 2 ; i < len ; ++i) {
        while (top >= 2 && check(pt[stk[top-1]].x - pt[stk[top-2]].x,
            pt[stk[top-1]].y - pt[stk[top-2]].y,
            pt[i].x - pt[stk[top-1]].x,
            pt[i].y - pt[stk[top-1]].y, is_up)) --top;
        stk[top++] = i;
    }
    for (int i = 0 ; i < top ; ++i) {
        out[i].x = pt[stk[i]].x;
        out[i].y = pt[stk[i]].y;
    }
    return top;
}

int merge_bound(Pt *a0, int len0, Pt *a1, int len1, Pt *out, bool is_up) {
    assert(len0 > 0 && len1 > 0);
    int p0 = 0, p1 = 0, p = 0;
    out[p++] = pt_add(a0[0], a1[0]);
    ++p0; ++p1;
    while (p0 < len0 || p1 < len1) {
        if (p0 == len0) {
            out[p++] = pt_add(a0[p0-1], a1[p1++]);
            continue;
        }
        if (p1 == len1) {
            out[p++] = pt_add(a0[p0++], a1[p1-1]);
            continue;
        }
        Pt tmp0 = pt_add(a0[p0-1], a1[p1-1]);
        Pt tmp1 = pt_add(a0[p0], a1[p1-1]);
        Pt tmp2 = pt_add(a0[p0-1], a1[p1]);
        if (check(tmp1.x-tmp0.x, tmp1.y-tmp0.y,
                    tmp2.x-tmp0.x, tmp2.y-tmp0.y, is_up)) {
            out[p++] = tmp2;
            ++p1;
        } else {
            out[p++] = tmp1;
            ++p0;
        }
    }
    return p;
}

void output(Pt *pt, int len, const char *str) {
    printf("%s", str);
    for (int i = 0 ; i < len ; ++i)
        printf("(%d,%d)",pt[i].x,pt[i].y);
    printf("\n");
}

double solve(int lt, int rt) {
    if (lt == rt) {
        return abs(a[lt]);
    }
    int mid = (lt + rt) / 2;
    double tmp_l = solve(lt, mid);
    double tmp_r = solve(mid+1, rt);
    double ans = max(tmp_l, tmp_r);
    int np = 0, sum = 0;
    for (int tmp = mid ; tmp >= lt ; --tmp) {
        sum += a[tmp];
        pt[np].x = mid - tmp + 1;
        pt[np].y = sum;
        ++np;
    }
    int len_up0 = get_bound(pt, np, up[0], true);
    int len_low0 = get_bound(pt, np, low[0], false);
    np = 0; sum = 0;
    for (int tmp = mid + 1 ; tmp <= rt ; ++tmp) {
        sum += a[tmp];
        pt[np].x = tmp - mid;
        pt[np].y = sum;
        ++np;
    }
    int len_up1 = get_bound(pt, np, up[1], true);
    int len_low1 = get_bound(pt, np, low[1], false);
    int len_merged0 = merge_bound(up[0], len_up0, up[1], len_up1, merged, true);
    int len_merged1 = merge_bound(low[0], len_low0, low[1], len_low1, merged+len_merged0, false);
    for (int i = 0 ; i < len_merged0 + len_merged1 ; ++i) {
        double tmp = (double)abs(merged[i].y) / sqrt(merged[i].x+0.0);
        if (tmp > ans) ans = tmp;
    }
    return ans;
}

int main() {
 //   freopen("1010.in","r",stdin);
  //  freopen("data.out","w",stdout);
    while (scanf("%d",&n) != EOF) {
        for (int i = 0 ; i < n ; ++i)
            scanf("%d",&a[i]);
        double ans = solve(0, n-1);
        printf("%.6lf\n", ans*ans);
    }
    return 0;
}