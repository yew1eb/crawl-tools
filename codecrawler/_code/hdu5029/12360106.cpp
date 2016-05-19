#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cassert>

#define mp make_pair
#define pb push_back
#define foreach(i,T) for(__typeof(T.begin()) i = T.begin(); i != T.end(); ++i)

using namespace std;

namespace Solve {
    const int MAXN = 100010;

    inline int read() {
        int r = 0, c, d;
        while (!isdigit(c = getchar()) && c != '-');
        if (c != '-') r = c - '0'; d = c;
        while ( isdigit(c = getchar())) r = r * 10 + c - '0';
        return d=='-'?-r:r;
    }

    struct edge {
        int y; edge *next;
        edge(int y, edge *next):y(y), next(next){}
    }*a[MAXN];

    int n, m;
    inline bool input() {
        n = read(), m = read();
        if (!n && !m) return false;
        for (int i = 1; i <= n; ++i) a[i] = NULL;
        for (int i = 1; i <= n - 1; i++) {
            int x = read(), y = read();
            a[x] = new edge(y, a[x]); a[y] = new edge(x, a[y]);
        }
        return true;
    }

    int dep[MAXN], belong[MAXN], son[MAXN], d[MAXN], sum[MAXN], father[MAXN];
    int f[19][MAXN];
    
    inline void divide() {
        int head = 1, tail = 1; d[1] = 1;
        while (head <= tail) {
            int now = d[head++];
            for (int i = 1; (1 << i) <= dep[now]; ++i) 
                f[i][now] = f[i - 1][f[i - 1][now]];
            for (edge *p = a[now]; p; p = p->next) if (p->y != father[now]) {
                dep[d[++tail] = p->y] = dep[now] + 1;
                father[p->y] = now;
                f[0][p->y] = now;
            }
        }
        for (int i = n; i >= 1; i--) sum[father[d[i]]] += ++sum[d[i]];
        for (int _ = 1; _ <= n; _++) {
            int i = d[_], best = 0;
            if (belong[i] == 0) belong[i] = i;
            for (edge *p = a[i]; p; p = p->next) 
                if (p->y != father[i] && sum[p->y] > best) 
                    best = sum[p->y], son[i] = p->y;
            belong[son[i]] = belong[i];
        }
    }

    inline int find(int x, int d) {
        for (int i = 18; i >= 0; i--) if (d & (1 << i)) x = f[i][x];
        return x;
    }

    inline int LCA(int x, int y) {
        while (true) {
            if (dep[x] > dep[y]) swap(x, y);
            if (belong[x] == belong[y]) return x;
            if (dep[belong[x]] < dep[belong[y]]) y = father[belong[y]]; else x = father[belong[x]];
        }
    }

    vector<pair<int, int> > c[MAXN];

    inline void insert(int x, int y, int z) {
        while (belong[x] != belong[y]) {
            c[belong[y]].pb(mp(z, 0));
            c[y].pb(mp(z, 1));
            y = father[belong[y]];
        }
        c[x].pb(mp(z, 0));
        c[y].pb(mp(z, 1));
    }

    inline void query() {
        for (int i = 1; i <= m; i++) {
            int x = read(), y = read(), z = read();
            if (dep[x] > dep[y]) swap(x, y);
            int A = LCA(x, y);
            if (A != x) {
                int d = dep[x] - dep[A] - 1;
                insert(find(x, d), x, z);
            }
            insert(A, y, z);
        }
    }

    int Ans[MAXN], cnt[MAXN];
    priority_queue<pair<int, int> > Q;

    inline void Work(int u) {
        while (!Q.empty()) Q.pop();
        for (;u;u=son[u]) {
            foreach(it, c[u]) if (it->second == 0) Q.push(mp(++cnt[it->first], -it->first));
            while (!Q.empty() && Q.top().first != cnt[-Q.top().second]) Q.pop();
            if (!Q.empty()) Ans[u] = -Q.top().second;
            foreach(it, c[u]) if (it->second == 1) if (--cnt[it->first]) Q.push(mp(cnt[it->first], -it->first));
        }
    }

    inline bool solve() {
        if (!input()) return false;
        memset(dep, 0, sizeof dep);
        memset(belong, 0, sizeof belong);
        memset(son, 0, sizeof son);
        memset(d, 0, sizeof d);
        memset(sum, 0, sizeof sum);
        memset(father, 0, sizeof father);
        memset(f, 0, sizeof f);
        while (!Q.empty()) Q.pop();
        memset(Ans, 0, sizeof Ans);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i <= MAXN; ++i)
            c[i].clear();
        divide();
        query();
        for (int i = 1; i <= n; i++) if (belong[i] == i) {
            Work(i);
        }
        for (int i = 1; i <= n; i++) printf("%d\n", Ans[i]);
        return true;
    }
}

int main(void) {
#ifdef KANARI
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    while (Solve::solve());
    
    return 0;
}