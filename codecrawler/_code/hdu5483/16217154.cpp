#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

const int N = 3000 + 5;
std::vector<std::pair<int,int> > w[N];
int head[N];
int n;

struct Edge {
    int v,next;
} g[3000 * 3000 + 5];
int etot;

inline void add_edge(int u,int v) {
    g[etot].v = v; g[etot].next = head[u]; head[u] = etot ++;
}

int dfn[N],low[N],tim;

int trajin(int u,int pree) {
    int ret = 0;
    dfn[u] = low[u] = ++ tim;
    for (int i = head[u]; i != -1; i = g[i].next) {
        int v = g[i].v;
        if ((pree ^ i) == 1) continue;
        if (!dfn[v]) ret += trajin(v,i);
        low[u] = std::min(low[u],low[v]);
    }
    if (dfn[u] == low[u]) {
        if (pree != -1)
            ret ++;
    }
    return ret;
}

int dsu[N];

int find(int x) {
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int work() {
    int ret = 0;
    for (int i = 0; i < n; ++ i) {
        dsu[i] = i;
        head[i] = -1;
    }
    for (int x = 1; x <= 3000; ++ x) {
        if (w[x].empty()) continue;
        etot = 0;
        for (int i = 0; i < w[x].size(); ++ i) {
            int a = w[x][i].first;
            int b = w[x][i].second;
            a = find(a);
            b = find(b);
            if (a == b) continue;
            add_edge(a,b);
            add_edge(b,a);
            dfn[a] = low[a] = 0;
            dfn[b] = low[b] = 0;
        }
        tim = 0;
        for (int i = 0; i < w[x].size(); ++ i) {
            int a = w[x][i].first;
            int b = w[x][i].second;
            a = find(a);
            b = find(b);
            if (a == b) continue;
            if (dfn[a] == 0)
                ret += trajin(a,-1);
            if (dfn[b] == 0)
                ret += trajin(b,-1);
        }
        for (int i = 0; i < w[x].size(); ++ i) {
            int a = w[x][i].first;
            int b = w[x][i].second;
            a = find(a);
            b = find(b);
            if (a == b) continue;
            head[a] = -1;
            head[b] = -1;
            dsu[a] = b;
        }
    }
    return ret;
}

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%d",&n);
        for (int i = 1; i <= 3000; ++ i) {
            w[i].clear();
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                int x;
                scanf("%d",&x);
                w[x].push_back(std::make_pair(i,j));
            }
        }
        printf("%d\n",work());
    }
}