#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int inf = 1<<30;

int n;
int map[205][205];
int a[205],cnt;
int vis[205],cast[205];

void Dijkstra(int s,int e)
{
    int i,j,min,pos;
    memset(vis,0,sizeof(vis));
    for(i = 0; i<n; i++)
        cast[i] = map[s][i];
    cast[s] = 0;
    vis[s] = 1;
    for(i = 1; i<n; i++)
    {
        min = inf;
        for(j = 0; j<n; j++)
        {
            if(cast[j]<min && !vis[j])
            {
                pos = j;
                min = cast[j];
            }
        }
        if(min == inf)
            break;
        vis[pos] = 1;
        for(j = 0; j<n; j++)
        {
            if(cast[pos]+map[pos][j]<cast[j] && !vis[j])
                cast[j] = cast[pos]+map[pos][j];
        }
    }
}

int main()
{
    int i,j,s,e,x,y;
    while(~scanf("%d",&n),n)
    {
        scanf("%d%d",&s,&e);
        s--,e--;
        for(i = 0; i<n; i++)
            for(j = 0; j<n; j++)
                map[i][j] = inf;
        for(i = 0; i<n; i++)
        {
            scanf("%d",&a[i]);
            if(i+a[i]<n)
                map[i][i+a[i]] = 1;
            if(i-a[i]>=0)
                map[i][i-a[i]] = 1;
        }
        Dijkstra(s,e);
        printf("%d\n",cast[e]==inf?-1:cast[e]);
    }

    return 0;
}