#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int inf = 1<<30;

int T,S,D,n;
int map[1111][1111];
int vis[1111],cast[1111];
int s[1111],e[1111];

void Dijkstra()
{
    int i,j,minn,pos;
    memset(vis,0,sizeof(vis));
    vis[0] = 1;
    for(i = 0; i<=n; i++)
        cast[i] = map[0][i];
    for(i = 1; i<=n; i++)
    {
        minn = inf;
        for(j = 1; j<=n; j++)
        {
            if(cast[j]<minn && !vis[j])
            {
                pos = j;
                minn = cast[j];
            }
        }
        vis[pos] = 1;
        for(j = 1; j<=n; j++)
        {
            if(cast[pos]+map[pos][j]<cast[j] && !vis[j])
                cast[j] = cast[pos]+map[pos][j];
        }
    }
}

int main()
{
    int i,j,x,y,z,start,end;
    while(~scanf("%d%d%d",&T,&S,&D))
    {
        n = 0;
        for(i = 0; i<1111; i++)
        {
            for(j = 0; j<1111; j++)
                map[i][j] = inf;
            map[i][i] = 0;
        }
        while(T--)
        {
            scanf("%d%d%d",&x,&y,&z);
            n = max(max(n,x),y);
            if(z<map[x][y])
                map[x][y] = map[y][x] = z;
        }
        int minn = inf;
        for(i = 0; i<S; i++)
        {
            scanf("%d",&s[i]);
            map[0][s[i]] = map[s[i]][0] = 0;
        }
        for(i = 0; i<D; i++)
            scanf("%d",&e[i]);
        Dijkstra();
        for(i = 0; i<D; i++)
            minn = min(minn,cast[e[i]]);
        printf("%d\n",minn);
    }

    return 0;
}
