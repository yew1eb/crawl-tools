#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int N, D[maxn];
vector<int> G[maxn];

void init () {
    for (int i = 1; i <= N; i++) G[i].clear();

    int t;
    for (int i = 2; i <= N; i++) {
        scanf("%d", &t);
        G[t].push_back(i);
    }

    queue<int> Q;
    D[1] = 0;
    Q.push(1);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            D[v] = D[u] + 1;
            Q.push(v);
        }
    }
    sort(D + 1, D + 1 + N);
}

int main () {
    while (scanf("%d", &N) == 1) {
        init ();

        double ans = 0;
        for (int i = 0; i < N && i < 100; i++) {
            int u = N - i;
            double w = 0;
            for (int j = N; j > u; j--)
                w += 1.0 * (D[u] + 1) * (D[j] + 1) / (D[u] + D[j] + 2);
            double t = pow(2, N-u+1) - (N+1) / pow(2, u-1);
            ans += w / t;
        }
        printf("%.6lf\n", ans);
    }
    return 0;
}
