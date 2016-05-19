#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define MAXM 111111
#define MAXN 111111
#define INF 1000000007
#define eps 1e-8
using namespace std;
vector<int>g[MAXN];
vector<pair<int, int> >query[MAXN];
int ta[2][MAXN];
int n, m, q, cnt;
int w[MAXN];
int a[MAXN * 2];
int ans[MAXN][2];
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int v, int j)
{
    for(int i = x; i <= cnt; i += lowbit(i))
        ta[j][i] += v;
}
int getsum(int x, int j)
{
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        sum += ta[j][i];
    return sum;
}
void dfs(int u)
{
    int sz = query[u].size();
    for(int i = 0; i < sz; i++)
    {

        int weight = query[u][i].second;
        int id = query[u][i].first;
        int pos = lower_bound(a, a + cnt, weight) - a + 1;
        int ls = getsum(pos - 1, 0);
        int rs = getsum(pos - 1, 1);
        int lall = getsum(cnt, 0);
        int rall = getsum(cnt, 1);
        int lb = lall - getsum(pos, 0);
        int rb = rall - getsum(pos, 1);
        if(ls + lb + rs + rb - lall - rall != 0)
        {
            ans[id][0] = -1;
            continue;
        }
        ans[id][0] = ls * 3 + rs * 3 + lb + rb;
        ans[id][1] = rs;
    }
    sz = g[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = g[u][i];
        int weight = w[u];
        int pos = lower_bound(a, a + cnt, weight) - a + 1;
        add(pos, 1, i);
        dfs(v);
        add(pos, -1, i);
    }
}
int main()
{
    int T, u, v, fa, x;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) g[i].clear();
        cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &w[i]);
            a[cnt++] = w[i];
        }
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d%d%d", &fa, &u, &v);
            g[fa].push_back(u);
            g[fa].push_back(v);
        }
        scanf("%d", &q);
        for(int i = 0; i <= q; i++) query[i].clear();
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &v, &x);
            query[v].push_back(make_pair(i, x));
            a[cnt++] = x;
        }
        sort(a, a + cnt);
        cnt = unique(a, a + cnt) - a;
        memset(ta, 0, sizeof(ta));
        dfs(1);
        for(int i = 0; i < q; i++)
            if(ans[i][0] == -1)
                puts("0");
            else printf("%d %d\n", ans[i][1], ans[i][0]);
    }
    return 0;
}
