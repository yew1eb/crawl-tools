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
#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

const int MAXN = 100010;
const int MAXM = 300010;

struct Edge
{
    int to, next;
    bool cut;
} edge[MAXM << 1];

int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN];
int Index, top, block;
bool Instack[MAXN];
int bridge;

void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].cut = false;
    head[u] = tot++;
}

void Tarjan(int u, int pre)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if (v == pre)continue;
        if (!DFN[v])
        {
            Tarjan(v, u);
            if (Low[u] > Low[v])
                Low[u] = Low[v];
            if (Low[v] > DFN[u])
            {
                bridge++;
                edge[i].cut = true;
                edge[i ^ 1].cut = true;
            }
        }
        else if (Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if (Low[u] == DFN[u])
    {
        block++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = block;
        } while (v != u);
    }
}

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}


void solve(int n)
{
    memset(DFN, 0, sizeof(DFN));
    memset(Instack, false, sizeof(Instack));
    bridge = Index = top = block = 0;
    for (int i = 1; i <= n; i++)
        if (!DFN[i])
            Tarjan(i, i);
}

int num;
int vis[MAXN], dep[MAXN], cnt[MAXN];
bool odd, even;

void dfs(int u, int depth, int pre)
{
    vis[u] = 1;
    dep[u] = depth;
    cnt[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        if (edge[i].cut) continue;
        int v = edge[i].to;
        if(v == pre) continue;
        if (vis[v])
        {
            if (cnt[v])
            {
                int len = dep[u] - dep[v] + 1;
                if (len % 2 == 1)
                {
                    odd = true;
                    num++;
                    if (num > 1)
                        even = true;
                }
                else
                    even = true;
            }
        }
        else
            dfs(v, depth + 1, u);
    }
    cnt[u] = 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        init();
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        solve(n);

        odd = even = false;
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                num = 0;
                dfs(i, 1, -1);
            }
        }

        printf("%s\n", odd ? "YES" : "NO");
        printf("%s\n", even ? "YES" : "NO");
    }
    return 0;
}