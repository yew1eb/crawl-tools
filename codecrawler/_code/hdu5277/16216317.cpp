#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1010;

struct Edge {
    int u, v;
};

struct Tria {
    int a, b, c;
};

bool vis[N][N];
vector<Tria> tria;
vector<int> G[N];
vector<Edge> edge;
int n, m;

void init() {
    memset(vis, false, sizeof(vis));
    tria.clear();
    edge.clear();
    for(int i = 0; i <= n; i++) {
        G[i].clear();
    }
}

void addEdge(int u, int v) {
    G[u].push_back(v);
}

int main() {
    int x, y, u, v;
    int cnt[5], a, b, c;
    while(scanf("%d%d", &n, &m) != EOF) {
        init();

        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
        }

        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            edge.push_back((Edge){u, v});
            addEdge(u, v);
            addEdge(v, u);
            vis[u][v] = vis[v][u] = true;
        }

        for(int i = 0; i < edge.size(); i++) {
            a = edge[i].u, b = edge[i].v;
            for(int j = 0; j < G[a].size(); j++) {
                c = G[a][j];
                if(c != b && vis[b][c]) {
                    tria.push_back((Tria){a, b, c});
                }
            }
        }

        cnt[2] = m;
        cnt[3] = tria.size();
        cnt[4] = 0;

        for(int i = 0; i < tria.size(); i++) {
            a = tria[i].a , b = tria[i].b, c = tria[i].c;
            for(int j = 0; j < G[a].size(); j++) {
                int d = G[a][j];
                if(d == b || d == c) continue;
                if(vis[b][d] && vis[c][d]) {
                    cnt[4]++;
                }
            }
        }

        if(cnt[4] > 0) {
            printf("4 %d\n", cnt[4]/12);
        }else if(cnt[3] > 0) {
            printf("3 %d\n", cnt[3]/3);
        }else if(cnt[2] > 0) {
            printf("2 %d\n", cnt[2]);
        }else {
            printf("1 %d\n", n);
        }
    }
    return 0;
}
