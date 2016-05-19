#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100010;
const LL INF = 0x3f3f3f3f3f3f3f3f;
vector<int> Set[N];
vector<int> Belong[N];

struct Node {
    LL d;
    int u;
    Node() {}
    Node(LL d, int u): d(d), u(u) {}
    bool operator < (const Node &a) const{
        return d > a.d;
    }
};

int n, m, cas = 1;
int num[N];
bool visNode[N], used[N];
LL d1[N], d2[N], dis[N];

void init() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        Belong[i].clear();
    for (int i = 0; i < m; i++)
        Set[i].clear();

    int t;
    for (int i = 0; i < m; i++) {
        scanf("%lld%d", &dis[i], &num[i]);
        for (int j = 0; j < num[i]; j++) {
            scanf("%d", &t);
            Set[i].push_back(t);
            Belong[t].push_back(i);
        }
    }
}

void Dijkstra(int s, LL *d) {
    priority_queue<Node> Q;
    for (int i = 1; i <= n; i++) d[i] = INF;
    d[s] = 0;
    memset(visNode, 0, sizeof(visNode));    
    memset(used, 0, sizeof(used));
    Q.push(Node(0, s));

    while (!Q.empty()) {
        Node x = Q.top(); Q.pop();
        int u = x.u;
        if (visNode[u]) continue;
        visNode[u] = true;

        for (int i = 0; i < Belong[u].size(); i++) {
            int v = Belong[u][i];
            if (used[v]) continue;
            used[v] = true;
            for (int j = 0; j < num[v]; j++) {
                int vv = Set[v][j];
                if (vv == u) continue;
                if (d[vv] > d[u] + dis[v]) {
                    d[vv] = d[u] + dis[v];
                    Q.push(Node(d[vv], vv));
                }
            }
        }
    }
}

void solve() {
    Dijkstra(1, d1);
    Dijkstra(n, d2);

    LL ans = INF;
    for (int i = 1; i <= n; i++)
        ans = min(ans, max(d1[i], d2[i]));

    if (ans == INF) printf("Case #%d: Evil John\n", cas++);
    else {
        printf("Case #%d: %lld\n", cas++, ans);
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (ans == max(d1[i], d2[i]))  {
                if (flag) printf(" ");
                printf("%d", i);
                flag = true;
            }
        }
        printf("\n");
    }
}

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        init();
        solve();
    }
    return 0;
}
