#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
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
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) pt(x / 10);
    putchar(x % 10 + '0');
}
typedef long long ll;
typedef pair<int, ll> pii;
const double eps = 1e-9;
const int N = 200000 + 10;
#define L(x) tree[x].l
#define R(x) tree[x].r
#define M(x) tree[x].ma
#define ls (id<<1)
#define rs (id<<1|1)
struct node {
    int l, r;
    int ma;
}tree[N << 2];
int a[N], p[N];
void Up(int id) {
    M(id) = max(M(ls), M(rs));
}
void build(int l, int r, int id) {
    L(id) = l; R(id) = r;
    if (l == r) { M(id) = a[l];return; }
    int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid + 1, r, rs);
    Up(id);
}
void update(int pos, int id) {
    if (L(id) == R(id))
    {
        M(id) = -1;return;
    }
    int mid = (L(id) + R(id)) >> 1;
    if (pos <= mid)update(pos, ls);
    else update(pos, rs);
    Up(id);
}
int query(int l, int r, int id) {
    if (l == L(id) && R(id) == r)return M(id);
    int mid = (L(id) + R(id)) >> 1;
    if (r <= mid)return query(l, r, ls);
    else if (mid < l)return query(l, r, rs);
    else return max(query(l, mid, ls), query(mid + 1, r, rs));
}
int n;
int use[N], num[N];
pii b[N];
int ans[N];
void getcir(int l, int r) {
    if (l > r)return;
    for (int i = l; i <= r; i++) {
        if (use[a[i]])continue;
        int to = i + 1;
        if (to > r) to = l;
        ans[a[i]] = a[to];
        use[a[i]] = 1;
        num[a[to]] = 1;
        update(i, 1);
    }
}
int getmax(int l, int r) {
    if (l > r)return -1;
    return query(l, r, 1);
}
int hehe[N];
set<int>s;
int main() {
    int T;rd(T);
    while (T--) {
        s.clear();
        s.insert(0);
        rd(n);
        for (int i = 1; i <= n; i++) {
            rd(a[i]);
            p[a[i]] = i;
            use[i] = num[i] = false;
            b[i] = { a[i], i };
            ans[i] = 0;
        }
        build(1, n, 1);
        sort(b + 1, b + 1 + n);
        int top = 0;
        for (int i = 1; i <= n; i++) {
            if (use[i])continue;
            int idx = b[i].second;
            int t[3] = { -1, -1, -1 };
            if (idx < n && !num[a[idx+1]])t[0] = a[idx + 1];
            top = -(*s.upper_bound(-idx));
            t[1] = getmax(top + 1, idx - 1);
            if (num[i]==false)t[2] = i;
            if (t[0] > max(t[1], t[2]))
            {
                ans[i] = t[0]; use[i] = 1;
                num[t[0]] = 1; 
                update(idx + 1, 1);
            }
            else if (t[1] > max(t[0], t[2]))
            {
                getcir(p[t[1]], idx);
                s.insert(-idx);
            }
            else {
                getcir(idx, idx);
                s.insert(-idx);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            pt(ans[i]);i == n ? putchar('\n') : putchar(' ');
        }
    }
    return 0;
}
/*
99
3
1 3 2
ans: 3 2 1
5
1 5 2 3 4
ans: 5 3 4 2 1
 
5
5 2 3 4 1
ans : 5 3 4 1 2
 
7
6 7 1 3 2 5 4
ans:7 5 3 4 2 6 1
 
1
8
1 3 6 4 8 7 2 5
 
1
5
3 2 4 5 1
 
*/