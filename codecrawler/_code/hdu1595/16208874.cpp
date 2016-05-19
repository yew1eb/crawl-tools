#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int inf = 999999999;
int map[1005][1005];
int vis[1005],dis[1005],link[1005];
int n,m;

void Dijkstra(int s,int flag)
{
    int i,j,minn,pos;
    memset(vis,0,sizeof(vis));
    for(i = 0; i<=n; i++)
        dis[i] = inf;
    dis[s] = 0;
    for(i = 1; i<=n; i++)
    {
        minn = inf;
        for(j = 1; j<=n; j++)
        {
            if(dis[j]<minn && !vis[j])
                minn = dis[pos = j];
        }
        vis[pos] = 1;
        for(j = 1; j<=n; j++)
            if(dis[pos]+map[pos][j]<dis[j])
            {
                dis[j] = dis[pos]+map[pos][j];
                if(flag)//åªè®°å½æç­åªæ¡è·¯å¾çç¶èç¹
                    link[j] = pos;
            }
    }
}

int main()
{
    int i,j,x,y,w;
    while(~scanf("%d%d",&n,&m))
    {
        for(i = 0; i<=n; i++)
        {
            for(j = 0; j<=n; j++)
                map[i][j] = inf;
            map[i][i] = 0;
        }
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&w);
            if(w<map[x][y])
                map[x][y] = map[y][x] = w;
        }
        memset(link,0,sizeof(link));
        Dijkstra(1,1);
        int ans = dis[n];
        for(i = n; i!=1; i=link[i])
        {
            int tem = map[i][link[i]];
            map[i][link[i]] = map[link[i]][i] = inf;
            Dijkstra(1,0);
            ans = max(ans,dis[n]);
            map[i][link[i]] = map[link[i]][i] = tem;
        }
        printf("%d\n",ans);
    }

    return 0;
}
