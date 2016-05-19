#include<stdio.h>
#include<string.h>
#define INF 1<<26
const int N = 1e3 + 10;
int w[N][N], d[N];

void Dijkstra(int n, int u)
{
    int vis[N], i;
    memset(vis, 0, sizeof(vis));
    for(i = 0; i <= n; i++)
        d[i] = INF;
    d[u] = 0;
    for(i = 0; i <= n; i++)
    {
        int x = u, temp = INF;
        for(int y = 0; y <= n; y++)
            if(!vis[y] && d[y] < temp)
                temp = d[x = y];
        if(temp == INF) break;
        vis[x] = 1;
        for(int y = 0; y <= n; y++)
            if(d[y] > d[x] + w[x][y])
                d[y] = d[x]+ w[x][y];
    }
}

int main()
{
    int n, m, des, i, j;
    while(~scanf("%d%d%d",&n, &m, &des))
    {
        for(i = 0; i <= n; i++)
            for(j = 0; j <= n; j++)
            {
                if(i == j)
                    w[i][j] = 0;
                else
                    w[i][j] = INF;
            }
        int a, b, c;
        for(i = 0; i < m; i++)
        {
            scanf("%d%d%d",&a, &b, &c);
            if(c < w[a][b])
                w[a][b] = c;
            //ä¸¤ä¸ªè½¦ç«ä¹é´å¦ææå¤æ¡è·¯ï¼éæ©æç­çä¸æ¡
        }
        int num, p;
        scanf("%d",&num);
        for(i = 0; i < num; i++)
        {
            scanf("%d",&p);
            w[0][p] = 0;
            //èªå·±å ä¸ä¸ªèµ·ç¹ï¼æå¾æ´æ°
        }
        Dijkstra(n, 0);
        if(d[des] < INF)
            printf("%d\n",d[des]);
        else
            printf("-1\n");
    }
    return 0;
}