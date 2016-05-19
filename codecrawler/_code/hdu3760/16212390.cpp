#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define MAXN 100005
#define MAXM 400005
#define INF 1000000011
#define lch(x) x<<1
#define rch(x) x<<1|1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define eps 1e-7
using namespace std;
struct EDGE
{
    int v, w, next;
}edge[MAXM * 2];
int head[MAXN], e;
int dis[2][MAXN];
int vis[MAXN];
void init()
{
    memset(head, -1, sizeof(head));
    e = 0;
}
void add(int u, int v, int w)
{
    edge[e].v = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
}
int n, m;
int q[4 * MAXM];
int L;
int color[MAXN];
void spfa(int src, int k)
{
    for(int i = 1; i <= n; i++) dis[k][i] = INF, vis[i] = 0;
    int h = 0, t = 0;
    q[t++] = src;
    dis[k][src] = 0;
    vis[src] = 1;
    while(h < t)
    {
        int u = q[h++];
        vis[u] = 0;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if(dis[k][u] + 1 < dis[k][v])
            {
                dis[k][v] = dis[k][u] + 1;
                if(!vis[v])
                {
                    q[t++] = v;
                    vis[v] = 1;
                }
            }
        }
    }
    if(k == 0) L = dis[k][n];
}
struct node
{
    int num, u;
    node(){}
    node(int a, int b){num = a; u = b;}
}que[4 * MAXM];
int pre[MAXN], prec[MAXN];
int ans[MAXN];
void bfs()
{
    int h = 0, t = 0;
    for(int i = 1; i <= n; i++) color[i] = INF, vis[i] = 0;
    vis[1] = 1;
    que[t++] = node(0, 1);
    while(h < t)
    {
        node tmp = que[h];
        if(que[h].num == L) break;
        for(int j = h; j < t; j++)
        {
            if(que[j].num != tmp.num) break;
            int u = que[j].u;
            for(int i = head[u]; i != -1; i = edge[i].next)
            {
                int v = edge[i].v;
                int w = edge[i].w;
                if(dis[0][u] + 1 + dis[1][v] == L)
                {
                    if(w < color[tmp.num + 1]) color[tmp.num + 1] = w;
                }
            }
        }
        while(h < t && que[h].num == tmp.num)
        {
            int u = que[h].u;
            for(int i = head[u]; i != -1; i = edge[i].next)
            {
                int v = edge[i].v;
                if(dis[0][u] + 1 + dis[1][v] == L && color[tmp.num + 1] == edge[i].w && !vis[v])
                {
                    vis[v] = 1;
                    pre[v] = u;
                    prec[v] = edge[i].w;
                    que[t++] = node(tmp.num + 1, v);
                }
            }
            h++;
        }
    }
    int now = n;
    int cnt = 0;
    while(pre[now] != 1)
    {
        ans[cnt++] = prec[now];
        now = pre[now];
    }
    ans[cnt++] = prec[now];
    printf("%d", ans[cnt - 1]);
    for(int i = cnt - 2; i >= 0; i--) printf(" %d", ans[i]);
    printf("\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int x, y, z;
        scanf("%d%d", &n, &m);
        init();
        while(m--)
        {
            scanf("%d%d%d", &x, &y, &z);
            if(x == y) continue;
            add(x, y, z);
            add(y, x, z);
        }
        spfa(1, 0); spfa(n, 1);
        printf("%d\n", L);
        bfs();
    }
    return 0;
}