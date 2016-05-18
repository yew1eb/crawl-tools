#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <functional>
#include <deque>
#include <ctime>
#include <string>

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

const int maxn = 105;

struct edge
{
    int u, v, w;
    bool operator < (const edge &rhs) const
    {
        return w > rhs.w;
    }
};

int fa[maxn];
int a[maxn][maxn];
int ans[maxn][maxn];

int Find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = Find(fa[x]);
}

bool unite(int x, int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if (fx == fy)
        return false;
    fa[fx] = fy;
    return true;
}

vector <edge> g;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        g.clear();
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
            ans[i][i] = -1;
            for (int j = 1; j <= n; j++)
            {
                edge e;
                e.u = i, e.v = j;
                scanf("%d", &e.w);
                g.push_back(e);
                a[i][j] = e.w;
            }
        }

        int fl = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                {
                    if (i == j || j == k || i == k) continue;
                    if (a[i][j] < min(a[i][k], a[k][j]))
                        fl = 1;
                }

        if (fl)
        {
            puts("NO");
            continue;
        }
        sort(g.begin(), g.end());
//        for(int i = 0; i < g.size(); i++)
//            printf("%d %d %d\n", g[i].u, g[i].v, g[i].w);

        for (int i = 0; i < g.size(); i++)
        {
            edge e = g[i];
            int u = e.u, v = e.v;
            if (unite(u, v))
                ans[u][v] = ans[v][u] = e.w;
        }

        puts("YES");
        for (int i = 1; i <= n; i++)
        {
            printf("%d", ans[i][1]);
            for (int j = 2; j <= n; j++)
            {
                printf(" %d", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}