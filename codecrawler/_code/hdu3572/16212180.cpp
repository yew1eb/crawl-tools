#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1111;
const int maxm = 505000;
const int oo = 1 << 30;

int idx;
int cur[maxn], pre[maxn];
int dis[maxn], gap[maxn];
int aug[maxn], head[maxn];

struct Node
{
    int u, v, w;
    int next;
}edge[maxm];

void addEdge(int u, int v, int w)
{
    edge[idx].u = u;
    edge[idx].v = v;
    edge[idx].w = w;
    edge[idx].next = head[u];
    head[u] = idx++;

    edge[idx].u = v;
    edge[idx].v = u;
    edge[idx].w = 0;
    edge[idx].next = head[v];
    head[v] = idx++;
}


int SAP(int s, int e, int n)
{
    int max_flow = 0, v, u = s;
    int id, mindis;
    aug[s] = oo;
    pre[s] = -1;
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    gap[0] = n; // æè§å¾è¿ä¸å¥è¦ä¸è¦é½è¡ï¼å ä¸ºdis[e]å§ç»ä¸º0
    for (int i = 0; i <= n; ++i)
    {   // åå§åå½åå¼§ä¸ºç¬¬ä¸æ¡å¼§
        cur[i] = head[i];
    }

    while (dis[s] < n)
    {
        bool flag = false;
        if (u == e)
        {
            max_flow += aug[e];
            for (v = pre[e]; v != -1; v = pre[v]) // è·¯å¾åæº¯æ´æ°æ®çç½ç»
            {
                id = cur[v];
                edge[id].w -= aug[e];
                edge[id^1].w += aug[e];
                aug[v] -= aug[e]; // ä¿®æ¹å¯å¢å¹¿éï¼ä»¥åä¼ç¨å°
                if (edge[id].w == 0) u = v; // ä¸åéå°æºç¹ï¼ä»åéå°å®¹éä¸º0çå¼§çå¼§å°¾
            }
        }
        for (id = cur[u]; id != -1; id = edge[id].next)
        {   // ä»å½åå¼§å¼å§æ¥æ¾åè®¸å¼§
            v = edge[id].v;
            if (edge[id].w > 0 && dis[u] == dis[v] + 1) // æ¾å°åè®¸å¼§
            {
                flag = true;
                pre[v] = u;
                cur[u] = id;
                aug[v] = min(aug[u], edge[id].w);
                u = v;
                break;
            }
        }
        if (flag == false)
        {
            if (--gap[dis[u]] == 0) break; /* gapä¼åï¼å±æ¬¡æ åºç°æ­å±åç»æç®æ³ */
            mindis = n;
            cur[u] = head[u];
            for (id = head[u]; id != -1; id = edge[id].next)
            {
                v = edge[id].v;
                if (edge[id].w > 0 && dis[v] < mindis)
                {
                    mindis = dis[v];
                    cur[u] = id; // ä¿®æ¹æ å·çåæ¶ä¿®æ¹å½åå¼§
                }
            }
            dis[u] = mindis + 1;
            gap[dis[u]]++;
            if (u != s) u = pre[u]; // åæº¯ç»§ç»­å¯»æ¾åè®¸å¼§
        }
    }
    return max_flow;
}

int main()
{
    int t, n, m, pi, si, ei;
    int Max, sum, source, sink, vn;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        idx = 0;
        memset(head, -1, sizeof(head));
        sum = 0; source = 0; Max = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d %d %d", &pi, &si, &ei);
            sum += pi;
            Max = max(Max, ei);
            addEdge(source, i, pi);
            for (int j = si; j <= ei; ++j)
            {
                addEdge(i, n + j, 1);
            }
        }
        sink = n + Max + 1;
        vn = sink + 1;
        for (int i = 1; i <= Max; ++i)
        {
            addEdge(n + i, sink, m);
        }
        if (SAP(source, sink, vn) == sum)
            printf("Case %d: Yes\n\n", cas);
        else printf("Case %d: No\n\n", cas);
    }
    return 0;
}
