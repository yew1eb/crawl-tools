#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int inf = 100000000;
int n,m,s;
int map[1005][1005];
int vis[1005],cast[1005];

void Dijkstra()
{
    int i,j,minn,pos;
    memset(vis,0,sizeof(vis));
    vis[0] = 1;
    for(i = 0; i<=n; i++)
        cast[i] = map[0][i];
    for(i = 0; i<=n; i++)
    {
        minn = inf;
        for(j = 0; j<=n; j++)
        {
            if(cast[j]<minn && !vis[j])
            {
                pos = j;
                minn = cast[j];
            }
        }
        vis[pos] = 1;
        for(j = 0; j<=n; j++)
        {
            if(cast[pos]+map[pos][j]<cast[j] && !vis[j])
                cast[j] = cast[pos]+map[pos][j];
        }
    }
}


int main()
{
    int i,j;
    int x,y,t;
    while(~scanf("%d%d%d",&n,&m,&s))
    {
        for(i = 0; i<=n; i++)
            for(j = 0; j<=n; j++)
                map[i][j] = inf;
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&t);
            if(t<map[x][y])
            map[x][y] = t;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&x);
            map[0][x] = 0;
        }
        Dijkstra();
        if(cast[s] == inf)
            printf("-1\n");
        else
            printf("%d\n",cast[s]);
    }

    return 0;
}
