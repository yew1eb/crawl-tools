#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 2 * 1e5 + 5;
const int maxm = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int N, M, T[maxm];
ll dp[2][maxn];
vector<int> G[maxn], E[maxm];
bool flag[maxm], used[maxn];

void init () {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) G[i].clear();

    int k, x;
    for (int i = 1; i <= M; i++) {
        E[i].clear();
        scanf("%d%d", &T[i], &k);
        while (k--) {
            scanf("%d", &x);
            G[x].push_back(i);
            E[i].push_back(x);
        }
    }
}

struct Node {
    ll w;
    int u;
    Node (ll w = 0, int u = 0): w(w), u(u) {}
    bool operator < (const Node& a) const { return w > a.w; }
};

void bfs(int s, ll* d) {
    memset(flag, false, sizeof(flag));
    memset(used, false, sizeof(used));
    for (int i = 1; i <= N; i++) d[i] = inf;
    d[s] = 0;

    priority_queue<Node> que;
    que.push(Node(d[s], s));

    while (!que.empty()) {
        int u = que.top().u;
        que.pop();

        if (used[u]) continue;
        used[u] = true;

        for (int i = 0; i < G[u].size(); i++) {
            int k = G[u][i];
            if (flag[k]) continue;
            flag[k] = true;

            for (int j = 0; j < E[k].size(); j++) {
                int  v = E[k][j];
                if (d[v] > d[u] + T[k]) {
                    d[v] = d[u] + T[k];
                    que.push(Node(d[v], v));
                }
            }
        }
    }
}

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        init();
        bfs(1, dp[0]);
        bfs(N, dp[1]);

        ll ans = inf;
        vector<int> g;
        for (int i = 1; i <= N; i++) {
            ll tmp = max(dp[0][i], dp[1][i]);
            if (tmp < ans) { ans = tmp, g.clear(); }
            if (tmp == ans) g.push_back(i);
        }
        printf("Case #%d: ", kcas);
        if (ans == inf)
            printf("Evil John\n");
        else {
            printf("%lld\n", ans);
            for (int i = 0; i < g.size(); i++)
                printf("%d%c", g[i], i == g.size()-1 ? '\n' : ' ');
        }
    }
    return 0;
}