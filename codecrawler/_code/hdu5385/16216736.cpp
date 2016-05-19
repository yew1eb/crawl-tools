#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

const int N = 300005;
const int M = 600005;
typedef long long ll;
int n, m;
int head[M], vis[N];
int d[M], ec;
struct Edge{
    int from, to, next;
}edges[M];

void addEdge(int u, int v) {
    edges[ec].from = u;
    edges[ec].to = v;
    edges[ec].next = head[u];
    head[u] = ec++;
}

void init() {
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    ec = 0;
    d[1] = 0;
    d[2] = 1;
    d[n] = 1;
    vis[1] = -1;
}

void mark(int u) { //æ è®°å·²æ è®°ç¹uæç¸è¿çæªæ è®°çç¹
    for (int i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].to;    
        if (!vis[v]) vis[v] = u;
    }
}

void input() {
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);         
        addEdge(a, b);
    }
}

void solve() {
    int l = 1, r = n, val = 1;  
    while (l <= r) { //ä»2ånå¼å§å ç¹ï¼d[i]ä¸ºç¹iå å¥çæ¶é´
        if (vis[l]) {
            mark(l);    
            d[l++] = val++;
        }   
        if (vis[r]) {
            mark(r);        
            d[r--] = val++;
        }
    }
    for (int i = 0; i < ec; i++) {
        int u = edges[i].from, v = edges[i].to;
        if (vis[v] != u) printf("%d\n", n); //ä¸å¨æç­è·¯æ ä¸çè¾¹
        else printf("%d\n", d[v] - d[u]); //æç­è·¯æ ä¸çè¾¹
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        input();
        solve();
    }
    return 0;
}