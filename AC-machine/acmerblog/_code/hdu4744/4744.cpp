/**************************************************
 *        Problem:  HDU 4744
 *         Author:  clavichord93
 *          State:  Accepted
 **************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define sqr(a) ((a) * (a))
using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

template <class T>
inline void gmax(T &a, T b) {
    if (a < b) {
        a = b;
    }
}

template <class T>
inline void gmin(T &a, T b) {
    if (a > b) {
        a = b;
    }
}

const int MAX_N = 105;
const int MAX_E = 50005;

struct Edge {
    int dest;
    int capa;
    int cost;
    Edge *next;
    Edge *pair;
    Edge() {}
    Edge(int _dest, int _capa, int _cost, Edge *_next) : dest(_dest), capa(_capa), cost(_cost), next(_next) {}
};

Edge EdgePool[MAX_E];
Edge *EP;
Edge *e[2 * MAX_N];
int s;
int t;
int maxflow;
int mincost;
int dist[2 * MAX_N];
bool vis[2 * MAX_N];

int n;
int x[MAX_N];
int y[MAX_N];
int z[MAX_N];
int w[MAX_N];
int cost[MAX_N][MAX_N];

inline void addedge(int a, int b, int c, int d) {
    e[a] = new(EP++)Edge(b, c, d, e[a]);
    e[b] = new(EP++)Edge(a, 0, -d, e[b]);
    e[a]->pair = e[b];
    e[b]->pair = e[a];
}

int aug(int i, int delta) {
	if (i == t) {
        maxflow += delta;
		mincost += delta * dist[s];
		return delta;
	}
	vis[i] = true;
	for (Edge *j = e[i]; j; j = j->next) {
        if (!vis[j->dest] && j->capa && dist[j->dest] + j->cost == dist[i]) {
            int flow = aug(j->dest, min(j->capa, delta));
            if (flow) {
                j->capa -= flow;
                j->pair->capa += flow;
                return flow;
            }
        }
    }
	return 0;
}

bool modlabel() {
	int delta = INF;
	for (int i = s; i <= t; i++) {
        if (vis[i]) {
            for(Edge *j=e[i]; j; j = j->next) {
                if(j->capa && !vis[j->dest]) {
                    gmin(delta,dist[j->dest] + j->cost - dist[i]);
                }
            }
        }
	}
	if (delta == INF) {
        return false;
    }
	for (int i = s; i <= t; i++) {
        if (vis[i]) {
            dist[i] += delta;
            vis[i] = false;
        }
	}
	return true;
}

void costflow() {
    maxflow = 0;
    mincost = 0;
	do {
		do {
            memset(vis, 0, sizeof(vis));
		} while (aug(s, INF));
	} while (modlabel());
}

int main() {
    #ifdef LOCAL_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    while (scanf("%d", &n), n) {
        EP = EdgePool;
        memset(e, 0, sizeof(e));
        memset(dist, 0, sizeof(dist));

        int sumW = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d %d", &x[i], &y[i], &z[i], &w[i]);
            sumW += w[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                double dist = sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]));
                cost[i][j] = (int)(floor(dist) + 0.5);
            }
        }

        s = 0;
        t = n * 2 + 1;
        for (int i = 1; i <= n; i++) {
            addedge(s, 2 * i, w[i], 0);
            //addedge(2 * i - 1, 2 * i, INF, 0);
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    addedge(2 * i, 2 * j - 1, INF, cost[i][j]);
                }
            }
            addedge(2 * i - 1, t, w[i], 0);
        }

        costflow();

        if (maxflow == sumW) {
            printf("%d\n", mincost);
        }
        else {
            printf("-1\n");
        }
    }

    return 0;
}
