#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
typedef unsigned long long ll;

const int N = 233333;
int n, m, head[N], mm;
struct Edge
{
    int to, next, w;
} e[N << 1];
void add(int u, int v, int w = 1)
{
    e[mm].to = v;
    e[mm].next = head[u];
    e[mm].w = w;
    head[u] = mm++;
}
int sz[N], dep[N];
int f[N][22]; /// f[i][j] è¡¨ç¤º i çç¬¬ 2^j ä¸ªç¥å
int dfn[N];  ///dfs index
int cur;
int id[N]; /// you dfs xu qiu chu bian hao
int len[N];
void dfs(int u, int fa) /// ç¹ä» 1 å¼å§æ å·
{
    f[u][0] = fa;
    sz[u] = 1;
    dfn[u] = ++cur;
    id[cur] = u;
    for (int i=head[u]; ~i; i=e[i].next)
    {
        int v = e[i].to;
        int w = e[i].w;
        if (v != fa)
        {
            dep[v] = dep[u] + 1;
            len[v] = len[u] + w;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}
int maxh;
void gao()
{
    cur = 0;
    dep[0] = -1;
    len[1] = dep[1] = 0;
    f[1][0] = 1;
    dfs(1, 0);f[1][0] = 1;
    int j;
    for (j=1; (1<<j)<n; j++)
        for (int i=1; i<=n; i++)
            f[i][j] = f[f[i][j-1]][j-1];
    maxh = j - 1;
}
int swim(int x, int k)
{
    for (int i=0; i<=maxh; i++)
        if (k >> i & 1)
            x = f[x][i];
    return x;
}
int LCA(int x, int y)
{
    if (dep[x] > dep[y]) swap(x, y); ///dep[x] <= dep[y];
    y = swim(y, dep[y] - dep[x]);
    if (x == y) return y;
    for (int i=maxh; i>=0; i--)
    {
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}
int Q;

set<int> se;
set<int>::iterator it;
int dist(int x, int y)
{
    int lca = LCA(x, y);
    return len[x] - len[lca] + len[y] - len[lca];
}
int solve(int u)
{
    if (se.empty()) return 0;
    int x, y;
    int t = *se.begin();
    it = se.lower_bound( u);
    y = *it;
    it--;
    x = *(it );
    int t2 = *se.rbegin();
    x = id[x];
    y = id[y];
    if (t2 < u || t > u)
    {
        x = id[t]; y = id[t2];
    }
    u = id[u];
    return len[u] - len[LCA(x,u) ] - len[LCA(y,u)] + len[LCA(x,y) ];
}
int main()
{
    int re;
    cin>>re;
    int ca=1;
    while (re--)
    {
        cin>>n>>Q;
        mm = 0;
        memset(head,-1,sizeof head);
        for (int i=0; i<n-1; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        gao();
        printf("Case #%d:\n", ca++);
        se.clear();
        int ans = 0;
        while (Q--)
        {
            int op, u;
            scanf("%d%d", &op, &u);
            u = dfn[u];
            if (op==1)
            {
                it = se.find(u);
                if (it==se.end())
                {
                    ans += solve(u);
                    se.insert(u);
                }
            }
            else
            {
                it = se.find(u);
                if (it != se.end())
                {
                    se.erase(u);
                    ans -= solve(u);
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
