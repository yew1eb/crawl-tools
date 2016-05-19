#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

typedef long long LL;
const int INF = 100000000;
const int MOD = 1e9 + 7;
const int N = 2000 + 10;
const int MAXM = 120000 + 10;

int n, m;

struct Node {
    int from, to, next;
    int cap;
} edge[MAXM];

int tol;
int head[N];
int dep[N];
int gap[N]; 

void init() {
    tol = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int u, int v, int w) {
    edge[tol].from = u;
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].from = v;
    edge[tol].to = u;
    edge[tol].cap = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}
void BFS(int start, int end) {
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    gap[0] = 1;
    int que[N];
    int front, rear;
    front = rear = 0;
    dep[end] = 0;
    que[rear++] = end;
    while(front != rear) {
        int u = que[front++];
        if(front == N)front = 0;
        for(int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if(dep[v] != -1)continue;
            que[rear++] = v;
            if(rear == N)rear = 0;
            dep[v] = dep[u] + 1;
            ++gap[dep[v]];
        }
    }
}

int SAP(int start, int end) {
    int res = 0;
    BFS(start, end);
    int cur[N];
    int S[N];
    int top = 0;
    memcpy(cur, head, sizeof(head));
    int u = start;
    int i;
    while(dep[start] < n) {
        if(u == end) {
            int temp = INF;
            int inser;
            for(i = 0; i < top; i++)
                if(temp > edge[S[i]].cap) {
                    temp = edge[S[i]].cap;
                    inser = i;
                }
            for(i = 0; i < top; i++) {
                edge[S[i]].cap -= temp;
                edge[S[i] ^ 1].cap += temp;
            }
            res += temp;
            top = inser;
            u = edge[S[top]].from;
        }
        if(u != end && gap[dep[u] - 1] == 0) //åºç°æ­å±ï¼æ å¢å¹¿è·¯
            break;
        for(i = cur[u]; i != -1; i = edge[i].next)
            if(edge[i].cap != 0 && dep[u] == dep[edge[i].to] + 1)
                break;
        if(i != -1) {
            cur[u] = i;
            S[top++] = i;
            u = edge[i].to;
        } else {
            int min = n;
            for(i = head[u]; i != -1; i = edge[i].next) {
                if(edge[i].cap == 0)continue;
                if(min > dep[edge[i].to]) {
                    min = dep[edge[i].to];
                    cur[u] = i;
                }
            }
            --gap[dep[u]];
            dep[u] = min + 1;
            ++gap[dep[u]];
            if(u != start)u = edge[S[--top]].from;
        }
    }
    return res;
}

struct Edge {
    int v, w;
    Edge(int v, int w): v(v), w(w) {}
};

vector<Edge> G[N];
int dis[N], cnt[N];
bool vis[N];

void Dijkstra(int s, int dist[]) {
    priority_queue<pair<int, int> > Q;

    for(int i = 0; i < n; i++)
        dist[i] = INF, cnt[i] = INF;
    memset(vis, 0, sizeof(vis));

    Q.push(make_pair(0, s));
    dist[s] = 0;
    cnt[s] = 0;

    while(!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        if(vis[u]) continue ;
        vis[u] = 1;
        for(int i = 0; i < G[u].size(); i++) {
            Edge& e = G[u][i];
            if(dist[u] + e.w < dist[e.v]) {
                dist[e.v] = dist[u] + e.w;
                Q.push(make_pair(-dist[e.v], e.v)); // é»è®¤å¤§çåç´ ä¼åçº§é«ï¼æä»¥è¦åæå°å°±å è´å·
            }
        }
    }
}
int minEdges() {
    queue<int> Q;
    Q.push(0);
    for(int i = 0; i < n; i++) cnt[i] = INF;
    cnt[0] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if(u == n - 1) return cnt[u];
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].v, w = G[u][i].w;
            if(dis[u] + w != dis[v]) continue;
            if(cnt[u] + 1 < cnt[v]) {
                cnt[v] = cnt[u] + 1;
                Q.push(v);
            }
        }
    }
}

int main() {
#ifdef Tally_Ho
    freopen("in.txt", "r", stdin);
#endif // Tally_Ho
    while(scanf("%d%d", &n, &m) != EOF) {
        int x, y, t;
        for(int i = 0; i < n; i++) {
            G[i].clear();
        }
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &x, &y, &t);
            x--, y--;
            G[x].push_back(Edge(y, t));
            G[y].push_back(Edge(x, t));
        }

        Dijkstra(0, dis);

        init();
        for(int u = 0; u < n; u++) {
            for(int i = 0; i < G[u].size(); i++) {
                int v = G[u][i].v, w = G[u][i].w;
                if(dis[u] + w == dis[v]) {
                    addedge(u, v, 1);
                }
            }
        }

        printf("%d %d\n", SAP(0, n - 1), m - minEdges());
    }
    return 0;
}
