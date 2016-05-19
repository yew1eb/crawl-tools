#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 1010;
const int MAXM = 10010;

struct Edge
{
    int v, w;
    int id;
    int next;
}edge[MAXM];

int n, m;
int cnt;

int first[MAXN];
int ind[MAXN], outd[MAXN];
int Ee[MAXN], El[MAXN], E[MAXN], L[MAXN];
/*äºä»¶Eeææ©å¼å§æ¶é´ï¼äºä»¶Elæè¿åè®¸å¼å§æ¶é´ï¼Eæ´»å¨aææ©å¼å§æ¶é´ï¼Læ´»å¨aæè¿åè®¸å¼å§æ¶é´*/
void init()
{
    cnt = 0;
    memset(first, -1, sizeof(first));
    memset(ind, 0, sizeof(ind));
    memset(outd, 0, sizeof(outd));
    memset(Ee, 0, sizeof(Ee));
}

void read_graph(int u, int v, int w)
{
    edge[cnt].v = v, edge[cnt].w = w;
    edge[cnt].next = first[u], first[u] = cnt++;
}

void toposort()
{
    queue<int> q;
    for(int i = 0; i < n; i++) if(!ind[i])
    {
        q.push(i);
        Ee[i] = 1;
    }
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        for(int e = first[x]; e != -1; e = edge[e].next)
        {
            int v = edge[e].v, w = edge[e].w;
            if(--ind[v] == 0) q.push(v);
            if(Ee[v] < Ee[x] + w)
            {
                Ee[v] = Ee[x] + w;
            }
        }
    }
}

void read_case()
{
    init();
    while(m--)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        read_graph(u, v, w);
        ind[v]++;
    }
}

void solve()
{
    int ans = 0;
    read_case();
    toposort();
    for(int i = 0; i < n; i++) ans = max(ans, Ee[i]); //å¯»æ¾æé¿è·¯å¾å³å¯ã 
    printf("%d\n", ans);
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        solve();
    }
    return 0;
}
