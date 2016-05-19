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

typedef long long ll;

const int maxn = 101000;
const int inf = 0x3f3f3f3f;

struct Edge
{
    int from, to, next;
} edge[maxn << 1];

int head[maxn], tot, val[maxn];
int top[maxn], fa[maxn], deep[maxn];
int num[maxn], p[maxn], fp[maxn];
int son[maxn], pos, mp[maxn];

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
    pos = 1;
    memset(son, -1, sizeof(son));
}

void addedge(int u, int v)
{
    edge[tot].from = u;
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs1(int u, int pre, int d)
{
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != pre)
        {
            dfs1(v, u, d + 1);
            num[u] += num[v];
            if (son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;
        }
    }
}

void getpos(int u, int sp)
{
    top[u] = sp;
    mp[u] = p[u] = pos++;
    fp[p[u]] = u;
    if (son[u] == -1) return;
    getpos(son[u], sp);
    mp[u] = max(mp[u], mp[son[u]]);
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != son[u] && v != fa[u])
            getpos(v, v);
        mp[u] = max(mp[u], mp[v]);
    }
}

struct UF
{
    int fa[maxn];

    void init(int n)
    {
        for (int i = 0; i <= n; i++)
            fa[i] = i;
    }

    int Find(int x)
    {
        if (fa[x] == x) return x;
        return fa[x] = Find(fa[x]);
    }
} uf;

map <int, int> ma[maxn];
map <int, int> ::iterator it;
int tr[maxn << 2], lazy[maxn << 2];

void pushup(int rt)
{
    tr[rt] = tr[rt << 1] + tr[rt << 1 | 1];
}

void build(int l, int r, int rt)
{
    lazy[rt] = 0;
    if (l == r)
    {
        tr[rt] = 1;
        return ;
    }

    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int ql, int qr, int l, int r, int rt)
{
    if (lazy[rt]) return ;
    if (ql <= l && qr >= r)
    {
        tr[rt] = 0;
        lazy[rt] = 1;
        return ;
    }

    int mid = (l + r) >> 1;
    if (ql <= mid)
        update(ql, qr, lson);
    if (qr > mid)
        update(ql, qr, rson);
    pushup(rt);
}

int query(int ql, int qr, int l, int r, int rt)
{
    if (lazy[rt]) return 0;
    if (ql <= l && qr >= r)
        return tr[rt];

    int res = 0;
    int mid = (l + r) >> 1;
    if (ql <= mid)
        res += query(ql, qr, lson);
    if (qr > mid)
        res += query(ql, qr, rson);
    return res;
}

void change(int u, int v)
{
    int fu = top[u], fv = top[v];
    while (fu != fv)
    {
        if (deep[fu] < deep[fv])
        {
            swap(fu, fv);
            swap(u, v);
        }
        update(p[fu], p[u], 1, pos, 1);
        u = fa[fu], fu = top[u];
    }
    if (deep[u] > deep[v]) swap(u, v);
    if (u != v)
        update(p[son[u]], p[v], 1, pos, 1);
}

int answer(int u, int v)
{
    int res = 0;
    int fu = top[u], fv = top[v];
    while (fu != fv)
    {
        if (deep[fu] < deep[fv])
        {
            swap(fu, fv);
            swap(u, v);
        }
        res += query(p[fu], p[u], 1, pos, 1);
        u = fa[fu], fu = top[u];
    }
    if (deep[u] > deep[v]) swap(u, v);
    if (u != v)
        res += query(p[son[u]], p[v], 1, pos, 1);
    return res;
}

struct node
{
    int op, u, v, ans;
} que[maxn];

int main()
{
    int t;
    cin >> t;
    for (int ca = 1; ca <= t; ca++)
    {
        printf("Case #%d:\n", ca);

        init();
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 0; i <= n; i++) ma[i].clear();
        uf.init(n);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u > v) swap(u, v);
            ma[u][v]++;
        }

        for (int i = 1; i <= q; i++)
        {
            scanf("%d%d%d", &que[i].op, &que[i].u, &que[i].v);
            if (que[i].u > que[i].v) swap(que[i].u, que[i].v);
            if (que[i].op == 1)
                ma[que[i].u][que[i].v]--;
        }


        for (int i = 1; i <= n; i++)
        {
            for (it = ma[i].begin(); it != ma[i].end(); it++)
            {
                if (it->second > 0)
                {
                    int u = i, v = it->first;
                    int fu = uf.Find(u), fv = uf.Find(v);
                    if (fu != fv)
                    {
                        addedge(u, v);
                        addedge(v, u);
                        uf.fa[fu] = fv;
                        (it->second)--;
                    }
                }
            }
        }

        dfs1(1, 0, 0);
        getpos(1, 1);
        build(1, pos, 1);

        // for (int i = 0; i < tot; i += 2)
        //     printf("%d %d\n", edge[i].from, edge[i].to);
        // for (int i = 1; i <= n; i++)
        //     printf("%d\n", p[i]);

        for (int i = 1; i <= n; i++)
        {
            for (it = ma[i].begin(); it != ma[i].end(); it++)
            {
                if (it->second > 0)
                {
                    int u = i, v = it->first;
                    change(u, v);
                }
            }
        }

        for (int i = q; i >= 1; i--)
        {
            if (que[i].op == 1)
                change(que[i].u, que[i].v);
            else
                que[i].ans = answer(que[i].u, que[i].v);
        }

        for (int i = 1; i <= q; i++)
            if (que[i].op == 2)
                printf("%d\n", que[i].ans);
    }
    return 0;
}