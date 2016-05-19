#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int map[20][20];
int n,vis[20],maxn;

void dfs(int now,int len,int tim)
{
    maxn = max(maxn,len);
    if(maxn == n)
        return ;
    for(int i = 1; i<n; i++)
    {
        if(vis[i])
            continue;
        if(map[now][i]>=tim)
        {
            vis[i] = 1;
            dfs(i,len+1,map[now][i]);
            vis[i] = 0;
        }
    }
}

int main()
{
    int i,j;
    while(~scanf("%d",&n))
    {
        for(i = 0; i<n; i++)
        {
            for(j = 0; j<n; j++)
                scanf("%d",&map[i][j]);
        }
        maxn = 0;
        memset(vis,0,sizeof(vis));
        vis[0] = 1;
        for(int i = 1; i<n; i++)
        {
            vis[i] = 1;
            dfs(i,2,map[0][i]);
            vis[i] = 0;
        }
        printf("%d\n",maxn);
    }

    return 0;
}
