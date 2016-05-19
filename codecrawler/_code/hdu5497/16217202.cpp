#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
#define lowbit(x) ((x)&(-x))

struct Fenw {
    int n, f[maxn];
    void init(int n) {
        this->n = n;
        memset(f, 0, sizeof(f));
    }

    void add(int x, int v) {
        while (x <= n) {
            f[x] += v;
            x += lowbit(x);
        }
    }

    int sum(int x) {
        int ret = 0;
        while (x) {
            ret += f[x];
            x -= lowbit(x);
        }
        return ret;
    }

    int query (int l, int r) { return sum(r) - sum(l-1); }
}P, S;

int N, M, L[maxn], R[maxn], A[maxn];
ll G;

void init () {
    G = 0;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    P.init(N+1);
    for (int i = 0; i < N; i++) {
        L[i] = P.query(A[i] + 1, N + 1);
        P.add(A[i], 1);
        G = G + L[i];
    }
    P.init(N+1);
    for (int i = N-1; i >= 0; i--) {
        R[i] = P.query(1, A[i] - 1);
        P.add(A[i], 1);
    }
}

ll solve () {
    P.init(N+1);
    S.init(N+1);

    ll sum = 0;
    for (int i = 0; i < M; i++) {
        sum += R[i];
        S.add(A[i], 1);
    }

    ll ret = sum;
    for (int i = M; i < N; i++) {
        sum += R[i] - R[i-M] - L[i-M];
        S.add(A[i-M], -1);
        S.add(A[i], 1);
        sum += S.query(1, A[i-M]-1) + P.query(A[i]+1, N+1);
        P.add(A[i-M], 1);
        ret = max(ret, sum);
    }

    //printf("%lld %lld\n", ret, G);
    return G - ret;
}

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        init ();
        printf("%lld\n", solve());
    }
    return 0;
}