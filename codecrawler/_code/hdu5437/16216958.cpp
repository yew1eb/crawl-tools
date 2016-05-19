#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 150005;
const int maxm = 205;

struct State {
    int w, id;
    State(int w = 0, int id = 0): w(w), id(id) {}
    bool operator < (const State& u) const {
        if (w != u.w) return w < u.w;
        return id > u.id;
    }
};

int N, M, Q, C[maxn], W[maxn], I[maxn];
char name[maxn][maxm];

void init () {
    scanf("%d%d%d", &N, &M, &Q);
    memset(C, 0, sizeof(C));
    for (int i = 1; i <= N; i++)
        scanf("%s%d", name[i], &W[i]);
    int u, v;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &u, &v);
        C[u] = v;
    }
}

void solve () {
    priority_queue<State> que;

    int p = 0, n = 0;
    for (int i = 1; i <= N; i++) {
        que.push(State(W[i], i));
        n = C[i];

        while (!que.empty() && n) {
            I[++p] = que.top().id;
            que.pop();
            n--;
        }
    }

    while (!que.empty()) {
        I[++p] = que.top().id;
        que.pop();
    }

    while (p != N);
}

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        init();
        solve();

        int x;
        for (int i = 1; i <= Q; i++) {
            scanf("%d", &x);
            printf("%s%c", name[I[x]], i == Q ? '\n' : ' ');
        }
    }
    return 0;
}
