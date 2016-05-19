#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN = 3010;
const int MAXM = 3010*3010;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int v;
    int next;
}edge[MAXM];

struct node
{
    double x, y;
    double v;
}a[MAXN], b[MAXN];

int nx, ny;
int cnt;
int t;
int dis;

int first[MAXN];
int xlink[MAXN], ylink[MAXN];
int dx[MAXN], dy[MAXN];
int vis[MAXN];

void init()
{
    cnt = 0;
    memset(first, -1, sizeof(first));
    memset(xlink, -1, sizeof(xlink));
    memset(ylink, -1, sizeof(ylink));
}

void read_graph(int u, int v)
{
    edge[cnt].v = v;
    edge[cnt].next = first[u], first[u] = cnt++;
}

int bfs()
{
    queue<int> q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for(int i = 0; i < nx; i++)
    {
        if(xlink[i] == -1)
        {
            q.push(i);
            dx[i] = 0;
        }
    }
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        if(dx[u] > dis) break;
        for(int e = first[u]; e != -1; e = edge[e].next)
        {
            int v = edge[e].v;
            if(dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if(ylink[v] == -1) dis = dy[v];
                else
                {
                    dx[ylink[v]] = dy[v]+1;
                    q.push(ylink[v]);
                }
            }
        }
    }
    return dis != INF;
}

int find(int u)
{
    for(int e = first[u]; e != -1; e = edge[e].next)
    {
        int v = edge[e].v;
        if(!vis[v] && dy[v] == dx[u]+1)
        {
            vis[v] = 1;
            if(ylink[v] != -1 && dy[v] == dis) continue;
            if(ylink[v] == -1 || find(ylink[v]))
            {
                xlink[u] = v, ylink[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int MaxMatch()
{
    int ans = 0;
    while(bfs())
    {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < nx; i++) if(xlink[i] == -1)
        {
            ans += find(i);
        }
    }
    return ans;
}

/*double dist(const node a, const node b) //TLE,æ ååæ§½äº
{
    return sqrt(pow((a.x-b.x), 2.0) + pow((a.y-b.y), 2.0));
}*/

double dist(const node a, const node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void read_case()
{
    init();
    int Time;
    scanf("%d", &Time);
    scanf("%d", &nx);
    for(int i = 0; i < nx; i++)
    {
        scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].v);
    }
    scanf("%d", &ny);
    for(int i = 0; i < ny; i++)
    {
        scanf("%lf%lf", &b[i].x, &b[i].y);
    }
    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            double limit = a[i].v*Time;
            double s = dist(a[i], b[j]);
            if(s <= limit) read_graph(i, j);
        }
    }
}

void solve()
{
    read_case();
    int ans = MaxMatch();
    printf("%d\n\n", ans); //æ³¨ææ ¼å¼ 
}

int main()
{
    int T, times = 0;
    scanf("%d", &T);
    while(T--)
    {
        printf("Scenario #%d:\n", ++times);
        solve();
    }
    return 0;
}
