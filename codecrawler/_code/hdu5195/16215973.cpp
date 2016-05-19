#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define ls o*2
#define rs o*2+1
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

vector<int> G[N];
int minv[N<<2], indeg[N];
int n, m, k;

inline void maintain(int o) {
    minv[o] = min(minv[ls], minv[rs]);
}

void build(int o, int L, int R) {
    if(L == R) {
        minv[o] = indeg[L];
        return;
    }
    int M = (L+R)/2;
    build(ls, L, M);
    build(rs, M+1, R);
    maintain(o);
}

int pos;
void modify(int o, int L, int R) {
    if(L == R) {
        minv[o]--;
        return ;
    }
    int M = (L+R)/2;
    if(pos <= M) modify(ls, L, M);
    else modify(rs, M+1, R);
    maintain(o);
}

int ret;
void query(int o, int L, int R) {
    if(L == R) {
        minv[o] = INF;
        ret = L;
        return ;
    }
    int M = (L+R)/2;
    if(minv[rs] <= k) query(rs, M+1, R);
    else query(ls, L, M);
    maintain(o);
}

void init() {
    memset(indeg, 0, sizeof(indeg));
    for(int i = 0; i < n+5; i++) {
        G[i].clear();
    }
}

void addEdge(int from, int to) {
    G[from].push_back(to);
}

void toposort() {
    vector<int> ans;

    build(1, 1, n);
    for(int i = 1; i <= n; i++) {
        query(1, 1, n);
        int u = ret;
        ans.push_back(u);
        k -= indeg[u];

        for(int j = 0; j < G[u].size(); j++) {
            int v = G[u][j];
            --indeg[v];

            pos = v;
            modify(1, 1, n);
        }
    }

    printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++) {
        printf(" %d",ans[i]);
    }
    puts("");
}

int main() {
    int u, v;
    while(~scanf("%d%d%d", &n, &m, &k)) {
        init();
        while(m--) {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            indeg[v]++;
        }
        toposort();
    }
    return 0;
}