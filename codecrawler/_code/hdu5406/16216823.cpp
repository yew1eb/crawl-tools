#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define lowbit(x) ((x)&(-x))
const int maxn = 1005;

struct Item {
    int h, d;
    bool operator < (const Item& u) const { return h > u.h || (h == u.h && d < u.d); }
}P[maxn];

int N, M, idx[maxn], top, fenw[maxn][maxn];

void add (int* f, int x, int w) {
    while (x < maxn) {
        f[x] = max(f[x], w);
        x += lowbit(x);
    }
}

int find(int* f, int x) {
    int ret = 0;
    while (x) {
        ret = max(ret, f[x]);
        x -= lowbit(x);
    }
    return ret;
}

void init () {
    scanf("%d", &N);
    memset(fenw, 0, sizeof(fenw));
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &P[i].h, &P[i].d);
        idx[i] = P[i].d;
    }
    sort(P, P + N);

    top = 1;
    sort(idx, idx + N);
    for (int i = 1; i < N; i++) {
        if (idx[i] == idx[top-1]) continue;
        idx[top++] = idx[i];
    }
    for (int i = 0; i < N; i++)
        P[i].d = lower_bound(idx, idx + top, P[i].d) - idx + 1;
}

int solve () {
    int ans = 0, tmp[maxn];
    for (int i = 0; i < N; i++) {
        int v = P[i].d;
        for (int j = 0; j <= top; j++)
            tmp[j] = find(fenw[j], v + 1) + 1;
        for (int j = 0; j <= top; j++) {
            ans = max(ans, tmp[j]);
            add(fenw[j], v + 1, tmp[j]);
            add(fenw[v], j + 1, tmp[j]);
        }
    }
    return ans;
}

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        init ();
        printf("%d\n", solve());
    }
    return 0;
}
