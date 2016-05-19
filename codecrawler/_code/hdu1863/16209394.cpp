#include <iostream>
#include <cstring>
#define INF 999999999
using namespace std;

int map[105][105],visit[105],dis[105],M;
int prim()
{
    for(int i = 1;i <= M; i++)
    {
        dis[i] = map[i][1];
    }
    dis[1] = 0;
    visit[1] = 1;
    int sum = 0;
    for(int i = 1; i <= M-1; i++)
    {
        int temp = INF,pos;
        for(int j= 1; j <= M; j++)
        {
            if(!visit[j] && temp > dis[j])
            {
                temp = dis[j];
                pos = j;
            }
        }
        if(temp == INF)return 0;
        visit[pos] = 1;
        sum += dis[pos];
        for(int j = 1; j <= M; j++)
        {
            if(!visit[j] && map[pos][j] < dis[j] && map[pos][j]!=INF)
            {
                dis[j] = map[pos][j];
            }
        }
    }
    return sum;
}
int main()
{
    int N;
    while(scanf("%d%d",&N,&M),N)
    {
        int u,v,w;
        memset(map,0x3f,sizeof(map));
        memset(dis,0x3f,sizeof(dis));
        memset(visit,0,sizeof(visit));
        for(int i = 1; i <= N; ++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            map[u][v] = map[v][u] = w;
        }
        int ans = prim();
        if(ans)
            printf("%d\n",ans);
        else
            printf("?\n");
    }
} 