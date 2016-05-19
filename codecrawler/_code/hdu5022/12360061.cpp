#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#if __cplusplus > 201103L
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#ifdef LOCAL
#define DEBUG
#endif

#define inf 0x3F3F3F3F
#define fst first
#define snd second
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int _end_ = (b), i = (a); i <= _end_; ++i)
#define ROF(i, a, b) for (int _end_ = (b), i = (a); i >= _end_; --i)

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

int64 fpm(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr(T x) {return x * x;}
template <typename T> T gcd(T x, T y) {for (T t; x; ) t = x, x = y % x, y = t; return y; }

template<class edge> struct Graph {
    vector<vector<edge> > adj;
    Graph(int n) {adj.clear(); adj.resize(n + 5);}
    Graph() {adj.clear(); }
    void resize(int n) {adj.resize(n + 5); }
    void add(int s, edge e){adj[s].push_back(e);}
    void del(int s, edge e) {adj[s].erase(find(iter(adj[s]), e)); }
    vector<edge>& operator [](int t) {return adj[t];}
};

const int LMT = 100000;

int P, g, sqrtP, decP, pp, drd[LMT];
pair<int, int> v[LMT];

int get_pr(int P) {
    int t = 0, ps[50], x = decP;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            ps[++t] = i;
            for (; x % i == 0; )
                x /= i;
        }
    if (x != 1) ps[++t] = x;
    
    for (int i = 2; ; ++i) {
        bool b = true;
        for (int j = 1; j <= t; ++j)
            if (fpm(i, (P - 1) / ps[j], P) == 1) {
                b = false;
                break;
            }
        if (b) return i;
    }
    return 0;
}

int dlog(int x) {
    for (int i = 0; i < sqrtP; ++i) {
        int y = fpm(g, P - 1 - i * sqrtP, P) * x % P; 
        pair<int, int> *it = lower_bound(v, v + sqrtP, make_pair(y, -1));
        if (it->fst == y) return i * sqrtP + it->snd;
    }
    assert(0);
}

int phi(int x) {
    int t = x, i;
    for (i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            t = t / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    if (x > 1) t = t / x * (x - 1);
    return t;
}

int solve(int m, int a, int s, int t, int p) {
    int sp = sqrt(p) + 3;
    for (int i = 0; i < sp; ++i)
        drd[i] = (int64)a * i % p;
    sort(drd, drd + sp);

    m = (m + p - s % p) % p, t -= s;
    if (t >= p) return 0;

    for (int i = 0; i < sp; ++i) {
        int mm = (m + (int64)i * a * sp) % p, cnt = 0;

        if (t >= mm) {
            cnt += (drd + sp) - lower_bound(drd, drd + sp, p - mm);
            cnt += upper_bound(drd, drd + sp, t - mm) - drd;
        } else {
            cnt += upper_bound(drd, drd + sp, t + p - mm) - lower_bound(drd, drd + sp, p - mm);
        }

        if (cnt > 0) {
            for (int k = 0; k < sp; ++k) {
                int n = i * sp + k;
                if ((m + (int64)a * n) % p <= t)
                    return n;
            }
            assert(0);
        }
    }
    return -1;
}

int main(int argc, char **argv) {
#ifdef LOCAL
    freopen("A.in" , "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int M, A, B, s, t;
    for (; scanf("%d%d%d%d%d%d", &M, &A, &B, &s, &t, &P), P; ) {
        decP = P - 1;
        g = get_pr(P);
        sqrtP = sqrt(P) + 3;
        v[0] = make_pair(1, 0);
        for (int i = 1; i < sqrtP; ++i)
            v[i] = make_pair((int64)v[i - 1].fst * g % P, i);
        sort(v, v + sqrtP);
        v[sqrtP] = make_pair(-1, -1);

        A = dlog(A), B = dlog(B), M = dlog(M);

        int r = gcd(B, decP);
        int w = gcd(A, r);
        if (M % w != 0) {
            puts("impossible");
            continue;
        }

        int y = r / w, h = (y - (M % r) / w) * fpm(A / w, phi(y) - 1, y) % y; // a = e * y + h

        int mm = (M + (int64)A * h) % decP, aa = (int64)A * y % decP, bb = B / r, pp = decP / r;
        assert(mm % r == 0 && aa % r == 0);

        mm /= r, aa /= r;
        int64 inv = fpm(bb, phi(pp) - 1, pp);
        mm = mm * inv % pp, aa = aa * inv % pp;

        int e = solve(mm, aa, s, t, pp);
        if (e < 0) {
            puts("impossible");
        } else {
            printf("%d\n", (e * y + h) % decP);
        }
    }

    return 0; 
}