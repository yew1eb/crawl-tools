#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
#define lowbit(x) ((x)&(-x))

struct Point {
    int x, y, z;
    ll w;
    Point(int x = 0, int y = 0, int z = 0, ll w = 0): x(x), y(y), z(z), w(w) {}
    bool operator < (const Point& u) const { 
        if (x != u.x) return x < u.x;
        if (y != u.y) return y < u.y;
        return z < u.z;
    }
    bool operator == (const Point& u) const { return !((*this)<u || u<(*this)); }
};

int N, M, T[maxn], C[maxn];
Point P[maxn];

void init () {
    scanf("%d%d", &N, &M);
    memset(T, 0, sizeof(T));

    int a, b, c;
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &a, &b);
        if (a > T[b]) { T[b] = a, C[b] = 0; }
        if (a == T[b]) C[b]++;
    }

    int n = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (T[c])
            P[n++] = Point(T[c], a, b, C[c]);
    }

    sort(P, P + n);
    N = 0;
    for (int i = 1; i < n; i++) {
        if (P[i] == P[N]) P[N].w += P[i].w;
        else P[++N] = P[i];
    }
}

ll fenw[1005][1005];

void add(int x, int y, ll v) {
    for (int i = x; i <= 1000; i += lowbit(i)) {
        for (int j = y; j <= 1000; j += lowbit(j)) 
            fenw[i][j] += v;
    }
}

ll sum(int x, int y) {
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) {
        for (int j = y; j; j -= lowbit(j))
            ret += fenw[i][j];
    }
    return ret;
}

ll query(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1);
}

ll solve () {
    ll ans = 0;
    memset(fenw, 0, sizeof(fenw));

    for (int i = N; i >= 0; i--) {
        if (!query(P[i].y, P[i].z, 1000, 1000))
            ans += P[i].w;
        add(P[i].y, P[i].z, 1);
    }
    return ans;
}

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        init();
        printf("Case #%d: %lld\n", kcas, solve());
    }
    return 0;
}