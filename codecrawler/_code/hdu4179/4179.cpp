#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>
#include <ctime>
#include <vector>
#include <algorithm>
#define ll __int64
#define L(rt) (rt<<1)
#define R(rt)  (rt<<1|1)

using namespace std;

const double INF = 1e16;
const int maxn = 50005;

struct Edge
{
    int v;
    double w;
    int next;
} et[maxn * 100];
struct node
{
    int x, y, z;
} p[maxn];
int n, m, d, num, s, t;
int eh1[maxn], eh2[maxn], aa[maxn], bb[maxn];
double dis1[maxn], dis2[maxn];
bool vis[maxn];
vector<int>edg;
double dis(node a, node b)
{
    double xx = 1.0 * (a.x - b.x) * (a.x - b.x);
    double yy = 1.0 * (a.y - b.y) * (a.y - b.y);
    double zz = 1.0 * (a.z - b.z) * (a.z - b.z);
    return sqrt(xx + yy + zz);
}
int dif(node a, node b)
{
    if(b.z <= a.z) return 0;
    double xx = 1.0 * (a.x - b.x) * (a.x - b.x);
    double yy = 1.0 * (a.y - b.y) * (a.y - b.y);
    return (int)(100 * (b.z - a.z) / sqrt(xx + yy));
}
void init()
{
    memset(eh1, -1, sizeof(eh1));
    memset(eh2, -1, sizeof(eh2));
    edg.clear();
    num = 0;
}
void add(int u, int v, double w, int *eh)
{
    Edge e = {v, w, eh[u]};
    et[num] = e;
    eh[u] = num++;
}
void spfa(int x, int *eh, double *dis)
{
    queue<int> Q;
    for(int i = 1; i <= n; i++)
    {
        dis[i] = INF;
        vis[i] = false;
    }
    dis[x] = 0;
    vis[x] = true;
    Q.push(x);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        vis[u] = false;
        for(int i = eh[u]; i != -1; i = et[i].next)
        {
            int v = et[i].v;
            double w = et[i].w;
            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if(!vis[v])
                {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d", &n, &m), n || m)
    {
        init();
        for(int i = 1; i <= n; i++)
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
        for(int i = 0; i < m; i++)
        scanf("%d%d", &aa[i], &bb[i]);
        scanf("%d%d%d", &s, &t, &d);
        for(int i = 0; i < m; i++)
        {
            int a = aa[i], b = bb[i];
            int df1 = dif(p[a], p[b]);
            int df2 = dif(p[b], p[a]);
            double dd = dis(p[a], p[b]);
            if(df1 <= d)
            {
                add(a, b, dd, eh1);
                add(b, a, dd, eh2);
            }
            if(df2 <= d)
            {
                add(b, a, dd, eh1);
                add(a, b, dd, eh2);
            }
            if(df1 == d)
            {
                edg.push_back(a);
                edg.push_back(b);
            }
            if(df2 == d)
            {
                edg.push_back(b);
                edg.push_back(a);
            }
        }
        spfa(s, eh1, dis1);
        spfa(t, eh2, dis2);
        double ans = INF;
        for(int i = 0; i < (int)edg.size(); i += 2)
        {
            int u = edg[i], v = edg[i + 1];
            double tmp = dis1[u] + dis(p[u], p[v]) + dis2[v];
            if(ans > tmp) ans = tmp;
        }
        if(ans == INF) printf("None\n");
        else printf("%.1lf\n", ans);
    }
    return 0;
}
