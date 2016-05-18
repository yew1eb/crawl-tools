#include<stdio.h>
#include<string.h>
#define N 210
#define inf 0x3fffffff
int n,m,vis[N],dis[N];
int map[N][N];
int dijkstra(int s) 
{
    int i,j,k,min;
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
        dis[i]=inf;
    dis[s]=0;
    for(i=1;i<=n;i++)
    {
        min=inf;k=-1;
        for(j=0;j<n;j++)
        {
            if(min>dis[j]&&vis[j]==0)
            {
                k=j;
                min=dis[j];
            }
        }
        if(k==-1||dis[k]>7)break;
        vis[k]=1;
        for(j=0;j<n;j++)
            if(!vis[j]&&dis[j]>dis[k]+map[k][j])
                dis[j]=dis[k]+map[k][j];
    }
    if(i<=n)return 0;
    else return 1;
}
int main()
{
    int i,j,x,y;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                map[i][j]=inf;
            for(i=0;i<m;i++)
            {
                scanf("%d%d",&x,&y);
                if(x!=y)
                map[x][y]=map[y][x]=1;
            }
            for(i=0;i<n;i++)
            {
                 if(dijkstra(i)==0)break;
            }
            if(i<n)
                printf("No\n");
            else printf("Yes\n");        
    }
    return 0;
}