#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 100000;
const int maxm = 1010*1010;

const int INF = 0x3f3f3f3f;

int nx, ny;
int n, m, k;
int cnt;

struct Edge
{
	int u, v;
	int next;
}edge[maxm];

int first[maxn];

int xlink[maxn], ylink[maxn];
bool vis[maxn];

bool edges[maxn];

void init()
{
	cnt = 0;
    memset(first, -1, sizeof(first));
    memset(xlink, -1, sizeof(xlink));
    memset(ylink, -1, sizeof(ylink));
    memset(edges, 0, sizeof(edges));
}

void read_graph(int u, int v)
{
	edge[cnt].u = u, edge[cnt].v = v;
	edge[cnt].next = first[u], first[u] = cnt++;
}

int dis;

int dx[maxn], dy[maxn];

int bfs()
{
    queue<int> q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for(int i = 1; i <= nx; i++)
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
			if(edges[e]) continue; 
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
	int v;
    for(int e = first[u]; e != -1; e = edge[e].next)
    {
        if(edges[e]) continue;
        v = edge[e].v;
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
        for(int i = 1; i <= nx; i++) if(xlink[i] == -1)
        {
            ans += find(i);
        }
    }
    return ans;
}

inline void readint(int &x)
{
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	
	x = 0;
	while(isdigit(c))
	{
		x = x*10 + c-'0';
		c = getchar();
	}
}

inline void writeint(int x)
{
	if(x > 9) writeint(x/10);
	putchar(x%10+'0');
}

void read_case()
{
    init();
    while(k--)
    {
        int u, v;
        readint(u), readint(v);
        read_graph(u, v);
    }
}

int XLINK[maxn];

int times;

int find_edge(int u, int v)
{
	for(int e = first[u]; e != -1; e = edge[e].next)
	{
		if(edge[e].v == v) return e;
	}
	return -1;
}

void solve()
{
    read_case();
    int ans = MaxMatch();
    int count = 0;
    memcpy(XLINK, xlink, sizeof(xlink));
    
    for(int u = 1; u <= nx; u++)
    {
        memset(xlink, -1, sizeof(xlink));
        memset(ylink, -1, sizeof(ylink));
        if(XLINK[u] != -1)
        {
			int e = find_edge(u, XLINK[u]);
			edges[e] = 1;
            int t = MaxMatch();
            if(t != ans) count++;
            edges[e] = 0;
        }
    }
    printf("Board %d have %d important blanks for %d chessmen.\n", ++times, count, ans);
}

int main()
{
    times = 0;
    while(~scanf("%d%d%d", &nx, &ny, &k))
    {
        solve();
    }
    return 0;
}