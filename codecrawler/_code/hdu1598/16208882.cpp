#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 205;
const int maxm = 1005;
const int inf = (0x7f7f7f7f);
#define min(a,b)    ((a)<(b)?(a):(b))

int n, m, s, t;
int ans;
int fa[maxn];
struct Edge
{
    int s, e, speed;
}edge[maxm];

int cmp(Edge a, Edge b)
{
    return a.speed < b.speed;
}

int find(int x)
{
    while (fa[x] != x) x = fa[x];
    return x;
}

int main()
{
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int i, j;
        for (i=0; i<m; i++)
        {
            scanf("%d %d %d", &edge[i].s, &edge[i].e, &edge[i].speed);
        }
        sort(edge, edge+m, cmp);
        int q;
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d %d", &s, &t);
            int min = inf;
            for (i=0; i<m; i++)    //æä¸¾
            {
                for (j=1; j<=n; j++) fa[j] = j;
                for (j=i; j<m; j++)
                {
                    int fx = find(edge[j].s);
                    int fy = find(edge[j].e);
                    if (fx != fy) fa[fx] = fy;
                    if (find(s) == find(t))
                    {
                        min = min(min, edge[j].speed - edge[i].speed);
                        break;
                    }
                }
            }
            if (min == inf) puts("-1");
            else printf("%d\n", min);
        }
    }
    return 0;
}