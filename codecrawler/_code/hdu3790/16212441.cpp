#include <stdio.h>
#include <string.h>

#define MAX 1001
#define INF 999999999

typedef struct _road
{
    int d;
    int p;
}road;

road map[MAX][MAX];

int n, m;

void init()
{
    int i, j;
    for(i = 1; i <= n; i ++){
        for(j = 1; j <= n; j ++){
            map[i][j].d = INF;
            map[i][j].p = INF;
        }
    }
}

void dijkstra(int start, int end)
{
    int dist[MAX];
    int cost[MAX];
    int min1, min2;
    int pre[MAX];
    memset(pre, 0, sizeof(pre));
    int i, j, v;
    for(i = 1; i <= n; i ++){
        dist[i] = map[start][i].d;
        cost[i] = map[start][i].p;
    }
    pre[start] = 1;//å¾ªç¯ån-1æ¬¡
    for(i = 1; i < n; i ++){
        min1 = INF;
        min2 = INF;//è®°å½å½åæç­è·¯å¾çé¡¶ç¹
        for(j = 1; j <= n; j ++){
            if(pre[j] == 0 && (min1 > dist[j] || (dist[j] == min1 && min2 > cost[j]))){
                v = j;
                min1 = dist[j];
                min2 = cost[j];
            }
        }
        if(min1 == INF)break;
        pre[v] = 1;//æ´æ°
        for(j = 1; j <= n; j ++){
            if(pre[j] == 0){
                if((dist[v] + map[v][j].d) <= dist[j] || (dist[v] + map[v][j].d == dist[j] && cost[v] + map[v][j].p < cost[j])){
                    dist[j] = dist[v] + map[v][j].d;
                    cost[j] = cost[v] + map[v][j].p;
                }
            }
        }
    }
    printf("%d %d\n", dist[end], cost[end]);
}

int main()
{
    int a, b, d, p;
    int i;
    int s, t;
    while(scanf("%d%d", &n, &m)!=EOF){
        if(n ==0 && m == 0)break;
        init();
        for(i = 0; i < m; i ++){
            scanf("%d%d%d%d", &a, &b, &d, &p);//è¿æ»¤éè¾¹
            if(d < map[a][b].d || (d == map[a][b].d && p < map[a][b].p)){
                map[a][b].d = map[b][a].d = d;
                map[a][b].p = map[b][a].p = p;
            }
        }
        scanf("%d%d", &s, &t);
        dijkstra(s, t);
    }    
    return 0;
}