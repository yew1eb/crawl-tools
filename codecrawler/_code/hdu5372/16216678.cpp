#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <map>
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
typedef pair<int, int> pii;
typedef long long ll;
const int N = 450007;
struct Tree {
    int c[N], maxn;
    void init(int n) { maxn = n; for (int i = 0; i <= n; i++)c[i] = 0; }
    int lowbit(int x) { return x&-x; }
    int sum(int x) {
        int ans = 0;
        while (x)ans += c[x], x -= lowbit(x);
        return ans;
    }
    void update(int pos, int val) {
        while (pos <= maxn)c[pos] += val, pos += lowbit(pos);
    }
}A, B;
int n;
set<pii> s;
int op[N], l[N], r[N];
pii a[N];
vector<int>G;
int main() {
    int cas = 0;
    while (cin>>n) {
        G.clear();
        int top = 0;
        for (int i = 1; i <= n; i++) {
            rd(op[i]), rd(l[i]);
            if (op[i] == 0)
            {
                G.push_back(l[i]);
                r[i] = l[i] + (++top);
                G.push_back(r[i]);
            }
        }
        printf("Case #%d:\n", ++cas);
        sort(G.begin(), G.end()); G.erase(unique(G.begin(), G.end()), G.end());
        top = 0;
        for (int i = 1; i <= n; i++)
            if (op[i] == 0) {
                l[i] = lower_bound(G.begin(), G.end(), l[i]) - G.begin() + 1;
                r[i] = lower_bound(G.begin(), G.end(), r[i]) - G.begin() + 1;
                a[++top] = { l[i], r[i] };
            }
        A.init(G.size()); B.init(G.size());
        int all = 0;
        for (int i = 1; i <= n; i++)
        {
            if (op[i] == 0)
            {
                int ans = B.sum(r[i]);
                ans -= A.sum(l[i]-1);
                pt(ans); putchar('\n');
                A.update(l[i], 1);
                B.update(r[i], 1);
                all++;
            }
            else {
                A.update(a[l[i]].first, -1);
                B.update(a[l[i]].second, -1);
                all--;
            }
        }
    }
    return 0;
}
/*
99
7
1 2 2 1 3 !1 2
/*
1
????0
1 8 3 7 2
*/