#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1005;

struct point {
    int id;
    ll x, y;
}p[maxn], s, e;

ll L;
int N, d[maxn];
vector<int> g[maxn];
set<pii> vis;

inline ll gcd (ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

inline bool cmp (const point& a, const point& b) {
    return a.x < b.x;
}

inline ll dis (ll x, ll y) {
    return x * x + y * y;
}

bool search (ll x, ll y) {
    ll d = gcd(x, y);
    if (d < 0)
        d = -d;

    x /= d; y /= d;
    if (vis.find(make_pair(x, y)) != vis.end())
        return true;

    vis.insert(make_pair(x, y));
    return false;
}

void addEdge (point a, point b) {
    ll d = dis(a.x - b.x, a.y - b.y);
    if (d <= L && !search(b.x - a.x, b.y - a.y)) {
        g[a.id].push_back(b.id);
        g[b.id].push_back(a.id);
        //printf("%d %d %lld %lld\n", a.id, b.id, d, L * L);
    }
}

void init () {
    scanf("%d%lld", &N, &L);
    scanf("%lld%lld%lld%lld", &p[0].x, &p[0].y, &p[1].x, &p[1].y);
    p[0].id = 0;
    p[1].id = 1;

    N += 2;
    L = L * L;

    for (int i = 0; i < N; i++)
        g[i].clear();

    for (int i = 2; i < N; i++) {
        scanf("%lld%lld", &p[i].x, &p[i].y);
        p[i].id = i;
    }

    sort(p, p + N, cmp);

    for (int i = 0; i < N; i++) {
        vis.clear();
        for (int j = i + 1; j < N; j++)
            addEdge(p[i], p[j]);
    }
}

void bfs () {
    queue<int> que;
    que.push(0);
    memset(d, -1, sizeof(d));
    d[0] = 0;

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        if (u == 1) {
            printf("%d\n", d[u]-1);
            return;
        }

        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];

            if (d[v] == -1) {
                d[v] = d[u] + 1;
                que.push(v);
            }
        }
    }
    printf("impossible\n");
}

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        init();
        bfs();
    }
    return 0;
}