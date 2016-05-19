#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 0x3f3f3f3f
#define N 1010

int num, road, destination;
int map[N][N], dis[N];
bool visit[N];

void Dijkstra()
{
    int temp, k;
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i <= num; ++i) //n+1ä¸ªç¹çDijkstra
        dis[i] = map[0][i];
    dis[0] = 0;
    visit[0] = 1;
    for(int i = 0; i <= num; ++i)
    {
        temp = MAX;
        for(int j = 0; j <= num; ++j)
            if(!visit[j] && temp > dis[j])
                temp = dis[k = j];
        if(temp == MAX) break;
        visit[k] = 1;
        for(int j = 0; j <= num; ++j)
            if(!visit[j] && dis[j] > dis[k] + map[k][j])
                dis[j] = dis[k] + map[k][j];
    }
}

int main()
{
    int x, y, cost, exp, cost1;
    while(scanf("%d%d%d", &num, &road, &destination) != EOF)
    {
        memset(map, MAX, sizeof(map));
        for(int i = 1; i <= road; ++i)
        {
            scanf("%d%d%d", &x, &y, &cost);
            if(cost < map[x][y])
            map[x][y] = cost;
        }
        scanf("%d", &exp);
        for(int i = 1; i <= exp; ++i) //å·§å¦ä¹å¤ï¼å è¶çº§æºç¹
        {
            scanf("%d", &cost1);
            map[0][cost1] = 0;
        }
        Dijkstra();
        if(dis[destination] == MAX) printf("-1\n");
        else printf("%d\n", dis[destination]);
    }
    return 0;
}