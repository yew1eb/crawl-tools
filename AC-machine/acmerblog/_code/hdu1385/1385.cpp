#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=1202;
const int INF=99999999;
int map[MAXN][MAXN],path[MAXN][MAXN],n,cost[MAXN],st,ed;
void Floyd()
{
    int i,j,k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                if(map[i][j]>map[i][k]+map[k][j]+cost[k])
                {
                    map[i][j]=map[i][k]+map[k][j]+cost[k];
                    path[i][j]=path[i][k];
                }
                else if(map[i][j]==map[i][k]+map[k][j]+cost[k])//寻找字典序更小的路径
                {
                    if(path[i][j]>path[i][k])
                    {
                        path[i][j]=path[i][k];
                    }
                }
            }
}
int main()
{
    while(scanf("%d",&n)!=EOF&&n)
    {
        int i,j,w;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                path[i][j]=j;
                scanf("%d",&map[i][j]);
                if(map[i][j]==-1) map[i][j]=INF;
            }
        }
        for(i=1; i<=n; i++)
            scanf("%d",&cost[i]);
        Floyd();
        while(scanf("%d%d",&st,&ed))
        {
            if( st==-1&&ed==-1) break;
            printf("From %d to %d :\n",st,ed);
            printf("Path: %d",st);
            int u=st,v=ed;
            while (u!=v)
            {
                printf ("-->%d", path[u][v]);
                u=path[u][v];
            }
            printf("\n");
            printf("Total cost : %d\n\n",map[st][ed]);
        }
    }
    return 0;
}