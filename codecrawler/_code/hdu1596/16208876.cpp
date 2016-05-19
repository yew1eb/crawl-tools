#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const double inf = 1000000;
int n,m;
double map[1005][1005],cast[1005];
int x,y,vis[1005];

void Dijkstra(int s,int e)
{
    int i,j,pos;
    double maxn;
    int flag = 0;
    for(i = 1; i<=n; i++)
    {
        vis[i] = 0;
        cast[i] = map[s][i];
    }
    vis[s] = 1;
    for(i = 1; i<n; i++)
    {
        pos = s;
        maxn = 0;
        for(j = 1; j<=n; j++)
        {
            if(cast[j]>maxn && !vis[j])
            {
                pos = j;
                maxn = cast[j];
            }
        }
        if(fabs(maxn)<=10e-6)
        {
            flag = 1;
            break;
        }
        vis[pos] = 1;
        for(j = 1; j<=n; j++)
        {
            if(!vis[j] && map[pos][j]>0 && cast[pos]*map[pos][j]>cast[j])
                cast[j] = cast[pos]*map[pos][j];
        }
    }
    if(flag)
        printf("What a pity!\n");
    else
        printf("%.3lf\n",cast[e]);
}

int main()
{
    int i,j;
    double w;
    while(~scanf("%d",&n))
    {
        for(i = 1; i<=n; i++)
            for(j = 1; j<=n; j++)
                scanf("%lf",&map[i][j]);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            Dijkstra(x,y);
        }
    }

    return 0;
}
