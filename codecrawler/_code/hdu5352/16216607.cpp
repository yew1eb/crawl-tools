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

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

const int MAXN = 1000;
const int MAXM = 100000;
const int INF = 0x3f3f3f3f;

typedef long long ll;

struct Edge
{
    int to, next, cap, flow;
} edge[MAXM];


int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], cur[MAXN];

void init()
{
    tol = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int u, int v, int w, int rw = 0)
{
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = rw;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}

int Q[MAXN];

void BFS(int start, int end)
{
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    gap[0] = 1;
    int front = 0, rear = 0;
    dep[end] = 0;
    Q[rear++] = end;
    while (front != rear)
    {
        int u = Q[front++];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dep[v] != -1)continue;
            Q[rear++] = v;
            dep[v] = dep[u] + 1;
            gap[dep[v]]++;
        }
    }
}

int S[MAXN];

int sap(int start, int end, int N)
{
    BFS(start, end);
    memcpy(cur, head, sizeof(head));
    int top = 0;
    int u = start;
    int ans = 0;
    while (dep[start] < N)
    {
        if (u == end)
        {
            int Min = INF;
            int inser;
            for (int i = 0; i < top; i++)
                if (Min > edge[S[i]].cap - edge[S[i]].flow)
                {
                    Min = edge[S[i]].cap - edge[S[i]].flow;
                    inser = i;
                }
            for (int i = 0; i < top; i++)
            {
                edge[S[i]].flow += Min;
                edge[S[i] ^ 1].flow -= Min;
            }
            ans += Min;
            top = inser;
            u = edge[S[top] ^ 1].to;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = cur[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u])
            {
                flag = true;
                cur[u] = i;
                break;
            }
        }
        if (flag)
        {
            S[top++] = cur[u];
            u = v;
            continue;
        }
        int Min = N;

        for (int i = head[u]; i != -1; i = edge[i].next)
            if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]]--;
        if (!gap[dep[u]])return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if (u != start)u = edge[S[--top] ^ 1].to;
    }
    return ans;
}

int g[MAXN][MAXN], can[MAXN][MAXN], ans[MAXN];
int n, m, k, cnt;

vector <int> gra[MAXN];

void dfs(int id, int u)
{
    can[id][u] = 1;
    gra[id].push_back(u);
    for (int v = 1; v <= n; v++)
    {
        if (!g[u][v] || can[id][v]) continue;
        dfs(id, v);
    }
}

int solve()
{
    init();
    int s = 0, t = cnt + n + 1;

    for (int i = 1; i <= cnt; i++)
        addedge(s, i, k);
    for (int i = 1; i <= n; i++)
        addedge(i + cnt, t, 1);

    int res = 0;
    for (int i = cnt; i >= 1; i--)
    {
        for (int j = 0; j < gra[i].size(); j++)
        {
            int v = gra[i][j];
            addedge(i, v + cnt, 1);
        }
        res += sap(s, t, t + 1);
    }

    for (int i = head[s]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        ans[v] = edge[i].flow;
    }
    return res;
}

void Init()
{
    cnt = 0;
    memset(g, 0, sizeof(g));
    memset(can, 0, sizeof(can));
    for (int i = 0; i < MAXN; i++)
        gra[i].clear();
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &k);

        Init();
        while (m--)
        {
            int op;
            scanf("%d", &op);

            if (op == 1)
            {
                int x;
                scanf("%d", &x);
                cnt++;
                dfs(cnt, x);
            }
            else if (op == 2)
            {
                int x, y;
                scanf("%d%d", &x, &y);
                g[x][y] = g[y][x] = 1;
            }
            else
            {
                int num;
                scanf("%d", &num);
                while (num--)
                {
                    int x, y;
                    scanf("%d%d", &x, &y);
                    g[x][y] = g[y][x] = 0;
                }
            }
        }

        int flow = solve();
        printf("%d\n", flow);
        for (int i = 1; i <= cnt; i++)
            printf("%d%c", ans[i], i == cnt ? '\n' : ' ');
    }
    return 0;
}