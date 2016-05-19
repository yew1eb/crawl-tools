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

const int maxn = 100010;

struct Edge
{
    int to, next;
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

int tr[maxn << 2], sum[maxn << 2], col[maxn << 2];

void pushup(int rt)
{
    tr[rt] = tr[rt << 1] + tr[rt << 1 | 1];
}

void pushdown(int rt)
{
    if (col[rt])
    {
        col[rt << 1] = col[rt << 1 | 1] = 1;
        tr[rt << 1] = sum[rt << 1];
        tr[rt << 1 | 1] = sum[rt << 1 | 1];
        col[rt] = 0;
    }
}

void build(int l, int r, int rt)
{
    tr[rt] = col[rt] = 0;
    if (l == r)
    {
        sum[rt] = val[fp[l]];
        return ;
    }

    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int ql, int qr, int c, int l, int r, int rt)
{
    if (ql <= l && r <= qr)
    {
        col[rt] = c;
        tr[rt] = c ? sum[rt] : 0;
        return ;
    }

    pushdown(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        update(ql, qr, c, lson);
    if (qr > mid)
        update(ql, qr, c, rson);
    pushup(rt);
}

void change(int u, int v, int c)
{
    int fu = top[u], fv = top[v];
    while (fu != fv)
    {
        if (deep[fu] < deep[fv])
        {
            swap(fu, fv);
            swap(u, v);
        }
        update(p[fu], p[u], c, 1, pos, 1);
        u = fa[fu], fu = top[u];
    }
    if (deep[u] > deep[v]) swap(u, v);
    update(p[u], p[v], c, 1, pos, 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        init();
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &val[i]);

        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }

        dfs1(1, 0, 0);
        getpos(1, 1);
        build(1, pos, 1);

//        for(int i = 1; i <= pos * 2; i++)
//        {
//            if(sum[i] == 1)
//                printf("***************");
//            printf("%d %d %d\n", tr[i], sum[i], col[i]);
//        }

        int q;
        scanf("%d", &q);
        while (q--)
        {
            int op, x, y;
            scanf("%d", &op);
            if (op == 1)
            {
                scanf("%d%d", &x, &y);
                change(x, y, 1);
            }
            else if (op == 2)
            {
                scanf("%d", &x);
                update(p[x], p[x], 0, 1, pos, 1);
            }
            else
            {
                scanf("%d", &x);
                update(p[x], mp[x], 1, 1, pos, 1);
            }
            printf("%d\n", tr[1]);
        }
    }
    return 0;
}