#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 2010;
const int maxm = 233333;
const int INF = 0x3f3f3f3f;

struct Edge{
    int v, cost;
    Edge(int vv=0,int cc=0):v(vv),cost(cc){}
};

vector<Edge> ee[maxn];

bool vis[maxn];
int dist[maxn], cnt[maxn];
void spfa(int start, int n)
{
    memset(vis, 0, sizeof vis );
    for(int i=1; i<=n; ++i) {
        dist[i] = INF;
        cnt[i] = INF;
    }
    vis[start] = true;
    dist[start] = 0;
    queue<int> que;
    que.push(start);
    cnt[start] = 0;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        vis[u] = false;
        for(int i=0; i<ee[u].size(); ++i) {
            int &v = ee[u][i].v;
            int &cost = ee[u][i].cost;
            if(dist[v]==dist[u]+cost){
                cnt[v] = min(cnt[v], cnt[u] + 1);
            }
            if(dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                cnt[v] = cnt[u] + 1;
                if(!vis[v]){
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
}

struct EDGE{
    int to, next, cap, flow;
}edge[maxm];
int tol;
int head[maxn];
void init(){
    tol = 0;
    memset(head, -1, sizeof head );
}

void addedge(int u, int v, int w, int rw=0) {
    edge[tol].to = v; edge[tol].cap = w; edge[tol].flow = 0;
    edge[tol].next = head[u]; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = rw; edge[tol].flow = 0;
    edge[tol].next = head[v]; head[v] = tol++;
}
int Q[maxn];
int dep[maxn], cur[maxn], sta[maxn];
bool bfs(int s, int t, int n)
{
    int front = 0, tail = 0;
    memset(dep, -1, sizeof(dep[0])*(n+1));
    dep[s] = 0;
    Q[tail++] = s;
    while(front<tail){
        int u = Q[front++];
        for(int i=head[u]; ~i; i=edge[i].next){
            int& v = edge[i].to;
            if(edge[i].cap > edge[i].flow && dep[v] == -1) {
                dep[v] = dep[u] + 1;
                if(v == t) return true;
                Q[tail++] = v;
            }
        }
    }
    return false;
}

int dinic(int s, int t, int n)
{
    int maxflow = 0;
    while(bfs(s, t, n)){
        for(int i=0; i<=n; ++i) cur[i] = head[i];
        int u = s, tail = 0;
        while(cur[s] != -1) {
            if(u == t){
                int tp = INF;
                for(int i=tail-1; i>=0; --i)
                    tp = min(tp, edge[sta[i]].cap-edge[sta[i]].flow);
                maxflow += tp;
                for(int i=tail-1; i>=0; --i) {
                    edge[sta[i]].flow += tp;
                    edge[sta[i]^1].flow -= tp;
                    if(edge[sta[i]].cap - edge[sta[i]].flow == 0)
                        tail = i;
                }
                u = edge[sta[tail]^1].to;
            }
            else if(cur[u]!=-1 && edge[cur[u]].cap > edge[cur[u]].flow &&
                    dep[u]+1 == dep[edge[cur[u]].to]){
                sta[tail++] = cur[u];
                u = edge[cur[u]].to;
            }
            else {
                while(u != s && cur[u] == -1)
                    u = edge[sta[--tail]^1].to;
                cur[u] = edge[cur[u]].next;
            }
        }
    }
    return maxflow;
}

void build_graph(int n)
{
    init();
    for(int u=1; u<=n; ++u) {
        for(int i=0; i<ee[u].size(); ++i) {
            int& v = ee[u][i].v;
            int& cost = ee[u][i].cost;
            if(dist[u] + cost == dist[v]) {
                addedge(u, v, 1); //ÓÐÏò±ß
            }
        }
    }
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        int a, b, l;
        for(int i=0; i<=n; ++i) ee[i].clear();
        for(int i=0; i<m; ++i) {
            scanf("%d%d%d", &a, &b, &l);
            ee[a].push_back(Edge(b,l));
            ee[b].push_back(Edge(a,l));
        }
        spfa(1, n);
        build_graph(n);
        int maxFlow = dinic(1, n, n);
        printf("%d %d\n", maxFlow, m - cnt[n]);
    }
    return 0;
}
