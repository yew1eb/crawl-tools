#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>  
#include <iostream>  
#include <algorithm>  
#include <sstream>  
#include <stdlib.h>  
#include <string.h>  
#include <limits.h>  
#include <vector>  
#include <string>  
#include <time.h>  
#include <math.h>  
#include <iomanip>  
#include <queue>  
#include <stack>  
#include <set>  
#include <map>  
const int inf = 1e9;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) pt(x / 10);
    putchar(x % 10 + '0');
}
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
typedef pair<int, int> pii;
template <class T>
inline T gcd(T a, T b) {
    if (a > b)swap(a, b);
    while (a)b %= a, swap(a, b);return b;
}
vector<int>G[N];
class MST {
    struct Edge {
        int from, to, dis;
        Edge(int _from = 0, int _to = 0, int _dis = 0) :from(_from), to(_to), dis(_dis) {}
        bool operator < (const Edge &x) const { return dis < x.dis; }
    }edge[N << 3];
    int f[N], tot;
    int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
    bool Union(int x, int y) {
        x = find(x); y = find(y);
        if (x == y)return false;
        if (x > y)swap(x, y);
        f[x] = y;
        return true;
    }
public:
    void init(int n) {
        for (int i = 0; i <= n; i++)f[i] = i;
        tot = 0;
    }
    void add(int u, int v, int dis) {
        edge[tot++] = Edge(u, v, dis);
    }
    ll work() {//è®¡ç®æå°çææ ï¼è¿åè±è´¹  
        sort(edge, edge + tot);
        ll cost = 0;
        for (int i = 0; i < tot; i++)
            if (Union(edge[i].from, edge[i].to)) {
                cost += edge[i].dis;
                G[edge[i].from].push_back(edge[i].to);
                G[edge[i].to].push_back(edge[i].from);
            }
        return cost;
    }
}mst;
struct Point {//äºç»´å¹³é¢çç¹  
    int x, y, id;
    bool operator < (const Point&a) const {
        return x == a.x ? y < a.y : x < a.x;
    }
}p[N];
bool cmp_id(const Point&a, const Point&b) {
    return a.id < b.id;
}
class BIT {//æ ç¶æ°ç»  
    int c[N], id[N], maxn;
    int lowbit(int x) { return x&-x; }
public:
    void init(int n) {
        maxn = n + 10;
        fill(c, c + maxn + 1, inf);
        fill(id, id + maxn + 1, -1);
    }
    void updata(int x, int val, int _id) {
        while (x) {
            if (val < c[x]) { c[x] = val; id[x] = _id; }
            x -= lowbit(x);
        }
    }
    int query(int x) {
        int val = inf, _id = -1;
        while (x <= maxn) {
            if (val > c[x]) { val = c[x]; _id = id[x]; }
            x += lowbit(x);
        }
        return _id;
    }
}tree;
inline bool cmp(int *x, int *y) { return *x < *y; }
class Manhattan_MST {
    int A[N], B[N];
public:
    ll work(int l, int r) {
        for (int i = l; i <= r; i++)G[i].clear();
        mst.init(r);
        for (int dir = 1; dir <= 4; dir++) {
            if (dir % 2 == 0)for (int i = l; i <= r; i++)swap(p[i].x, p[i].y);
            else if (dir == 3)for (int i = l; i <= r; i++)p[i].y = -p[i].y;
            sort(p + l, p + r + 1);
            for (int i = l; i <= r; i++) A[i] = B[i] = p[i].y - p[i].x; //ç¦»æ£å  
            sort(B + l, B + r + 1);
            int sz = unique(B + l, B + r + 1) - B;
            //åå§ååæ ç¶æ°ç»  
            tree.init(sz);
            for (int i = r; i >= l; i--)
            {
                int pos = lower_bound(B + l, B + sz, A[i]) - B;
                int id = tree.query(pos);
                if (id != -1)
                    mst.add(p[i].id, p[id].id, abs(p[i].x - p[id].x) + abs(p[i].y - p[id].y));
                tree.updata(pos, p[i].x + p[i].y, i);
            }
        }
        for (int i = l; i <= r; i++)p[i].y = -p[i].y;
        return mst.work();
    }
}m_mst;

int n, m, a[N];
int l[N], r[N];
vector<pii>L[N], R[N];
ll ans[N], now;
int now_l, now_r;
ll cal_l(int point, int lim) {//point < lim
    int pre = point; ll hehe = 0;
    for (auto v : R[point]) {
        hehe += (ll)v.second * (min(v.first, lim) - pre + 1);
        pre = v.first + 1;
        if (pre > lim)break;
    }
    return hehe;
}
ll cal_r(int point, int lim) {//lim < point
    int pre = point; ll hehe = 0;
    for (auto v : L[point]) {
        hehe += (ll)v.second * (pre - max(v.first, lim) + 1);
        pre = v.first - 1;
        if (pre < lim)break;
    }
    return hehe;
}
void add(int x, int y) {
    if (now_l > now_r)
    {
        now = a[x];
        now_l = now_r = x;
        x++;
        if (x > y)return;
    }
    for (int i = x; i <= y; i++)
    {
        if (y < now_l)
            now += cal_l(i, now_r);
        else
            now += cal_r(i, now_l);
    }
    if (y < now_l)now_l = x;
    else now_r = y;
}
void del(int x, int y) {
    for (int i = x; i <= y; i++)
    {
        if (y < now_r)
            now -= cal_l(i, now_r);
        else
            now -= cal_r(i, now_l);
    }
    if (y < now_r)now_l = y + 1;
    else now_r = x - 1;
}
void dfs(int u, int fa) {
    if (u == fa)
        add(l[u], r[u]);
    else
    {
        if (l[u] < l[fa]) add(l[u], l[fa] - 1);
        if (r[u] > r[fa]) add(r[fa] + 1, r[u]);
        if (l[u] > l[fa]) del(l[fa], l[u] - 1);
        if (r[u] < r[fa]) del(r[u] + 1, r[fa]);
    }
    ans[u] = now;
    for (int v : G[u]) if (v != fa)dfs(v, u);
    if (fa != u)
    {
        if (l[u] > l[fa]) add(l[fa], l[u] - 1);
        if (r[u] < r[fa]) add(r[u] + 1, r[fa]);
        if (l[u] < l[fa]) del(l[u], l[fa] - 1);
        if (r[u] > r[fa]) del(r[fa] + 1, r[u]);
    }
}
void deal_vector(vector<pii>&x) {
    for (int i = 1; i < x.size(); i++)
        if (x[i].first == x[i - 1].first)x[i] = x[i - 1];
    x.erase(unique(x.begin(), x.end()), x.end());
}
void get_left_gcd() {
    vector<pii>tmp;
    for (int i = 1; i <= n; i++)
    {
        int gc = a[i];
        for (int j = tmp.size() - 1; j >= 0; j--)
            gc = tmp[j].first = gcd(tmp[j].first, gc);
        tmp.push_back({ a[i], i });
        deal_vector(tmp);
        L[i] = tmp;
        reverse(L[i].begin(), L[i].end());
        for (int j = 0; j < L[i].size(); j++)swap(L[i][j].first, L[i][j].second);
    }
}
void get_right_gcd() {
    vector<pii>tmp;
    for (int i = n; i; i--)
    {
        int gc = a[i];
        for (int j = tmp.size() - 1; j >= 0; j--)
            gc = tmp[j].first = gcd(tmp[j].first, gc);
        tmp.push_back({ a[i], i });
        deal_vector(tmp);
        R[i] = tmp;
        reverse(R[i].begin(), R[i].end());
        for (int j = 0; j < R[i].size(); j++)swap(R[i][j].first, R[i][j].second);
    }
}
int main() {
    int T; rd(T);
    while (T--) {
        rd(n);
        for (int i = 1; i <= n; i++)rd(a[i]);
        get_left_gcd();
        get_right_gcd();
        rd(m);
        for (int i = 1; i <= m; i++) {
            rd(p[i].x); rd(p[i].y); p[i].id = i;
            l[i] = p[i].x; r[i] = p[i].y;
        }
        m_mst.work(1, m);
        now_l = 1; now_r = 0;
        dfs(1, 1);
        for (int i = 1; i <= m; i++)pt(ans[i]), puts("");
    }
    return 0;
}
/*
1
9
74 93 61 58 17 35 26 65 83
4
6 6
8 9
2 8
2 7


1
6
476 961 584 469 858 930
9
5 6
4 5
4 4
2 2
1 6
4 4
2 6
4 4
4 4


1
8
855 814 483 780 214 518 462 693
8
8 8
7 8
7 7
6 6
1 1
2 3
6 8
8 8

*/