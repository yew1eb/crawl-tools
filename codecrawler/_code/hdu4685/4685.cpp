#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#define MAXN 2005
#define INF 100000000
#define eps 1e-7
using namespace std;
struct Edge
{
    int v, next;
}edge[200 * MAXN], newedge[255555];
int head[MAXN], e, visited[MAXN], newhead[MAXN], newe;
int top, scc, index;
int low[MAXN], dfn[MAXN], instack[MAXN];
int order[MAXN], cnt, st[MAXN], fa[MAXN];
int mark[MAXN], cx[MAXN], cy[MAXN];
int n, m;
int nt, all;
void init()
{
    top = scc = index = e = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(instack, 0, sizeof(instack));
    memset(newhead, -1, sizeof(newhead));
    newe = 0;
}
inline void insert(const int &x, const int &y)
{
    edge[e].v = y;
    edge[e].next = head[x];
    head[x] = e++;
}
inline int in()
{
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' || ch == '\n');
    a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n')
    {
        a *= 10;
        a += ch - '0';
    }
    return a;
}
inline void out(int a)
{
    if(a >= 10)out(a / 10);
    putchar(a % 10 + '0');
}
inline void newinsert(const int &x, const int &y)
{
    newedge[newe].v = y;
    newedge[newe].next = newhead[x];
    newhead[x] = newe++;
}
inline int path(int u)
{
    for(int i = newhead[u]; i != -1; i = newedge[i].next)
    {
        int v =  newedge[i].v;
        if(!mark[v])
        {
            mark[v] = 1;
            if(cy[v] == -1 || path(cy[v]))
            {
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int solve()
{
    int ans = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for(int i = 1; i <= nt; i++)
    {
        memset(mark, 0, sizeof(mark));
        ans += path(i);
    }
    return ans;
}

void readdata()
{
    int t, v;
    for(int i = 1; i <= n; i++)
    {
        t = in();
        while(t--)
        {
            v = in();
            insert(i, v + nt);
            newinsert(i, v + nt);
        }
    }

    solve();
    all = 2 * nt;
    for(int i = 1; i <= nt; i++)
        if(cx[i] == -1)
        {
            ++all;
            cx[i] = all;
            cy[all] = i;
            for(int k = 1; k <= nt; k++)
                insert(k, all);
        }

    for(int j = 1; j <= nt; j++)
        if(cy[j + nt] == -1)
        {
            ++all;
            cy[j + nt] = all;
            cx[all] = j + nt;
            for(int k = 1; k <= nt; k++)
                insert(all, k + nt);
        }
    for(int i = 1; i <= all; i++)
        if(cx[i] != -1)
            insert(cx[i], i);
}
void tarjan(int u)
{
    low[u] = dfn[u] = ++index;
    instack[u] = 1;
    st[++top] = u;
    int v;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instack[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        scc++;
        do
        {
            v = st[top--];
            instack[v] = 0;
            fa[v] = scc;
        }while(v != u);
    }
}
void gao()
{
    init();
    readdata();
    for(int i = 1; i <= all; i++)
        if(!dfn[i]) tarjan(i);
    for(int u = 1; u <= n; u++)
    {
        cnt = 0;
        int ans[MAXN];
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if(fa[u] == fa[v])
            {
                if(v - nt <= m)
                ans[cnt++] = v - nt;
            }
        }
        sort(ans, ans + cnt);
        out(cnt);
        for(int i = 0; i < cnt; i++)
        {
            putchar(' ');
            out(ans[i]);
        }
        puts("");
    }
}
int main()
{
    int cas = 0;
    int T;
    //freopen("C:/in.txt", "r", stdin);
    //freopen("C:/out2.txt", "w", stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        nt = max(n, m);
        printf("Case #%d:\n", ++cas);
        gao();
    }
    return 0;
}