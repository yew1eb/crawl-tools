#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int SIZE = 1000001;
const int INF = 0x3f3f3f3f;
int u[2*SIZE], v[2*SIZE], w[2*SIZE], next[2*SIZE];
int s_u[2*SIZE], s_v[2*SIZE], s_w[2*SIZE];
int first[SIZE], d[SIZE];
int n, m, cnt;

void init()
{
    memset(u, 0, sizeof(u));
    memset(v, 0, sizeof(v));
    memset(w, INF, sizeof(w));
    memset(d, 0, sizeof(d));
    memset(next, 0, sizeof(next));
    memset(first, -1, sizeof(first));
    cnt = 0;
}

void spfa(int src)
{
    queue<int> q;
    bool inq[SIZE] = {0};
    for(int i = 1; i <= n; i++) d[i] = (i == src)? 0:INF;
    q.push(src);
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        inq[x] = 0;
        for(int e = first[x]; e!=-1; e = next[e]) if(d[v[e]] > d[x]+w[e])
        {
            d[v[e]] = d[x] + w[e];
            if(!inq[v[e]])
            {
                inq[v[e]] = 1;
                q.push(v[e]);
            }
        }
    }
}

void read_graph(int u1, int v1, int w1)
{
    u[cnt] = u1; v[cnt] = v1; w[cnt] = w1;
    next[cnt] = first[u[cnt]];
    first[u[cnt]] = cnt;
    cnt++;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int ans = 0;
        init();
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++)    scanf("%d%d%d", &s_u[i], &s_v[i], &s_w[i]);
        for(int i = 1; i <= m; i++) read_graph(s_u[i], s_v[i], s_w[i]);
        spfa(1);
        for(int i = 1; i <= n; i++) ans += d[i];
        init();
        for(int i = 1; i <= m; i++) read_graph(s_v[i], s_u[i], s_w[i]);
        spfa(1);
        for(int i = 1; i <= n; i++) ans += d[i];
        printf("%d\n", ans);
    }
    return 0;
}