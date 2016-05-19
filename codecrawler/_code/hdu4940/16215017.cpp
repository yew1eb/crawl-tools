#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAXN = 1000;
const int MAXM = 100010;
const int INF = 0x3f3f3f3f;

int w[MAXN];
struct Edge
{
    int to, next, cap, flow;
} edge[MAXM];

int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], cur[MAXN];

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
void init()
{
    tol = 0;
    memset(head, -1, sizeof(head));
    memset(w, 0, sizeof(w));
}
int main()
{
    //freopen("in", "r", stdin);
    int T;
    int ca = 1;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        init();
        int u, v, d, b;
        for(int i = 0; i < m; ++i) {
            scanf("%d%d %d%d", &u, &v, &d, &b);
            addedge(u, v, b);
            w[u] -= d;
            w[v] += d;
        }

        int s = 0, t = n+1;
        int sum = 0;
        for(int i = 1; i <= n; ++i) {
            if(w[i] > 0) {
                sum += w[i];
                addedge(s, i, w[i]);
            }
            if(w[i] < 0) {
                addedge(i, t, -w[i]);
            }
        }


        int flow = sap(s, t, n+2);
        if(flow == sum) {
            printf("Case #%d: happy\n", ca++);
        }
        else printf("Case #%d: unhappy\n", ca++);

    }
    return 0;
}
