#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
const int maxn = 46340;
typedef int Mat[2][2];

struct State {
    int d, p;
    State (int d = 0, int p = 0): d(d), p(p) {}
    bool operator < (const State& u) const { return d < u.d; }
};

int N, M;
Mat X, Y;
vector<State> G[maxn];

void mul(Mat a, Mat b, Mat& c) {
    Mat s;
    memset(s, 0, sizeof(s));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++)
                s[i][j] = (s[i][j] + a[i][k] * b[k][j] % M) % M;
        }
    }

    memcpy(c, s, sizeof(s));
}

void init () {
    scanf("%d%d", &N, &M);
    X[0][0] = X[1][1] = 5 % M;
    X[1][0] = 2 % M, X[0][1] = 12 % M;
    memcpy(Y, X, sizeof(X));
    for (int i = 0; i < M; i++) G[i].clear();
}

int solve () {

    int start = 0, cnt = 1;
    while (!start) {
        int a = X[0][0], b = X[1][0];
        State u = State(b, cnt);

        for (int i = 0; i < G[a].size(); i++)
            if (G[a][i].d == b)
                start = G[a][i].p;

        mul(X, X, X);
        G[a].push_back(u);
        cnt++;
    }

    cnt -= (start + 1);
    memcpy(X, Y, sizeof(Y));
    for (int i = 0; i < min(start, N); i++)
        mul(X, X, X);

    if (N > start) {
        N -= start;
        N = N % cnt;
        for (int i = 0; i < N; i++)
            mul(X, X, X);
    }

    mul(X, Y, X);
    return (2 * X[0][0] - 1 + M) % M;
}

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        init();
        printf("Case #%d: %d\n", kcas, solve());
    }
    return 0;
}