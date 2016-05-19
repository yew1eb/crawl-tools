#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define FIN freopen("input.txt","r",stdin)
#define FOUT freopen("output.txt","w+",stdout)

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 1e3 + 5;
const int MM = 2e5 + 5;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, next, cap, flow, cost;
    Edge() {}
    Edge(int _to, int _next, int _cap, int _flow, int _cost) {
        to = _to; next = _next; cap = _cap; flow = _flow; cost = _cost;
    }
} E[MM];

int Head[MX], tol;
int pre[MX]; //å¨å­åé©±é¡¶ç¹
int dis[MX]; //å¨å­å°æºç¹sçè·ç¦»
bool vis[MX];
int N;//èç¹æ»ä¸ªæ°ï¼èç¹ç¼å·ä»0~N-1

void init(int n) {
    tol = 0;
    N = n + 2;
    memset(Head, -1, sizeof(Head));
}
void edge_add(int u, int v, int cap, int cost) {
    E[tol] = Edge(v, Head[u], cap, 0, cost);
    Head[u] = tol++;

    E[tol] = Edge(u, Head[v], 0, 0, -cost);
    Head[v] = tol++;
}
bool spfa(int s, int t) {
    queue<int>q;
    for (int i = 0; i < N; i++) {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = Head[u]; i != -1; i = E[i].next) {
            int v = E[i].to;
            if (E[i].cap > E[i].flow && dis[v] > dis[u] + E[i].cost) {
                dis[v] = dis[u] + E[i].cost;
                pre[v] = i;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if (pre[t] == -1) return false;
    else return true;
}

//è¿åçæ¯æå¤§æµï¼ costå­çæ¯æå°è´¹ç¨
int minCostMaxflow(int s, int t, int &cost) {
    int flow = 0;
    cost = 0;
    while (spfa(s, t)) {
        int Min = INF;
        for (int i = pre[t]; i != -1; i = pre[E[i ^ 1].to]) {
            if (Min > E[i].cap - E[i].flow)
                Min = E[i].cap - E[i].flow;
        }
        for (int i = pre[t]; i != -1; i = pre[E[i ^ 1].to]) {
            E[i].flow += Min;
            E[i ^ 1].flow -= Min;
            cost += E[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}

inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();

    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int main() {
    int n, m; //FIN;
    while(~scanf("%d%d", &n, &m)) {
        int s = 0, t = 2 * n + 1;
        init(t);

        for(int i = 1; i <= n; i++) {
            edge_add(s, i, 1, 0);
            edge_add(i + n, t, 1, 0);
        }

        for(int i = 1; i <= m; i++) {
            int u, v, cost;
            u = read(); v = read(); cost = read();
            edge_add(u, n + v, 1, cost);
        }

        int ans = 0;
        if(minCostMaxflow(s, t, ans)!=n) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}