#include <iostream>
#include <cstring>
#include <cstdio>
#define inf 99999999
using namespace std;
int dist[105][105];
int map[105][105];
int micircle;
int n;
void floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<k;i++)
        {
            for(j=i+1;j<k;j++)
                micircle=min(micircle,map[i][k]+map[k][j]+dist[i][j]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        int j;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i==j)
                    map[i][j]=dist[i][j]=0;
                else
                    map[i][j]=dist[i][j]=inf;
            }
        }
        for(i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(w<map[u][v])
                map[u][v]=map[v][u]=dist[u][v]=dist[v][u]=w;
        }

        micircle=inf;
        floyd();
        if(micircle>=inf)
            printf("It's impossible.\n");
        else
            printf("%d\n",micircle);
    }
    return 0;
}
