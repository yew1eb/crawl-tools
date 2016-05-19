#include <iostream>
#include <queue>
using namespace std;
const int inf = 1000000000;
struct Node
{
    int x, y;
};
int map[256][256], cost[256][256];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int n, m;
Node fruit[18];
int val[17], cunt;
int dis[18][18];
queue<Node> Q;
int best[1<<17][17];
bool Bound(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
void BFS(Node start)
{
    int i, j;
    Node now, nex;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cost[i][j] = inf;
        }
    }
    cost[start.x][start.y] = 0;
    Q.push(start);
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for (i = 0; i < 4; i++)
        {
            nex.x = now.x + dir[i][0];
            nex.y = now.y + dir[i][1];
            if (Bound(nex.x, nex.y) && map[nex.x][nex.y] != -1 && cost[nex.x][nex.y] == inf)
            {
                cost[nex.x][nex.y] = cost[now.x][now.y] + 1;
                Q.push(nex);
            }
        }
    }
}
void DP()
{
    int i, j, v;
    Node now, nex;
    for (i = 1; i < (1 << cunt); i++)
    {
        for (j = 0; j < cunt; j++)
        {
            best[i][j] = -1;
        }
    }
    best[1][0] = val[0];
    now.x = 1; now.y = 0;
    Q.push(now);
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for (i = 1; i < cunt; i++)
        {
            if ((now.x & (1 << i)) == 0)
            {
                nex.x = (now.x | (1 << i));
                nex.y = i;
                v = best[now.x][now.y] - dis[now.y][nex.y];
                if (v < 0)
                {
                    continue;
                }
                v = v + val[nex.y];
                if (v > best[nex.x][nex.y])
                {
                    best[nex.x][nex.y] = v;
                    Q.push(nex);
                }
            }
        }
    }
}
int main()
{
    int i, j, ans;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        cunt = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                scanf("%d", &map[i][j]);
                if (map[i][j] > 0)
                {
                    fruit[cunt].x = i;
                    fruit[cunt].y = j;
                    val[cunt++] = map[i][j];
                }
            }
        }
        if (n == 1 && m == 1)
        {
            printf("%d/n", map[0][0]);
            continue;
        }
        if (map[0][0] == 0)
        {
            printf("you loss!/n");
            continue;
        }
        // 把终点也加入进去计算距离
        fruit[cunt].x = n - 1;
        fruit[cunt].y = m - 1;
        for (i = 0; i <= cunt; i++)
        {
            BFS(fruit[i]);
            for (j = 0; j <= cunt; j++)
            {
                dis[i][j] = cost[fruit[j].x][fruit[j].y];
            }
        }
        DP();
        ans = -1;
        for (i = 1; i < (1 << cunt); i++)
        {
            for (j = 0; j < cunt; j++)
            {
                if (ans < best[i][j] - dis[j][cunt])
                {
                    ans = best[i][j] - dis[j][cunt];
                }
            }
        }
        if (ans >= 0)
        {
            printf("%d/n", ans);
        }
        else
        {
            printf("you loss!/n");
        }
    }
    return 0;
} 
参考：http://blog.csdn.net/racebug2010/article/details/6177834
						                        





(adsbygoogle = window.adsbygoogle || []).push({});

 


window._bd_share_config={"common":{"bdSnsKey":{},"bdText":"","bdMini":"2","bdMiniList":false,"bdPic":"","bdStyle":"0","bdSize":"24"},"share":{}};with(document)0[(getElementsByTagName('head')[0]||body).appendChild(createElement('script')).src='http://bdimg.share.baidu.com/static/api/js/share.js?v=89860593.js?cdnversion='+~(-new Date()/36e5)];

					