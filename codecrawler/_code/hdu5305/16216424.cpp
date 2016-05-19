#include <cstdio>
#include <cstring>
bool mp[10][10];
int deg[10], c1[10], c2[10];
int n, m, cnt, ans;

struct EDGE
{
    int u, v;
}e[100000];

void DFS(int cur)
{
    if(cur == m + 1)
    {
        ans ++;
        return;
    }
    int v = e[cur].v;
    int u = e[cur].u;
    if(c1[u] && c1[v])
    {
        c1[u] --;
        c1[v] --;
        DFS(cur + 1);
        c1[u] ++;
        c1[v] ++;
    }
    if(c2[u] && c2[v])
    {
        c2[u] --;
        c2[v] --;
        DFS(cur + 1);
        c2[u] ++;
        c2[v] ++;
    }
    return;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        cnt = 0;
        ans = 0;
        memset(deg, 0, sizeof(deg));
        memset(e, 0, sizeof(e));
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d", &e[i].u, &e[i].v);
            deg[e[i].u] ++;
            deg[e[i].v] ++;
        }
        bool f = false;
        for(int i = 1; i <= n; i++)
        {
            c1[i] = c2[i] = deg[i] / 2;
            if(deg[i] & 1)
            {
                f = true;
                break;
            }
        }
        if(f)
        {
            printf("0\n");
            continue;
        }
        DFS(1);
        printf("%d\n", ans);
    }
}