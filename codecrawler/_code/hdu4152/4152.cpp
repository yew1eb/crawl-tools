#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int g[22], ans[22], h[22][22];
int n, m, goal, habit, num;
bool vis[22];

void dfs(int s, int t)
{
    if(t == num)
    {
        int sum, k = 1;
        for(int i = 0; i < n; i++)
        {
            sum = 0;
            for(int j = 0; j < m; j++)
                if(vis[j])
                    sum += h[j][i];
            if(sum < g[i])
                k = 0;
        }
        if(k && t > habit)
        {
            habit = t;
            for(int i = 0, x = 0; i < m; i++)
                if(vis[i])
                    ans[x++] = i;
        }
        return ;
    }
    for(int i = s; i < m; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(i + 1, t + 1);
            vis[i] = 0;
        }
    }
    return ;
}

int main()
{
    int i, j;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 0; i < n; i++)
            scanf("%d", &g[i]);
        scanf("%d", &m);
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                scanf("%d", &h[i][j]);
        habit = goal = 0;
        for(i = m; i > 0; i--)
        {
            memset(vis, 0, sizeof(vis));
            num = i;
            dfs(0, 0);
        }
        printf("%d", habit);
        for(i = 0; i < habit; i++)
            printf(" %d", ans[i] + 1);
        printf("\n");
    }
}