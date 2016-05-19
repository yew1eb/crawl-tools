#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int inf = 1<<30;

int n,m;
int map[300][300];
int vis[300],cast[300];

void Dijkstra(int s,int e)
{
    int i,j,min,pos;
    memset(vis,0,sizeof(vis));
    cast[s] = 0;
    vis[s] = 1;
    for(i = 0;i<n;i++)
    cast[i] = map[s][i];
    for(i = 1;i<n;i++)
    {
        min = inf;
        for(j = 0;j<n;j++)
        {
            if(cast[j]<min && !vis[j])
            {
                pos = j;
                min = cast[j];
            }
        }
        vis[pos] = 1;
        for(j = 0;j<n;j++)
        {
            if(cast[pos]+map[pos][j]<cast[j] && !vis[j])
            cast[j] = cast[pos]+map[pos][j];
        }
    }
}

int main()
{
    int i,j,x,y,z,start,end;
    while(~scanf("%d%d",&n,&m))
    {
        for(i = 0; i<200; i++)
        {
            for(j = 0; j<200; j++)
                map[i][j] = inf;
            map[i][i] = 0;
        }
        for(i = 0; i<m; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(z<map[x][y])
            map[x][y] = map[y][x] = z;
        }
        scanf("%d%d",&start,&end);
        Dijkstra(start,end);
        printf("%d\n",cast[end]==inf?-1:cast[end]);
    }

    return 0;
}
