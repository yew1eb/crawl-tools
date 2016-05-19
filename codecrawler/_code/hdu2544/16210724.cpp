#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3;
int map[110][110],dis[110],visited[110];

void Dijkstra(int n,int x)
{
    int i,p,j,min;
    for (i=1;i<=n;i++)
    {
        dis[i]=map[1][i];
        visited[i]=0;
    }
    visited[x]=1;
    for (i=1;i<=n;i++)
    {
        min=INF;
        for (j=1;j<=n;j++)
        {
            if(!visited[j] && dis[j]<min)
            {
                p=j;
                min=dis[j];
            }
        }
        visited[p]=1;
        for (j=1;j<=n;j++)
        {
            if(!visited[j] && dis[p]+map[p][j]<dis[j])
            {
                    dis[j]=dis[p]+map[p][j];
            }
        }
    }
    
}

int main()
{
    int n,m,i,j,a,b,t;
    while(scanf("%d%d",&n,&m)!=EOF,n+m)
    {
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                map[i][j]=INF;
            }
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&t);
            map[a][b]=map[b][a]=t;
        }
        Dijkstra(n,1);
        printf("%d\n",dis[n]);
    }
    return 0;
}