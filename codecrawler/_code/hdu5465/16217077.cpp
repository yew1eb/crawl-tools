#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 505;
#define lowbit(x) ((x)&(-x))

int N, M, Q, A[maxn][maxn], fenw[maxn][maxn];

void add (int x, int y, int v) {
    for (int i = x; i <= N; i += lowbit(i)) {
        for (int j = y; j <= M; j += lowbit(j))
            fenw[i][j] ^= v;
    }
}

int query (int x, int y) {
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) {
        for (int j = y; j; j -= lowbit(j))
            ret ^= fenw[i][j];
    }
    return ret;
}

void init () {
    scanf("%d%d%d", &N, &M, &Q);
    memset(fenw, 0, sizeof(fenw));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &A[i][j]);
            add(i, j, A[i][j]);
        }
    }
}

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        init();

        int k, x1, y1, x2, y2;
        while (Q--) {
            scanf("%d", &k);
            if (k == 2) {
                scanf("%d%d%d", &x1, &y1, &k);
                add(x1, y1, A[x1][y1]^k);
                A[x1][y1] = k;
            } else {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                int ans = query(x2, y2) ^ query(x1-1, y2) ^ query(x2, y1-1) ^ query(x1-1, y1-1);
                printf("%s\n", ans ? "Yes" : "No");
            }
        }
    }
    return 0;
}