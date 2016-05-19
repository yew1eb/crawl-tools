#include <iostream>
#include <cstring>
#include <cstdio>
#define inf 1000000000
using namespace std;
int map[1005][1005];
char str[1005][1000];
int val[1005];
int vis[1005];
int cost[1005];
int n;
void dijkstra()
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i<n; i++)
        cost[i] = map[0][i];
    cost[0] = 0;
    vis[0] = 1;
    for (int i = 1; i<n; i++)
    {
        int  pos,min = inf;
        for (int j = 1; j<n; j++)
            if (!vis[j] && cost[j] <= min)
            {
                pos = j;
                min = cost[j];
            }
        vis[pos] = 1;
        for (int j = 1; j<n; j++)
        {
            if (!vis[j] && (cost[j]>cost[pos] + map[pos][j]))
            {
                cost[j] = cost[pos] + map[pos][j];
            }
        }
    }
}
int main()
{
    int len;
    while (scanf("%d", &n), n)
    {
        for (int i = 0; i<n; i++)
            scanf("%d%s", &val[i], str[i]);
        for (int i = 0; i<n; i++)
        {
            len = strlen(str[i]);
            for (int j = 1; j<n; j++)
            {
                if (i == j)
                    continue;
                if (str[j][0] == str[i][len - 4] && str[j][1] == str[i][len - 3] && str[j][2] == str[i][len - 2] && str[j][3] == str[i][len - 1])
                    map[i][j] = val[i];
                else
                {
                    map[i][j] = inf;
                }
            }
        }
        dijkstra();
        if (n == 1)
            printf("-1\n");
        else
            printf("%d\n", cost[n - 1] == inf ? -1 : cost[n - 1]);
    }
    return 0;
}
